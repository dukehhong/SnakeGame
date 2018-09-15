#ifndef POINT_H
#define POINT_H

class Point {
public:
	Point();
	Point(int x_in, int y_in);
	int getX();
	int getY();
	int getPX();
	int getPY();
	void changeC(int x1, int y1);
	void changeP(int x, int y);
	void move(int a);
	Point operator=(Point b);
private:
	int x;
	int y;
	int prex;
	int prey;
};


#endif POINT_H