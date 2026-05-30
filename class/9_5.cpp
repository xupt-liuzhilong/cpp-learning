#include <iostream>
using namespace std;

// C语言怎么实现一个Stack？
typedef int STDateType;
struct Stack_C {
    STDateType* _a;
    int _top;
    int _capacity;
};
typedef struct Stack_C Stack_C;

void StackInit(Stack_C* ps);
void StackDestroy(Stack_C* ps);
void StackPush(Stack_C* ps, STDateType x);
void StackPop(Stack_C* ps);
// ...


// C++怎么实现一个Stack？
template<class T>
class Stack_CPP {
public:
    Stack_CPP() {
        cout << "Stack_CPP()" << endl;
    }
    ~Stack_CPP() {
        cout << "~Stack_CPP()" << endl;
    }
    void Push(T x) {
        cout << "Push: " << x << endl;
    }

private:
    T* _a;
    int _top;
    int _capacity;
};


int main() {
    // 1. 忘记初始化和销毁                 -> 构造函数和析构函数
    // 2. 忘记封装，谁都可以修改结构体数据  -> 类加访问限定符
    // 3. 如果想同时定义两个栈，一个栈存 int，另一个栈存 double，做不到 -> 模板
    /*Stack_C st_c;
    StackInit(&st_c);
    StackPush(&st_c, 1);
    StackPush(&st_c, 2);
    StackPush(&st_c, 3);
    StackPush(&st_c, 4);

    StackDestroy(&st_c);*/

    //

    Stack_CPP<int> st_cpp_int;
    st_cpp_int.Push(1); // 实际也有两个参数，一个是 this 指针，指向 st_cpp 对象
    st_cpp_int.Push(2);
    st_cpp_int.Push(3);
    st_cpp_int.Push(4);

    Stack_CPP<double> st_cpp_double;
    st_cpp_double.Push(1.1);
    st_cpp_double.Push(2.2);
    st_cpp_double.Push(3.3);
    st_cpp_double.Push(4.4);

    return 0;
}