#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Container {
    protected:
        static double pi;
    public:
        virtual double area()=0;
        virtual double volume()=0;
        static double sumofarea(Container *c[],int n);
        static double sumofvolume(Container *c[],int n);
};
double Container::pi=3.1415926;

class Cube : public Container {
public:
    Cube(double a)
        : _a(a)
    {}

    double area() {
        return _a * _a * 6;
    }

    double volume() {
        return _a * _a * _a;
    }

private:
    double _a;
};
class Cylinder : public Container {
public:
    Cylinder(double r, double h)
        : _r(r)
        , _h(h)
    {}

    double area() {
        return 2 * _r * _r * Container::pi + 2 * Container::pi * _r * _h;
    }

    double volume() {
        return _r * _r * Container::pi * _h;
    }

private:
    double _r;
    double _h;
};

double Container::sumofarea(Container *c[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += c[i]->area();
    }
    return sum;
}

double Container::sumofvolume(Container *c[], int n) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += c[i]->volume();
    }
    return sum;
}

int main() {
    int n;
    cin >> n;

    Container* c[n];
    for (int i = 0; i < n; i++) {
        string type;
        cin >> type;
        if (type == "cube") {
            double a;
            cin >> a;
            c[i] = new Cube(a);
        }
        if (type == "cylinder") {
            double r, h;
            cin >> r >> h;
            c[i] = new Cylinder(r, h);
        }
    }

    cout << fixed << setprecision(2) << Container::sumofarea(c, n) << endl;
    cout << fixed << setprecision(2) << Container::sumofvolume(c, n) << endl;

    for (int i = 0; i < n; i++) {
        delete c[i];
    }

    return 0;
}
