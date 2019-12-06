#include "Bus.h"

Bus::Bus() {
    // clear RAM
    for (auto &i : ram)
        i = 0x00;

    // CPU <--> Bus
    cpu.connectBus(this);
}

Bus::~Bus() {

}

void Bus::write(uint64_t addr, uint8_t data) {
    if(addr >= 0x0000 && addr <= 0xFFFF) {
        ram[addr] = data;
    }
}

uint8_t Bus::read(uint64_t addr, bool bReadOnly = false) {
    if(addr >= 0x0000 && addr <= 0xFFFF) {
        return ram[addr]
    }

    return 0x00;
}