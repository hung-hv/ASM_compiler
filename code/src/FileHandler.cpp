#include "FileHandler.hpp"
#include <string.h>

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
    line = 0;
    curChar = 0;
    this->filename = (char*)malloc(sizeof(char) * filename.length());
    strcpy(this->filename, filename.c_str());
}

void FileHandler::setFilePath(const std::string& filename)
{
    this->filename = (char*)malloc(sizeof(char) * filename.length());
    strcpy(this->filename, filename.c_str());
}

void FileHandler::openFile(const std::string& filename)
{
    this->filename = (char*)malloc(sizeof(char) * filename.length());
    strcpy(this->filename, filename.c_str());
    file.open(this->filename);
}

void FileHandler::getLine(int Line)
{
    this->filename = (char*)malloc(sizeof(char) * filename.length());
    strcpy(this->filename, filename.c_str());
    file.open(this->filename);
}



