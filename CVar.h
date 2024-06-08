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
    CVar(const std::string &name, const std::string &path, int lineToReference);
    CVar(const CVar &cv);
    ~CVar();
    void setName(std::string n);
    void setPath(std::string p);
    void setLineToReference(int l);
    std::string getName() const;
    std::string getPath() const;
    int getLineToReference() const;
    void printPathContents(int start, int finish, bool isBeautified = true);
};


#endif //POKEMONBATTLESIM_V0_0_1_CVAR_H
