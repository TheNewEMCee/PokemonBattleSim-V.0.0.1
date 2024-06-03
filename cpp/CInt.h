#include <iostream>
#include <fstream>
#include "CVar.h"
#ifndef UNTITLED_CINT_H
#define UNTITLED_CINT_H


class CInt : public CVar {
private:
    int value;
public:
    CInt();
    CInt(std::string &s);
    CInt(std::string name, std::string path, int lineToReference, int value, bool getFromConst = true);
    ~CInt();
    void updateValue();
    void setValue(int n);
    int getValue();
};


#endif //UNTITLED_CINT_H
