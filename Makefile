ifndef RISCV
$(error RISCV is unset)
else
$(info Running with RISCV=$(RISCV))
endif

PREFIX ?= $(RISCV)/
SRC_DIR := src
SRCS=$(wildcard $(SRC_DIR)/*.cc)

default: libspikedevices.so

SPIKE_DIR := $(realpath ..)
libspikedevices.so: $(SRCS)
	g++ -L $(RISCV)/lib -Wl,-rpath,$(RISCV)/lib -shared -o $@ -std=c++17 \
	    -I $(RISCV)/include -I $(SPIKE_DIR) -fPIC $^

.PHONY: install
install: libspikedevices.so
	cp libspikedevices.so $(RISCV)/lib

clean:
	rm -rf *.o *.so
