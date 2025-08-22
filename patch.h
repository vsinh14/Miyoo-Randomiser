#ifndef UPR_PATCH_H
#define UPR_PATCH_H
#include <stddef.h>
#include <stdint.h>
#include "rom.h"
int patch_write8 (rom_t* rom, size_t off, uint8_t v);
int patch_write16(rom_t* rom, size_t off, uint16_t v);
int patch_write32(rom_t* rom, size_t off, uint32_t v);
#endif
