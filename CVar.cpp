#include <fstream>
#include <string>
#include <utility>
#include "CVar.h"


CVar::CVar() {}

CVar::CVar(const std::string &name, const std::string &path, int lineToReference) {
    this->setName(name);
    this->setPath(path);
    this->setLineToReference(lineToReference);
}

CVar::CVar(const CVar &cv) {
    this->setName(cv.getName());
    this->setPath(cv.getPath());
    this->setLineToReference(cv.getLineToReference());
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

std::string CVar::getName() const {
    return this->name;
}

std::string CVar::getPath() const {
    return this->path;
}

int CVar::getLineToReference() const {
    return this->lineToReference;
}