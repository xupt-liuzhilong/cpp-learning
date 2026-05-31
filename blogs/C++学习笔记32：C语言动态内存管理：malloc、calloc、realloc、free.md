# C++学习笔记32：C语言动态内存管理：malloc、calloc、realloc、free

## 一、为什么需要动态内存管理？

前面学习内存区域时已经知道，程序运行时大致有：

```cpp
栈区
堆区
数据段
代码段
```

其中，普通局部变量一般在栈上。

例如：

```cpp
int a = 10;
int arr[10];
```

这些变量的空间由系统自动管理，函数结束后自动释放。

但是有些时候，程序需要在运行过程中根据实际情况申请空间，例如：

```cpp
用户输入多少数据，程序就申请多大空间
链表节点需要一个一个创建
顺序表容量不够时需要扩容
树的节点需要动态创建
```

这些情况就需要使用**动态内存管理**。

C语言中，动态内存主要通过下面几个函数完成：

```cpp
malloc
calloc
realloc
free
```

这些函数申请出来的空间都在**堆区**。

------

## 二、malloc函数

`malloc` 用来向堆区申请一块指定大小的空间。

基本格式：

```cpp
void* malloc(size_t size);
```

例如，申请一个 `int` 类型大小的空间：

```cpp
int* p = (int*)malloc(sizeof(int));
```

申请 10 个 `int` 的空间：

```cpp
int* p = (int*)malloc(sizeof(int) * 10);
```

需要注意：

```
malloc 的参数是字节数
malloc 返回值是 void*
malloc 不会初始化空间
malloc 申请失败会返回 NULL
```

所以使用时最好判断一下：

```cpp
int* p = (int*)malloc(sizeof(int) * 10);

if (p == NULL)
{
    perror("malloc fail");
    return;
}
```

`malloc` 只负责申请空间，不负责初始化。

也就是说，申请出来的空间里面可能是随机值。

------

## 三、free函数

`malloc` 申请的空间用完以后，必须使用 `free` 释放。

```cpp
int* p = (int*)malloc(sizeof(int) * 10);

free(p);
p = NULL;
```

释放以后，建议把指针置空：

```cpp
p = NULL;
```

这样可以避免后面继续使用已经释放的空间。

如果只申请不释放，就可能造成**内存泄漏**。

例如：

```cpp
void Func()
{
    int* p = (int*)malloc(sizeof(int) * 10);
}
```

这里 `p` 是局部指针变量，函数结束后 `p` 会销毁。

但是 `malloc` 申请出来的堆空间不会自动释放。

这时就找不到那块堆空间了，造成内存泄漏。

------

## 四、calloc函数

`calloc` 也用于动态申请空间。

基本格式：

```cpp
void* calloc(size_t num, size_t size);
```

它的含义是：

```cpp
申请 num 个元素
每个元素大小是 size 字节
```

例如：

```cpp
int* p = (int*)calloc(10, sizeof(int));
```

表示申请 10 个 `int` 大小的空间。

`calloc` 和 `malloc` 最大的区别是：

```cpp
malloc 只申请空间，不初始化
calloc 申请空间，并把空间初始化为 0
```

例如：

```cpp
int* p1 = (int*)malloc(sizeof(int) * 10);
int* p2 = (int*)calloc(10, sizeof(int));
```

`p1` 指向的空间内容不确定。

`p2` 指向的空间内容会被初始化为 0。

使用完后同样需要释放：

```cpp
free(p2);
p2 = NULL;
```

------

## 五、realloc函数

`realloc` 用来调整已经申请好的动态空间大小。

基本格式：

```cpp
void* realloc(void* ptr, size_t size);
```

例如：

```cpp
int* p = (int*)malloc(sizeof(int) * 4);
```

一开始申请了 4 个 `int` 的空间。

如果后面不够用了，想扩容到 10 个 `int`：

```cpp
int* tmp = (int*)realloc(p, sizeof(int) * 10);
```

使用 `realloc` 时，建议不要直接写成：

```cpp
p = (int*)realloc(p, sizeof(int) * 10);
```

