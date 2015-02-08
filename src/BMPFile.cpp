#include "BMPFile.h"
#include "Polycode.h"
BMPFile::BMPFile(){

}

BMPFile::BMPFile(const char * filename){
	read(filename);
}

BMPFile::~BMPFile(){

}

void BMPFile::read(const char* filename){
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

std::vector< std::vector<unsigned char> > BMPFile::read_data(){
	std::vector< std::vector<unsigned char> > ret;
	int idx = file_header->bfOffBits;
	int width = info_header->biWidth;
	int height = info_header->biHeight;


	for (int i = 0; i < height; i++){
		std::vector<unsigned char> temp;
		for (int j = 0; j < width / 2; j++){
			temp.push_back((unsigned char)buffer[idx] >> 4);
			temp.push_back((unsigned char)buffer[idx++] & 0xf);
			Polycode::Logger::log("idx:%d, i:%d, j:%d, lower:%x, upper:%x\n", idx, i, j, (unsigned char)buffer[idx - 1] >> 4, (unsigned char)buffer[idx - 1] & 0xf);
		}
		ret.insert(ret.begin(), temp);
	}
	return ret;
}

unsigned int BMPFile::get_size_x(){
	return info_header->biWidth;
}

unsigned int BMPFile::get_size_y(){
	return info_header->biHeight;
}
