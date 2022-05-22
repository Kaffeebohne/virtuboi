#pragma once

#include "common.h"
#include "LR35902.hpp"
#include "T_Peripherals.hpp"

class Bus {
    public:
         Bus(CPU * c);
        ~Bus();

    private:
        uint8_t * memory;
        uint16_t saRstVecs[8];
        uint16_t saIrqVecs[5];
        T_Peripherals<cpuAddr, cpuData> *connectedDevices[8];
        CPU * cpuInstance;
        uint8_t lastDevice = 0;

    public:
        cpuData bus_read(cpuAddr);
        void bus_write(cpuAddr, cpuData);

    private:
        void bus_init();
};