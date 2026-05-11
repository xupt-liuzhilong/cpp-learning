​

## 一、C++ 的输入输出

在 C++ 中，常用：

```cpp
cout
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

进行输出，用：

```cpp
cin
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

进行输入。

使用它们之前，需要包含头文件：

```cpp
#include <iostream>
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

因为 `cin`、`cout`、`endl` 都属于 `std` 命名空间，所以一般还会写：

```cpp
using namespace std;
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

---

## 二、cout 输出

`cout` 用来向控制台输出内容。

基本写法：

```cpp
cout << 数据 << endl;
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

例如：

```cpp
#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    double b = 3.14;
    char c = 'A';

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

运行结果：

```
10
3.14
A
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

其中：

```cpp
<<
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

表示把数据输出到 `cout` 中。

`endl` 表示换行。

---

## 三、cin 输入

`cin` 用来从键盘输入数据。

基本写法：

```cpp
cin >> 变量;
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

例如：

```cpp
#include <iostream>
using namespace std;

int main()
{
    int a;
    double b;
    char c;

    cin >> a;
    cin >> b >> c;

    cout << a << endl;
    cout << b << " " << c << endl;

    return 0;
}
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

输入：

```
10
3.14 A
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

输出：

```
10
3.14 A
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

其中：

```cpp
>>
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

表示从 `cin` 中读取数据，存入变量。

---

## 四、C++ 输入输出的特点

C++ 的输入输出流可以自动识别变量类型。

比如：

```cpp
int a;
double b;
char c;

cin >> a >> b >> c;
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

编译器会根据变量类型自动处理输入。

相比 C 语言，不需要写：

```cpp
scanf("%d %lf %c", &a, &b, &c);
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

输出时也是一样。

C 语言中

```cpp
printf("%d\n", a);
printf("%lf\n", b);
printf("%c\n", c);
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

C++ 中：

```cpp
cout << a << endl;
cout << b << endl;
cout << c << endl;
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

所以 C++ 输入输出的优点是：

1. 不需要写格式控制符；
2. 可以自动识别变量类型；
3. 写法更统一。

---

## 五、endl 和 \n 的区别

换行时可以使用：

```cpp
endl
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

也可以使用：

```cpp
"\n"
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

例如：

```cpp
cout << "hello" << endl;
cout << "world" << "\n";
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

二者都可以换行。

不过 `endl` 除了换行之外，还会刷新缓冲区；`\n` 只是换行。

平时学习阶段使用 `endl` 没问题。

以后刷算法题时，为了效率，可以更多使用：

```cpp
cout << "\n";
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

---

## 六、简单示例

下面写一个输入两个整数并输出它们和的程序：

```cpp
#include <iostream>
using namespace std;

int main()
{
    int a, b;

    cout << "请输入两个整数：" << endl;
    cin >> a >> b;

    cout << "它们的和是：" << a + b << endl;

    return 0;
}
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

输入：

```
3 5
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

输出：

```
请输入两个整数：
它们的和是：8
```

![](data:image/gif;base64,R0lGODlhAQABAPABAP///wAAACH5BAEKAAAALAAAAAABAAEAAAICRAEAOw== "点击并拖拽以移动")

---

## 七、小结

本篇主要学习了 C++ 中的输入输出。

需要记住：

1. 使用 `cin` 和 `cout` 需要包含 `<iostream>`；
2. `cout` 用于输出，配合 `<<` 使用；
3. `cin` 用于输入，配合 `>>` 使用；
4. `cin`、`cout`、`endl` 都在 `std` 命名空间中；
5. C++ 输入输出可以自动识别变量类型；
6. `endl` 和 `\n` 都可以换行，但 `endl` 还会刷新缓冲区。

C++ 的输入输出比 C 语言更方便，后面写简单程序时会经常用到。

​