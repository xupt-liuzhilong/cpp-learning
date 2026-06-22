#include <iostream>
#include<iomanip>
using namespace std;

class Point {
public:
    Point(float x, float y)
        : _x(x)
        , _y(y)
    {
        cout << "Point constructor called" << endl;
    }

    ~Point() {
        cout << "Point destructor called" << endl;
    }

private:
    float _x;
    float _y;
};

class Circle : public Point {
public:
    Circle(float x, float y, float r)
        : Point(x, y)
        , _r(r)
    {
        cout << "Circle constructor called" << endl;
    }

    ~Circle() {
        cout << "Circle destructor called" << endl;
    }

    float getCircumference() {
        return 2 * 3.14 * _r;
    }

private:
    float _r;
};

int main()
{
    float x,y,r;
    cin>>x>>y>>r;
    Circle c(x,y,r);
    cout<<fixed<<setprecision(2)<<c.getCircumference()<<endl;
    return 0;
}