PIO ?= pio
ENV ?= esp32
BUILD_DIR := .pio/build/lab1/$(ENV)

# Load variables from the repo-root .env (e.g. WOKWI_CLI_TOKEN) if present.
ENV_FILE := ../.env
ifneq (,$(wildcard $(ENV_FILE)))
    include $(ENV_FILE)
    export $(shell sed -n 's/=.*//p' $(ENV_FILE))
endif

.PHONY: all build upload monitor clean simulate test test-wiring test-all

all: build

build:
	$(PIO) run -e $(ENV)

upload:
	$(PIO) run -e $(ENV) -t upload

monitor:
	$(PIO) device monitor

simulate: build
	wokwi-cli .

test: build
	wokwi-cli . --scenario lab1_tests.yaml --timeout 30000

# Verifies the diagram.json wiring topology (both ends of every wire + grounds).
test-wiring: build
	wokwi-cli . --scenario lab1_wiring_tests.yaml --timeout 30000

# Runs both the behaviour test and the wiring test.
test-all: test test-wiring

clean:
	$(PIO) run -e $(ENV) -t clean
	rm -rf .pio
