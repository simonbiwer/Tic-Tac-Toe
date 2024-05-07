//*******************************************************************
#include "lib.h"
#include "Module/RTOS.h"
#include "Square.h"
//#include "Coordinate.h"

//*******************************************************************

class Controller{
	
	private:
		cDevDisplayGraphic& disp;
		View view;
		Button button1;
		Button button2;
		bool cpuPlayer;
		Square* field[9];
	// Square(* field)[9];

	public:
		
		bool gameRunning;
	
		Controller(cDevDisplayGraphic& _disp) : disp(_disp), view(_disp),
			button1(550, 100, 200, 100), button2(550, 300, 200, 100)
		{
			gameRunning = false;
		}
		
		~Controller()
		{
			deleteField();
			delete field;
		}
		
		void setUpStartView(){
			view.createStartView(button1, button2);
		}
		
		void beforeGame(cDevControlPointer::cData event){
			if (button1.contains(event.posX, event.posY)){
				Coordinate co(button1.getX() + 100, button1.getY() + 50);
				view.drawCross(co);
				cpuPlayer = true;
				setupField();
				gameRunning = true;
			}
			
			if (button2.contains(event.posX, event.posY)){
				Coordinate co(button2.getX() + 100, button2.getY() + 50);
				view.drawCross(co);
				cpuPlayer = false;
				setupField();
				gameRunning = true;
			}
      disp.refresh();
		}
		
		void duringGame(cDevControlPointer::cData event){
			if (!cpuPlayer){
				int counter = 0;
				for (int i=0; i < 9; i++){
					Square sqr = (*field)[i];
					if (sqr.contains(event.posX, event.posY)){
						Coordinate co = sqr.getCenter();
						if (counter%2 == 0){
							view.drawCross(co);
						} else {
							view.drawCircle(co);
						}
						++counter;
					}
				}
			}
			disp.refresh();
		}
		
		void setupField(){
			// 9 Rechtecke erzeugen und zum Feld hinzufügen
			Square* sqr1 = new Square(0, 0);
			field[0] = sqr1;
			Square* sqr2 = new Square(0, 160);
			field[1] = sqr2;
			Square* sqr3 = new Square(0, 320);
			field[2] = sqr3;
			Square* sqr4 = new Square(160, 0);
			field[3] = sqr4;
			Square* sqr5 = new Square(160, 160);
			field[4] = sqr5;
			Square* sqr6 = new Square(160, 320);
			field[5] = sqr6;
			Square* sqr7 = new Square(320, 0);
			field[6] = sqr7;
			Square* sqr8 = new Square(320, 160);
			field[7] = sqr8;
			Square* sqr9 = new Square(320, 320);
			field[8] = sqr9;
		}
		
		void deleteField(){
			for (int i=0; i < 9; i++){
				delete field[i];
			}
		}
};

//EOF