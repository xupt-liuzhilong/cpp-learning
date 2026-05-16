# C++学习笔记15：this 指针

## 一、为什么需要 this 指针？

在C++中，同一个类可以创建多个对象。

例如：

```cpp
class Date {
	public:
		void Print() {
			cout << _year << " " << _month << " " << _day << endl;
		}
	
	private:
		int _year;
		int _month;
		int _day;
};

int main() {
	Date d1;
	Date d2;
	
	return 0;
}
```


d1 和 d2 都有自己的成员变量，但他们调用的是同一份成员函数代码。

那么问题来了：

```cpp
d1 调用 Print 时，Print 怎么知道要打印 d1 的数据？
d2 调用 Print 时，Print 怎么知道要打印 d2 的数据？
```


这就需要用到 **this 指针**。

------

## 二、this 指针时什么？

this 指针是C++编译器自动添加的一个隐藏指针。

它的作用是：

> 指向当前调用成员函数的对象。

比如：

```cpp
d1.Print();
```


调用时，this 指针就指向 d1。

所以成员函数能够通过 this 指针知道自己正在操作哪个对象。

------

## 三、this 指针的简单理解

假如有一个日期类：

```cpp
#include <iostream>
using namespace std;

class Date {
	public:
		void Init(int year, int month, int day) {
			_year = year;
			_month = month;
			_day = day;
		}
		
		void Print() {
			cout << _year << "-" << _month << "-" << _day << endl;
		}
	
	private:
		int _year;
		int _month;
		int _day;
};

int main() {
	Date d1;
	Date d2;
	
	d1.Init(2024, 5, 1);
	d2.Init(2025, 6, 1);
	
	d1.Print();
	d2.Print(); 
	
	return 0;
}
```

运行结果：

```cpp
2024-5-1
2025-6-1
```


虽然 d1 和 d2 调用的是同一个 Init 和 Print 函数，单手函数内部能区分不同的对象，就是因为调用成员函数时会自动传入当前对象的地址。

------

## 四、this 指针的底层理解

成员函数中访问成员变量时，其实隐含了 this->。

例如：

```cpp
void Print() {
    cout << _year << "-" << _month << "-" << _day << endl;
}
```


可以理解为：

```cpp
void Print() {
    cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
}
```


也就是说：

```cpp
_year
```


本质上是：

```cpp
this->_year
```


只不过平时编译器帮我们省略了 this->。

------

## 五、this 指针不能在参数列表中显示写出

this 指针是编译器自动传递的，我们不能再成员函数参数列表中手动写出来。

错误写法：

```cpp
class Date {
	public:
		void Print(Date* this) {    // 错误
			
		}
};
```

正确写法：

```cpp
class Date {
	public:
		void Print() {
			cout << this << endl;
		}
};
```

在成员函数内部，可以直接使用 this 指针。

------

## 六、this 指针解决成员变量和形参同名的问题

如果成员变量和函数参数同名，可以用 this-> 区分。

例如：

```cpp
class Date {
	public:
		void Init(int year, int month, int day) {
			this->year = year;
			this->month = month;
			this->day = day;
		}
	
	private:
		int year;
		int month;
		int day;
};
```

这里：

```cpp
this->year
```


表是成员变量。

而右边的：

```cpp
year
```


表示函数参数。

不过实际写代码时，很多人会把成员变量命名为：

```cpp
_year
_month
_day
```


这样可以减少命名冲突。

例如：

```cpp
void Init(int year, int month, int day) {
    _year = year;
    _month = month;
    _day = day;
}
```


这种写法更常见，也更清楚。

------

## 七、对象访问和指针访问

普通对象访问时，使用点运算符：

```cpp
Date d;
d.Print();
```


对象指针调用成员函数时，是用箭头运算符：

```cpp
Date* p = &d;
p->Print();
```


这里：

```cpp
p->Print();
```

等价于：

```cpp
(*p).Print();
```


因为 p 是指针，所以必须先解引用得到对象，再调用成员函数。

------

## 八、空指针调用成员函数问题

来看一个特殊情况：

```cpp
class A {
    public:
        void Print() {
            cout << "Print()" << endl;
        }
};

int main() {
    A* p = nullptr;
    p->Print();

    return 0;
}
```


这段代码有些情况下可能不会崩溃。

原因是：

> Print 函数没有访问成员变量。

成员函数代码存放在公共代码区，调用函数本身不一定需要访问对象中的数据。

但是如果成员函数访问了成员变量：

```cpp
class A {
    public:
        void Print() {
            cout << _a << endl;
        }

    private:
        int _a;
};

int main() {
    A* p = nullptr;
    p->Print();

    return 0;
}
```


这时很可能会崩溃。

因为 p 是空指针，传给 this 的也是空地址，函数内部访问：

```cpp
this->_a
```


就相当于通过空指针访问成员变量，这是非法的。

所以可以总结为：

```cpp
空指针调用成员函数不一定立即崩溃
但如果函数内部访问成员变量，就会通过空 this 之指针访问数据，通常会崩溃
```


实际写代码时，不应该用空指针调用成员函数。

------

## 九、this 指针存在哪里？

this 指针本质上是成员函数的一个隐藏形参。

既然是函数参数，他通常会随着函数调用进入栈帧。

不过一些编译器中，this 指针可能会通过寄存器传递，比如 VS 中可能通过 exc 寄存器传递。

这一点了解即可，初学阶段重点掌握：

> this 指针是编译器自动传递的，指向当前对象。

------

## 十、小结

本篇主要学习了C++中的 this 指针。

需要记住：

1. this 指针是编译器自动添加的隐藏指针；
2. this 指针指向当前调用成员函数的对象；
3. 成员函数中访问成员变量，本质上是通过 this 指针访问；
4. this 指针不能在函数参数列表中显示写出；
5. 在成员函数内部可以使用 this->成员变量；
6. 对象调用成员函数用 .；
7. 对象指针调用成员函数用 ->；
8. 空指针调用成员函数不一定立即崩溃，但访问成员变量通常会崩溃。

this 指针是理解C++类和对象的重要基础。理解它之后，就能明白为什么多个对象共享同一份成员函数代码，但成员函数之间仍能正确访问不同对象的数据。