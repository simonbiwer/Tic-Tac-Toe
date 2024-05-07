//*******************************************************************
#include "lib.h"
#include "Module/RTOS.h"

//*******************************************************************

// Quadrate mit einer Seitenlänge von 160 Einheiten

class Square{
	
	private:
		// Koordinate oben links
		int x;
		int y;
	
	public:
		Square(int _x, int _y) : 
			x(_x), y(_y)
		{}
			
		bool contains(int x, int y){
			return (x > this -> x) && (x < this -> x + 160) && (y > this -> y) && (y < this -> y + 160);
		}
		
		Coordinate getCenter(){
			int x = x + 80;
			int y = y + 80;
			Coordinate co(x, y);
			return co;
		}
};