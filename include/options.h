#ifndef UPR_OPTIONS_H
#define UPR_OPTIONS_H
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef enum { GAME_UNKNOWN=0, GAME_FRLG, GAME_RSE } game_t; // expand later

typedef struct {
  const char* rom_in;
  const char* rom_out;
  const char* patch_out;
  uint64_t seed;
  uint64_t seq;
  bool seed_auto;
  bool randomize_starters;
  bool randomize_wild;
  bool randomize_trainers;
  bool ban_legendaries;
  bool similar_strength;
  bool dry_run;
  int  verbosity;
  game_t game;
} upr_options_t;

void upr_options_init(upr_options_t* o);
void upr_options_print(const upr_options_t* o);
int  upr_detect_game(const unsigned char* rom, size_t size, game_t* out);
const char* upr_game_name(game_t g);

#endif
