#include "shuffle.h"

void fisher_yates_u32(uint32_t* a, size_t n, pcg32_t* rng){
    if(n < 2) return;
    for(size_t i=n-1; i>0; --i){
        uint32_t j = pcg32_bounded(rng, (uint32_t)(i+1));
        uint32_t t=a[i]; a[i]=a[j]; a[j]=t;
    }
}

size_t weighted_pick(const uint32_t* w, size_t n, pcg32_t* rng){
    uint64_t sum=0; for(size_t i=0;i<n;++i) sum += w[i];
    if(sum==0) return 0;
    uint64_t r = ((uint64_t)pcg32_next(rng) << 32) | pcg32_next(rng);
    r %= sum;
    for(size_t i=0;i<n;++i){
        if(r < w[i]) return i;
        r -= w[i];
    }
    return n-1;
}
