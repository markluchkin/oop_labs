#ifndef OOP_LABS_FILE_HPP
#define OOP_LABS_FILE_HPP

#include "structures.hpp"
#include "Errors.hpp"

class FileWriter {
private:
    std::string filename;
    std::ofstream outfile;
public:
    FileWriter(const std::string& filename);
    ~FileWriter();
    std::ofstream& getOutfile();
};

class FileReader {
private:
    std::string filename;
    std::ifstream infile;
public:
    FileReader(const std::string& filename);
    ~FileReader();
    std::ifstream& getInfile();
};


#endif
