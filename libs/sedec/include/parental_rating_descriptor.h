// parental_rating_descriptor.h: interface for the ParentalRatingDescriptor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined __PARENTAL_RATING_DESCRIPTOR_H__
#define __PARENTAL_RATING_DESCRIPTOR_H__

#include <list>
#include <string.h>
#include "descriptor.h"

namespace sedec
{
/**
    @addtogroup Sedec
    @{
*/

class BitReadWriter;

class ParentalRatingDescriptor : public Descriptor
{
public:
    ParentalRatingDescriptor();
    ParentalRatingDescriptor(BitReadWriter *rw);
    virtual ~ParentalRatingDescriptor();

    virtual void WriteDescriptor(BitReadWriter* rw);
    virtual void PrintDescriptor();

protected:
    virtual void calcLength();

    int country_code[64];
    unsigned char rating[64];
    int m_parent_rating_count;
};

/** @} */

} // end of sedec namespace
#endif
