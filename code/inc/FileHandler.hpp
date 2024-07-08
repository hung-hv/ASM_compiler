#include <fstream>
class FileHandler {
public:
    // Constructor
    FileHandler();

    // Destructor
    ~FileHandler();

    FileHandler(const std::string &filename);

    void setFilePath(const std::string& filename);

    // void FileHandler::getLine(int Line);
    // Methods
    std::string openFile(const std::string& filename);
    void printFile();
    // void closeFile();
    // void readFile();
    // void writeFile(const std::string& content);

private:
    char* filename;
    char* s_curLine;
    char s_curChar;
    std::ifstream file;
    int curLine;
    int curChar;
};
