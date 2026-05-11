​

# 前言

> 最近开始系统学习C++。因为之前学过C语言，所以学习C++时，最明显的感受就是C++再C语言的基础上增加了很多语法机制。
> 
> 这篇博客主要整理C++中的一个基础知识点：**命名空间 namespace。**
> 
> 命名空间是C++入门阶段的比较重要的内容，后面使用的 cin、cout、string、vector等标准库内容时，都要接触到**std**命名空间。

---

# 一、为什么需要命名空间？

在写程序时，我们经常会定义变量、函数、类等名字。

如果项目比较小，命名冲突的问题可能不太明显。如果项目变大，不同文件、不同模块，甚至不同程序员之间的代码，可可能出现相同的名字的变量或者函数。

例如：

```cpp
int a = 10;
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

如果另一个地方也定义了一个相同的变量a，那就可能产生命名冲突。

为了解决这个问题，C++引入了**命名空间namespace**。

命名空间的作用是：

> 避免命名冲突，对名字进行隔离。

比如：

```cpp
namespace N1
{
    int a = 10;
}

namespace N2
{
    int a = 20;
}
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

虽然N1和N2里面都有变量a，但他们属于不同的命名空间，所以不会冲突。

---

# 二、命名空间的基本写法

命名空间使用namespace关键字定义。

```cpp
namespace N
{
    int a = 10;
    
    void func()
    {
        cout << "hello C++" << endl;
    }
}
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

访问命名空间的内容时，需要使用 :: 作用域限定符。

```cpp
N::a;
N::func();
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

完整示例：

```cpp
#include <iostream>
using namespace std;

namespace N
{
    int a = 10;
    
    void func()
    {
        cout << "hello C++" << endl;
    }
}

int main()
{
    cout << N::a << endl;
    N::func();
    
    return 0;
}
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

---

# 三、命名空间的三种使用方式

假设有一个名命空间：

```cpp
namespace N
{
    int a = 10;
    int b = 20;
}
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

## 1.指定命名空间访问

```cpp
cout << N::a << endl;
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

这种写法最安全，也最麻烦。

## 2.展开某一个成员

```cpp
using N::a;

cout << a << endl;
cout << N::b << endl;
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

这样只有a可以直接使用，b仍然要写N::b。

## 3.展开整个命名空间

```cpp
using namespace N;

cout << a << endl;
cout << b << endl;
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

这种最方便，但如果项目比较大，可能会产生命名冲突。

---

# 四、std命名空间

我们平常经常写：

```cpp
using namespace std;
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

这是因为C++标准库中的很多内容都放在std命名空间，比如：cout、cin、endl。

如果不写：

```cpp
using namespace std;
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

就需要写成：

```cpp
std::cout << "hello" << std::endl;
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

所以学习阶段可以先写：

```cpp
using namespace std;
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

这样代码更简单。

但以后写正式项目时，更推荐写：

```cpp
std::cout
std::cin
std::endl
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

这样更安全。

---

# 五、小结

命名空间是C++中用来解决命名冲突的语法。

这一节需要记住：

1. 命名空间用namespace定义；
2. 访问命名空间成员用 :: ；
3. std 是C++标准库的命名空间；
4. 学习阶段可以使用 using namespace std; ；
5. 正式项目中尽量少展开整个命名空间，避免冲突。

​