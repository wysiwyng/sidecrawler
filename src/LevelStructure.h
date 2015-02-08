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
	LevelStructure(std::vector< std::vector<unsigned char> > levelData, int sizeX, int sizeY);
	virtual ~LevelStructure();
	unsigned char getTile(int x, int y);

private:
	std::vector< std::vector<unsigned char> > lvl;
	int sizeX;
	int sizeY;
};

 /* namespace Polycode */

#endif /* LEVELSTRUCTURE_H_ */
