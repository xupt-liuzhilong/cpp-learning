#include <iostream>
#include <string>
using namespace std;

class People
{
private:
    string name;
    int age,height,weight;
    static int cnt;
public:
    void set(string name,int age,int height,int weight);
    void show();
    int getCnt();
    People();
    ~People();
};

int main()
{
    int n;
    cin>>n;
    People *p=new People[n];
    string name;
    int age,height,weight,i;
    for(i=0;i<n;i++)
    {
        cin>>name>>age>>height>>weight;
        p[i].set(name,age,height,weight);
    }
    cout<<"There are "<<p->getCnt()<<" people."<<endl;
    cout<<"Details are as follows."<<endl;
    for(i=0;i<n;i++)
    {
        p[i].show();
    }
    return 0;
}

int People::cnt = 0;

void People::set(string name,int age,int height,int weight) {
    this->name = name;
    this->age = age;
    this->height = height;
    this->weight = weight;
}
void People::show() {
    cout << name << " " << age << " " << height << " " << weight<< endl;
}
int People::getCnt() {
    return cnt;
}
People::People() {
    cnt++;
}
People::~People() {
    cnt--;
}
