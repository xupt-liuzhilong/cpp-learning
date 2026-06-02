# C++学习笔记34：new/delete 与 operator new/operator delete

## 一、先区分几个概念

学习 C++ 动态内存管理时，很容易把下面几组概念混在一起：

```cpp
malloc / free
new / delete
operator new / operator delete
```

它们之间有关系，但不是同一个东西。

简单来说：

```cpp
malloc/free：C语言中的动态内存管理函数
new/delete：C++中的动态内存管理操作符
operator new/operator delete：C++底层用于申请和释放原始内存的函数
```

这一篇重点就是把它们之间的关系理清楚。

------

## 二、malloc/free 只负责内存

在 C 语言中，动态申请空间通常使用 `malloc`：

```cpp
int* p = (int*)malloc(sizeof(int));
```

释放空间使用 `free`：

```cpp
free(p);
```

对于内置类型来说，这样没问题。

但是如果是自定义类型，例如：

```cpp
class A
{
public:
    A()
    {
        cout << "A()" << endl;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }
};
```

如果使用 `malloc/free`：

```cpp
A* p = (A*)malloc(sizeof(A));

free(p);
```

这段代码只完成了：

```cpp
申请空间
释放空间
```

不会调用：

```cpp
构造函数
析构函数
```

也就是说，`malloc/free` 只管内存，不管对象生命周期。

------

## 三、new/delete 管理对象生命周期

C++ 中更推荐使用 `new/delete`：

```cpp
A* p = new A;

delete p;
```

这段代码和 `malloc/free` 的区别在于：

```cpp
new 不只是申请空间，还会调用构造函数
delete 不只是释放空间，还会调用析构函数
```

所以可以理解为：

```cpp
new = 申请空间 + 调用构造函数
delete = 调用析构函数 + 释放空间
```

验证代码：

```cpp
#include <iostream>
#include <cstdlib>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A()" << endl;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }
};

int main()
{
    cout << "malloc/free:" << endl;
    A* p1 = (A*)malloc(sizeof(A));
    free(p1);

    cout << "new/delete:" << endl;
    A* p2 = new A;
    delete p2;

    return 0;
}
```

运行结果类似：

```cpp
malloc/free:
new/delete:
A()
~A()
```

所以对于自定义类型来说，`new/delete` 不是单纯的“申请和释放内存”，而是负责对象的完整创建和销毁过程。

------

## 四、new 表达式的完整过程

当我们写：

```cpp
A* p = new A;
```

它大致会分成两步：

```cpp
1. 调用 operator new 申请一块原始内存
2. 在这块内存上调用 A 的构造函数
```

也就是：

```cpp
new A
↓
operator new(sizeof(A)) 申请空间
↓
调用 A::A() 构造对象
↓
返回 A* 指针
```

所以要注意：

```cpp
new 是一个表达式
operator new 是一个函数
```

它们不是一个东西。

`new` 表达式会在底层调用 `operator new` 函数，但 `operator new` 本身只负责申请空间，不负责调用构造函数。

------

## 五、delete 表达式的完整过程

当我们写：

```cpp
delete p;
```

它大致也会分成两步：

```cpp
1. 调用析构函数，清理对象资源
2. 调用 operator delete 释放原始内存
```

也就是：

```cpp
delete p
↓
调用 p->~A()
↓
operator delete(p) 释放空间
```

所以：

```cpp
delete 是表达式
operator delete 是函数
```

`delete` 表达式会调用析构函数，再调用 `operator delete` 释放空间。

而 `operator delete` 本身只负责释放内存，不负责调用析构函数。

------

## 六、operator new 和 malloc 的关系

`operator new` 是 C++ 标准库提供的函数，用来申请原始内存。

它的形式可以简单理解为：

```cpp
void* operator new(size_t size);
```

用法类似：

```cpp
void* p = operator new(sizeof(A));
```

它和 `malloc` 很像，都是按字节申请空间。

但是二者有一个重要区别：

```cpp
malloc 申请失败返回 NULL
operator new 申请失败会抛出 bad_alloc 异常
```

