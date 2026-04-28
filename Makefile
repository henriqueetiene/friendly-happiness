CC = gcc
BUILD_DIR = build

CFLAGS = -Wall -Wextra -Wpedantic -std=c11 -Iinclude
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2
LDFLAGS = -lm

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=$(BUILD_DIR)/%.o)

TARGET = $(BUILD_DIR)/programa

.PHONY: all debug release run clean

all: release

debug: CFLAGS += $(DEBUG_FLAGS)
debug: $(TARGET)

release: CFLAGS += $(RELEASE_FLAGS)
release: $(TARGET)

run: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)