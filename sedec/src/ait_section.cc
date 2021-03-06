// ait_section.cpp: implementation of the AITSection class.
//
//////////////////////////////////////////////////////////////////////

#include "section_common.h"
#include "ait_section.h"
#include "descriptor.h"
#include "application.h"
#include "descriptor_factory.h"

#include <string.h>
#include <cstddef>
#include <stdlib.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

namespace sedec
{

AITSection::AITSection()
{
    m_section_name = strdup("AITSection");

    table_id = APPLICATION_INFORMATION_TABLE;
    section_syntax_indicator = 0x01;
    section_length = 0;
    test_application_flag = 0;
    application_type = 0; // hbbtv : 0x0010 | oipf : 0x0011
    version_number = 0;
    current_next_indicator = 0;
    section_number = 0;
    last_section_number = 0;
    common_descriptors_length = 0;
}

AITSection::AITSection(unsigned char *raw_buffer)
    : Section(raw_buffer, (( raw_buffer[1] << 8 | raw_buffer[2] ) & 0x0fff ) + 3)
{
    decode();
}


AITSection::AITSection(unsigned char *raw_buffer, unsigned int raw_length) 
    : Section(raw_buffer, raw_length)
{
    decode();
}

AITSection::~AITSection()
{
    if(m_section_name) {
        free(m_section_name);
        m_section_name = NULL;
    }

    for (std::list<Descriptor*>::iterator it=m_common_descriptors.begin();
            it != m_common_descriptors.end(); ++it)
    {
        delete (*it);
    }

    for (std::list<Application*>::iterator it=m_applications.begin();
            it != m_applications.end(); ++it)
    {
        delete (*it);
    }

    m_applications.clear();
    m_common_descriptors.clear();
}

void AITSection::decode()
{
    m_section_name = strdup("AITSection");

    if(APPLICATION_INFORMATION_TABLE != table_id ||
            4093 < section_length) return;

    test_application_flag = Read_On_Buffer(1);
    application_type = Read_On_Buffer(15);
    Skip_On_Buffer(2);
    version_number = Read_On_Buffer(5);
    current_next_indicator = Read_On_Buffer(1);
    section_number = Read_On_Buffer(8);
    last_section_number = Read_On_Buffer(8);
    Skip_On_Buffer(4);

    common_descriptors_length = Read_On_Buffer(12);
    for(int i=common_descriptors_length;i>0;)
    {
        Descriptor *desc = DescriptorFactory::CreateDescriptor(this);
        i-=desc->GetDescriptorLength();
        m_common_descriptors.push_back(desc);
    }
    Skip_On_Buffer(4);
    application_loop_length = Read_On_Buffer(12);
    for(int i=application_loop_length;i>0;)
    {
        Application *app = new Application(this);
        i-=app->GetApplicationLength();
        m_applications.push_back(app);
    }
    checksum_CRC32 = Read_On_Buffer(32);
}

void AITSection::PrintSection()
{
    if(APPLICATION_INFORMATION_TABLE != table_id) return;
    SECTION_DEBUG("= AIT Section's raw information is followings ===== \n");
    SECTION_DEBUG("table_id : 0x%x \n", table_id);
    SECTION_DEBUG("section_syntax_indicator : 0x%x \n", section_syntax_indicator);
    SECTION_DEBUG("section_length : 0x%x (%d) \n", section_length, section_length);
    SECTION_DEBUG("test_application_flag : 0x%x \n", test_application_flag);
    SECTION_DEBUG("application_type : 0x%04x \n", application_type);
    SECTION_DEBUG("version_number : 0x%x \n", version_number);
    SECTION_DEBUG("current_next_indicator : %x \n", current_next_indicator);
    SECTION_DEBUG("section_number : 0x%x \n", section_number);
    SECTION_DEBUG("last_section_number : 0x%x \n", last_section_number);
    SECTION_DEBUG("common_descriptors_length : 0x%x (%d)\n",
                    common_descriptors_length, common_descriptors_length);

    for (std::list<Descriptor*>::iterator it=m_common_descriptors.begin();
            it != m_common_descriptors.end(); ++it)
    {
        ((Descriptor*)*it)->PrintDescriptor();
    }
    SECTION_DEBUG("application_loop_length : 0x%x (%d)\n",
                    application_loop_length, application_loop_length);
    int app_index=0;
    for (std::list<Application*>::iterator it=m_applications.begin();
            it != m_applications.end(); ++it)
    {
        SECTION_DEBUG("\n====== [%d] Application list ======\n", app_index++);
        ((Application*)*it)->PrintApplication();
        SECTION_DEBUG("======================================\n");
    }
    SECTION_DEBUG("checksum_CRC32 : 0x%02x%02x%02x%02x \n",
                    (checksum_CRC32 >> 24) & 0xff,
                    (checksum_CRC32 >> 16) & 0xff,
                    (checksum_CRC32 >> 8) & 0xff,
                    checksum_CRC32 & 0xff);
    SECTION_DEBUG("====================================== \n\n");
}

void AITSection::SetSection()
{
    common_descriptors_length = 0;
    for (std::list<Descriptor*>::iterator it=m_common_descriptors.begin();
            it != m_common_descriptors.end(); ++it)
    {
        Descriptor *desc = (Descriptor*)*it;
        common_descriptors_length+=desc->GetDescriptorLength();
    }

    application_loop_length = 0;
    for (std::list<Application*>::iterator it=m_applications.begin();
            it != m_applications.end(); ++it)
    {
        Application *app = (Application*)*it;
        application_loop_length += app->GetApplicationLength();
    }
}

void AITSection::CalcSectionLength()
{
    section_length = 0;
    for (std::list<Descriptor*>::iterator it=m_common_descriptors.begin();
            it != m_common_descriptors.end(); ++it)
    {
        Descriptor *desc = (Descriptor*)*it;
        section_length += desc->GetDescriptorLength();
    }

    for (std::list<Application*>::iterator it=m_applications.begin();
            it != m_applications.end(); ++it)
    {
        Application *app = (Application*)*it;
        section_length += app->GetApplicationLength();
    }
    section_length += 13; /* 9 + crc(4) */
}

void AITSection::WriteSection()
{
    Write_On_Buffer(test_application_flag, 1);
    Write_On_Buffer(application_type, 15);
    Write_On_Buffer(0x03, 2);
    Write_On_Buffer(version_number, 5);
    Write_On_Buffer(current_next_indicator, 1);
    Write_On_Buffer(section_number, 8);
    Write_On_Buffer(last_section_number, 8);
    Write_On_Buffer(0x0f, 4);
    Write_On_Buffer(common_descriptors_length, 12);

    for (std::list<Descriptor*>::iterator it=m_common_descriptors.begin();
            it != m_common_descriptors.end(); ++it)
    {
        Descriptor *desc = (Descriptor*)*it;
        desc->WriteDescriptor(this);
    }

    Write_On_Buffer(0x0f, 4);
    Write_On_Buffer(application_loop_length, 12);

    for (std::list<Application*>::iterator it=m_applications.begin();
            it != m_applications.end(); ++it)
    {
        Application *app = (Application*)*it;
        app->WriteApplication(this);
    }
    MakeCRC();
}

} // end of sedec namespace