也就是说，C 语言更偏向通过返回值表示错误，C++ 更偏向通过异常处理错误。

例如：

```cpp
try
{
    void* p = operator new(1024);
    operator delete(p);
}
catch (const bad_alloc& e)
{
    cout << "内存申请失败" << endl;
}
```

现阶段不用深入异常机制，只要知道：

```cpp
operator new 申请失败不是返回 NULL，而是抛异常。
```

------

## 七、operator delete 和 free 的关系

`operator delete` 用来释放由 `operator new` 申请的原始内存。

形式可以简单理解为：

```cpp
void operator delete(void* p);
```

用法类似：

```cpp
void* p = operator new(sizeof(A));

operator delete(p);
```

它和 `free` 的作用类似，都是释放空间。

可以简单理解：

```cpp
operator new 底层通常会封装 malloc
operator delete 底层通常会封装 free
```

但是在 C++ 中，`operator new/operator delete` 是专门为 `new/delete` 表达式服务的。

------

## 八、new[] 和 delete[] 的过程

如果申请对象数组：

```cpp
A* p = new A[3];
```

它大致会做：

```cpp
1. 调用 operator new[] 申请一整块连续空间
2. 调用 3 次构造函数
```

释放时：

```cpp
delete[] p;
```

它大致会做：

```cpp
1. 调用 3 次析构函数
2. 调用 operator delete[] 释放整块空间
```

代码验证：

```cpp
#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A()" << endl;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }
};

int main()
{
    A* p = new A[3];

    delete[] p;

    return 0;
}
```

运行结果类似：

```cpp
A()
A()
A()
~A()
~A()
~A()
```

所以数组申请和释放一定要配套：

```cpp
new      配 delete
new[]    配 delete[]
```

------

## 九、为什么 new[] 必须配 delete[]？

如果这样写：

```cpp
A* p = new A[3];

delete p; // 错误
```

问题是：`p` 指向的是一组对象，但你用了单对象释放方式。

对于自定义类型数组来说，可能会导致：

```cpp
析构函数调用次数不正确
内存释放方式不匹配
程序行为未定义
```

正确写法必须是：

```cpp
delete[] p;
```

这不是格式问题，而是对象生命周期管理问题。

------

## 十、用一张表总结关系

| 写法              | 作用                              |
| ----------------- | --------------------------------- |
| `malloc`          | C语言函数，只申请原始内存         |
| `free`            | C语言函数，只释放原始内存         |
| `operator new`    | C++函数，只申请原始内存           |
| `operator delete` | C++函数，只释放原始内存           |
| `new`             | C++操作符，申请空间并调用构造函数 |
| `delete`          | C++操作符，调用析构函数并释放空间 |
| `new[]`           | 申请数组空间并调用多次构造函数    |
| `delete[]`        | 调用多次析构函数并释放数组空间    |

最关键的是区分这两层：

```cpp
底层内存申请释放：
operator new / operator delete

对象创建销毁：
new / delete
```

------

## 十一、小结

本篇主要整理了 `new/delete` 与 `operator new/operator delete` 的关系。

需要记住：

1. `malloc/free` 是 C 语言中的动态内存管理函数；
2. `new/delete` 是 C++ 中的动态内存管理操作符；
3. `operator new/operator delete` 是 C++ 中申请和释放原始内存的函数；
4. `operator new` 只申请空间，不调用构造函数；
5. `operator delete` 只释放空间，不调用析构函数；
6. `new A` 会先调用 `operator new` 申请空间，再调用构造函数；
7. `delete p` 会先调用析构函数，再调用 `operator delete` 释放空间；
8. `new A[n]` 会申请连续空间，并调用 N 次构造函数；
9. `delete[] p` 会调用 N 次析构函数，再释放整块空间；
10. `new[]` 必须和 `delete[]` 配套使用；
11. `malloc` 失败返回 `NULL`，`operator new` 失败会抛异常。

这篇的核心不是死记哪个和哪个对应，而是理解：

```cpp
malloc/free 和 operator new/operator delete 管的是原始内存；
new/delete 管的是对象生命周期。
```