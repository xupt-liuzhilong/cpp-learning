#include <iostream>
#include <iomanip>
using namespace std;

class Shape
{
public:
    virtual double Area() = 0;
};

class Circle : public Shape
{
public:
    Circle(double r)
        : _r(r)
    {}

    double Area()
    {
        return 3.14159 * _r * _r;
    }

private:
    double _r;
};

class Square : public Shape
{
public:
    Square(double a)
        : _a(a)
    {}

    double Area()
    {
        return _a * _a;
    }

private:
    double _a;
};

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height)
        : _width(width)
        , _height(height)
    {}

    double Area()
    {
        return  _width * _height;
    }

private:
	double _width;
    double _height;
};

class Trapezoid : public Shape {
public:
	Trapezoid(double top, double bottom, double height)
		: _top(top)
		, _bottom(bottom)
		, _height(height)
	{}
	
	double Area() {
		return (_top + _bottom) * _height / 2;
	}
	
private:
	double _top;
	double _bottom;
	double _height;
};

class Triangle : public Shape
{
public:
    Triangle(double bottom, double height)
    	: _bottom(bottom)
        , _height(height)
    {}

    double Area()
    {
        return _bottom * _height / 2;
    }

private:
	double _bottom;
    double _height;
};

double getArea(Shape* ps)
{
    return ps->Area();
}

int main()
{
    double r;
    double a;
    double rw, rh;
    double tt, tb, th;
    double sb, sh;
    
    cin >> r >> a >> rw >> rh >> tt >> tb >> th >> sb >> sh;

    Circle c(r);
    Square s(a);
    Rectangle rect(rw, rh);
    Trapezoid tra(tt, tb, th);
    Triangle tri(sb, sh);

    double sum = getArea(&c) + getArea(&s) + getArea(&rect) + getArea(&tra) + getArea(&tri);
	cout << fixed << setprecision(3) << sum << endl;
	
    return 0;
}