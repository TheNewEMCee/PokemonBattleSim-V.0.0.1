#include <iostream>
#include <fstream>
#include <vector>
#include "CFile.h"

CFile::CFile() {
}
CFile::CFile(const std::string &name, const std::string &path) {
    this->setName(name);
    this->setPath(path);
}
CFile::CFile(const CFile &cf) {
    this->setName(cf.getName());
    this->setPath(cf.getPath());
}
void CFile::setName(std::string name) {
    this->name = name;
}
void CFile::setPath(std::string path) {
    this->path = path;
}
std::string CFile::getName() const {
    return this->name;
}
std::string CFile::getPath() const {
    return this->path;
}