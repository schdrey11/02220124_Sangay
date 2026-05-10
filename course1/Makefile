#------------------------------------------------------------------------------
# Makefile — Course 1 Final Assessment
#
# Author : Choden
# Date   : April 15, 2026
#
# Usage:
#   make                        Build for HOST (default)
#   make PLATFORM=MSP432        Cross-compile for MSP432 target
#   make COURSE1=1              Enable Course 1 entry point (-DCOURSE1)
#   make VERBOSE=1              Enable verbose array printing (-DVERBOSE)
#   make COURSE1=1 VERBOSE=1    Enable both switches
#   make compile-all            Compile all objects (no link)
#   make build                  Synonym for default build
#   make clean                  Remove generated files
#------------------------------------------------------------------------------

# ── Configurable options ─────────────────────────────────────────────────────

PLATFORM ?= HOST

# ── Source / include paths ───────────────────────────────────────────────────

INCLUDES  := -I./include

SRCS := src/main.c    \
        src/stats.c   \
        src/memory.c  \
        src/data.c    \
        src/course1.c

OBJS := $(SRCS:.c=.o)

TARGET := course1.out

# ── Platform selection ───────────────────────────────────────────────────────

ifeq ($(PLATFORM), HOST)
    CC      := gcc
    CFLAGS  := -Wall -Werror -g -O0 -std=c99 -DHOST
    LDFLAGS :=
else ifeq ($(PLATFORM), MSP432)
    CC      := arm-none-eabi-gcc
    CFLAGS  := -Wall -Werror -g -O0 -std=c99               \
               -DMSP432                                     \
               -mcpu=cortex-m4 -mthumb                     \
               -march=armv7e-m                              \
               -mfloat-abi=hard -mfpu=fpv4-sp-d16          \
               --specs=nosys.specs
    LDFLAGS := -Wl,-Map=$(TARGET:.out=.map)
else
    $(error Unsupported PLATFORM "$(PLATFORM)". Use HOST or MSP432.)
endif

# ── Optional compile-time switches ──────────────────────────────────────────

ifdef COURSE1
    CFLAGS += -DCOURSE1
endif

ifdef VERBOSE
    CFLAGS += -DVERBOSE
endif

# ── Targets ──────────────────────────────────────────────────────────────────

.PHONY: all build compile-all clean

all: $(TARGET)

build: $(TARGET)

# Link step
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@ $(LDFLAGS)
	@echo ""
	@echo "  Built : $(TARGET)  [PLATFORM=$(PLATFORM)]"
	@echo ""

# Compile step (pattern rule)
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compile everything but do not link
compile-all: $(OBJS)
	@echo "All objects compiled (no link)."

clean:
	rm -f $(OBJS) $(TARGET) $(TARGET:.out=.map)
	@echo "Clean complete."
