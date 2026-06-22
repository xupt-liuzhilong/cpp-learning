#include <iostream>
using namespace std;

class Vehicle {
public:
    int _speed;
    int _weight;

    Vehicle(int speed, int weight)
        : _speed(speed)
        , _weight(weight)
    {}
    void Run() {
    	cout << "Run" << endl;
	}
    void Stop(){
    	cout << "stop" << endl;
	}
};

class Bicycle : virtual public Vehicle {
public:
    int _height;

    Bicycle(int speed, int weight, int height)
        : Vehicle(speed, weight)
        , _height(height)
    {}
};

class Motorcycle : virtual public Vehicle {
public:
    int _seatnum;

    Motorcycle(int speed, int weight, int seatnum)
        : Vehicle(speed, weight)
        , _seatnum(seatnum)
    {}
};

class Motorcar : public Bicycle, public Motorcycle {
public:
    Motorcar(int speed, int weight, int height, int seatnum)
    	: Vehicle(speed, weight)
        , Bicycle(speed, weight, height)
        , Motorcycle(speed, weight, seatnum)
    {}
};

int main(){
    Motorcar  moto(30,50,120,5);
    cout<<"speed "<<moto._speed<<endl;
    cout<<"weight "<<moto._weight<<endl;
    cout<<"height "<<moto._height<<endl;
    cout<<"seatNum "<<moto._seatnum<<endl;
    
    return 0;
}
