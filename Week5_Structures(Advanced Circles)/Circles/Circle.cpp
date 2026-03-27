#include "Circle.h"

//void Circle::RandomSpeed() const
//{
//	// Change the speed randomly
//
//}

void Circle::Draw() const
{
	ChangeColour(this->R, this->G, this->B, this->A); // Sets Color Of The Circle
	DrawCircle(this->X, this->Y, this->Radius); // Spawns Circle On Screen
}

bool Circle::Update(int gScreenWidth, int gScreenHeight) const
{
	int xDIR1 = this->xDIR;
	int yDIR1 = this->yDIR;

	int xLOC1 = this->X;
	int yLOC1 = this->Y;
	
	int xspeed = this->XSpeed;
	int yspeed = this->YSpeed;

	int scale = this->Radius;

	if (xDIR1 == true) { xLOC1 -= xspeed; }
	else { xLOC1 += xspeed; }

	if (yDIR1 == true) { yLOC1 -= yspeed; }
	else { yLOC1 += yspeed; }

	this->SetPosition(xLOC1, yLOC1);

	// Checks for boundaries and reverses direction variable
	if (xLOC1 >= gScreenWidth - (scale * 2)) { xDIR1 = true; }
	else if (xLOC1 <= 0) { xDIR1 = false; }

	if (yLOC1 >= gScreenHeight - (scale * 2)) { yDIR1 = true; }
	else if (yLOC1 <= 0) { yDIR1 = false; }

	bool hasHit = xDIR1 != this->xDIR || yDIR1 != this->yDIR;

	if (hasHit) {
		this->RandomSpeed(); // Change speed when direction changes
		this->RandomColour(); // Change colour when direction changes
	}

	this->SetDirection(xDIR1, yDIR1); // Set New Direction (or old)

	this->Draw(); // Draw circle

	return hasHit;
}

void Circle::SetPosition(int x, int y) const
{
	this->X = x; // Set X
	this->Y = y; // Set Y
}

void Circle::SetDirection(bool x, bool y) const
{
	this->xDIR = x; // Set X Direction
	this->yDIR = y; // Set Y Direction
}

void Circle::RandomSpeed() const
{
	this->SetSpeed(max(rand() % 5, 3), max(rand() % 5, 3));
}

void Circle::SetSpeed(int xSpeed = 5, int ySpeed = 5) const
{
	this->XSpeed = xSpeed;
	this->YSpeed = ySpeed;
}
