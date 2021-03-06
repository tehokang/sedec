// DSISection.h: interface for the AITSection class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(__APPLICATION_H__)
#define __APPLICATION_H__

#include <list>
class Descriptor;
class BitReadWriter;

using namespace std;
class Application
{
public:
	Application();
	Application(BitReadWriter *rw);
	virtual ~Application();
	virtual int GetApplicationLength();
	virtual void WriteApplication(BitReadWriter *rw);
	virtual void PrintApplication();


	/* Interfaces to encode (setter) */
	void SetOrganizationId(int org_id) { organization_id = org_id;}
	void SetApplicationId(int app_id) { application_id = app_id;}
	
	void SetApplicationControlCode(int control_code) 
	{ 
		application_control_code = control_code;
	}

	void SetDescriptors(list<Descriptor*> descriptors) 
	{ 
		application_descriptors = descriptors;
	}

	/* Interfaces to decode (getter) */
	int GetOrganizationId(){ return organization_id;}
	int GetApplicationId() { return application_id;}
	int GetApplicationControlCode() { return application_control_code;}
	int GetApplicationDescriptorLength() { return application_descriptors_loop_length;}
	list<Descriptor*> GetDescriptors() { return application_descriptors;};

private:
	virtual void calcLength();

	/* application identifier */
	int organization_id;
	int application_id;

	int application_control_code;
	int application_descriptors_loop_length;
	list<Descriptor*> application_descriptors;
	int m_application_length;
};

#endif 
