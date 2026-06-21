// 1. 申请后忘记释放
int* p = new int[10];

// 忘记 delete[] p;

// 2. 中途 return 导致没有释放
void Func() {
    int*p = new int[10];
    if(/*某个条件*/) {
        return; /// 直接返回，p 没有释放
    }

    delete[] p;
}

// 3. 指针被覆盖，原空间丢失
int* p = new int[10];

p = new int[20]; // 原来那块 int[10] 的空间丢了

// 4. new 和 delete 不匹配
int* p = new int[10];

delete p; // 错误