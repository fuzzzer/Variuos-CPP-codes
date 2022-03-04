


#include "gwindow.h"
#include "gevents.h"
#include "gobjects.h"
#include "Vector.h"
#include "hashmap.h"
#include "random.h"


int clickesAllowed = 3;
double startingRadius = 1;
HashMap<int, Vector<double>> points;

void moveCurrentTowardChosen(int &currentPoint, int randomVertex){
  		 double currX = points.get(currentPoint)[0] + (points.get(randomVertex)[0] - points.get(currentPoint)[0]) / 2;
		 double currY = points.get(currentPoint)[1] + (points.get(randomVertex)[1] - points.get(currentPoint)[1]) / 2;

		 Vector<double> newCoordinates;

		 newCoordinates.add(currX);
		 newCoordinates.add(currY);

		 points[currentPoint] = newCoordinates;


}

void drawCircleAroundCurrentPoint(Vector<double> coordinates, GWindow &gw){
	GOval *oval = new GOval(coordinates[0] - startingRadius, coordinates[1] - startingRadius, startingRadius * 2, startingRadius * 2);
	oval->setFilled(true);
	gw.add(oval);
}


void drawCircles(GWindow &gw){
	int currentPoint = clickesAllowed;
	Vector<double> newCoordinates = points.get(randomInteger(0, points.size() - 1));
	points.put(currentPoint, newCoordinates);

	while(true){
		//if (MouseButtonIsDown()) break;
		/*
		if (e.getEventType() == MOUSE_PRESSED) {
			cout << " pressed " << endl;
			break;
		}
		*/

		 drawCircleAroundCurrentPoint(points.get(currentPoint), gw);

		 int randomVertex = randomInteger(0, points.size() - 1);
		 moveCurrentTowardChosen(currentPoint, randomVertex);

		 pause(0.5);
	}
}


void drawLines(GWindow &gw){
	gw.clear();

	if(points.size() > 1){
		for(int i=0; i < points.size() - 1; i++){

			GLine *line = new GLine(points.get(i)[0], points.get(i)[1], points.get(i+1)[0], points.get(i+1)[1]);
			gw.add(line);
		}
	}

	if(points.size() == clickesAllowed){
		GLine *line = new GLine(points.get(points.size()-1)[0], points.get(points.size()-1)[1], points.get(0)[0], points.get(0)[1]);
		gw.add(line);
	}
}


int main() {
      GWindow gw;
      
      cout << "This program lets the user choose points for fractal." << endl;

	  int clicks = 0;

      while (clicks < clickesAllowed) {
         GMouseEvent e = waitForEvent(MOUSE_EVENT);
         if (e.getEventType() == MOUSE_CLICKED) {

            Vector<double> coordinates;
			coordinates.add(e.getX());
			coordinates.add(e.getY());
			points.put(clicks, coordinates);
			

			if(clicks >= 1){
				drawLines(gw);
			}

			clicks++;
         }
      }

	  drawCircles(gw);

	  return 0;
   }