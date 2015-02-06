/*
 * Level.h
 *
 *  Created on: Jan 27, 2015
 *      Author: wysiwyng
 */

#ifndef LEVEL_H_
#define LEVEL_H_

#include "LevelStructure.h"
#include "Polycode.h"

using namespace Polycode;
using namespace std;

class Level {
public:
	Level();
	virtual ~Level();
	int readLevelFromFile(const char* file);
	int buildLevel();

private:
	LevelStructure *level;
};


#endif /* LEVEL_H_ */
