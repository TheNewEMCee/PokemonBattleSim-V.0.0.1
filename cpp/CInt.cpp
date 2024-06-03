#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <filesystem>
#include "CInt.h"
#include "CVar.h"

CInt::CInt() : CVar() {
    this->name = "Unnamed CInt";
    this->lineToReference = 0;
    this->value = 0;
}
CInt::CInt(std::string &s) : CVar() {
    this->name = s;
    this->lineToReference = 0;
    this->value = 0;
}

CInt::CInt(std::string n, std::string path, int lineToReference, int value, bool getFromConst) : CVar(name, path, lineToReference) {
    this->name = n;
    this->path = path;
    this->lineToReference = lineToReference;
    if (!getFromConst) {
        this->value = value;
    }
    std::ifstream inFile;
    inFile.open(path);
    if (inFile.fail()) {
        std::cerr << "In Thingy Failed in CInt constructor creation of " << n << "." << std::endl;
    }
    std::vector<std::string> lineArray;
    int lineWeAreAt = 0;
    while (!inFile.eof()) {
        getline(inFile, lineArray[lineWeAreAt]);
        lineWeAreAt++;
    }

    std::ofstream outFile;
    outFile.open(path);
    if (outFile.fail()) {
        std::cerr << "Out Thingy Failed" << std::endl;
    } else {
        inFile.close();
    }
    lineArray[lineToReference] = std::to_string(value);
    for (int i = 0; i < lineArray.size(); i++) {
        outFile << lineArray[i];
    }
    if (getFromConst) {
        this->value = stoi(lineArray[lineToReference]);
    }
    inFile.close();
    outFile.close();

}
CInt::~CInt() {
    std::cout << "CInt destroyed." << std::endl;
}

void CInt::updateValue() {
    std::ifstream inFile;
    inFile.open(this->getPath());
    if (inFile.fail()) {
        std::cerr << "In Thingy Failed" << std::endl;
    }
    std::vector<std::string> lineArray;
    int lineWeAreAt = 0;
    while (!inFile.eof()) {
        getline(inFile, lineArray[lineWeAreAt]);
    }
    this->setValue(std::stoi(lineArray[this->getLineToReference()]));
    std::ofstream outFile;
    outFile.open(this->getPath());
    if (outFile.fail()) {
        std::cerr << "Out Thingy Failed" << std::endl;
    } else {
        inFile.close();
    }
    for (int i = 0; i < lineArray.size(); i++) {
        outFile << lineArray[i];
    }
    inFile.close();
    outFile.close();

}

void CInt::setValue(int n) {
    this->value = n;
    std::ifstream inFile;
    inFile.open(this->getPath());
    if (inFile.fail()) {
        std::cerr << "In Thingy Failed" << std::endl;
    }
    std::vector<std::string> lineArray;
    int lineWeAreAt = 0;
    while (!inFile.eof()) {
        getline(inFile, lineArray[lineWeAreAt]);
    }
    lineArray[this->getLineToReference()] = std::to_string(n);
    std::ofstream outFile;
    outFile.open(this->getPath());
    if (outFile.fail()) {
        std::cerr << "Out Thingy Failed" << std::endl;
    } else {
        inFile.close();
    }
    for (int i = 0; i < lineArray.size(); i++) {
        outFile << lineArray[i];
    }
    inFile.close();
    outFile.close();
}

int CInt::getValue() {
    return this->value;
}

