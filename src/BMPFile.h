#pragma once
#pragma pack(1)

#ifndef BMPFILE_H__
#define BMPFILE_H__

#include <vector>
#include <fstream>

typedef int LONG;
typedef unsigned short WORD;
typedef unsigned int DWORD;

typedef struct bmp_file_header_s {
    WORD  bfType;
    DWORD bfSize;
    WORD  bfReserved1;
    WORD  bfReserved2;
    DWORD bfOffBits;
} bmp_file_header, *pbmp_file_header;

typedef struct bmp_info_header_s {
    DWORD biSize;
    LONG  biWidth;
    LONG  biHeight;
    WORD  biPlanes;
    WORD  biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG  biXPelsPerMeter;
    LONG  biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} bmp_info_header, *pbmp_info_header;

class BMPFile {
public:
	BMPFile();
	~BMPFile();
	void read(char* filename);
private:
	std::vector<char> buffer;
	pbmp_file_header file_header;
	pbmp_info_header info_header;
};

#endif
