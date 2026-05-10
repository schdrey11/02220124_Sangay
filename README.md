# Course 1 Final Assessment — Choden
**Date:** May 10, 2026

## Repository Structure

```
Course1-Choden/
└── course1/
    ├── include/
    │   ├── platform.h        PRINTF macro (HOST / MSP432)
    │   ├── common_types.h    Shared stdint / stddef includes
    │   ├── stats.h           Statistical analysis declarations
    │   ├── memory.h          Memory manipulation declarations
    │   ├── data.h            Integer ↔ ASCII conversion declarations
    │   └── course1.h         Test function declarations
    ├── src/
    │   ├── main.c            Entry point (COURSE1 switch)
    │   ├── stats.c           Statistical analysis implementation
    │   ├── memory.c          Memory manipulation implementation
    │   ├── data.c            Integer ↔ ASCII conversion implementation
    │   └── course1.c         Final assessment test functions
    └── Makefile              Build system
```

## Building

### Host machine (default)
```bash
cd course1
make COURSE1=1            # build and run
./course1.out
```

### With verbose array printing
```bash
make COURSE1=1 VERBOSE=1
./course1.out
```

### Compile objects only (no link)
```bash
make compile-all COURSE1=1
```

### Clean build artefacts
```bash
make clean
```

### Cross-compile for MSP432 target
```bash
make PLATFORM=MSP432 COURSE1=1
```

## Functions Implemented

### stats.c / stats.h
| Function | Description |
|---|---|
| `print_array()` | Prints array elements; guarded by `-DVERBOSE` |
| `print_statistics()` | Prints min, max, mean, median |
| `find_minimum()` | Returns minimum value |
| `find_maximum()` | Returns maximum value |
| `find_mean()` | Returns mean value |
| `find_median()` | Returns median value |
| `sort_array()` | Sorts descending (in-place) |

### memory.c / memory.h
| Function | Description |
|---|---|
| `my_memmove()` | Overlap-safe byte move using pointer arithmetic |
| `my_memcopy()` | Fast copy; undefined on overlap |
| `my_memset()` | Fill region with constant byte |
| `my_memzero()` | Fill region with zero |
| `my_reverse()` | Reverse byte order of region |
| `reserve_words()` | Dynamic allocation of 32-bit words |
| `free_words()` | Release dynamically allocated memory |

### data.c / data.h
| Function | Description |
|---|---|
| `my_itoa()` | Signed int → ASCII string, bases 2–16 |
| `my_atoi()` | ASCII string → signed int, bases 2–16 |

### course1.c / course1.h
| Function | Description |
|---|---|
| `course1()` | Top-level runner; calls all sub-tests |
| `test_data1()` | itoa/atoi decimal round-trip |
| `test_data2()` | itoa/atoi negative + hex + binary |
| `test_memmove1()` | Non-overlapping memmove |
| `test_memmove2()` | Overlapping: end of dst / start of src |
| `test_memmove3()` | Overlapping: start of dst / end of src |
| `test_memcopy()` | Non-overlapping memcopy |
| `test_memset()` | memset and memzero |
| `test_reverse()` | Byte reversal (odd and even lengths) |
