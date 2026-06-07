PIO ?= pio
ENV ?= esp32
BUILD_DIR := .pio/build/lab2/$(ENV)

# Load variables from the repo-root .env (e.g. WOKWI_CLI_TOKEN) if present.
ENV_FILE := ../.env
ifneq (,$(wildcard $(ENV_FILE)))
    include $(ENV_FILE)
    export $(shell sed -n 's/=.*//p' $(ENV_FILE))
endif

.PHONY: all build upload monitor clean simulate test

all: build

build:
	$(PIO) run -e $(ENV)

upload:
	$(PIO) run -e $(ENV) -t upload

monitor:
	$(PIO) device monitor

simulate: build
	wokwi-cli .

# Single-boot scenario: full GPIO0..6 sweep + WIN/LOSE/reset game logic.
test: build
	wokwi-cli . --scenario lab2_tests.yaml --timeout 30000

clean:
	$(PIO) run -e $(ENV) -t clean
	rm -rf .pio
