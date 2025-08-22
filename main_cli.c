#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <getopt.h>

#include "rom.h"
#include "patch.h"
#include "rng.h"
#include "shuffle.h"
#include "options.h"

static uint64_t auto_seed(void){
  FILE* f = fopen("/dev/urandom", "rb");
  uint64_t s=0;
  if(f){ fread(&s,1,sizeof(s),f); fclose(f); }
  if(s==0){ s = (uint64_t)time(NULL) ^ 0xA57F23D4u; }
  return s;
}

static void usage(const char* prog){
  fprintf(stderr,
  "Usage: %s --in ROM --out ROM [options]\n", prog);
}

static int list_games = 0;

static void plan_print(const upr_options_t* o, game_t g){
  printf("Plan: game=%s, seed=%llu, seq=%llu\n", upr_game_name(g),
         (unsigned long long)o->seed, (unsigned long long)o->seq);
}

static int do_randomize(rom_t* rom, const upr_options_t* opt){
  pcg32_t rng;
  pcg32_seed(&rng, opt->seed, opt->seq);
  size_t off = 0x100;
  for(int i=0;i<16;i++){
    patch_write8(rom, off+i, (uint8_t)pcg32_bounded(&rng, 256));
  }
  return 0;
}

int main(int argc, char** argv){
  upr_options_t opt; upr_options_init(&opt);
  // parsing omitted for brevity in zip version
  opt.rom_in = argv[1];
  opt.rom_out = argv[2];
  opt.seed = 12345; opt.seed_auto=false;
  rom_t rom={0};
  if(rom_load(opt.rom_in, &rom)){ return 3; }
  game_t g=GAME_UNKNOWN;
  upr_detect_game(rom.data, rom.size, &g);
  plan_print(&opt, g);
  do_randomize(&rom, &opt);
  rom_save(opt.rom_out, &rom);
  rom_free(&rom);
  return 0;
}
