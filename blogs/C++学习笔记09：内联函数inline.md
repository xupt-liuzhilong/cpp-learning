# C++学习笔记09：内联函数inline

# 一、什么是内联函数？

在C++中，可以使用 inline 关键字修饰函数，这种函数叫做**内联函数**。

基本写法：

```cpp
inline int Add(int x, int y) {
    return x + y;
}
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

内联函数的作用是：

> 在函数调用的地方直接展开函数代码，减少函数调用的开销。

普通函数调用时，需要经历参数压栈、函数跳转、返回等过程。如果一个函数狠毒按，并且被频繁调用，这些调用的开销就可能比较明显。

使用 inline 后，编译器可能会把这些函数直接展开到调用位置。

------

# 二、普通函数调用

```cpp
#include <iostream>
using namespace std;

int Add(int x, int y)
{
    return x + y;
}

int main()
{
    int ret = Add(1, 2);
    cout << ret << endl;

    return 0;
}
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

这里调用 Add(1, 2) 时，会进入 Add 函数执行，执行再返回main函数。

对普通函数来说，这是正常调用的过程。

------

# 三、内联函数的写法

使用 inline 修饰函数：

```cpp
#include <iostream>
using namespace std;

inline int Add(int x, int y)
{
    return x + y;
}

int main()
{
    int ret = Add(1, 2);
    cout << ret << endl;

    return 0;
}
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

如果编译器选择内联展开，那么：

```cpp
int ret = Add(1, 2);
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

可能会被处理成类似：

```cpp
int ret = 1 + 2;
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

这样就减少了一次函数调用的开销。

------

# 四、内联函数的优点

内莱妮函数的主要优点是：

> 减少函数调用开销，提高程序运行效率。

它比较适合：

1. 函数体比较短；
2. 函数逻辑比较简单；
3. 函数被频繁调用。

例如：

```cpp
inline int Max(int x, int y) {
    return x > y ? x : y;
}
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

这种函数比较短，适合写成内联函数。

------

# 五、内联函数缺点

内联函数并不是越多越好。

如果内联函数很长，还强行写成内联函数，可能会导致代码膨胀。

比如一个函数有很多行代码，如果每次调用都展开一份，最终生成可执行程序体积可能会变大。

所以简单可以理解为：

> 内联函数使用空间换时间。

它减少了函数调用时间，但增加了代码的体积。

------

# 六、inline 只是给编译器的建议

需要注意的是：

> inline 只是做建议，不是命令。

也就是说，不是写了 inline ，编译器就一定会把函数展开。

如果函数太复杂，编译器可能会忽略 inline。

例如：

```cpp
inline void Func() {
    for (int i = 0; i < 1000; i++) {
        cout << i << emdl;
    }
}
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

这种函数逻辑比较复杂，基石写了inline ，编译器也不一定会真正展开。

一般来说，递归函数、代码比较长的函数，都不适合写成内联函数。

------

# 七、内联函数和宏函数的区别

C语言有时候会用宏函数：

```cpp
#define ADD(x, y) ((x) + (y))
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

C++中更推荐使用内联函数：

```cpp
inline int Add(int x, int y) {
    return x + y;
}
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

宏函数是在预处理阶段进行文本替换，没有类型检查，容易出错。

内联函数虽然可能会再调用出展开，但是他是真正的函数，具有类型检查，更安全。

简单对比：

| 对比点   | 宏函数     | 内联函数 |
| -------- | ---------- | -------- |
| 处理阶段 | 预处理阶段 | 编译阶段 |
| 本质     | 文本替换   | 函数     |
| 类型检查 | 没有       | 有       |
| 调试     | 不方便     | 相对方便 |
| 安全性   | 较低       | 较高     |

所以在C++中，能用内联函数，一般不建议使用宏函数。

------

# 八、内联函数的注意事项

使用内联函数时需要注意：

1. 函数体不要太长；
2. 递归函数一般不适合内联；
3. inline 只是建议，是否展开由编译器决定；
4. 内联函数适合卸载头文件中；
5. 类中直接定义的成员函数，默认具有内联属性。

例如：

```cpp
class Date {
public:
    void Print() {
        cout << "Date" << endll;
    }
};
```

![点击并拖拽以移动](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw==)

这里 Print 函数直接在类里面定义，默认具有内联属性。

------

# 九、小结

本篇主要学习了C++中的内联函数。

需要记住：

1. 内联函数使用 inline 修饰；
2. 内联函数可能会在调用处展开；
3. 内联函数可以减少函数调用开销；
4. 内联函数适合短小、频繁调用的函数；
5. 内联函数是用空间换时间；
6. inline 只是给编译器的建议，不一定真正展开；
7. C++中的内联函数可以替代一部分宏函数。

内联函数时C++中比较实用的语法，后面学习类和对象时，类里面定义的短小成员函数经常设计内联。