#include "FileHandler.hpp"
#include <string.h>
#include <iostream>
#include <sstream>

FileHandler::FileHandler()
{
    this->filename = NULL;
}

FileHandler::~FileHandler()
{
    free(this->filename);
}

FileHandler::FileHandler(const std::string& filename)
{
    this->filename = (char*)malloc(sizeof(char) * filename.length());
    strcpy(this->filename, filename.c_str());
}

void FileHandler::setFilePath(const std::string& filename)
{
    this->filename = (char*)malloc(sizeof(char) * filename.length());
    strcpy(this->filename, filename.c_str());
}



std::string FileHandler::openFile(const std::string& filename)
{
    std::stringstream buffer;
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    buffer << file.rdbuf();
    return buffer.str();
}

void FileHandler::printFile() {
    std::string line;
    while (std::getline(this->file, line)) {
        std::cout << line << std::endl;
    }
}

// void FileHandler::getLine(int Line)
// {
//     this->filename = (char*)malloc(sizeof(char) * filename.length());
//     strcpy(this->filename, filename.c_str());
//     file.open(this->filename);
// }



