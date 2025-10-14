BUILD_DIR = build
TARGET = cymbalamp
PICO_MOUNT = /media/$(USER)/RPI-RP2

# Default target
all: build

# Configure and build
build:
	@mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake ..
	cd $(BUILD_DIR) && make -j$$(nproc)

#  Clean build directory
clean:
	rm -rf $(BUILD_DIR)

# Flash to Pico (if mounted as USB)
flash: build
	@if [ -d "$(PICO_MOUNT)" ]; then \
		cp $(BUILD_DIR)/$(TARGET).uf2 $(PICO_MOUNT); \
		echo "Program copied to Pico."; \
	else \
		echo "Pico not found at $(PICO_MOUNT). Plug it in with BOOTSEL held."; \
	fi
