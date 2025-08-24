#include "patch.h"

#define CHECK(o,s) do{ if((o) >= (s)) return -1; }while(0)

int patch_write8(rom_t* r, size_t off, uint8_t v){ CHECK(off, r->size); r->data[off]=v; return 0; }
int patch_write16(rom_t* r, size_t off, uint16_t v){
  CHECK(off+1, r->size);
  r->data[off]   = (uint8_t)(v & 0xFF);
  r->data[off+1] = (uint8_t)(v >> 8);
  return 0;
}
int patch_write32(rom_t* r, size_t off, uint32_t v){
  CHECK(off+3, r->size);
  r->data[off]   = (uint8_t)(v & 0xFF);
  r->data[off+1] = (uint8_t)((v>>8) & 0xFF);
  r->data[off+2] = (uint8_t)((v>>16)& 0xFF);
  r->data[off+3] = (uint8_t)((v>>24)& 0xFF);
  return 0;
}
