#include <iostream>
#include <fstream>
#include <vector>

#ifndef NAME_CFILE_H
#define NAME_CFILE_H


class CFile {
private:
    std::string name;
    std::string path;
public:
    CFile();
    CFile(const std::string &name, const std::string &path);
    CFile(const CFile &cf);
    ~CFile();
    void setName(std::string name);
    void setPath(std::string path);
    std::string getName() const;
    std::string getPath() const;
};


#endif //NAME_CFILE_H