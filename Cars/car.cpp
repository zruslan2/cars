#include "car.h"


car::car(string model, colors c, int year, double engineVolume, int engineCountCylinder, string engineType, double wheelDiameter, string wheelType)
{
	setModel(model);
	setColor(c);
	setYear(year);
	engine_ tmp(engineVolume, engineCountCylinder, engineType);
	setEngine(tmp);
	wheel wheeltmp(wheelDiameter, wheelType);
	for (int i = 0; i < 4; i++)
	{
		setWheel(wheeltmp, i);
	}
}

void car::setModel(string carModel)
{
	this->model = carModel;
}

void car::setColor(colors c)
{
	this->color = c;
}

void car::setYear(int carYear)
{
	this->year = carYear;
}

void car::setEngine(engine_ & engine)
{
	this->engine = engine;
}

void car::setWheel(wheel & wheel, int index)
{
	wheels[index] = wheel;
}

string car::getModel() const
{
	return this->model;
}

colors car::getColor() const
{
	return this->color;
}

int car::getYear() const
{
	return this->year;
}

engine_ car::getEngine() const
{
	return this->engine;
}

engine_& car::getEngine()
{
	return this->engine;
}


wheel car::getWheel(int index) const
{
	return wheels[index];
}

wheel& car::getWheel(int index)
{
	return wheels[index];
}

string car::getCarInfo() const
{
	string res = "Car model = " + this->model;
	res += "\nCar color = ";
	switch (color)
	{
	case WHITE:
		res += "white";
		break;
	case RED:
		res += "red";
		break;
	case GREEN:
		res += "green";
		break;
	case BLACK:
		res += "black";
		break;
	}

	res += "\nYear = " + to_string(year);
	res += "\n" + engine.getInfo();
	for (int i = 0; i < 4; i++)
	{
		res += "\n" + wheels[i].getInfo();
	}
	return res;
}

ostream & operator<<(ostream & os, const car & obj)
{
	os << obj.getCarInfo();
	return os;
}

istream & operator >> (istream & is, car & obj)
{
	int y;
	is >> y;
	obj.setYear(y);
	return is;
}
