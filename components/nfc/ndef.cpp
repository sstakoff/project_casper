#include "ndef.hpp"
#include <cassert>
#include <cstring>



NdefTextRecord::NdefTextRecord(const char *text) {
  recsize = strlen(text) + 1;

  recsize += 4;  // For flags, typelen, payloadlen, type
  recsize += 3; // For the text RTD - add flags and lang code(2)

  pRecord = new uint8_t[recsize];

  uint8_t *tmp = pRecord;
  *(tmp++) = 0xD1; // Flags: MB, ME, SR; TNF = 0x01

  *(tmp++) = 0x01;  // Type Len = 1 byte
  *(tmp++) = strlen(text) + 3; // Payload len
  *(tmp++) = 'T'; // Type == "T" for Text Record

  // Payload
  *(tmp++) = 0x02;  // Length of lang code
  *(tmp++) = 'e';
  *(tmp++) = 'n';

  memcpy(tmp, text, strlen(text) + 1);

}

const uint8_t *NdefTextRecord::data(size_t *datalen) {
  return pRecord;
  *datalen = recsize;
}


NdefTextRecord::~NdefTextRecord() {
  delete[] pRecord;
  pRecord = NULL;
}
