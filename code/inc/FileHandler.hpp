#include <fstream>

class FileHandler {
public:
    // Constructor
    FileHandler();

    // Destructor
    ~FileHandler();

    FileHandler(const std::string &filename);

    void setFilePath(const std::string& filename);

    void FileHandler::getLine(int Line);
    // Methods
    void openFile(const std::string& filename);
    void closeFile();
    void readFile();
    void writeFile(const std::string& content);

private:
    char* filename;
    char* curLine;
    std::ifstream file;
    int line;
    int curChar;
};
