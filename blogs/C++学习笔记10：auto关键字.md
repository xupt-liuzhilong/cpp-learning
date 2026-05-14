# C++学习笔记10：auto关键字

## 一、什么是auto？

auto 是 C++11引入的关键字。

它的作用是：

> 让编译器根据初始化表达式，自动推导变量的类型。

简单来说，就是有些时候我们不用手写变量类型，编译器可以自己判断。

例如：

```cpp
int a = 10;

auto b = a;
```


这里 a 是 int 类型，所以编译器会自动推导出 b 也是 int 类型。

上面的代码等价于：

```cpp
int b = a;
```

------

## 二、auto的基本使用

示例：

```cpp
#include <iostream>
using namespace std;

int main() {
	int a = 10;
	double b = 3.14;
	char c = 'A';

	auto x = a;
	auto y = b;
	auto z = c;

	cout << x << endl;
	cout << y << endl;
	cout << z << endl;

	return 0;
}
```

在这段代码中：

```cpp
cout << x << endl;    // x 被推导为 int
cout << y << endl;    // y 被推导为 double
cout << z << endl;    // z 被推导为 char
```


auto 可以让代码更简洁，尤其是类型比较长的时候很有用。

------

## 三、auto和引用

需要注意：

```cpp
auto b = a;
```

这种写法一般推导出来的是普通变量，不是引用。

如果想让b成为a的因哟个，需要写成：

```cpp
auto& b = a;
```


示例：

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;

    auto& b = a;
    b = 20;

    cout << a << endl;
    cout << b << endl;

    return 0;
}
```


运行结果：

```cpp
20
20
```

------

## 四、auto和指针

auto 也可以推导指针类型。

例如：

```cpp
int a = 10;
int*p = &a;
```


也可以写成：

```cpp
auto p = &a;
```


因为 &a 的类型是 int* ，所以 p 会被推到为 int*。

也可以写成：

```cpp
auto* p = &a;
```

这两种写法都可以：

```cpp
auto p = &a;    // p 被推导为 int*
auto* p = &a;   // p 被推导为 int*
```


不过 auto* 写法更明显，一眼能看出开是一个指针。

------

## 五、auto使用时必须初始化

auto 需要根据初始化表达式推导类型，所以定义时必须初始化。

错误写法：

```cpp
auto a;
```

因为没有初始值，编译器不知道 a 应该是什么类型。

正确写法：

```cpp
auto a = 10;
auto b = 3.14;
auto c = 'A';
```

------

## 六、auto的使用限制

auto 虽然很方便，但不是所有地方都能用。

### 1.不能用auto定义未初始化变量

```cpp
auto a;    // 错误
```


必须写成：

```cpp
auto a = 10;
```

------

### 2.一行定义多个变量时，类型必须一致

正确：

```cpp
auto a = 1, b = 2;
```


因为 a 和 b都是 int 类型。

错误：

```cpp
auto a = 1, b = 3.14;
```


因为 a 时 int，b 是double，类型不一致。

------

### 3.auto不能直接作为普通函数参数类型

错误写法：

```cpp
void func(auto x);
```


在普通C++函数中，一般不能这样写。

函数参数啦icing应该明确写出：

```cpp
void func(int x);
```

------

## 七、什么时候适合用auto？

auto 适合用在类型比较明显，或者类型比较复杂的地方。

例如：

```cpp
auto x = 10;
auto y = 3.14;
```


这种类型很容易看出来。

以后学习 STL 时，auto 会更常用，比如遍历容器：

```cpp
vector<int> v = {1, 2, 3};

for (auto e : v) {
    cout << e << endl;
}
```


这样比写长的类型要方便。

------

## 八、小结

本篇主要学习了C++中的auto关键字。

需要记住：

1. auto 是C++11引入的类型推导关键字；
2. auto 会根据初始化表达式自动推导变量类型；
3. auto 定义时必须初始化；
4. auto b = a通常是值拷贝；
5. auto& b = a才是引用；
6. auto p = &a可以推导出指针类型；
7. 一行定义多个auto变量时，类型必须相同。

auto 可以让代码更简洁，但不能滥用。刚开始学习时，还是要先理解变量的真实类型，在考虑使用 auto。