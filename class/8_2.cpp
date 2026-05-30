#include <cstdlib>

int main() {
    // 申请一个整数的内存空间
    int* p1 = (int *)malloc(sizeof(int));
    // 申请一个包含4个整数的内存空间，并初始化为0 
    int* p2 = (int *)calloc(4, sizeof(int));
    // 重新分配内存空间，将p2的内存空间扩大到10个整数的大小
    int* p3 = (int *)realloc(p2, sizeof(int) * 10);

    free(p1);
    // 由于p2已经被realloc重新分配了内存空间，所以不需要再调用free(p2)来释放内存
    free(p3);

    return 0;
}