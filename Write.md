# write something...

## cpp
cpp = c + object-Oriented c++ + Template + STL
1. c : 
2. object-Oriented c++ : 
3. Template : 
4. STL :

## website
1. boots.org

## explicit
```txt
被explicit 修饰的类可以避免被隐式转换，但是仍可以被显式转换
被声明为explicit的构造函数禁止编译器进行非预期类型的转换。
```

## undefined behavior
1. int* p = 0; std::cout << *p;
2. char arr[] = "David"; char c = arr[10]; // 注意 arr 末尾还有个 null
```cpp

#include <iostream>
using namespace std;

int main()
{
    char arr[] = "David";
    for (auto &n : arr){
        cout << n << endl;
    }
    
    cout << size(arr);
    
    /**
     * D
     * a
     * v
     * i
     * d
     * 
     * 6
     */
    // 这说明后面还有个null
}
```




## class
1. 定义一般写在头文件里