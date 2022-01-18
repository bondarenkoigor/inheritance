#include<iostream>
#include<string>

class shape
{
protected:
	int coordX;
	int coordY;
public:
	shape()
	{
		this->coordX = this->coordY = 0;
	}
	shape(int coordX, int coordY) : coordX(coordX), coordY(coordY) {}
	int getX()
	{
		return coordX;
	}
	int getY()
	{
		return coordY;
	}

	std::string getInfo()
	{
		return "X: " + std::to_string(this->coordX) + "\tY: " + std::to_string(this->coordY);
	}
};

class square : public shape
{
protected:
	int size;
public:
	square() : shape()
	{
		this->size = 0;
	}
	square(int coordX, int coordY, int size) : shape(coordX, coordY), size(size) {}
	int getsize()
	{
		return size;
	}
	std::string getInfo()
	{
		return shape::getInfo() + "\t" + std::to_string(this->size);
	}
};

class circle : public shape
{
protected:
	float diameter;
	std::string color;
public:
	circle() : shape()
	{
		this->diameter = 0;
		this->color = "none";
	}
	circle(int coordX, int coordY, float diameter, std::string color) : shape(coordX, coordY), diameter(diameter), color(color) {}
	float getdiameter()
	{
		return diameter;
	}
	std::string getcolor()
	{
		return color;
	}
	std::string getInfo() 
	{
		return shape::getInfo() + "\tdiameter: " + std::to_string(this->diameter) + "\tcolor: " + color;
	}
};

class redcircle : public circle
{
public:
	redcircle() : circle()
	{
		this->color = "red";
	}
	redcircle(int coordX, int coordY, float diameter) : circle(coordX, coordY, diameter, "red") {}
};

class greencircle : public circle
{
public:
	greencircle() : circle()
	{
		this->color = "green";
	}
	greencircle(int coordX, int coordY, float diameter) : circle(coordX, coordY, diameter, "green") {}
};

int main()
{
	circle* crcl = new circle(1, 2, 3, "yellow");
	std::cout << crcl->getInfo() << "\n";

	crcl = new greencircle(crcl->getX(), crcl->getY(), crcl->getdiameter());
	std::cout << crcl->getInfo() << "\n";
}