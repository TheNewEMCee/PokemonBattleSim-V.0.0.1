#include <iostream>
#include <fstream>
#include "CVar.h"

#ifndef POKEMONBATTLESIM_V0_0_1_CINT_H
#define POKEMONBATTLESIM_V0_0_1_CINT_H

class CInt : public CVar {
private:
    int value;
public:
    CInt();
    CInt(std::string &s);
    CInt(const CInt &ci); // Copy
    CInt(std::string name, std::string path, int lineToReference, int value, bool getFromConst = true);
    ~CInt();
    void updateValue();
    void setValue(int n);
    int getValue() const;
};


#endif //POKEMOdNBATTLESIM_V0_0_1_CINT_H