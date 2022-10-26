#ifndef __NDEF_H_
#define __NDEF_H_

#include "stdint.h"
#include <cstddef>


class NdefTextRecord {
  public:
    NdefTextRecord(const char *text);
    ~NdefTextRecord();

    const uint8_t *data(size_t *datalen);

    // size_t data(uint8_t * const * x;)
  private:
    NdefTextRecord(const NdefTextRecord&); // No Copy
    NdefTextRecord& operator=(const NdefTextRecord&); // No assign
    
    uint8_t *pRecord;
    size_t recsize;
};

 class NdefMsg {
  public:
    NdefMsg();
 };




#endif