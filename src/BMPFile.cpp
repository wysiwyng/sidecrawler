#include "BMPFile.h"

BMPFile::BMPFile(){

}

BMPFile::~BMPFile(){

}

void BMPFile::read(char* filename){
	std::ifstream file(filename);

	if (file){
		file.seekg(0, std::ios::end);
		std::streampos length = file.tellg();
		file.seekg(0, std::ios::beg);

		buffer.resize(length);
		file.read(&buffer[0], length);

		file_header = (pbmp_file_header)(&buffer[0]);
		info_header = (pbmp_info_header)(&buffer[0] + sizeof(bmp_file_header));
	}
}