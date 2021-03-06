// Descriptor.h: interface for the Descriptor class.
//
//////////////////////////////////////////////////////////////////////
#if !defined __DESCRIPTOR_H__
#define __DESCRIPTOR_H__
#define DESCRIPTOR_HEADER_LENGTH 2

class BitReadWriter;

class Descriptor
{
public:	
	Descriptor();
	Descriptor(BitReadWriter *rw);
	virtual ~Descriptor();

	int GetDescriptorLength();
	int GetDescriptorTag();

	virtual void WriteDescriptor(BitReadWriter* rw)=0;
	virtual void PrintDescriptor()=0;

	static enum DESCRIPTOR_TAG
	{
		APPLICATION_DESCRIPTOR = 0x00,
		APPLICATION_NAME_DESCRIPTOR = 0x01, 
		TRANSPORT_PROTOCOL_DESCRIPTOR = 0x02,
		APPLICATION_RECORDING_DESCRIPTOR = 0x06, 
		SIMPLE_APPLICATION_LOCATION_DESCRIPTOR = 0x15, 
		APPLICATION_USAGE_DESCRIPTOR = 0x16,
		SIMPLE_APPLICATION_BOUNDARY_DESCRIPTOR = 0x17,
		PARENTAL_RATING_DESCRIPTOR = 0x55, 
		UNKNOWN_DESCRIPTOR = 0xff,
	} _SUPPORTED_DESCRIPTOR_TAG_;

protected:
	virtual void calcLength()=0;

	int descriptor_tag;
	int descriptor_length;
};

class UnknownDescriptor : public Descriptor
{
public:
	UnknownDescriptor();
	UnknownDescriptor(BitReadWriter *rw);
	virtual ~UnknownDescriptor();

	virtual void WriteDescriptor(BitReadWriter* rw){};
	virtual void PrintDescriptor();

protected:
	virtual void calcLength(){};
};
#endif 
