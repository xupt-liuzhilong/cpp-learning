# C++学习笔记11：范围 for 和 nullptr

## 一、范围 for 是什么？

范围 for 是 C++11 引入的一种遍历方式。

它可以让我们更方便的便利数组或容器。

传统遍历数组时，一般这样写：

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}
```

使用范围 for 后，可以更简单：

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    
    for (auto e : arr) {
        cout << e << " ";
    }
    
    return 0;
}
```

运行结果：

```cpp
1 2 3 4 5
```

---

## 二、范围 for 的基本格式

范围for的基本格式是：

```cpp
for (变量 : 遍历对象) {
    // 循环体
}
```

例如：

```cpp
for (auto e : arr) {
    cout << e << endl;
}
```

这里的 `e` 会依次获得数组 `arr`中的每一个元素。

使用 `auto` 可以让编译器自动推导元素类型。

---

## 三、范围 for 修改数组元素

需要注意，如果这样写：

```cpp
for (auto e : arr) {
    e *= 2;
}
```

这种语法不能真正实现修改数组中的元素。

因为 `e` 是数组元素的一份拷贝。

例如：

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    
    for (auto e : arr) {
        e *= 2;
    }
    
    for (auto e : arr) {
        cout << e << " ";
    }
    
    return 0;
}
```

运行结果：

```cpp
1 2 3 4 5
```

可以看到，数组的内容没有改变。

如果想要修改数组的内容，需要使用：

```cpp
for (auto& e: arr) {
    e *= 2;
}
```

完整代码：

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    
    for (auto& e : arr) {
        e *= 2;
    }
    
    for (auto e : arr) {
        cout << e << " ";
    }
    
    return 0;
}
```

运行结果：

```cpp
2 4 6 8 10
```

所以要记住：

```cpp
for (auto e : arr)	// e 是拷贝
for (auto& e : arr)	// e 是引用，可以修改原元素
```

---

## 四、范围 for 的使用限制

范围 for 虽然方便，但也有一些限制。

它适合用来遍历：

```txt
数组
字符串
STL 容器
```

比如以后学习 `vector` 时，可以这样写：

```cpp
vector<int> v = {1, 2, 3, 4, 5};

for (auto e : v) {
    cout << e << " ";
}
```

但是如果数组退化成指针，就不能直接使用范围 for。

例如：

```cpp
void Print(int arr[]) {
    for (auto e : arr){	// 错误
        cout << e << " ";
    }
}
```

因为函数参数中的数组本质上已经退化成指针，编译器无法知道数组的范围。

---

## 五、nullptr 是什么？

在C语言中，我们常用 `NULL` 表示空指针。

例如：

```cpp
int* p = NULL;
```

在C++11中，更推荐使用：

```cpp
int* p = nullptr;
```

`nullptr` 是C++11引入的空指针关键字，专门表示空指针。

---

## 六、为什么不用 NULL？

在C++中，`NULL` 本质上就是一个宏，很多情况下被定义为 `0`。

这就可能导致函数重载时出现问题。

例如：

```cpp
#include <iostream>
using namespace std;

void func(int) {
    cout << "func(int)" << endl;
}

void func(int*) {
    cout << "func(int*)" << endl;
}

int main() {
    func(0);
    func(NULL);;
    
    return 0;
}
```

`func(0)` 会调用 `func(int)`。

而 `NULL` 很多情况下也被当成 `0`，所以 `func(NULL)` 也可能调用 `func(int)`，而不是我们想要的指针版本。

这就容易产生歧义。

---

## 七、nullptr 的优势

使用 `nullptr` 就可以明确表示这是一个空指针。

例如：

```cpp
#include <iostream>
using namespace std;

void func(int) {
    cout << "func(int)" << endl;
}

void func(int*) {
    cout << "func(int*)" << endl;
}

int main() {
    func(nullptr);;
    
    return 0;
}
```

运行结果：

```cpp
func(int*)
```

因为 `nullptr` 的类型是专门的空指针类型，可以精准的陪陪指针参数。

所以在C++中，建议使用：

```cpp
int* p = nullptr;
```

而不是：

```cpp
int* p = NULL;
```

---

## 八、小结

本篇主要学习了C++11中的范围 for 和 `nullptr`。

范围 for 需要记住：

1. 范围 for 可以简化数组和容器遍历；
2. `for(auto e : arr) `中的 e 是元素拷贝；
3. 如果要修改原元素，需要写 `for(auto& e : arr)`；
4. 数组退化成指针后，不能直接使用范围 for。

`nullptr` 需要记住：

1. `nullptr` 时C++11推荐使用的空指针；
2. `NULL` 在C++中可能会被当成整数 `0`；
3. 函数重载时，`NULL` 可能匹配到整数版本；
4. `nullptr` 能更明确的表示空指针；
5. C++中建议使用 `nullptr`，少用 `NULL`。