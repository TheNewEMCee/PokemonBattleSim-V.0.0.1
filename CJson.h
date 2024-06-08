#include <iostream>
#include <fstream>
#include "CFile.h"
#ifndef NAME_CJSON_H
#define NAME_CJSON_H


class CJson : public CFile {
private:
    int numLines;
public:
    void printFileContents(int start, int finish, int width = 32, bool isBeautified = true);
    void updateNumLines();
    int getNumLines();
};


#endif //NAME_CJSON_H
