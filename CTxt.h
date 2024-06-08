#include <iostream>
#include "CFile.h"

#ifndef NAME_CTXT_H
#define NAME_CTXT_H


class CTxt : public CFile {
private:
    int numLines;
public:
    CTxt();
    CTxt(const std::string &name, const std::string &path);
    void printFileContents(int start, int finish, int width = 32, bool isBeautified = true);
    void updateNumLines();
    int getNumLines();
};


#endif //NAME_CTXT_H
