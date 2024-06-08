#include "CTxt.h"
#include "CFile.h"

void CTxt::printFileContents(int start, int finish, int width, bool isBeautified) {
    std::ifstream inFile;
    inFile.open(this->getPath());
    if (isBeautified) {
        int lineCount = 1;
        std::string line;
        std::vector<std::pair<int, std::string>> lineArray;
        while (getline(inFile, line)) {
            lineArray.push_back(std::make_pair(lineCount, line));
        }
        std::cout << "╭───┬";
        for (int i = 0; i < width; i++) {
            std::cout << "─";
        }
        std::cout << "╮" << std::endl;

        for (int i = 1; i < 10; i++) {
            std::cout << "│" << "00" << lineArray.at(i - 1).first << "│";
            int numLines = 0;
            bool leftoverLines = true;
            bool firstLine = true;
            int leftoverCharacters = 0;
            int charCount = lineArray.at(i - 1).second.size();
            if (charCount <= width) {
                std::cout << lineArray.at(i - 1).second;
            } else {
                while (charCount > width) {
                    if (firstLine) {
                        std::cout << lineArray.at(i - 1).second.substr(0, width) << "│" << std::endl;
                        firstLine = false;
                    } else {
                        std::cout << "│   │" << lineArray.at(i - 1).second.substr(0, width);
                    }
                    charCount -= width;
                };
                if (charCount <= width) {
                    std::cout << "│   │";
                }
            }
        }
    }

}
