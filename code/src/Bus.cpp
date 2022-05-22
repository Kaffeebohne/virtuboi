#include "Bus.hpp"
#include <cstdlib>

#define MEM_EMPTY 0

Bus::Bus(CPU *c) {
    this->cpuInstance = c;
    bus_init();
}

Bus::~Bus() {
    delete memory;
}

void Bus::bus_init() {
    cpuAddr v = 0 - 1;
    memory = (cpuData *) malloc (v + 1);
    memory = new cpuData[v + 1];
    for(int i = 0; i <= v; ++i)
        memory[i] = 0;
}

cpuData Bus::bus_read(cpuAddr a) {
    cpuData * d = NULL;
    for (auto & cd: this->connectedDevices)
        if ((cd != NULL) && ((d = cd->peripheralRead(a)) != NULL))
            return *d;
}

void Bus::bus_write(cpuAddr a, cpuData d) {
    for (auto &cd: this->connectedDevices)
        cd->peripheralWrite(a, d);
}