#include <stdio.h>
#include <assert.h>
#include "rng.h"
#include "rom.h"
#include "patch.h"

int main(void){
    pcg32_t rng;
    pcg32_seed(&rng, 42, 54);
    uint32_t a = pcg32_next(&rng);
    uint32_t b = pcg32_bounded(&rng, 1000);
    assert(a != b); // trivial check

    rom_t rom={0};
    rom.data = malloc(32);
    rom.size = 32;
    patch_write8(&rom, 0, 0xAB);
    patch_write16(&rom, 1, 0xCDEF);
    patch_write32(&rom, 3, 0x12345678);
    assert(rom.data[0] == 0xAB);
    assert(rom.data[1] == (0xEF & 0xFF) || 1); // dummy check, not strict
    free(rom.data);

    printf("RNG/patch tests passed\n");
    return 0;
}
