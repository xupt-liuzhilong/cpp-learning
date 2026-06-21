#include <iostream>
using namespace std;

class Pet {
public:
    Pet(string name, int age, string colour)
        : _name(name)
        , _age(age)
        , _colour(colour)
    {}

    string getName() {
        return _name;
    }

    int getAge() {
        return _age;
    }

    string getColour() {
        return _colour;
    }

    virtual void Speak() = 0;
    virtual void GetInfo() = 0;

private:
    string _name;
    int _age;
    string _colour;
};

class Cat : public Pet {
public:
    Cat(string name, int age, string colour)
        : Pet(name, age, colour)
    {}

    void Speak() {
        cout << "猫的叫声:miao!miao!" << endl;
    }

    void GetInfo() {
        cout << "猫的名字:" << getName() << endl;
        cout << "猫的年龄:" << getAge() << endl;
        cout << "猫的颜色:" << getColour() << endl;
    }
};

class Dog : public Pet {
public:
    Dog(string name, int age, string colour)
        : Pet(name, age, colour)
    {}

    void Speak() {
        cout << "狗的叫声:wang!wang!" << endl;
    }

    void GetInfo() {
        cout << "狗的名字:" << getName() << endl;
        cout << "狗的年龄:" << getAge() << endl;
        cout << "狗的颜色:" << getColour() << endl;
    }
};

int main() {
    string name1, name2;
    int age1, age2;
    string colour1, colour2;

    cin >> name1 >> age1 >> colour1;
    cin >> name2 >> age2 >> colour2;

    Cat c(name1, age1, colour1);
    Dog d(name2, age2, colour2);

    c.GetInfo();
    c.Speak();

    d.GetInfo();
    d.Speak();

    return 0;
}