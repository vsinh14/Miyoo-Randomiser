#ifndef UPR_ROM_H
#define UPR_ROM_H
#include <stddef.h>
#include <stdint.h>
typedef struct {
  uint8_t* data;
  size_t   size;
} rom_t;

int  rom_load(const char* path, rom_t* out);
int  rom_save(const char* path, const rom_t* rom);
void rom_free(rom_t* rom);

#endif
