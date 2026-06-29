#include <iostream>
using namespace std;

class Student {
public:
    void set(int num, int score) {
        _num = num;
        _score = score;
    }

    void Print() const {
        cout << _num << " " << _score << endl;
    }

private:
    int _num;
    int _score;
};

int main() {
    Student stu[5];
    for (int i = 0; i < 5; i++) {
        int n, s;
        cin >> n >> s;
        stu[i].set(n, s);
    }

    for(int i = 0; i < 5; i++) {
        stu[i].Print();
    }

    return 0;
}