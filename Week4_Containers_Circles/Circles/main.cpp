/*
    Start shape drawing file
*/

#include <iostream>
#include "Framework.h"

// Variables with global scope - do not rename them, feel free to change values though

// Screen dimensions
int gScreenWidth{800};
int gScreenHeight{600};

// Delay to slow things down
int gTimeDelayMS{10};

using namespace std;

int main()
{
	std::cout << "Hello circles" << endl;

	srand(time(0));

	bool xDIR1[100];
	bool yDIR1[100];

	int xLOC1[100];
	int yLOC1[100];
	int scale = 20;
	int xspeed = 5;
	int yspeed = 5;

	cout << "Created variables" << endl;

	for (int a = 0; a < 100; a++) {
		xDIR1[a] = false;
		yDIR1[a] = false;
		xLOC1[a] = rand() % gScreenWidth;
		yLOC1[a] = rand() % gScreenHeight;

		cout << xDIR1[a] << ", " << yDIR1[a] << endl;
	}

	while(UpdateFramework())
	{
		for (int i=0; i < 100; i++)
		{
			// Updates location based on direction variable
			if (xDIR1[i] == true) { xLOC1[i] -= xspeed; }
			else { xLOC1[i] += xspeed; }

			if (yDIR1[i] == true) { yLOC1[i] -= yspeed; }
			else { yLOC1[i] += yspeed; }

			// Checks for boundaries and reverses direction variable
			if (xLOC1[i] >= gScreenWidth - (scale * 2)) { xDIR1[i] = true; }
			else if (xLOC1[i] <= 0) { xDIR1[i] = false; }

			if (yLOC1[i] >= gScreenHeight - (scale * 2)) { yDIR1[i] = true; }
			else if (yLOC1[i] <= 0) { yDIR1[i] = false; }

			//cout << xLOC1[i] << ", " << yLOC1[i] << endl;

			// Draws a circle at 100,200 with radius 20
			DrawCircle(xLOC1[i], yLOC1[i], scale);
		}
	}

	cout << "Bye bye" << endl;

	return 0;
}
