#include <iostream>
#include <string>
using namespace std;

class Figure
{
public:
	virtual string draw() = 0;	
};

class Triangle : public Figure
{
public:
	virtual string draw() { return "Draw Triangle"; }
};

class Square : public Figure
{
public:
	virtual string draw() { return "Draw Square"; }
};

class Circle : public Figure
{
public:
	virtual string draw() { return "Draw Circle"; }
};

int main()
{
	Figure* F1 = new Triangle;
	Figure* F2 = new Square;
	Figure* F3 = new Circle;

	cout << F1->draw() <<endl;
	cout << F2->draw() <<endl;
	cout << F3->draw() <<endl;
	
	delete F1;
	delete F2;
	delete F3;
		
	return 0;
}