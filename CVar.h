#include <iostream>
#include <fstream>
#ifndef POKEMONBATTLESIM_V0_0_1_CVAR_H
#define POKEMONBATTLESIM_V0_0_1_CVAR_H


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


#endif //POKEMONBATTLESIM_V0_0_1_CVAR_H
