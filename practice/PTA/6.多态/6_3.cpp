#include <iostream>
using namespace std;

class Animal {
public:
    Animal(int num, string name)
        : _num(num)
        , _name(name)
    {}
    
    int getnum() {
        return _num;
    }
    
    string getname() {
        return _name;
    }
    
    virtual void eat() = 0;
    
private:
    int _num;
    string _name;
};

class Dog : public Animal {
public:
    Dog(int num, string name)
        : Animal(num, name)
    {}

    void eat() {
        cout << getnum() << "号" << getname() << "啃骨头" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(int num, string name)
        : Animal(num, name)
    {}

    void eat() {
        cout << getnum() << "号" << getname() << "吃小鱼" << endl;
    }
};

int main() {
    int num1, num2;
    string name1, name2;

    cin >> num1 >> name1;
    cin >> num2 >> name2;

    Dog dog(num1, name1);
    Cat cat(num2, name2);

    Animal* p = &dog;
    p->eat();

    p = &cat;
    p->eat();
    
    return 0;
}