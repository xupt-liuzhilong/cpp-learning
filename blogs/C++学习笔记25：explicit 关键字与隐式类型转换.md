# C++学习笔记25：explicit 关键字与隐式类型转换

## 一、什么是隐式类型转换？

在C++中，有些情况下编译器会自动进行类型转换。

比如：

```cpp
double d = 10;
```

这里 10 是 int 类型，但可以自动转换成 double 类型。

在类和对象中，构造函数也可能发生隐式类型转换。

例如：

```cpp
class Date {
	public:
	    Date(int year)
	        : _year(year)
	        , _month(1)
	        , _day(1)
	    {
	    }

	private:
	    int _year;
	    int _month;
	    int _day;
};
```

如果这样写：

```cpp
Date d = 2024;
```

编译器会把 2024 转换成一个 Date 对象。

可以理解为：

```cpp
Date d(2024);
```

这就是构造函数产生的隐式类型转换。

------

## 二、为什么会发生这种转换？

因为 Date 类中由一个单参数的构造函数。

```cpp
Date(int year)
```
他可以用一个 int 类型的数据构造出一个 Date 对象。

所以当写：

```cpp
Date d = 2024;
```

编译器会认为：

> 可以用 2024 构造一个 Date 对象。

这种方法虽然简单，但有时候也可能让代码含义不够清楚。

------

## 三、隐式类型转换的过程

代码：

```cpp
Date d = 2024;
```

大致可以理解为：

```cpp
先用 2024 构造一个临时 Date 对象
在用这个临时对象初始化 d
```

有些编译器可能会进行优化，直接构造 d ，但从语法理解上，可以先这样认为。

------

## 四、explicit 的作用

如果不希望构造函数发生隐式类型转换，可以使用 explicit 关键字。

写法：

```cpp
class Date {
	public:
	    explicit Date(int year)
	        : _year(year)
	        , _month(1)
	        , _day(1)
	    {
	    }

	private:
	    int _year;
	    int _month;
	    int _day;
};
```

加上 explicit 关键字后，瞎买你这种写法就不允许了：

```cpp
Date d = 2024;    //错误
```

必须显示构造：

```cpp
Date d(2024);     // 正确
```

也就是说：

> explicit 可以禁止构造函数发生隐式类型转换。

------

## 五、什么时候需要 explicit？

如果一个构造函数只有一个参数，或者其他参数都有默认值，就可能发生隐式类型转换。

例如：

```cpp
Date(int year)
```

或者：

```cpp
Date(int year, int month = 1, int day = 1)
```

这种构造函数都能支持类似：

```cpp
Date d = 2024;
```
如果这种转换容易遭阿成误解，就建议加 explicit。

例如：

```cpp
explicit Date(int year, int month = 1, int day = 1)
```

这样写可以让代码更明确。

------

## 六、C++11 后的花括号初始化

C++11 之后，支持花括号初始化。

```cpp
Date d1{2024};
Date d2{2024, 5, 1};
```

也可能出现这种写法：

```cpp
Date d = {2024, 5, 1};
```

如果构造函数加了 explicit，也会限制这种隐式类型转换。

所以 explicit 的作用就是让对象构造更明确，避免编译器会自动帮我们做一些不明显的转换。

------

## 七、小结

本篇主要学习了 explicit 关键字和隐式类型转换。

需要记住：

1. 单参数构造函数可能发生隐式类型转换；
2. Date d = 2024 可能会调用 Date(int year)；
3. 隐式转换可能生成临时对象；
4. explicit 可以禁止构造函数隐式类型转换；
5. 加了 explicit 后，应使用 Date d(2024) 这种显示写法；
6. 当构造函数可能造成歧义时，建议使用 explicit。