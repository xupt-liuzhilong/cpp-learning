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
        return 3.1415926 * _r * _r;
    }

private:
    double _r;
};

class Rectangle : public Shape
{
public:
    Rectangle(double height, double width)
        : _height(height)
        , _width(width)
    {}

    double Area()
    {
        return _height * _width;
    }

private:
    double _height;
    double _width;
};

class Triangle : public Shape
{
public:
    Triangle(double height, double bottom)
        : _height(height)
        , _bottom(bottom)
    {}

    double Area()
    {
        return _height * _bottom / 2;
    }

private:
    double _height;
    double _bottom;
};

void PrintArea(Shape* ps)
{
    cout << fixed << setprecision(2) << ps->Area() << endl;
}

int main()
{
    double r;
    double rh, rw;
    double th, tb;

    cin >> r >> rh >> rw >> th >> tb;

    Circle c(r);
    Rectangle rect(rh, rw);
    Triangle tri(th, tb);

    PrintArea(&c);
    PrintArea(&rect);
    PrintArea(&tri);

    return 0;
}