#pragma once
#include "common.h"

template <class T_ADR, class T_DAT> 
class T_Peripherals {
    public:
        T_Peripherals(T_ADR from, T_ADR to, bool read = true, bool write = true) {
            this->rangeFrom = from;
            this->rangeTo = to;
            this->access = read + 2 * write;
        }

    private:
        T_ADR rangeFrom, rangeTo;
        typedef enum {
            eACLNo,
            eACLR,
            eACLW,
            eACLRW
        } E_ACCESS;
        E_ACCESS access;
        virtual T_DAT * _periphRead(T_ADR a);
        virtual void _periphWrite(T_ADR a, T_DAT d);

    public:
        T_DAT * peripheralRead(T_ADR a) {
            if ((rangeFrom <= a <= rangeTo) && (access & 1))
                return _periphRead(a);
            return nullptr;
        }

        void peripheralWrite(T_ADR a, T_DAT d) {
            if ((rangeFrom <= a <= rangeTo) && (access & 2))
                _periphWrite(a, d);
        }
};