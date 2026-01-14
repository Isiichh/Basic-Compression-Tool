#include "rle.h"
#include <fstream>
#include <iostream>

bool compressRLE(const std::string& input, const std::string& output) {
    std::ifstream inFile(input, std::ios::binary);
    if (!inFile) {
        std::cerr << "Cannot open input file\n";
        return false;
    }

    std::ofstream outFile(output, std::ios::binary);
    if (!outFile) {
        std::cerr << "Cannot open output file\n";
        return false;
    }

    char current;
    while (inFile.read(&current, 1)) {
        unsigned char count = 1;
        char next;

        while (count < 255 && inFile.read(&next, 1) && next == current) {
            ++count;
        }

        outFile.put(count);    // write number of repeats
        outFile.put(current);  // write the byte

        if (inFile && next != current) {
            inFile.seekg(-1, std::ios::cur);  // unread the different byte
        }
    }

    inFile.close();
    outFile.close();

    return true;
}


bool decompressRLE(const std::string& input, const std::string& output) {
    std::ifstream inFile(input, std::ios::binary);
    if (!inFile) {
        std::cerr << "Cannot open input file\n";
        return false;
    }

    std::ofstream outFile(output, std::ios::binary);
    if (!outFile) {
        std::cerr << "Cannot open output file\n";
        return false;
    }

    unsigned char count;
    char value;

    while (inFile.read(reinterpret_cast<char*>(&count), 1) &&
           inFile.read(&value, 1)) {
        for (unsigned char i = 0; i < count; ++i) {
            outFile.put(value);
        }
    }

    inFile.close();
    outFile.close();

    return true;
}

