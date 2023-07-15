/**
 * explicit 可以避免类被隐式转换
 */
#include <iostream>

class Foo{
public:
    Foo();
    ~Foo();
};

int x;

std::size_t numD(int number){
    int d = 1;
    while((number /=10) != 0) ++d;
    return d;
}

template<typename T>
class tpl{
    tpl();
    ~tpl();
};

class A{
public:
    A();
};

class B{
public:
    explicit B(int x = 0 , bool b = true); // default 构造函数
};

class C{
public:
    explicit C(int x); // 并非构造函数。我想应该是这个构造函数没有赋初值
};

void doSomething(B b){}; // 接受一个 类型为 B 的对象

// copy 构造函数
class Wid{
public:
    Wid();                  // default构造函数
    Wid(const Wid& rts);    // copy 构造函数
    Wid& operator=(const Wid& rts); // copy assignment 操作符
};


int main()
{
    B b;
    doSomething(b);
    // err doSomething(28)
    doSomething(B(28));
    Wid w;     // 调用构造函数
    Wid w1(w); // 调用copy 构造函数
    w = w1;    // 调用copy assignment 操作符
    return 0;
}