//*******************************************************************
#include "lib.h"
#include "Module/RTOS.h"
#include "Button.h"
#include "Coordinate.h"

//*******************************************************************

class View{
	
	private:
		cDevDisplayGraphic& disp;

	public:
		View(cDevDisplayGraphic& dispRef): disp(dispRef){
		}
		
		void createStartView(Button button1, Button button2){
			#ifdef USE_GRAPHIC_DISPLAY
				disp.setBackColor(cHwDisplayGraphic::Navy);
				disp.clear();
				disp.printf(0,0,0,__DATE__ " " __TIME__);

				// Button 1
				disp.drawFrame(button1.getX(), button1.getY(), button1.getXLaenge(), button1.getYLaenge(), 2, cHwDisplayGraphic::Red);
				disp.drawText(button1.getX() + 10, button1.getY() - 30, 20, "1 Spieler");
			
				// Button 2
				disp.drawFrame(button2.getX(), button2.getY(), button2.getXLaenge(), button2.getYLaenge(), 2, cHwDisplayGraphic::Red);
				disp.drawText(button2.getX() + 10, button2.getY() - 30, 20, "2 Spieler");
			
				// Feld
				disp.drawLine(0, 160, 480, 160, 5, cHwDisplayGraphic::Black);
				disp.drawLine(0, 320, 480, 320, 5, cHwDisplayGraphic::Black);
				disp.drawLine(160, 0, 160, 480, 5, cHwDisplayGraphic::Black);
				disp.drawLine(320, 0, 320, 480, 5, cHwDisplayGraphic::Black);
				disp.drawLine(480, 0, 480, 480, 5, cHwDisplayGraphic::Black);

				disp.refresh();
			#endif
		}
		
		void drawCross(Coordinate co){
			// male ein Kreuz an die Koordinate
			disp.drawLine(co.x-40, co.y-40, co.x+40, co.y+40, 10, cHwDisplayGraphic::Red);
			disp.drawLine(co.x-40, co.y+40, co.x+40, co.y-40, 10, cHwDisplayGraphic::Red);
		}
		
		void drawCircle(Coordinate co){
			// male einen Kreis um die Koordinate
			disp.drawCircle(co.x, co.y, 4, cHwDisplayGraphic::Red);
		}
};

//EOF