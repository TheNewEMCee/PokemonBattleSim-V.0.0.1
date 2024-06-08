#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include "CString.h"
#include "CVar.h"

CString::CString() : CVar() {
    this->name = "Undefined CString";
    this->lineToReference = 0;
    this->value = "";
}

CString::CString(std::string name, std::string path, int lineToReference, int value, bool getFromConst) : CVar(name, path, lineToReference) {
    this->name = name;
    this->path = path;
    this->lineToReference = lineToReference;
    if (getFromConst) {
        this->value = std::to_string(value);
    }
    std::ifstream inFile;
    inFile.open(path);
    if (inFile.fail()) {
        std::cerr << "In Thingy Failed" << std::endl;
    }
    std::vector<std::string> lineArray;
    int lineWeAreAt = 0;
    while (!inFile.eof()) {
        getline(inFile, lineArray[lineWeAreAt]);
    }

    std::ofstream outFile;
    outFile.open(this->getPath());
    if (outFile.fail()) {
        std::cerr << "Out Thingy Failed" << std::endl;
    } else {
        inFile.close();
    }
    lineArray[lineToReference] = std::to_string(value);
    for (int i = 0; i < lineArray.size(); i++) {
        outFile << lineArray[i];
    }
    if (!getFromConst) {
        this->value = lineArray[lineToReference];
    }
    inFile.close();
    outFile.close();

}

CString::CString(const CString &cs) : CVar(cs) {
    this->name = cs.name;
    this->path = cs.path;
    this->value = cs.value;
    this->lineToReference = cs.lineToReference;
}

CString::~CString() {
    std::cout << "CString " << this->name << " destroyed." << std::endl;
}

void CString::updateValue() {
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
    this->setValue(lineArray[this->getLineToReference()]);
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

void CString::setValue(std::string v) {
    this->value = std::move(v);
}

std::string CString::getValue() {
    return this->value;
}