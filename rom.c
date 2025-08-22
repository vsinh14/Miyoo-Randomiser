#include "rom.h"
#include <stdio.h>
#include <stdlib.h>

int rom_load(const char* path, rom_t* out){
  FILE* f = fopen(path, "rb");
  if(!f) return -1;
  fseek(f, 0, SEEK_END);
  long sz = ftell(f);
  fseek(f, 0, SEEK_SET);
  if(sz <= 0){ fclose(f); return -2; }
  out->data = (uint8_t*)malloc(sz);
  out->size = (size_t)sz;
  if(!out->data){ fclose(f); return -3; }
  if(fread(out->data, 1, out->size, f) != out->size){ fclose(f); free(out->data); return -4; }
  fclose(f); return 0;
}

int rom_save(const char* path, const rom_t* rom){
  FILE* f = fopen(path, "wb");
  if(!f) return -1;
  size_t n = fwrite(rom->data, 1, rom->size, f);
  fclose(f);
  return n == rom->size ? 0 : -2;
}

void rom_free(rom_t* rom){
  free(rom->data);
  rom->data = NULL;
  rom->size = 0;
}
