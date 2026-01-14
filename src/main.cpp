#include <iostream>
#include "rle.h"

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage:\n";
        std::cout << "  rle compress <input> <output>\n";
        std::cout << "  rle decompress <input> <output>\n";
        return 1;
    }

    std::string mode = argv[1];
    std::string input = argv[2];
    std::string output = argv[3];

    bool success = false;

    if (mode == "compress") {
        std::cout << "Compressing: " << input << " -> " << output << "\n";
        success = compressRLE(input, output);
    } else if (mode == "decompress") {
        std::cout << "Decompressing: " << input << " -> " << output << "\n";
        success = decompressRLE(input, output);
    } else {
        std::cerr << "Unknown mode: " << mode << "\n";
        return 1;
    }

    if (!success) {
        std::cerr << "Operation failed! Check file paths.\n";
        return 1;
    }

    std::cout << "Operation completed successfully.\n";
    return 0;
}
