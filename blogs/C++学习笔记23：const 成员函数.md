# C++学习笔记23：const 成员函数

## 一、为什么需要 const 成员函数？

在C++中，如果一个对象被 const 修饰，那么这个对象就不能被修改。

例如：

```cpp
const Date d(2024, 5, 1);
```

这里 d 是一个 const 对象，表示它的内容不能被修改。

如果我们写一个普通成员函数：

```cpp
void Print() {
    cout << _year << "-" << _month << "-" << _day << endl;
}
```

然后让 const 对象调用它：

```cpp
const Date d(2024, 5, 1);
d.Print();
```

这时可能会编译错误。

原因是：普通成员函数没有承诺不修改对象，而 const 对象不允许被修改。

所以 C++ 提供了 **const 成员函数**。

------

## 二、const 成员函数的写法

const 成员函数就是在成员函数参数列表后面加上 const。

例如：

```cpp
void Print() const {
	cout << _year << "-" << _month << "-" << _day << endl;
}
```

完成示例：

```cpp
#include <iostream>
using namespace std;

class Date {
	public:
		Date(int year = 2024, int month = 1, int day = 1) {
			_year = year;
			_month = month;
			_day = day;
		}
		
		void Print() const {
			cout << _year << "-" << _month << "-" << _day << endl;
		}
	
	private:
		int _year;
		int _month;
		int _day;
};

int main() {
	const Date d(2024, 5, 1);
	d.Print();
	
	return 0;
}
```

运行结果：

```cpp
2024-5-1
```

加上 const 后，const 对象就可以正常调用 Print() 了。

------

## 三、const 修饰的到底是什么？

成员函数后面的 const，本质上修饰的是隐藏的 this 指针指向的对象。

普通成员函数中，this 指针可以理解为：

```cpp
Date* const this
```

也就是：

```cpp
this 指针本身不能改变指向的
但 this 指向的对象可以被修改
```

而 const 成员函数中，this 指针可以理解为：

```cpp
const Date* const this
```

也就是说：

```cpp
this 指针本身不能改变；
this 指向的对象也不能被修改。
```

所以在 const 函数中，不能修改成员变量。

------

## 四、const 成员函数不能修改成员变量

例如：

```cpp
void Print() const {
    _year = 2025;	// 错误 
	cout << _year << "-" << _month << "-" << _day << endl;
}
```

这段代码会报错。

原因是 Print() 被声明成了 const 成员函数，函数内部不能修改点给钱对象的成员变量。

所以 const 成员函数适用于：

```cpp
只读取对象数据，不修改对象状态的函数
```

比如：

```cpp
void Print() const;
bool operator==(const Date& d) const;
bool operator<(const Date& d) const;
int GetMonthDay(int year, int month) const;
```

------

## 五、const 对象和普通对象的调用规则

成员函数调用时，有一套权限规则。

### 1. const 对象只能调用 const 成员函数

```cpp
const Date d(2024, 5, 1);
d.Print();
```

如果 Print() 是普通成员函数，就可能报错。

应该写成：

```cpp
void Print() const {
	cout << _year << "-" << _month << "-" << _day << endl;
}
```

------

### 2. 普通对象可以调用 const 成员函数

```cpp
Date d(2024, 5, 1);
d.Print();
```

如果 Print() 是 const 成员函数，普通对象也可以调用。

因为普通对象权限更大，调用只读函数属于权限缩小，是安全的。

------

### 3. 普通对象也可以调用普通成员函数

```cpp
Date d(2024, 5, 1);
d.Print();
```

普通对象本来就可以修改，所以可以调用普通成员函数。

------

简单总结：

| 对象类型  | 普通成员函数 | const成员函数 |
| --------- | ------------ | ------------- |
| 普通对象  | 可以调用     | 可以调用      |
| const对象 | 不能调用     | 可以调用      |

------

## 六、成员函数之间的调用规则

成员函数内部也会涉及到 const 权限问题。

### 1. 普通成员函数可以调用 const 成员函数。

```cpp
class Date {
	public:
		void Func1() {
			Func2();
		}
		
		void Func2() const {
			cout << "Func2" << endl;
		}
};
```

这是可以的。

因为普通成员函数中的 this 是 Date*，调用 const 成员函数时，可以转换换成 const Date*，属于权限缩小。

------

### 2. const 成员函数不能调用普通成员函数

```cpp
class Date {
	public:
		void Func1 const () {
			Func2();    // 错误
		}
		
		void Func2() {
			cout << "Func2" << endl;
		}
};
```

这是错误的。

因为 const 成员函数中的 this 是 const Date*，如果调用普通成员函数，就相当于把 const Date* 转成 Date*，属于权限放大，不允许。

------

## 七、在日期类中的应用

之前写日期类比较运算符时，可写成这样：

```cpp
bool operator==(const Date& d) {
    return _year == d._year
        && _month == d._month
        && _day == d._day;
}
```

这个函数知识比较日期，不会修改当前对象。

所以更规范的写法应该是：

```cpp
bool operator==(const Date& d) const {
    return _year == d._year
        && _month == d._month
        && _day == d._day;
}
```

同理，下面这些比较函数也应该加 const：

```cpp
bool operator>(const Date& d) const;
bool operator<(const Date& d) const;
bool operator>=(const Date& d) const;
bool operator<=(const Date& d) const;
bool operator!=(const Date& d) const;
```

这样 const Date 对象也可以正常调用这些函数。

哪些成员函数应该加 const？判断标准很简单：

> 只要这个成员函数不修改成员变量，就应该加 const。

不能加 const 的函数一般是会修改对象的，比如：

```cpp
Date& operator+=(int day);
Date& operator-=(int day);
Date& operator++();
Date& operator--();
```

------

## 八、构造函数和析构函数能不能加 const？

构造函数和析构函数不能写成 const 成员函数？

例如下面这种写法是错误的：

```cpp
Date() const {

}

~Date() const {

}
```

原因是构造函数和析构函数本身负责对象的初始化和清理，不属于普通成员函数调用的场景。

所以：

```cpp
构造函数不能加 const
析构函数不能加 const
```

------

## 九、const 成员函数和 const 引用参数的关系

实际写代码时，函数经常会此写成：

```cpp
void Func() (const Date& d) {
	d.Print();
} 
```

这里 d 是 const Date&，也就是一个只读对象。

如果 Print() 没有加 const：

```cpp
void Print() {

}
```

那么：

```cpp
d.Print();
```

就会报错。

所以如果一个对象可以 const 引用形式传参，那么它调用的成员函数也应该是 const 成员函数。

这也是为什么在日期类中，Print()、比较运算符等不修改对象的函数 ，都应该加上const。

------

## 十、小结

本篇主要学习了C++中的 const 成员函数。

需要记住：

1. const 成员函数是成员函数参数列表后面加 const；
2. const 成员函数的本质是限制 this指针指向的对象不能修改；
3. 普通对象可以调用普通成员函数和const 成员函数；
4. const 对象只能调用 const 成员函数；
5. const 成员函数内部不能修改成员变量；
6. 普通成员函数可以调用 const 成员函数；
7. const 成员函数不能调用普通成员函数；
8. 不修改成员变量的函数都建议加 const；
9. 构造函数和析构函数都不能加 const；
10. 日期类中的比较函数、打印函数通常都应该写成 const 成员函数。

const 成员函数是写规范C++类代码时非常重要的知识点。理解它之后，就能很好的处理 const 对象、const 引用参数以及成员函数之间的调用权限问题。