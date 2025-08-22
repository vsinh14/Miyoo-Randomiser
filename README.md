# upr-c

A C port skeleton of the Universal Pokémon Randomizer.

## Build

```bash
cmake -B build
cmake --build build
```

Requires CMake >= 3.15 and a C11 compiler (gcc/clang).

## Usage

Currently minimal CLI:

```bash
./build/upr-c input.gba output.gba
```

This will load the ROM, apply a demo randomization (mutating 16 bytes at offset 0x100),
and save the new ROM.

## Options

The skeleton already defines flags for:

- `--seed N` / `--seq N` for RNG seed/stream
- `--starters`, `--wild`, `--trainers` feature toggles (not implemented yet)
- `--ban-legendaries`, `--similar` constraints
- `--dry-run`, `--verbose`, `--quiet`
- `--patch` (future IPS/BPS support)

Currently, only the demo mutation is applied.

## Next Steps

- Implement per-game data modules (e.g. Gen3 wild encounters, trainers)
- Replace demo mutation with real randomization logic
- Add IPS/BPS patch output option
- Expand game detection and checksum fixing

## License

This skeleton is provided for educational purposes. If you port actual Universal Pokémon Randomizer logic, note that the original project is GPL-3.0 licensed.
