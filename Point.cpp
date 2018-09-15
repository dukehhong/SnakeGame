#include <iostream>
#include "Point.h"

Point::Point() {
	x = 0;
	y = 0;
	prex = 0;
	prey = 0;
}

Point::Point(int x_in, int y_in) {
	x = x_in;
	y = y_in;
	prex = 11;
	prey = 10;
}

int Point::getX() {
	return x;
}

int Point::getY() {
	return y;
}

void Point::changeC(int x1, int y1) {
	x = x1;
	y = y1;
}

void Point::changeP(int x, int y) {
	prex = x;
	prey = y;
}

void Point:: move(int a) {
	if (a == 0) {
		y += -1;
	}
	else if (a == 1) {
		x += 1;
	}
	else if (a == 2) {
		y += 1;
	}
	else if (a == 3) {
		x += -1;
	}
}

int Point::getPX() {
	return prex;
}

int Point::getPY() {
	return prey;
}

Point Point::operator=(Point b) {
	Point a(3, 3);
	a.x = b.x;
	a.y = b.y;
	a.prex = b.prex;
	a.prey = b.prey;
	return a;
	
}
