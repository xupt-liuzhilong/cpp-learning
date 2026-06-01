# C++学习笔记33：C++动态内存管理：new和delete

## 一、为什么 C++ 要引入 new 和 delete？

在 C 语言中，动态内存管理主要使用：

```cpp
malloc
calloc
realloc
free
```

但是 C++ 是面向对象语言，除了申请空间，还要考虑对象的初始化和清理。

所以 C++ 引入了新的动态内存管理方式：

```cpp
new
delete
```

在 C++ 中更推荐使用 `new/delete`，而不是继续使用 `malloc/free`。

简单来说：

```cpp
malloc/free 是 C 语言中的动态内存管理方式
new/delete 是 C++ 中的动态内存管理方式
```

------

## 二、new 的基本用法

`new` 用来在堆区申请空间。

### 1. 申请一个 int 空间

```cpp
int* p = new int;
```

这表示在堆区申请一个 `int` 类型的空间，并返回这个空间的地址。

`p` 是一个指针变量，保存这块堆空间的地址。

------

### 2. 申请一个 int 并初始化

```cpp
int* p = new int(10);
```

这表示申请一个 `int` 空间，并初始化为 `10`。

相当于：

```cpp
申请一个 int 大小的堆空间
并把里面的值初始化为 10
```

使用：

```cpp
cout << *p << endl;
```

输出：

```cpp
10
```

------

### 3. 申请数组空间

如果要申请多个 `int`，可以使用 `new[]`：

```cpp
int* p = new int[10];
```

这表示申请 10 个 `int` 的连续空间。

使用时可以像数组一样访问：

```cpp
p[0] = 1;
p[1] = 2;
p[2] = 3;
```

需要注意：

```cpp
new int[10] 申请的是数组空间
释放时必须使用 delete[]
```

------

## 三、delete 的基本用法

`delete` 用来释放 `new` 申请的空间。

### 1. 释放单个对象

如果是这样申请的：

```cpp
int* p = new int(10);
```

就应该这样释放：

```cpp
delete p;
p = nullptr;
```

释放后建议把指针置空，避免继续使用已经释放的空间。

------

### 2. 释放数组空间

如果是这样申请的：

```cpp
int* p = new int[10];
```

就必须这样释放：

```cpp
delete[] p;
p = nullptr;
```

也就是说：

```cpp
new       对应 delete
new[]     对应 delete[]
```

这个配对一定要记住。

------

## 四、new/delete 和 new[]/delete[] 不能乱配

下面这种写法是错误的：

```cpp
int* p = new int[10];

delete p; // 错误
```

因为 `p` 指向的是一块数组空间，应该使用：

```cpp
delete[] p;
```

同理，下面这样也不规范：

```cpp
int* p = new int;

delete[] p; // 错误
```

应该使用：

```cpp
delete p;
```

总结：

| 申请方式      | 释放方式     |
| ------------- | ------------ |
| `new int`     | `delete p`   |
| `new int(10)` | `delete p`   |
| `new int[10]` | `delete[] p` |

------

## 五、new 和 malloc 的用法区别

C 语言中申请一个 `int` 空间：

```cpp
int* p = (int*)malloc(sizeof(int));
```

C++ 中可以写成：

```cpp
int* p = new int;
```

C 语言中申请 10 个 `int`：

```cpp
int* p = (int*)malloc(sizeof(int) * 10);
```

C++ 中可以写成：

```cpp
int* p = new int[10];
```

可以看出，`new` 的写法更加符合类型习惯：

```cpp
malloc 需要自己计算字节数
new 直接写类型
```

例如：

```
new int
new int[10]
new double
new Date
```

`new` 返回的就是对应类型的指针，不需要强制类型转换。

------

## 六、new 和 delete 是操作符

`malloc` 和 `free` 是函数：

```cpp
malloc(sizeof(int));
free(p);
```

而 `new` 和 `delete` 是 C++ 中的操作符：

