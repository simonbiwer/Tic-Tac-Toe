//*******************************************************************
#include "lib.h"
#include "Module/RTOS.h"

//*******************************************************************

class Button{
	
	private:
		int x;
		int y;
		int xLaenge;
		int yLaenge;
//		char[]* text;
	
	public:
		Button(int x, int y, int xLaenge, int yLaenge){
			this -> x = x;
			this -> y = y;
			this -> xLaenge = xLaenge;
			this -> yLaenge = yLaenge;
		}
		
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
		int getXLaenge(){
			return xLaenge;
		}
		int getYLaenge(){
			return yLaenge;
		}
			
//		char[] getText(){
//			return *text;
//		}
		
		bool contains(int x, int y){
			return (x > this -> x) && (x < this -> x + xLaenge) && (y > this -> y) && (y < this -> y + yLaenge);
		}
	
};