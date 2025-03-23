#ifndef __VORTEX_H__
#define __VORTEX_H__

#include <queue>
#include <vector>
#include <optional>
#include <string>
#include <riscv/abstract_device.h>
#include <riscv/simif.h>
#include <riscv/abstract_interrupt_controller.h>
#include <riscv/mmu.h>
#include <riscv/processor.h>
#include <riscv/simif.h>
#include <riscv/sim.h>
#include <riscv/dts.h>
#include <fdt/libfdt.h>

#define VORTEX_BASE 0xc0000000
#define VORTEX_SIZE 0x10000000
#define VORTEX_INTERRUPT_ID 3

class vortex_t : public abstract_device_t {
public:
  bool load(reg_t addr, size_t len, uint8_t* bytes) override { 
    // TODO: Implement this
    return false; 
  }

  bool store(reg_t addr, size_t len, const uint8_t* bytes) override {
    // TODO: Implement this 
    return false; 
  }
};

#endif //__VORTEX_H__