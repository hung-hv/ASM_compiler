#include "FileHandler.hpp"
#include <string.h>
#include <iostream>

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
    // std::string file;
    std::stringstream buffer;
    this->filename = (char*)malloc(sizeof(char) * filename.length());
    strcpy(this->filename, filename.c_str());
    this->file.open(this->filename);

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



