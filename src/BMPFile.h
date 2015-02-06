#pragma once
#pragma pack(1)

#ifndef BMPFILE_H__
#define BMPFILE_H__

#include <vector>
#include <fstream>
#include <cstdint>

typedef struct bmp_file_header_s {
	uint16_t bfType;
	uint32_t bfSize;
	uint16_t bfReserved1;
	uint16_t bfReserved2;
	uint32_t bfOffBits;
} bmp_file_header, *pbmp_file_header;

typedef struct bmp_info_header_s {
	uint32_t biSize;
	int32_t  biWidth;
	int32_t  biHeight;
	uint16_t  biPlanes;
	uint16_t  biBitCount;
	uint32_t biCompression;
	uint32_t biSizeImage;
	int32_t  biXPelsPerMeter;
	int32_t  biYPelsPerMeter;
	uint32_t biClrUsed;
	uint32_t biClrImportant;
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