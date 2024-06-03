#include <fstream>
#include <string>
#include <utility>
#include "CVar.h"


CVar::CVar() {}

CVar::CVar(std::string name, std::string path, int lineToReference) {
    this->name = name;
    this->path = path;
    this->lineToReference= lineToReference;
}
CVar::~CVar() {
    std::cout << "CVar " << this->name << " destroyed." << std::endl;
}

void CVar::setName(std::string n) {
    this->name = std::move(n);
}

void CVar::setPath(std::string p) {
    this->path = std::move(p);
}

void CVar::setLineToReference(int l) {
    this->lineToReference = l;
}

std::string CVar::getName() {
    return this->name;
}

std::string CVar::getPath() {
    return this->path;
}

int CVar::getLineToReference() {
    return this->lineToReference;
}