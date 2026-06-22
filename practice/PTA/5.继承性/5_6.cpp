#include <iostream>
using namespace std;

enum COLOR{ WHITE, RED, BROWN, BLACK, KHAKI };

class Mammal
{
public:
    //constructors
    Mammal() {
        itsAge = 1;
        itsWeight = 1;
    }
    Mammal(int age)
        : itsAge(age)
    {}
    ~Mammal() {}
    
    //accessors
    int GetAge() const {
        return itsAge;
    }
    void SetAge(int age) {
        itsAge = age;
    }
    int GetWeight() const {
        return itsWeight;
    }
    void SetWeight(int weight) {
        itsWeight = weight;
    }
    
    //Other methods    
    void Speak() const {
        cout << "Mammal is spaeking..." << endl;
    }
    void Sleep() const {
        cout << "Mammal is sleeping..." << endl;
    }     
protected:
    int itsAge;
    int itsWeight;
};

class Dog : public Mammal {
public:
    Dog() {
        itsColor = WHITE;
    }
    Dog(int age)
        : Mammal(age)
    {
        itsColor = WHITE;
    }
    Dog(int age, int weight)
        : Mammal(age)
    {
        itsWeight = weight;
        itsColor = WHITE;
    }
    Dog(int age, COLOR color)
        : Mammal(age)
        , itsColor(color)
    {}
    Dog(int age, int weight, COLOR color)
        : Mammal(age)
        , itsColor(color)
    {
        itsWeight = weight;
    }
    ~Dog() {}

    COLOR GetColor() const {
        return itsColor;
    }

    void SetColor(COLOR color) {
        itsColor = color;
    }

    void WagTail() const {
        cout << "The Dog is Wagging its tail..." << endl;
    }
    void BegForFood() const {
        cout << "The dog is begging for food..." << endl;
    }
private:
    COLOR itsColor;
};

int main()
{
    Dog Fido;
    Dog Rover(5);
    Dog Buster(6, 8);
    Dog Yorkie(3, RED);
    Dog Dobbie(4, 20, KHAKI);
    Fido.Speak();
    Rover.WagTail();
    cout << "Yorkie is " << Yorkie.GetAge() << " years old." << endl;
    cout << "Dobbie weighs " << Dobbie.GetWeight() << " pounds." << endl;   
    return 0;
}
