#include <iostream>
using namespace std;

class Animal {
public:
    Animal(int age)
        : _age(age)
    {}

    int getAge() {
        return _age;
    }

private:
    int _age;
};

class Dog : public Animal {
public:
    Dog(int age, string colour)
        : Animal(age)
        , _colour(colour)
    {}

    void showInfor() {
        cout << "age:" << getAge() << endl;
        cout << "colour:" << _colour << endl;
    }

private:
    string _colour;
};

int main(){
    Animal ani(5);
    cout<<"age of ani:"<<ani.getAge()<<endl;
    Dog dog(5,"black");
    cout<<"infor of dog:"<<endl;
    dog.showInfor();
}

