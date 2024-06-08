#include <iostream>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <vector>
#include "CVar.h"
#include "CInt.h"
#include "CString.h"
/*
void enterDetector() {
    std::string enterDetector;
    do {
        getline(std::cin, enterDetector);
    } while (!enterDetector.empty());
}

*/

int main() {
    //Confirm functioning build
    std::cout << "main.cpp runtime initialized" << std::endl;
    //Try to see if CInt works... Hopefully!
    std::string v = "hehy";
    //CInt CInt1(v);
    CInt CInt1("CInt1", "/Users/mylesclark/VSCode/ICS4UThing/PokemonBattleSim-V.0.0.1/CInts.txt", 2, 6, true);
    std::cout << "Hello!" << std::endl;
    std::cout << "Name: " << CInt1.getName() << std::endl;
    std::cout << "Stored at " << CInt1.getPath() << ", line " << CInt1.getLineToReference() << std::endl;
    std::cout << "Value is set to " << CInt1.getValue() << std::endl;
    std::ifstream inFile;

    inFile.open(CInt1.getPath());
    if (inFile.fail()) {
        std::cerr << "In Thingy Failed" << std::endl;
    }
    std::vector<std::string> lineArray;
    int lineWeAreAt = 0;
    while (!inFile.eof()) {
        getline(inFile, lineArray[lineWeAreAt]);
    }
    std::string newValue;
    std::cout << "Input value:" << std::endl;
    std::cin >> newValue;
    lineArray[CInt1.getLineToReference()] = newValue;
    std::ofstream outFile;
    outFile.open(CInt1.getPath());
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
    CInt1.updateValue();
    std::cout << "New value is: " << CInt1.getValue() << std::endl;
    return 0;
}