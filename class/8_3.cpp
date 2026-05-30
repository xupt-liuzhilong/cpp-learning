#include <cstdlib>

int main() {
    // 使用 malloc 函数申请内存空间
    int* p1 = (int*)malloc(sizeof(int));
    int* p2 = (int*)malloc(sizeof(int) * 10);

    free(p1);
    free(p2);
    

    // 使用 new 运算符申请内存空间
    int* p3 = new int(10);  // 申请 1 个 int 的 4 字节内存空间，并将其初始化为 10
    int* p4 = new int[10];  // 申请 10 个 int 的 40 字节内存空间

    delete p3;
    delete[] p4;    // 释放数组内存空间时需要使用 delete[] 运算符

    return 0;
}