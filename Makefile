# Declare phony targets to avoid conflicts with file names
.PHONY: all CM7 CM4 clean

# Default target: build both CM7 and CM4 configurations
all: CM7 CM4

# Target to build CM7 configuration
CM7:
	@echo "Start building for CM7....."
	$(MAKE) -f Makefile_CM7 CM7
	@echo ".....Build for CM7 has been completed!"


# Target to build CM4 configuration
CM4:
	@echo "Start building for CM4....."
	$(MAKE) -f Makefile_CM4 CM4
	@echo ".....Build for CM4 has been completed!"

# Target to clean both CM7 and CM4 configurations
clean:
	$(MAKE) -f Makefile_CM7 clean
	$(MAKE) -f Makefile_CM4 clean
