#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <filesystem>
#include <unistd.h>
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

CInt::CInt(std::string name, std::string path, int lineToReference, int value, bool getFromConst) : CVar(name, path, lineToReference) {
    this->setName(name);
    this->setPath(path);
    this->setLineToReference(lineToReference);
    if (!getFromConst) {
        this->setValue(value);
    }
    std::ifstream inFile(this->getPath());
    if (inFile.fail()) {
        std::cerr << "In Thingy Failed in CInt constructor creation of " << name << "." << std::endl;
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
        return;
    }
    std::cout << "Boingo" << std::endl;
    std::vector<std::string> lineArray;
    std::string line;
    int lineWeAreAt = 0;
    while (getline(inFile, line)) {
        lineWeAreAt++;
    }
    while (lineToReference >= lineArray.size()) {
        std::cerr << "Error: lineToReference is out of range." << std::endl << "Add lines? Y/N" << std::endl;
        std::string userInput;
        std::cin >> userInput;
        bool goOn = false;
        do {
            if (userInput == "Y" || userInput == "y") {
                inFile.close();
                std::ofstream outFile;
                outFile.open(path);
                if (outFile.fail()) {
                    std::cerr << "Out Thingy Failed" << std::endl;
                    std::cerr << "Error: " << std::strerror(errno) << std::endl;
                }
                for (int i = 0; i <= lineToReference; i++) {
                    outFile << "";
                }
                if (getFromConst) {
                    this->value = stoi(lineArray.at(lineToReference));
                }
                goOn = true;
            } else if (userInput == "N" || userInput == "n") {
                int newLineToReference;
                std::cout << "What should the new line to reference be? The maximum is " << lineArray.size() - 1 << "." << std::endl;
                std::cin >> newLineToReference;
                this->setLineToReference(newLineToReference);
                return;
            }
            lineWeAreAt = 0;
            inFile.seekg(0, std::ios::beg);

            while (getline(inFile, line)) {
                lineArray.push_back(line);
                lineWeAreAt++;
            }
        } while (!goOn);
    }
    lineWeAreAt = 0;
    inFile.seekg(0, std::ios::beg);
    while (getline(inFile, line)) {
        lineArray.push_back(line);
        lineWeAreAt++;
    }
    inFile.close();

    std::ofstream outFile;
    outFile.open(path);
    if (outFile.fail()) {
        std::cerr << "Out Thingy Failed" << std::endl;
    } else {
        inFile.close();
    }
    lineArray[lineToReference] = std::to_string(value);
    for (int i = 0; i < lineArray.size(); i++) {
        outFile << lineArray.at(i);
    }
    if (getFromConst) {
        this->value = stoi(lineArray.at(lineToReference));
    }
    inFile.close();
    outFile.close();

}

CInt::CInt(const CInt &ci) : CVar(ci), value(ci.value) {
    this->setName(ci.getName());
    this->setPath(ci.getPath());
    this->setLineToReference(ci.getLineToReference());
    this->setValue(ci.getValue());
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
    std::string line;
    int lineWeAreAt = 0;
    while (!inFile.eof()) {
        getline(inFile, line);
        lineArray.push_back(line);
        lineWeAreAt++;    }
    this->setValue(std::stoi(lineArray[this->getLineToReference()]));
    std::ofstream outFile;
    outFile.open(this->getPath());
    if (outFile.fail()) {
        std::cerr << "Out Thingy Failed" << std::endl;
    } else {
        inFile.close();
    }
    for (int i = 0; i < lineArray.size(); i++) {
        outFile << lineArray.at(i);
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

int CInt::getValue() const {
    return this->value;
}