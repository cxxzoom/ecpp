//
// Created by doff on 2023/7/15.
//

#include <iostream>

#define CALL_WITH (a, b ,f(a > b ? a : b));

using namespace std;

void f(int num) {
    cout << endl << "f() : " << num << endl;
}


class Foo {
public:
    Foo() {

    };
    const int a = 1;
    const int b = 2;

    ~Foo() { callWithMax(this->a, this->b); };
    // enum hack
    enum {
        A = 5
    };
    char arr[A];

private:
    template<typename T>
    inline void callWithMax(const T &a, const T &b) {
        f(a > b ? a : b);
    }
};

void T(const Foo *f) {};

int main() {
    char arr[] = "David";
    for (const auto &n: arr) {
        cout << n << endl;
    }
    const char *const C = "123";
    const std::string Name("David");
    // err C = "999";
    cout << C << endl;
    cout << Name << endl;
    cout << size(arr);
    int a = 1, b = 0;
    CALL_WITH
    (++a, b);
    CALL_WITH
    (++a, b);

    cout << "-==========================-" << endl;
    Foo foo;

    std::string const name = "1";
//    name = 2;

}