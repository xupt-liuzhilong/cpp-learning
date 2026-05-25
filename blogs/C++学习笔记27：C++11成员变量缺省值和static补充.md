# C++学习笔记27：C++11成员变量缺省值和static补充

## 一、类内的成员变量可以给缺省值

在C++11之后，类中的非静态成员变量可以直接在声明的时候给缺省值。

例如：

```cpp
class Date {
	public:
		Date() {
			
		}
		
		void Print() const {
			cout <<  _year << "-" << _month << "-" << _day << endl;	
		}
		
	private:
		int _year = 2024;
		int _month = 1;
		int _day = 1;
};
```

这样创建对象时：

```cpp
Date d;
d.Print();
```

如果构造函数没有在初始化列表中显示初始化这些成员变量，那么他们就会使用类内给的缺省值。

运行结果：

```cpp
2024-1-1
```

------

## 二、类内给的是缺省值，不是真正的初始化

这里要注意：

```cpp
int _year = 2024;
```

他不是成员变量的真正定义和初始化。

成员变量真正被创建，是在对象创建时，也就是构造函数的初始化阶段。

类内的这个值，本质上是：

> 如果构造函数没有显式初始化，就用这个默认值。

所以它更准确的说是**缺省值**。

------

## 三、初始化列表优先级更高

如果构造函数初始化列表中显式初始化了这个成员变量，那么会优先使用初始化列表中的这个值。

例如：

```cpp
class Date {
	public:
		Date(int year, int month, int day) 
			: _year(year)
			, _month(month)
			, _day(day)
		{
		}
		
		void Print() const {
			cout <<  _year << "-" << _month << "-" << _day << endl;	
		}
		
	private:
		int _year = 2024;
		int _month = 1;
		int _day = 1;
};
```

创建对象：

```cpp
Date d(2024, 5, 1);
d.Print();
```

运行结果：

```cpp
2024-5-1
```

虽然类内给了：

```cpp
int _year = 2024;
int _month = 1;
int _day = 1;
```

但构造函数初始化列表中传入了新值，所以最终使用的是初始化列表中的值。

简单记：

```cpp
初始化列表有值，用初始化列表；
初始化列表没写，才用类内缺省值。
```

------

## 四、static成员变量不能这样初始化

非静态成员可以在类内给缺省值，但是 static 静态成员变量不可以这样定义。

错误写法：

```cpp
class A {
    private:
        static int _count = 0;    // 错误
);
```

原因是：

> static 成员变量属于整个类，不属于某一个对象。

他不存储在对象内部，卫视存储在静态区。

所以静态成员变量必须在类外单独定义和初始化。

正确写法：

```cpp
class A {
    private:
        static int _count;
);

int A::_count = 0;
```

这里：

```cpp
static int _count;
```

是类内声明。

```cpp
int A::_count = 0;
```

是类外定义和初始化。

------

## 五、静态成员函数补充

静态成员函数没有 this 指针。

所以它不能直接访问普通成员变量，也不能直接调用普通成员函数。

```cpp
class Date {
	public:
		Date(int year = 0) {
			_year = year;
		}
		
		void Print() const {
			cout << _year << endl;
		}
		
		static void Func() {
			Print();    // 错误
		}
		
	private:
		int _year;
};
```

这里因为静态成员函数没有 this 指针，但其实普通成员函数有 this 指针，所以在调用时静态成员函数相当于没有给普通成员函数传递 this 指针这个参数，会导致编译器报错。

相反的，普通成员函数可以调用静态成员函数：

```cpp
class Date {
	public:
		Date(int year = 0) {
			_year = year;
		}
		
		void Print() const {
			Func();
		}
		
		static void Func() {
			cout << "static" << endl;
		}
		
	private:
		int _year;
};
```

如果执行：

```cpp
Date d;
d.Func();
```

运行结果：

```cpp
static
```

说明普通成员函数成功调用了静态成员函数。

------

## 六、小结

本篇主要补充了C++11成员变量缺省值和 static 静态成员的相关细节。

需要记住：

1. C++11之后，非静态成员变量是可以在类内给缺省值；
2. 类内给的是缺省值，不是真正的初始化；
3. 成员变量真正初始化发生在构造函数初始化阶段；
4. 初始化列表有值时，优先使用初始化列表；
5. static 成员变量属于类，不属于对象；
6. static 成员变量需要在类内声明，类外定义和初始化；
7. 静态成员函数没有 this 指针；
8. 静态成员函数不能调用普通成员函数；
9. 普通成员函数可以调用静态成员函数。