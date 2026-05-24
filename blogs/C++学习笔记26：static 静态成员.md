# C++学习笔记26：static 静态成员

## 一、为什么需要静态成员？

在C++中，普通成员变量是属于每个对象的。

例如：

```cpp
class A {
	private:
		int _a;
}; 
```

如果多创建几个对象：

```cpp
A a1;
A a2;
A a3;
```

那么这几个对象都有自己独立的 _a。

但是有些数据不应该只属于某一个对象，应该属于整个类。

比如想统计一共创建了多少个对象，就可以使用静态成员变量。

------

## 二、静态成员变量

静态成员变量使用 static 修饰。

例如：

```cpp
class A {
	public:
		A() {
			++_count;
		}
	private:
		static int _count;
};
```

这里 _count 是静态成员变量。

它不属于某一个具体的对象，而是属于整个类。

也就是说：

```cpp
所有 A 类对象共享同一个 _count
```

------

## 三、静态成员变量需要类外定义

静态成员变量虽然在类中声明，还需要在类外定义。

```cpp
class A {
	private:
		static int _count;
}; 

int A::_count = 0;
```

注意：

```cpp
static int _count;
```

这只是声明。

```cpp
int A::_count = 0;
```

这才是定义和初始化。

如果只在类中声明，没有在类外定义，可能会出现来连接错误。

------

## 四、用静态成员变量统计对象个数

示例：

```cpp
#include <iostream>
using namespace std;

class A {
	public:
		A() {
			++_count;
		}
		
		A(const A& a) {
			++_count;
		} 
		
		static int GetCount() {
			return _count;
		}
		
	private:
		static int _count;
}; 

int A::_count = 0;

int main() {
	A a1;
	A a2;
	A a3(a1);
	
	cout << A::GetCount() << endl;
	
	return 0;	
}
```

运行结果：

```cpp
3
```

这里创建了 a1、a2，又用 a1 拷贝了 a3，所以构造了 3 个对象。

静态成员变量 _count 被所有对象共享，可以用来统计对象数量。

------

## 五、静态成员变量不占对象空间

普通成员变量属于对象，会影响对象大小。

但是静态成员变量属于类，存放在静态区，不存放在对象内部。

例如：

```cpp
class A {
	private:
		int _a;
        static int _count;
};
```

这里对象只存 _a，不存 _count。

所以静态成员变量不会增加对象的大小。

------

## 六、静态成员函数

静态成员函数也使用 static 修饰。

例如：

```cpp
class A {
	public:
		static int GetCount() {
			return _count;
		}
		
	private:
		static int _count;
}; 
```

静态成员函数可以通过类名直接调用。

```cpp
A::GetCount();
```

不需要先创建对象。

------

## 七、静态成员函数没有 this 指针

普通成员函数调用时，会隐含传递 this 指针。

但是静态成员函数不属于某一个具体的对象，所以没有 this 指针。

错误示例：

```cpp
class A {
    public:
        static void Func() {
            cout << _a << endl; // 错误
        }

    private:
        int _a;
};
```

因为 _a 是普通成员变量，必须依赖具体对象存在。

而静态成员函数没有 this 指针，不知道一概访问哪个对象的 _a。

------

## 八、静态成员函数可以访问静态成员

静态成员函数可以直接访问静态成员变量。

```cpp
#include <iostream>
using namespace std;

class A {
	public:
		static int GetCount() {
			return _count;
		}

	private:
		static int _count;
}; 
```

因为 _count 属于类，不属于某个对象，所以静态储层元函数可以访问它。

简单总结：

```cpp
静态成员函数可以访问静态成员；
静态成员函数不能直接访问非静态成员。
```

------

## 九、调用方式

静态成员函数有两种调用方式。

### 1. 通过类名调用

```cpp
A::GetCount();
```

这种方式更推荐，因为他能说明 GetCount 属于类本身。

### 2. 通过对象调用

```cpp
A a;
a.GetCount();
```

这种方式也可以，但不如类名调用清晰。

------

## 十、小结

本篇主要学习了C++中的 static 静态成员。

需要记住：

1. 静态成员变量使用 static 修饰；
2. 静态成员变量属于类，不属于某个对象；
3. 所有对象共享一个静态成员变量；
4. 静态成员变量需要在类外定义和初始化；
5. 静态成员变量不占对象空间；
6. 静态成员函数也使用 static 修饰；
7. 静态成员函数没有 this 指针；
8. 静态成员函数不能直接访问普通成员变量；
9. 静态成员函数可以直接访问静态成员变量；
10. 静态成员函数推荐通过类名调用。

static 静态成员适合用来保存和类整体相关的数据，例如对象计数、共享配置等。