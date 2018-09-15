#include <iostream>
#include <conio.h>
#include <thread>
#include "Point.h"
#include <stdlib.h>
#include <vector>
#include <ctime>



static bool s_Finished = false;
char input = 'm';
int board[20][20];
Point a(10, 10);

int lx, ly;
std::vector<Point> snake = {a};
Point food(5, 5);

void eat(Point &food, Point a) {
	if (input == 'H') { //up
		if (board[a.getX() - 1][a.getY()] == 2) {
			food.changeC(snake[snake.size() - 1].getX(), snake[snake.size() - 1].getY());
			snake.push_back(food);
		}
		else if (board[a.getX() - 1][a.getY()] == 1) {
			s_Finished = true;
		}
		else if (a.getX() - 1 < 0) {
			s_Finished = true;
		}
		
		
	}
	if (input == 'K') { //left
		if (board[a.getX()][a.getY() - 1] == 2) {
			food.changeC(snake[snake.size() - 1].getX(), snake[snake.size() - 1].getY());
			snake.push_back(food);
		}
		else if (board[a.getX()][a.getY() - 1] == 1) {
			s_Finished = true;
		}
		else if (a.getY() - 1 < 0) {
			s_Finished = true;
		}
		
	}
	if (input == 'P') { //down
		if (board[a.getX() + 1][a.getY()] == 2) {
			food.changeC(snake[snake.size() - 1].getX(), snake[snake.size() - 1].getY());
			snake.push_back(food);
		}
		else if (board[a.getX() + 1][a.getY()] == 1) {
			s_Finished = true;
		}
		else if (a.getX() + 1 > 19) {
			s_Finished = true;
		}
	
	}
	if (input == 'M') { //right
		if (board[a.getX()][a.getY() + 1] == 2) {
			food.changeC(snake[snake.size() - 1].getX(), snake[snake.size() - 1].getY());
			snake.push_back(food);
		}
		else if (board[a.getX()][a.getY() + 1] == 1) {
			s_Finished = true;
		}
		else if (a.getY() + 1 > 19) {
			s_Finished = true;
		}
		
	}
}


void clear() {
	for (int i = 0;i < 20;i++) {
		for (int j = 0; j < 20; j++) {
			board[i][j] = 0;
		}
	}
}

void plot(Point a) {
	board[a.getX()][a.getY()] = 1;
}

void display() {
	for (int i = 0; i < 20;i++) {
		for (int j = 0; j < 20;j++) {
			if (board[i][j] == 0) {
				std::cout << " - ";
			}
			if (board[i][j] == 1) {
				std::cout << "[] ";
			}
			if (board[i][j] == 2) {
				std::cout << " @ ";
			}
		}
		std::cout << std::endl;
	}
}

void move(char input, Point &a) {
	if (input == 'H') { //up
		if (snake.size() > 0) {
			board[a.getX()][a.getY()] = 0;
		}
		board[a.getX() - 1][a.getY()] = 1;
		a.changeP(a.getX(), a.getY());
		a.changeC(a.getX() - 1, a.getY());
	}
	if (input == 'K') { //left
		if (snake.size() > 0) {
			board[a.getX()][a.getY()] = 0;
		}
		board[a.getX()][a.getY() - 1] = 1;
		a.changeP(a.getX(), a.getY());
		a.changeC(a.getX(), a.getY() - 1);
	}
	if (input == 'P') { //down
		if (snake.size() >0) {
			board[a.getX()][a.getY()] = 0;
		}
		board[a.getX() + 1][a.getY()] = 1;
		a.changeP(a.getX(), a.getY());
		a.changeC(a.getX() + 1, a.getY());
	}
	if (input == 'M') { //right
		if (snake.size() >0) {
			board[a.getX()][a.getY()] = 0;
		}
		board[a.getX()][a.getY() + 1] = 1;
		a.changeP(a.getX(), a.getY());
		a.changeC(a.getX(), a.getY() + 1);
	}
}

void moveBody(Point a, Point &b) {
	
	b.changeC(a.getX(), a.getY());
}

void run(){
	using namespace std::literals::chrono_literals;
	srand((int)time(0));
	int fx = 8;
	int fy = 6;
	board[fx][fy] = 2;
	while (!s_Finished) {
		
		if (board[fx][fy] != 2) {
			fx = rand() % 20;
			fy = rand() % 20;
			while (board[fx][fy] == 1) {
				fx = rand() % 20;
				fy = rand() % 20;
			}
			board[fx][fy] = 2;
		}

		eat(food, snake[0]);
		
		int last = snake.size() - 1;
		board[snake[last].getX()][snake[last].getY()] = 0;
		for (int i = snake.size() - 1; i > 0; i--) {
			moveBody(snake[i - 1], snake[i]);
		}

		move(input, snake[0]);
		
		for (int i = 1; i < snake.size(); i++) {
			plot(snake[i]);
		}
		

		display();
		std::this_thread::sleep_for(0.1s);
		system("CLS");

	
	}
	
	
}




int main() {
	plot(a);
	
	
	int x, y;

	std::thread worker(run);
	while (!s_Finished) {
		
		input = _getch();
	}
	if (s_Finished == true) {
		std::cout << "You lost!";
	}
	std::cin.get();
	

	worker.join();

	
	

	return 0;
}