#include "Framework.h"
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

#pragma once
class Circle
{
	public:
		// (Mutable lets us change individual values without changing EVERYTHING)
		// Directional Values, Decides Where The Circles Are Going
		mutable bool xDIR = false;
		mutable bool yDIR = false;

		// Speed Values For Each Circle
		mutable int XSpeed = 5;
		mutable int YSpeed = 5;

		// Current Location And Scale Of Circle
		mutable int X = 100;
		mutable int Y = 500;
		mutable int Radius = 20;

		// Color Of The Circle (for fun)
		mutable unsigned char R = 255;
		mutable unsigned char G = 0;
		mutable unsigned char B = 0;
		mutable unsigned char A = 255;

		Circle(int x = 0, int y = 0, int radius = 20, int speedx = 5, int speedy = 5) {
			if (x == 0) // Sets X To A Random Number Based On The Usual Screen Size Values
			{
				x = rand() % 800;
			}

			if (y == 0) // Sets Y To A Random Number Based On The Usual Screen Size Values
			{
				y = rand() % 600;
			}

			this->SetDirection(rand() % 2 == 1, rand() % 2 == 1); // Sets Direction To A Random Direction (Code In Circle.CPP)
			this->SetPosition(x, y); // Sets Spawn Position (Code In Circle.CPP)
			this->SetSpeed(speedx, speedy); // Sets Set Speed (Code In Circle.CPP)
			this->Radius = radius; // Sets the Size of The circle
			this->RandomColour(); // Randomly Sets the Color (YAY) (Code In Circle.CPP)
			this->Draw(); // Draws The Circle (Code In Circle.CPP)
		};

		bool Update(int gScreenWidth, int gScreenHeight) const; // Updates The Position Of The Circle
		void SetSpeed(int xSpeed, int ySpeed) const; // Sets Speed of The Circle (this is the function tho)
		void SetPosition(int x, int y) const; // Sets Position (But the function)
		void SetDirection(bool x, bool y) const; // Sets Direction (again)
		void SetColour(unsigned char red, unsigned char green,
			unsigned char blue, unsigned char alpha = 255) const {
			this->R = red;
			this->G = green;
			this->B = blue;
			this->A = alpha;
		} // Sets Random Color Variables

		void RandomSpeed() const; //  Sets Random Speed
		void RandomColour() const {
			SetColour(rand() % 256, rand() % 256, rand() % 256, 255); // Actually Does The Randomising
		}
	private:
		void Draw() const;
};

