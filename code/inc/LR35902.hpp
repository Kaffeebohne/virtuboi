#pragma once
#include "common.h"
#include "Bus.hpp"

class CPU {

    public:
        CPU::CPU(char *);
        CPU::~CPU(void);

    private:
        Bus * busInstance;
};