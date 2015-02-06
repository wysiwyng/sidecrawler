/*
 * Level.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: wysiwyng
 */

#include "Level.h"
#include <iostream>
#include <fstream>
#include <string>


Level::Level() {


}

Level::~Level() {
	// TODO Auto-generated destructor stub
}

int Level::readLevelFromFile(const char* file) {
	std::streampos size;
	std::streampos specSize;

	char *memblock;
	char *levelSpecs;
	char *pnt;

	std::ifstream inFile(file,std::ios::in|std::ios::binary|std::ios::ate);

	if(!inFile.is_open()) return -1;

	size = inFile.tellg();
	specSize = size - (streampos)4;
	memblock = new char[size];
	levelSpecs = new char[specSize];

	inFile.seekg(0, std::ios::beg);
	inFile.read(levelSpecs, specSize);

	inFile.seekg(4, std::ios::beg);
	inFile.read(memblock, size);

	inFile.close();

	level = new LevelStructure(memblock, (levelSpecs[0] << 8) | levelSpecs[1], (levelSpecs[2] << 8) | levelSpecs[3]);

	return 0;
}
