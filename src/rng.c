#include "rng.h"

static inline uint32_t rotr32(uint32_t x, unsigned r){ return (x>>r) | (x<<(32-r)); }

void pcg32_seed(pcg32_t* r, uint64_t seed, uint64_t seq){
    r->state = 0u;
    r->inc   = (seq<<1u) | 1u;
    (void)pcg32_next(r);
    r->state += seed;
    (void)pcg32_next(r);
}

uint32_t pcg32_next(pcg32_t* r){
    uint64_t old = r->state;
    r->state = old * 6364136223846793005ULL + r->inc;
    uint32_t xorshifted = (uint32_t)(((old >> 18u) ^ old) >> 27u);
    uint32_t rot = (uint32_t)(old >> 59u);
    return rotr32(xorshifted, rot);
}

uint32_t pcg32_bounded(pcg32_t* r, uint32_t bound){
    uint32_t threshold = -bound % bound;
    for(;;){
        uint32_t v = pcg32_next(r);
        if(v >= threshold) return v % bound;
    }
}
