#include <iostream>
using namespace std;

class CShape {
public:
    virtual double Area() = 0;
    virtual double Length() = 0;
};

class CRectangle : public CShape {
public:
    CRectangle(double length, double width)
        : _length(length)
        , _width(width)
    {}

    double Area() {
        return _length * _width;
    }

    double Length() {
        return 2 * (_length + _width);
    }

protected:
    double _length;
    double _width;
};

class CCuboid : public CRectangle {
public:
    CCuboid(double length, double width, double height)
        : CRectangle(length, width)
        , _height(height)
    {}

    double Area() {
        return 2 * (_length * _width + _length * _height + _width * _height);
    }

    double Length() {
        return 4 * (_length + _width + _height);
    }

private:
    double _height;
};

void Display(CRectangle &r) {
    cout << r.Area() << "," << r.Length() << endl;
}

int main()
{
    CRectangle liv_Rect(4,8);//实例化边长为4、8的长方形
    CCuboid liv_Cub(4,4,8);// 实例化长方体，长方体的长宽高分别为4、4、8
    cout<<liv_Rect.Area()<<','<<liv_Rect.Length()<<endl;  //直接输出矩形的周长和面积
    cout<<liv_Cub.Area()<<','<<liv_Cub.Length()<<endl; //直接输出长方体的周长和面积
    Display(liv_Rect);             //调用Display函数输出liv_Rect的周长和面积
    Display(liv_Cub);             //调用Display函数输出liv_Cub的周长和面积
    return 0;
}

