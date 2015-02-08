#pragma once
#pragma pack(1)

#ifndef BMPFILE_H__
#define BMPFILE_H__

#include <vector>
#include <fstream>

typedef struct bmp_file_header_s {
    unsigned short  bfType;
    unsigned int bfSize;
    unsigned short  bfReserved1;
    unsigned short  bfReserved2;
    unsigned int bfOffBits;
} bmp_file_header, *pbmp_file_header;

typedef struct bmp_info_header_s {
    unsigned int biSize;
    int  biWidth;
    int  biHeight;
    unsigned short  biPlanes;
    unsigned short  biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int  biXPelsPerMeter;
    int  biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} bmp_info_header, *pbmp_info_header;

class BMPFile {
public:
	BMPFile();
	BMPFile(const char * filename);
	~BMPFile();
	void read(const char* filename);
	std::vector< std::vector<unsigned char> > read_data();
	unsigned int get_size_x();
	unsigned int get_size_y();
private:
	std::vector<char> buffer;
	//std::vector<std::vector<unsigned char>> data;
	pbmp_file_header file_header;
	pbmp_info_header info_header;
};

#endif
