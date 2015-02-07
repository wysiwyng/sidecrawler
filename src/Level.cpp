/*
 * Level.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: wysiwyng
 */

#include "Level.h"
#include "BMPFile.h"


Level::Level() {


}

Level::~Level() {
	// TODO Auto-generated destructor stub
}

int Level::readLevelFromFile(const char* file) {
	BMPFile * bmp = new BMPFile();

	bmp->read(file);


	level = new LevelStructure(bmp->read_data(), bmp->get_size_x(), bmp->get_size_y());

	return 0;
}
