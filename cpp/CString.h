#include <iostream>
#include <fstream>
#include "CVar.h"
#ifndef UNTITLED_CString_H
#define UNTITLED_CString_H


class CString : public CVar {
private:
    std::string value;
public:
    CString();
    CString(std::string name, std::string path, int lineToReference, int value, bool getFromConst = false);
    ~CString();
    void updateValue();
    void setValue(std::string n);
    std::string getValue();
};


#endif //UNTITLED_CString_H