#include<iostream>
using namespace std;
class A{
    int data;
public:
    A(int k=0){
        data=k;
    }
    void show(){
        cout<<"data="<<data<<endl;
    }
};

int main() {
    A a1[3];
    for (int i = 0; i < 3; i++) {
        a1[i].show();
    }
    cout << "\n";

    A a2[3] = {A(1)};
    for (int i = 0; i < 3; i++) {
        a2[i].show();
    }
    cout << "\n";

    A a3[3] = {A(1), A(2), A(3)};
    for (int i = 0; i < 3; i++) {
        a3[i].show();
    }
    cout << "\n";
    
    return 0;
}