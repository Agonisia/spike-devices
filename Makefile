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
# usage: sudo env RISCV=$RISCV make install
install: libspikedevices.so
	cp libspikedevices.so $(RISCV)/lib
	sudo cp /opt/riscv/lib/libspikedevices.so /usr/lib/

clean:
	rm -rf *.o *.so
