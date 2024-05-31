// 包含标准输入输出流库
#include<iostream>
// 包含格式化输入输出库
#include<iomanip>
// 使用标准命名空间
using namespace std;

// 创建一个形状基类
class Shape {
public:
    // 定义一个虚函数，用来计算面积
    virtual double area() { // 父类虚函数，用于计算面积
        return 0;
    }
};

// 创建一个圆形类，继承自形状类
class Circle : public Shape {
    double r; // 圆的半径
public:
    Circle(double r1) { // 构造函数，初始化半径
        r = r1;
    }
    double area() { // 重写面积函数，计算圆的面积
        return 3.14 * r * r;
    }
};

// 创建一个正方形类，继承自形状类
class Square : public Shape {
    double length; // 正方形的边长
public:
    Square(double length1) { // 构造函数，初始化边长
        length = length1;
    }
    double area() { // 重写面积函数，计算正方形的面积
        return length * length;
    }
};

// 创建一个矩形类，继承自形状类
class Rectangle : public Shape {
    double length, width; // 矩形的长和宽
public:
    Rectangle(double l, double w) { // 构造函数，初始化长和宽
        length = l;
        width = w;
    }
    double area() { // 重写面积函数，计算矩形的面积
        return length * width;
    }
};

int main() {
    int t; // 测试次数
    cin >> t;
    while (t--) {
        Shape* p[3]; // 创建形状指针数组
        double r, l, w;
        cin >> r; // 输入圆的半径
        Circle c(r);
        p[0] = &c; // 将圆形对象的地址赋给指针数组
        cin >> l; // 输入正方形的边长
        Square s(l);
        p[1] = &s; // 将正方形对象的地址赋给指针数组
        cin >> w; // 输入矩形的宽
        Rectangle r(r, w);
        p[2] = &r; // 将矩形对象的地址赋给指针数组
        for (int i = 0; i < 3; i++) {
            // 输出每个形状的面积，保留两位小数
            cout << fixed << setprecision(2) << p[i]->area() << endl; // 输出面积结果
        }
    }
}

