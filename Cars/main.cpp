#include "car.h"
#include <iostream>


void main() {
	car c("audi", colors::GREEN);


	//string cl = c.getColor();
	//cl.clear();

	c.getEngine().setVolume(1.58);
	cout << c.getWheel(0).getInfo();
	c.setColor(colors::WHITE);
	cout << c.getWheel(0).getInfo();
	cout << c<<endl;
	cout << "Year - ";
	cin >> c;
	cout << c;
	system("pause");
}