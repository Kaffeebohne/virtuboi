#include "LR35902.hpp"
#include <fstream>

CPU::CPU(char * cart) {
    this->busInstance = &Bus(this);
    std::fstream f;
    f.open(cart, std::fstream::in | std::fstream::binary);
    if (f.failbit)
        exit(1);
}