Basic Compression Tool v0.4

A simple tool with Lempel Ziv and Run Lenght Encoding compression and decompression algorithms I made as a student learning project.

Features:
-Compress Files
-Decompress previously compressed files
-Works with any file type (binary safe)
-Command-line interface
-Simple compression/decompression statistics

Requirements:
C++ compiler
Tested on Windows, should work for Linux/macOS

How to compile:
Open a terminal in the project folder: 

```g++ src/*.cpp -o compress```


How to use:    
    Command:
        ```.\compress <algorithm (lz/rle)> <mode> <input file> <output file>```
    lz algorithm = Lempel Ziv compression, has to be decompressed using lz aswell.
    rle algorithm = Run Lenght Encoding, has to be decompressed using rle aswell

    <mode> = compress/decompress
    <input file> = anything from the folder where the compress.exe is located. Include file extension when entering command
    <output file> = any name, I prefer .rle extension for files compressed with rle, and .lz for files compressed with lz, for easier decompressing later, but it doesn't matter

    Example:
    ```.\compress lz compress test.txt test.lz```