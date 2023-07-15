# ecpp
learn rule about Effective cpp 3rd


```
侯捷：世上没有白吃的午餐!又要有效率，又要有弹性，又要前瞻望远，又要回溯相容，又要治大国，又要烹小鲜，学习起来当然就不可能太简单。在庞大复杂的机制下，万千使用者前仆后继的动力是: 一旦学成，妙用无穷。
```

###   1.让自己习惯c++
```text
c++ 是 c object-Oriented c++  template  STL 组成

c part: 区块，语句，预处理器，内置数据类型，指针，数组...都来自与c。

object-Oriented c++ part: classes,封装，继承，多态，重载，虚函数...

template part: 泛型编程

STL part: template 程序库,容器，迭代器，算法，函数对象...
```
### 2. enum，const, inline 代替 #define
```txt
单纯的常量以 enum，const来替换#defines
// reason
    在编译之前，常量的#define就被预处理器替换成了常量值，并且不会记录进符号表（symbol table）。
    所以在编译时，可能出现 令人困惑，不知哪里来的 的常量。增加心智负担。
    而且使用宏定义常量，可抗导致目标吗出现多份，而const 就不会
    
    特别的： 
    1.定义常量指针时，需要将指针定义为const，exp: const char* const Name = "David";
    // 第一个是将指针定义为 const，第二次是将变量定义为const
    // 好吧，其实它是 char*_based 类型，可以替换成 const std::string Name("David");
    2. 类常量： 在类中的作用域中定义常量。 
    class Foo{ 
        const std::string Name = "doff"; //这里是声明式
    };
    
    // 怎么让这个类常量只有一份呢？ static const std::string Name = "doff";
    notice: #define 不能限制变量的作用域，直到被#undef。不能定义 类的专属常量，也不能提供封装，比如private #define ...
    
    可能会到这种写法：
    class Foo{
        // enum hack
        enum { A = 5};
        char arr[A];
    };
    // 对enum 或者 #define 取地址是不合法的
    void f(int num){
        std::cout << num << endl;
        return ;
    }
    class Foo{
        template<template T>
        inline void callWithMax(T& a, T& b){
            f(a > b ? a : b);
        }
    };
函数形式的宏，用inline替换#defines
// reason
    
```