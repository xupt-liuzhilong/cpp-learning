#include <iostream>
using namespace std;

class Sum {
public:
    Sum() {
        _sum += ++_i;
    }

    static int GetSum() {
        return _sum;
    }

    static void Init() {
        _i = 0;
        _sum = 0;
    }

private:
    static int _i;
    static int _sum;
};

int Sum::_i = 0;
int Sum::_sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        Sum::Init();            // 初始化静态成员变量
        Sum* s = new Sum[n];    // 创建一个长度为 n 的 Sum 数组，调用构造函数计算 1+2+...+n 的和
        delete[] s;             // 释放内存，调用析构函数，避免内存泄漏
        return Sum::GetSum();
    }
};

int main() {
    int n;
    // 输入一个整数 n，计算 1+2+...+n 的和
    // 可以以多组测试数据的形式输入，直到输入结束
    while (cin >> n) {
        Solution s;
        cout << s.Sum_Solution(n) << endl;
    }
    
    return 0;
}