//*******************************************************************
#include "lib.h"
#include "Module/RTOS.h"

//*******************************************************************

class Coordinate{
	
	public:
		int x;
		int y;
		
		Coordinate(int _x, int _y) : 
			x(_x), y(_y)
			{}
};