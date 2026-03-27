/*
	Start shape drawing file
*/

#include <iostream>
#include "Framework.h"
#include "Circle.h"
#include <vector>

// Variables with global scope - do not rename them, feel free to change values though
const int MAX_CIRCLES = 100;

// Screen dimensions
int gScreenWidth{ 800 };
int gScreenHeight{ 600 };

// Delay to slow things down
int gTimeDelayMS{ 10 };

using namespace std;

int scale = 20;
int xspeed = 5;
int yspeed = 5;

vector<Circle> circles = {};

void CreateCircle(int speedx = 5, int speedy = 5)
{
	if (circles.size() >= MAX_CIRCLES) return;
	circles.emplace_back(rand() % gScreenWidth, rand() % gScreenHeight, scale, speedx, speedy);
}

int main()
{
	srand(time(0));

	circles.reserve(MAX_CIRCLES);

	CreateCircle(1, 1);

	while (UpdateFramework())
	{
		int hits = 0;

		for (int i = 0; i < circles.size(); i++)
		{
			bool hasHit = circles.at(i).Update(gScreenWidth, gScreenHeight);
			if (hasHit) hits++;
		}

		for (int i = 0; i < hits; i++)
		{
			CreateCircle();
		}
	}

	cout << "Bye bye" << endl;

	return 0;
}
