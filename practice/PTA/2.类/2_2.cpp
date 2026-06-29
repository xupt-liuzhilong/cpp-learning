#include <iostream>
#include <iomanip>
using namespace std;

class Rectangle {
public:
    Rectangle(double a, double b)
        : _a(a)
        , _b(b)
    {}

    double getPerimeter() {
        return 2 * (_a + _b);
    }

private:
    double _a;
    double _b;
};

int main() {
    double a, b;
    cin >> a >> b;

    Rectangle rect(a, b);

    cout << fixed << setprecision(2) << rect.getPerimeter() << endl;
    return 0;
}