#include "vortex.h"

vortex_t* vortex_parse_from_fdt(const void* fdt, const sim_t* sim, reg_t* base, const std::vector<std::string>& sargs) {
  *base = 0xc0000000; // set base address
  return new vortex_t();
}

std::string vortex_generate_dts(const sim_t* sim, const std::vector<std::string>& args) {
  std::stringstream s;
  s << std::hex
    << "    vortex: vortex@" << VORTEX_BASE << " {\n"
       "      compatible = \"ucb-bar,vortex\";\n"
       "      interrupt-parent = <&PLIC>;\n"
       "      interrupts = <" << std::dec << VORTEX_INTERRUPT_ID;
  reg_t vortexbs = VORTEX_BASE;
  reg_t vortexsz = VORTEX_SIZE;
  s << std::hex << ">;\n"
       "      reg = <0x" << (vortexbs >> 32) << " 0x" << (vortexbs & (uint32_t)-1) <<
                   " 0x" << (vortexsz >> 32) << " 0x" << (vortexsz & (uint32_t)-1) << ">;\n"
       "    };\n";
  return s.str();
}


REGISTER_DEVICE(vortex, vortex_parse_from_fdt, vortex_generate_dts)


