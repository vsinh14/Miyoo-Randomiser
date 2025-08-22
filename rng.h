#ifndef RNG_H
#define RNG_H
#include <stdint.h>

typedef struct { uint64_t state, inc; } pcg32_t;

void     pcg32_seed(pcg32_t* r, uint64_t seed, uint64_t seq);
uint32_t pcg32_next(pcg32_t* r);
uint32_t pcg32_bounded(pcg32_t* r, uint32_t bound);

#endif
