#ifndef SHUFFLE_H
#define SHUFFLE_H
#include <stdint.h>
#include <stddef.h>
#include "rng.h"

void fisher_yates_u32(uint32_t* a, size_t n, pcg32_t* rng);
size_t weighted_pick(const uint32_t* weights, size_t n, pcg32_t* rng);

#endif
