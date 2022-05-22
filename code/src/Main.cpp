#include "LR35902.hpp"
#include <unistd.h>

int main(int argc, char ** argv) {
    char * cartridgename;
    int c;
    while ((c = getopt(argc, argv, ":f:")) != -1)
        switch (c) {
            case 'f':
                cartridgename = optarg;
                break;
            default:
                // nothing?
                break;
        }

    CPU c = CPU(cartridgename);
}