更推荐写成：

```cpp
int* tmp = (int*)realloc(p, sizeof(int) * 10);

if (tmp == NULL)
{
    perror("realloc fail");
}
else
{
    p = tmp;
}
```

原因是：如果 `realloc` 申请失败，会返回 `NULL`。

如果直接把结果赋给 `p`，原来那块空间的地址就丢了，可能造成内存泄漏。

------

## 六、realloc扩容的两种情况

`realloc` 扩容时，大致有两种情况。

### 1. 原地扩容

如果原空间后面还有足够的连续空间，`realloc` 可能直接在原位置扩容。

这时返回的地址和原来的地址相同。

------

### 2. 异地扩容

如果原空间后面没有足够空间，`realloc` 会重新找一块更大的空间。

大致过程是：

```cpp
重新申请一块更大的空间
把原空间数据拷贝过去
释放原来的空间
返回新空间地址
```

这时返回的新地址可能和原地址不同。

所以使用 `realloc` 后，要用返回值更新指针。

------

## 七、malloc、calloc、realloc对比

| 函数      | 作用             | 是否初始化           | 是否需要free |
| --------- | ---------------- | -------------------- | ------------ |
| `malloc`  | 申请指定字节空间 | 不初始化             | 需要         |
| `calloc`  | 申请多个元素空间 | 初始化为0            | 需要         |
| `realloc` | 调整已有空间大小 | 新增空间不一定初始化 | 需要         |

这三个函数申请出来的空间都在堆区。

只要是动态申请的空间，用完后都应该释放。

------

## 八、链表节点中的应用

动态内存管理最典型的应用就是链表。

例如定义一个链表节点：

```cpp
struct ListNode
{
    int val;
    struct ListNode* next;
};
```

在 C 语言中创建一个节点，通常这样写：

```cpp
struct ListNode* node =
    (struct ListNode*)malloc(sizeof(struct ListNode));

if (node == NULL)
{
    perror("malloc fail");
    return;
}

node->val = 1;
node->next = NULL;
```

这里要注意：

```cpp
malloc 只申请空间
不会自动初始化 val 和 next
所以必须手动给成员变量赋值
```

用完后释放：

```cpp
free(node);
node = NULL;
```

这就是 C 语言中创建动态节点的基本方式。

------

## 九、使用动态内存时的常见错误

### 1. 忘记释放

```cpp
int* p = (int*)malloc(sizeof(int) * 10);
```

如果后面没有：

```cpp
free(p);
```

就会造成内存泄漏。

------

### 2. 重复释放

```cpp
free(p);
free(p); // 错误
```

同一块空间不能释放两次。

释放后建议：

```cpp
p = NULL;
```

------

### 3. 释放后继续使用

```cpp
free(p);
*p = 10; // 错误
```

`free` 之后，`p` 指向的空间已经不属于当前程序继续使用的有效空间。

------

### 4. 越界访问

```cpp
int* p = (int*)malloc(sizeof(int) * 10);

p[10] = 1; // 错误
```

如果申请了 10 个 `int`，合法下标是：

```cpp
0 ~ 9
```

访问 `p[10]` 就越界了。

------

## 十、小结

本篇主要学习了 C 语言中的动态内存管理。

需要记住：

1. 动态申请的空间在堆区；
2. `malloc` 按字节申请空间，不初始化；
3. `calloc` 申请空间，并初始化为 0；
4. `realloc` 用于调整已有动态空间大小；
5. `free` 用来释放动态申请的空间；
6. `malloc/calloc/realloc` 申请失败会返回 `NULL`；
7. `realloc` 建议用临时指针接收返回值；
8. `malloc` 创建结构体节点后，需要手动初始化成员变量；
9. 动态申请的空间用完后必须释放；
10. 常见错误有内存泄漏、重复释放、释放后继续使用、越界访问。

C 语言的动态内存管理比较灵活，但也比较容易出错。后面学习 C++ 的 `new/delete` 时，就能看到 C++ 在动态内存管理上对 C 语言做了进一步改进。