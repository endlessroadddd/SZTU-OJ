#  三维坐标点的平移（运算符重载）

## 题目描述

定义一个三维点Point类，利用友元函数重载"++"和"--"运算符，并区分这两种运算符的前置和后置运算。

要求如下：
1. 实现Point类；
2. 编写main函数，初始化1个Point对象，将这个对象++或--后赋给另外一个对象，并输出计算后对象的坐标信息。

## 输入

第1行：输入三个int类型的值，分别为一个Point对象p1的x,y,z坐标。

## 输出

第1行：Point对象p1后置++之后的坐标信息输出。
第2行：Point对象p1后置++操作后赋给另外一个Point对象p2的坐标信息。
第3行开始，依次输出前置++，后置--，前置--运算的坐标信息，输出格式与后置++一样。

## 样例输入
```
10 20 30
```

## 样例输出
```
x=11 y=21 z=31
x=10 y=20 z=30
x=11 y=21 z=31
x=11 y=21 z=31
x=9 y=19 z=29
x=10 y=20 z=30
x=9 y=19 z=29
x=9 y=19 z=29
```
## 代码
```c++
#include <iostream>
using namespace std;

class Point {
private:
    int x, y, z;
public:
    Point(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

    friend Point& operator++(Point& qian);
    friend Point operator++(Point& hou, int);
    friend Point& operator--(Point& qian);
    friend Point operator--(Point& hou, int);

    void show() {
        cout << "x=" << x << ' ' << "y=" << y << ' ' << "z=" << z << endl;
    }
};

// 前置递增
Point& operator++(Point &qian) {
    qian.x++;
    qian.y++;
    qian.z++;
    return qian;
}

// 后置递增
Point operator++(Point &hou, int) {
    Point temp = hou;
    ++hou;
    return temp;
}

// 前置递减
Point& operator--(Point &qian) {
    qian.x--;
    qian.y--;
    qian.z--;
    return qian;
}

// 后置递减
Point operator--(Point &hou, int) {
    Point temp = hou;
    --hou;
    return temp;
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    Point p1(x, y, z), p2;

    // 后置++
    p2 = p1++;
    p1.show(); // 输出修改后的 p1
    p2.show(); // 输出修改前的 p1

    // 恢复 p1 原始值并前置++
    p1 = Point(x, y, z);
    p2 = ++p1;
    p1.show();
    p2.show();

    // 恢复 p1 原始值并后置--
    p1 = Point(x, y, z);
    p2 = p1--;
    p1.show();
    p2.show();

    // 恢复 p1 原始值并前置--
    p1 = Point(x, y, z);
    p2 = --p1;
    p1.show();
    p2.show();

    return 0;
}
