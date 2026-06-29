#include <iostream>
using namespace std;
class Student
 {public:
   Student(int n,float s):num(n),score(s){}
   int num;
   float score;
 };

int main()
{Student stud[5]={
  Student(101,78.5),Student(102,85.5),Student(103,98.5),
  Student(104,100.0),Student(105,95.5)};
 void max(Student* );
 Student *p=&stud[0];
 max(p);
 return 0; 
 }

void max(Student* s) {
    int max = 0;
    for (int i = 0; i < 5; i++) {
        if (s[i].score > s[max].score) {
            max = i;
        }
    }
    cout << s[max].num << " " << s[max].score << endl;
}