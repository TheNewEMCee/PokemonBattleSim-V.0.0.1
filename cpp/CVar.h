#include <iostream>
#include <fstream>
#ifndef UNTITLED_CVAR_H
#define UNTITLED_CVAR_H


class CVar {
protected:
    std::string name;
    std::string path;
    int lineToReference;
public:
    CVar();
    CVar(std::string name, std::string path, int lineToReference);
    ~CVar();
    void setName(std::string n);
    void setPath(std::string p);
    void setLineToReference(int l);
    std::string getName();
    std::string getPath();
    int getLineToReference();
};


#endif //UNTITLED_CVAR_H
