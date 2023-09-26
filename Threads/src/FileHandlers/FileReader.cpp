// FileReader.cpp
#include "../../include/FileReader.h"

std::string FileReader::readLine() {
    std::wstring utf8Data;
    getline(fs, utf8Data);

    // Convierte a std::string (UTF-8)
    std::string utf8String(utf8Data.begin(), utf8Data.end());

    return utf8String;
}

std::vector<std::string>FileReader::readLines() {
    std::vector<std::string> vec;
    while (!fs.eof()) 
        vec.push_back(readLine());
    return vec;
}

std::string FileReader::read() {
    // Lee todo el contenido del archivo en una cadena
    std::istreambuf_iterator<wchar_t> begin(fs);
    std::istreambuf_iterator<wchar_t> end;
    std::wstring utf8Data(begin, end);

    return std::string(utf8Data.begin(),utf8Data.end());
}


bool FileReader::open(std::string path) {
    if (!checkFile(path))
        return false;
    fs.open(path, std::ios::in);
    if (!fs.is_open()) {
        return false;
    }
    fullRoute = path;
    return true;
}



bool FileReader::eof() {
    return fs.eof();
}

bool FileReader::close() {
    if (fs.is_open()) {
        fs.close();
        return true;
    }
    return false;
}

FileReader& FileReader::operator>>(std::string& line) {
    line = readLine();
    return *this;
}