```cpp
new int;
delete p;
```

所以它们的用法和普通函数不一样。

例如：

```cpp
int* p1 = new int;
int* p2 = new int(10);
int* p3 = new int[10];
```

这里：

```cpp
new 后面直接跟类型
圆括号用于初始化
方括号用于申请数组
```

------

## 七、数组 new 的注意点

对于数组申请，常见写法是：

```cpp
int* p = new int[10];
```

这里申请了 10 个 `int` 的连续空间。

不过需要注意，普通数组形式一般不使用圆括号整体初始化。

比如：

```cpp
int* p = new int[10];
```

这是常用写法。

如果想初始化，可以根据标准支持写成：

```cpp
int* p = new int[10]{};
```

这样会把数组元素初始化为 0。

但初学阶段先掌握最基本的：

```cpp
new int[10]
delete[] p
```

就够了。

------

## 八、自定义类型也可以使用 new

比如有一个类：

```cpp
class Date
{
public:
    Date(int year = 2024, int month = 1, int day = 1)
        : _year(year)
        , _month(month)
        , _day(day)
    {
    }

private:
    int _year;
    int _month;
    int _day;
};
```

可以这样动态创建对象：

```cpp
Date* p1 = new Date;
Date* p2 = new Date(2024, 5, 1);
```

释放：

```cpp
delete p1;
delete p2;
```

也可以创建对象数组：

```cpp
Date* p = new Date[10];
```

释放时：

```cpp
delete[] p;
```

这部分先知道用法即可。

至于为什么 `new Date` 会调用构造函数，`delete p` 会调用析构函数，下一篇会专门讲。

------

## 九、new/delete 的简单示例

```cpp
#include <iostream>
using namespace std;

int main()
{
    int* p1 = new int;
    int* p2 = new int(10);
    int* p3 = new int[5];

    *p1 = 1;

    for (int i = 0; i < 5; i++)
    {
        p3[i] = i + 1;
    }

    cout << *p1 << endl;
    cout << *p2 << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << p3[i] << " ";
    }
    cout << endl;

    delete p1;
    delete p2;
    delete[] p3;

    p1 = nullptr;
    p2 = nullptr;
    p3 = nullptr;

    return 0;
}
```

输出结果：

```cpp
1
10
1 2 3 4 5
```

------

## 十、使用 new/delete 的常见错误

### 1. 申请后忘记释放

```cpp
int* p = new int[10];
```

如果后面没有：

```cpp
delete[] p;
```

就会造成内存泄漏。

------

### 2. new[] 和 delete 不匹配

```cpp
int* p = new int[10];

delete p; // 错误
```

应该写：

```cpp
delete[] p;
```

------

### 3. 释放后继续使用

```cpp
int* p = new int(10);

delete p;

cout << *p << endl; // 错误
```

释放后的空间不能继续使用。

------

### 4. 重复释放

```cpp
int* p = new int(10);

delete p;
delete p; // 错误
```

释放后建议置空：

```cpp
p = nullptr;
```

------

## 十一、小结

本篇主要学习了 C++ 中的动态内存管理方式：`new` 和 `delete`。

需要记住：

1. C++ 中更推荐使用 `new/delete` 管理动态内存；
2. `new` 用来在堆区申请空间；
3. `delete` 用来释放 `new` 申请的空间；
4. `new int` 表示申请一个 `int` 空间；
5. `new int(10)` 表示申请并初始化为 10；
6. `new int[10]` 表示申请 10 个 `int` 的数组空间；
7. `new` 对应 `delete`；
8. `new[]` 对应 `delete[]`；
9. `new/delete` 是操作符，不是普通函数；
10. 使用动态内存时要避免内存泄漏、重复释放和释放后继续使用。

这一篇先掌握 `new/delete` 的基本用法。下一篇重点讲它们和 `malloc/free` 的核心区别：**自定义类型中，new 会调用构造函数，delete 会调用析构函数。**