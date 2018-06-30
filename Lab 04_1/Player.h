#pragma once
#include "Circle_1.h"
#include "Figure_1.h"
#include "Rectangl_1.h"
#include <math.h>
#include <stdio.h>    
#include <stdlib.h>     
#include <time.h>

class Player : public Figure
{
public:
	Player(double _x, double _y)
	{
		r = 0;
		g = 0.6;
		b = 0.4;
		Circle c(_x, _y + 0.3, 0.22, r, 0.4, 0.6);
		head = c;
		Rectangl b(0.2, 0.3, _x, _y, 0, r, g, b);
		body = b;
		x = _x;
		y = _y;
	}
	void changeColour()
	{
		srand(time(NULL));
		this->r = 0.1*(rand() % 10);
		this->g = 0.1*(rand() % 10);
		this->b = 0.1*(rand() % 10);
		Circle c(x, y + 0.3, 0.22, r, g, b);
		head = c;
		Rectangl b(0.2, 0.3, x, y, 0, r, g, b);
		body = b;
		Draw();
	}
	void Draw()
	{
		head.draw();
		body.draw();
	}
	void move(double dx,double dy)
	{
		x += dx;
		y += dy;
		Circle c(x, y + 0.3, 0.22, r, g, b);
		head = c;
		Rectangl b(0.2, 0.3, x, y, 0, r, g, b);
		body = b;
		Draw();
	}
private:
	Circle head;
	Rectangl body;
};
