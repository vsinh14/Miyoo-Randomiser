#include "options.h"
#include <stdio.h>
#include <string.h>

void upr_options_init(upr_options_t* o){
  memset(o, 0, sizeof(*o));
  o->verbosity = 1;
  o->seed_auto = true;
}

const char* upr_game_name(game_t g){
  switch(g){
    case GAME_FRLG: return "GBA: FireRed/LeafGreen";
    case GAME_RSE:  return "GBA: Ruby/Sapphire/Emerald";
    default:        return "Unknown";
  }
}

int upr_detect_game(const unsigned char* rom, size_t size, game_t* out){
  if(size < 0xC0) return -1;
  const char* code = (const char*)(rom + 0xAC);
  if(!memcmp(code, "BPRE", 4) || !memcmp(code, "BPGE", 4)){ *out = GAME_FRLG; return 0; }
  if(!memcmp(code, "BPEE", 4) || !memcmp(code, "AXVE", 4) || !memcmp(code, "AXPE", 4)){ *out = GAME_RSE; return 0; }
  *out = GAME_UNKNOWN; return 0;
}

void upr_options_print(const upr_options_t* o){
  printf("[upr-c] config\n");
  printf("  rom_in:  %s\n", o->rom_in ? o->rom_in : "(none)");
  printf("  rom_out: %s\n", o->rom_out ? o->rom_out : "(none)");
  if(o->patch_out) printf("  patch:   %s\n", o->patch_out);
  printf("  seed:    %s%llu\n", o->seed_auto ? "(auto) " : "", (unsigned long long)o->seed);
  printf("  seq:     %llu\n", (unsigned long long)o->seq);
  printf("  features: starters=%d wild=%d trainers=%d ban_legendaries=%d similar=%d\n",
         o->randomize_starters, o->randomize_wild, o->randomize_trainers, o->ban_legendaries, o->similar_strength);
  printf("  modes: dry_run=%d verbosity=%d\n", o->dry_run, o->verbosity);
}
