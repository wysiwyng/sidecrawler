/*
 * LevelStructure.cpp
 *
 *  Created on: Jan 27, 2015
 *      Author: wysiwyng
 */

#include "LevelStructure.h"

using namespace Polycode;
using namespace std;

LevelStructure::LevelStructure(char *levelData, int sizeX, int sizeY) {
	lvl = levelData;
	this -> sizeX = sizeX;
	this -> sizeY = sizeY;

}

LevelStructure::~LevelStructure() {
	// TODO Auto-generated destructor stub
}

