#include <iostream>
#include<iomanip>
using namespace std;
const double PI=3.14;

class Dot {
public:
    Dot(float x, float y)
        : _x(x)
        , _y(y)
    {
        cout << "Dot constructor called" << endl;
    }

    ~Dot() {
        cout << "Dot destructor called" << endl;
    }

private:
    float _x;
    float _y;
};

class Cir : public Dot {
public:
    Cir(float x, float y, float r)
        : Dot(x, y)
        , _r(r)
    {
        cout << "Cir constructor called" << endl;
    }

    float getArea() {
        return PI * _r * _r;
    }

    ~Cir() {
        cout << "Cir destructor called" << endl;
    }

private:
    float _r;
};

int main(){
    float x,y,r;
    cin>>x>>y>>r;
    Cir c(x,y,r);
    cout<<fixed<<setprecision(2)<<c.getArea()<<endl;
    return 0;
}
