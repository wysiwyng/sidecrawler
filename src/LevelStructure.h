/*
 * LevelStructure.h
 *
 *  Created on: Jan 27, 2015
 *      Author: wysiwyng
 */

#ifndef LEVELSTRUCTURE_H_
#define LEVELSTRUCTURE_H_

#include "Polycode.h"

using namespace Polycode;
using namespace std;

class LevelStructure {
public:
	LevelStructure(char *levelData, int sizeX, int sizeY);
	virtual ~LevelStructure();
	char getTile(int x, int y);

private:
	char *lvl;
	int sizeX;
	int sizeY;
};

 /* namespace Polycode */

#endif /* LEVELSTRUCTURE_H_ */
