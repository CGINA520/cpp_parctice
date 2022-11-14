#include <iostream>
using namespace std;

//一、立方体类：
/*class Cube
{
public:
    void set_long(int l);
    int get_long();
    void set_width(int w);
    int get_width();
    void set_high(int h);
    int get_high();
    int CaculateS();
    int CaculateV();
    //利用成员函数判断两个立方体是否相等：
    bool Is_same(Cube &c); //函数声明

private:
    int Long;
    int Width;
    int High;
};
void Cube::set_long(int l)
{
    Long = l;
}
int Cube::get_long()
{
    return Long;
}
void Cube::set_width(int w)
{
    Width = w;
}
int Cube::get_width()
{
    return Width;
}
void Cube::set_high(int h)
{
    High = h;
}
int Cube::get_high()
{
    return High;
}
int Cube::CaculateS()
{
    cout << "立方体的面积为" << endl;
    return 2 * (Long * Width + Long * High + Width * High);
}
int Cube::CaculateV()
{
    cout << "立方体的体积为：" << endl;
    return Long * Width * High;
}
bool Cube::Is_same(Cube &c) //成员判断函数的定义
{
    if (Long == c.get_long() && Width == c.get_width() && High == c.get_high())
    {
        return true;
    }
    return false;
}

//利用全局函数判断两个立方体是否相等：
bool Is_same(Cube &c1, Cube &c2)
{
    if (c1.get_long() == c2.get_long() && c1.get_width() == c2.get_width() && c1.get_high() == c2.get_high())
    {
        return true;
    }
    return false;
}
int main()
{
    Cube c1;
    c1.set_long(10);
    c1.set_width(10);
    c1.set_high(10);
    cout << c1.CaculateS() << endl;
    cout << c1.CaculateV() << endl;
    Cube c2;
    c2.set_long(15);
    c2.set_width(10);
    c2.set_high(20);
    cout << c2.CaculateS() << endl;
    cout << c2.CaculateV() << endl;
    //用全局函数判断：
    bool ret = Is_same(c1, c2);
    if (ret)
    {
        cout << "c1和c2是相等的" << endl;
    }
    else
    {
        cout << "c1和c2不相等" << endl;
    }
    //用成员函数判断：
    ret = c1.Is_same(c2);
    if (ret)
    {
        cout << "c1和c2是相等的" << endl;
    }
    else
    {
        cout << "c1和c2不相等" << endl;
    }
    system("pause");
    return 0;
}*/

//二、点和圆的关系：
//点类：
class Point
{
public:
    void set_x(int x);
    int get_x();
    void set_y(int y);
    int get_y();

private:
    int m_X;
    int m_Y;
};
void Point::set_x(int x)
{
    m_X = x;
}
int Point::get_x()
{
    return m_X;
}
void Point::set_y(int y)
{
    m_Y = y;
}
int Point::get_y()
{
    return m_Y;
}

//圆类：
class Circle
{
public:
    void set_r(int r);
    int get_r();
    void set_center(Point center);
    Point get_center()
    {
        return m_Center;
    }

private:
    int m_R;
    Point m_Center;
};
void Circle::set_r(int r)
{
    m_R = r;
}
int Circle::get_r()
{
    return m_R;
}
void Circle::set_center(Point center)
{
    m_Center = center;
}

//判断点和圆的关系：
void isInCircle(Circle &c, Point &p)
{
    //计算两点的距离平方：
    int pdistence =
        (c.get_center().get_x() - p.get_x()) * (c.get_center().get_x() - p.get_x()) +
        (c.get_center().get_y() - p.get_y()) * (c.get_center().get_y() - p.get_y());
    //计算半径的平方：
    int rdistence = (c.get_r()) * (c.get_r());
    //判断：
    if (pdistence == rdistence)
    {
        cout << "点在圆上！" << endl;
    }
    else if (pdistence > rdistence)
    {
        cout << "点在圆外！" << endl;
    }
    else
    {
        cout << "点在圆内！" << endl;
    }
}

int main()
{
    //创建一个圆：
    Circle c;
    c.set_r(10);
    Point center;
    center.set_x(10);
    center.set_y(0);
    c.set_center(center);
    //创建一个点：
    Point p;
    p.set_x(10);
    p.set_y(9);
    //判断关系：
    isInCircle(c, p);
    system("pause");
    return 0;
}