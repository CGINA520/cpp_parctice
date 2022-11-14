// #include <iostream>
// #include <string>
// using namespace std;

//项目中一般不用这种方式
//练习中为了方便可使用
//项目中指定命名空间访问+展开常用
// eg:
// std::cout<<"hello world !"<<std::endl;
//展开常用eg:
// using std::cout;
// using std::endl;

//设置一个圆类，求其周长：
/*const double PI = 3.14;
class Circle
{
public:
    int r;
    double Caculate()
    {
        return 2 * PI * r;
    }
};

int main()
{
    Circle c;
    c.r = 1;
    cout << c.Caculate() << endl;
    system("pause");
    return 0;
}*/

//简单的学生类：
/*class student
{
public:
    void setstudent(string name, string id);
    void show_student();

private:
    string Name;
    string Id;
};
void student::setstudent(string name, string id)
{
    Name = name;
    Id = id;
}
void student::show_student()
{
    cout << "姓名：" << Name << endl;
    cout << "学号： " << Id << endl;
}

int main()
{
    student s1;
    s1.setstudent("张三", "21121121");
    s1.show_student();
    system("pause");
    return 0;
}*/

//简单的人类：
/*class Person
{
public:
    void set_name(string name)
    {
        Name = name;
    }
    void set_age(int age)
    {
        Age = age;
    }
    void set_lover(string lover)
    {
        Lover = lover;
    }
    void Show()
    {
        cout << "姓名是： " << Name << endl;
        cout << "年龄是： " << Age << endl;
        cout << "爱人是： " << Lover << endl;
    }

private:
    string Name;
    int Age;
    string Lover;
};

int main()
{
    Person p1;
    p1.set_name("张三");
    p1.set_age(20);
    p1.set_lover("阿拉啦");
    p1.Show();
    system("pause");
    return 0;
}*/

// 浅拷贝与深拷贝
// class Person
// {
// public:
//     Person()
//     {
//         cout << "默认的构造函数调用：" << endl;
//     }
//     Person(int age, int height)
//     {
//         cout << "构造函数调用：" << endl;
//         m_Age = age;
//         m_Height = new int(height); //在堆区创建的变量必须由程序员自己释放
//     }
//     //自己定义深拷贝构造函数来解决浅拷贝的问题：
//     Person(const Person &p)
//     {
//         cout << "拷贝构造函数使用：" << endl;
//         m_Age = p.m_Age;
//         // m_Height = p.m_Height;//这是编译器默认生成的
//         //深拷贝：
//         m_Height = new int(*p.m_Height);
//     }
//     ~Person()
//     {
//         cout << "析构函数调用：" << endl;
//         //释放：
//         if (m_Height != NULL)
//         {
//             delete m_Height;
//             m_Height = NULL;
//         }
//     }

// public:
//     int m_Age;
//     int *m_Height;
// };

// void test01()
// {
//     Person p1;
//     Person p2(19, 180);
//     Person p3(p2); //浅拷贝带来的问题是堆区的内容重复释放!!!
//     cout << "p2 " << p2.m_Age << ' ' << *p2.m_Height << endl;
//     cout << "p3 " << p3.m_Age << " " << *p3.m_Height << endl;
// }

// int main()
// {
//     test01();
//     system("pause");
//     return 0;
//

// this指针
// class Person
// {
// public:
//     Person(int age)
//     {
//         this->age = age;
//     }
//     Person &Add_age(Person &p)
//     {
//         this->age += p.age;
//         return *this;
//     }
//     //如果返回值类型为Person，则结果为20，这是编译器会自动拷贝数据 P2',P2",P2'".而不是P2本身

//     // Person Add_age(Person &p)
//     // {
//     //     this->age += age;
//     //     return *this;
//     // }
//     int age;
// };

// void test01()
// {
//     Person p1(10);
//     cout << p1.age << endl;
// }

// void test02()
// {
//     Person p1(10);
//     Person p2(10);
//     //链式编程思想：
//     p2.Add_age(p1).Add_age(p1).Add_age(p1);
//     cout << p2.age << endl;
// }

// int main()
// {
//     test01();
//     test02();
//     system("pause");
//     return 0;
// }

//+ 运算符重载:
// class Person
// {
// public:
//     //成员函数重载 + 号：
//     // Person operator+(Person &p)
//     // {
//     //     Person tmp;
//     //     tmp.m_A = this->m_A + p.m_A;
//     //     tmp.m_B = this->m_B + p.m_B;
//     //     return tmp;
//     // }
//     void show();
//     int m_A;
//     int m_B;
// };
// void Person::show()
// {
//     cout << m_A << endl;
//     cout << m_B << endl;
// }
// //全局函数实现 + 重载：
// Person operator+(Person &p1, Person &p2)
// {
//     Person tmp;
//     tmp.m_A = p1.m_A + p2.m_A;
//     tmp.m_B = p1.m_B + p2.m_B;
//     return tmp;
// }
// //重载的版本：
// Person operator+(Person &p, int num)
// {
//     Person tmp;
//     tmp.m_A = p.m_A + num;
//     tmp.m_B = p.m_B + num;
//     return tmp;
// }

// void test01()
// {
//     Person p1;
//     p1.m_A = 10;
//     p1.m_B = 10;
//     Person p2;
//     p2.m_A = 10;
//     p2.m_B = 10;
//     Person p3;
//     //成员函数调用的本质：
//     // p3 = p1.operator+(p2);
//     //全局函数调用的本质:
//     // p3 = operator+(p1, p2);
//     p3 = p2 + p1;
//     //运算符重载可以发生重载：
//     Person p4 = p1 + 100;
//     p3.show();
//     p4.show();
// }

// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//左移运算符<<重载：
// class Person
// {
//     friend ostream &operator<<(ostream &cout, Person p);

// public:
//     Person(int a, int b)
//     {
//         m_a = a;
//         m_b = b;
//     }

// private:
//     //成员函数不可以重载左移运算符，因为p.operator<<(cout)写完后输出格式为p << cout:
//     int m_a;
//     int m_b;
// };

// //只能用全局函数重载<<运算符：
// ostream &operator<<(ostream &cout, Person p)
// {
//     cout << "m_a=" << p.m_a << ' ' << "m_b=" << p.m_b;
//     return cout;
// }

// void test01()
// {
//     Person p(10, 20);
//     //链式编程原理：
//     cout << p << endl;
// }

// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//递增运算符重载++：
// #include <iostream>
// using namespace std;

// class MyInteger
// {
//     friend ostream &operator<<(ostream &cout, MyInteger myint);

// public:
//     MyInteger()
//     {
//         m_num = 0;
//     }
//     //重载前置的++运算符：
//     //返回引用是为了返回自己你本身，从而实现多个++运算符运算的情况：
//     MyInteger &operator++()
//     {
//         //先加加，后返回；
//         ++m_num;
//         return *this;
//     }
//     //重载后置的++运算符：
//     //此时返回的是MyInteger,而不是其引用，因为函数使用后会释放，返回本身为非法操作：
//     //这里的int作为占位参数，区分前置与后置的++运算；
//     MyInteger operator++(int)
//     {
//         //先记录当前传入的值：
//         MyInteger tmp = *this;
//         //执行操作：
//         m_num++;
//         //返回记录的值：
//         return tmp;
//     }

// private:
//     int m_num;
// };

// //重载左移运算符：
// ostream &operator<<(ostream &cout, MyInteger myint)
// {
//     cout << myint.m_num;
//     return cout;
// }
// void test01()
// {
//     cout << "前置的++运算符使用中：" << endl;
//     MyInteger myint;
//     cout << ++myint << endl;
//     cout << myint << endl;
// }
// void test02()
// {
//     cout << "后置的++运算符使用中：" << endl;
//     MyInteger myint;
//     cout << myint++ << endl;
//     cout << myint << endl;
// }

// int main()
// {
//     test01();
//     test02();
//     system("pause");
//     return 0;
// }

//重载--运算符：
// #include <iostream>
// using namespace std;

// class MyInteger
// {
//     friend ostream &operator<<(ostream &cout, MyInteger myint);

// public:
//     MyInteger()
//     {
//         m_num = 10;
//     }
//     //重载前置的--运算符：
//     MyInteger &operator--()
//     {
//         --m_num;
//         return *this;
//     }
//     //重载后置的--运算符；
//     MyInteger operator--(int)
//     {
//         MyInteger tmp = *this;
//         m_num--;
//         return tmp;
//     }

// private:
//     int m_num;
// };

// //重载<<运算符：
// ostream &operator<<(ostream &cout, MyInteger myint)
// {
//     cout << myint.m_num;
//     return cout;
// }
// void test01()
// {
//     cout << "前置的--运算符使用中：" << endl;
//     MyInteger myint;
//     cout << --myint << endl;
//     cout << myint << endl;
// }

// void test02()
// {
//     cout << "后置的--运算符使用中：" << endl;
//     MyInteger myint;
//     cout << myint-- << endl;
//     cout << myint << endl;
// }

// int main()
// {
//     test01();
//     test02();
//     system("pause");
//     return 0;
// }

//赋值运算符=重载：
// #include <iostream>
// using namespace std;

// class Person
// {
// public:
//     Person(int age)
//     {
//         m_Age = new int(age);
//     }
//     ~Person()
//     {
//         if (m_Age != NULL)
//         {
//             delete m_Age;
//             m_Age = NULL;
//         }
//     }
//     int *m_Age;
//     //重载赋值运算符=：
//     Person &operator=(Person &p)
//     {
//         //编译器提供的浅拷贝：
//         // m_Age = p.m_Age;
//         //应该先判断是否有属性在堆区，如果有，应该先是放干净：
//         if (m_Age != NULL)
//         {
//             delete m_Age;
//             m_Age = NULL;
//         }
//         //深拷贝：
//         m_Age = new int(*p.m_Age);
//         //返回本身:
//         return *this;
//     }
// };

// void test01()
// {
//     Person p1(18);
//     Person p2(20);
//     Person p3(30);
//     p3 = p2 = p1;
//     cout << "p1的年龄是 " << *p1.m_Age << endl;
//     cout << "p2的年龄是 " << *p2.m_Age << endl;
//     cout << "p3的年龄是 " << *p3.m_Age << endl;
// }

// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//关系运算符重载：
// #include <iostream>
// #include <string>
// using namespace std;

// class Person
// {
// public:
//     Person(string name, int age)
//     {
//         Name = name;
//         Age = age;
//     }
//     //重载==运算符：
//     bool operator==(Person &p)
//     {
//         if (this->Age == p.Age && this->Name == p.Name)
//         {
//             return true;
//         }
//         return false;
//     }
//     //重载！=运算符:
//     bool operator!=(Person &p)
//     {
//         if (this->Age == p.Age && this->Name == p.Name)
//         {
//             return false;
//         }
//         return true;
//     }
//     string Name;
//     int Age;
// };

// void test01()
// {
//     Person p1("Tom", 19);
//     Person p2("Tom", 19);
//     if (p1 == p2)
//     {
//         cout << "p1和p2相等!" << endl;
//     }
//     else
//     {
//         cout << "p1和p2不相等!" << endl;
//     }
// }
// void test02()
// {
//     Person p1("Tom", 19);
//     Person p2("Jerry", 20);
//     if (p1 != p2)
//     {
//         cout << "p1和p2不相等!" << endl;
//     }
//     else
//     {
//         cout << "p1和p2相等!" << endl;
//     }
// }

// int main()
// {
//     test01();
//     test02();
//     system("pause");
//     return 0;
// }

//函数调用运算符重载：（仿函数）
// #include <iostream>
// #include <string>
// using namespace std;

// class MyPrint
// {
// public:
//     void operator()(string test) //由于用起来非常像函数调用，所以又叫仿函数
//     {
//         cout << test << endl;
//     }
//     //仿函数非常灵活，没有固定写法
//     int operator()(int num1, int num2)
//     {
//         return num1 + num2;
//     }
// };
// void test01()
// {
//     MyPrint myprint;
//     myprint("hello world");
// }
// void test02()
// {
//     MyPrint myprint;
//     int ret = myprint(100, 200);
//     cout << ret << endl;
// }
// void test03()
// {
//     cout << MyPrint()(100, 300) << endl;
// }

// int main()
// {
//     test01();
//     test02();
//     test03();
//     system("pause");
//     return 0;
// }

//继承中同名继承处理
// #include <iostream>
// using namespace std;

// class Base
// {
// public:
//     Base()
//     {
//         m_A = 100;
//     }
//     void func()
//     {
//         cout << "Base_func调用中" << endl;
//     }
//     void func(int a)
//     {
//         cout << "Base_func(int a)调用" << endl;
//     }
//     int m_A;
// };

// class Son : public Base
// {
// public:
//     Son()
//     {
//         m_A = 200;
//     }
//     void func()
//     {
//         cout << "Son_func调用中" << endl;
//     }
//     int m_A;
// };

// //同名成员处理
// void test01()
// {

//     Son s;
//     cout << s.m_A << endl;
//     //如果用子类对象访问父类的成员，需要作用域运算符：
//     cout << s.Base::m_A << endl;
// }
// //同名成员函数处理：
// void test02()
// {
//     Son s;
//     s.func();
//     //如果子类与父类拥有同名的成员函数，子类会隐藏父类的同名函数，加作用域运算符可以访问父类中的同名函数:
//     s.Base::func();
//     s.Base::func(100);
// }

// int main()
// {
//     test01();
//     test02();
//     system("pause");
//     return 0;
// }

//继承中同名静态成员处理
// #include <iostream>
// using namespace std;

// class Base
// {
// public:
//     static void func()
//     {
//         cout << "Base_func调用" << endl;
//     }
//     static void func(int a)
//     {
//         cout << "Base_func(int a)调用" << endl;
//     }
//     static int m_A;
// };
// int Base::m_A = 100;

// class Son : public Base
// {
// public:
//     static void func()
//     {
//         cout << "Son_func调用" << endl;
//     }
//     static int m_A;
// };
// int Son::m_A = 200;

// void test01()
// {
//     cout << "通过对象访问" << endl;
//     Son s;
//     cout << s.m_A << endl;
//     cout << s.Base::m_A << endl;

//     cout << "通过类名访问" << endl;
//     cout << Son::m_A << endl;
//     //第一个::表示通过类名访问，第二个::表示在父亲作用域下
//     cout << Son::Base::m_A << endl;
// }

// void test02()
// {
//     cout << "通过对象访问" << endl;
//     Son s;
//     s.func();
//     s.Base::func();
//     cout << "通过类名访问" << endl;
//     Son::func();
//     //如果子类与父类拥有同名的静态成员函数，子类会隐藏父类的同名函数，加作用域运算符可以访问父类中的同名函数:
//     Son::Base::func();
//     Son::Base::func(100);
// }

// int main()
// {
//     test01();
//     test02();
//     system("pause");
//     return 0;
// }

//菱形继承
// #include <iostream>
// using namespace std;

// class Animal
// {
// public:
//     int m_Age;
// };
// //用虚继承解决菱形继承的问题
// //虚继承只会拷贝一份数据
// class Sheep : virtual public Animal
// {
// };
// class Tuo : virtual public Animal
// {
// };
// class Sheep_Tuo : public Sheep, public Tuo
// {
// };

// void test01()
// {
//     Sheep_Tuo st;
//     //由于虚继承的特性，一下数据只会拷贝一份，所有相当于修改值：
//     st.m_Age = 20;
//     st.Sheep::m_Age = 30;
//     st.Tuo::m_Age = 15;
//     cout << st.m_Age << endl;
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//多态
// #include <iostream>
// using namespace std;
// //动态多态
// class Animal
// {
// public:
//     //虚函数
//     virtual void speak()
//     {
//         cout << "动物在说话" << endl;
//     }
// };
// class Cat : public Animal
// {
//     void speak()
//     {
//         cout << "小猫在说话" << endl;
//     }
// };
// class Dog : public Animal
// {
//     void speak()
//     {
//         cout << "小狗在说话" << endl;
//     }
// };
// //如果函数地址在编译时就已经确定，称为静态联编
// //如果函数地址在运行时确定，称为动态联编
// void dospeak(Animal &animal)
// {
//     animal.speak();
// }

// //多态满足的条件
// // 1.具有继承关系
// // 2.子类重写父类中的虚函数

// //多态使用
// //父类的指针或者引用指向子类的对象
// void test01()
// {
//     Cat cat;
//     dospeak(cat);
//     Dog dog;
//     dospeak(dog);
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//多态与抽象类
// #include <iostream>
// using namespace std;

// class Base
// {
//     //纯虚函数
//     //一旦类中有一个纯虚函数，那么这个类就为抽象类
//     //抽象类的子类需要重写纯虚函数，否则子类也为抽象类
// public:
//     virtual void func() = 0;
// };

// class Son : public Base
// {
// public:
//     void func()
//     {
//         cout << "func调用" << endl;
//     }
// };

// void test01()
// {
//     //抽象类的指针或者引用指向子类的对象
//     Base *base = new Son;
//     base->func();
//     delete base;
// }

// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//虚析构与纯虚析构
// #include <iostream>
// #include <string>
// using namespace std;

// class Animal
// {
// public:
//     Animal()
//     {
//         cout << "animal构造函数调用" << endl;
//     }
//     // ~Animal()
//     // {
//     //     cout << "animal析构函数调用" << endl;
//     // }
//     //利用虚析构可以解决父类释放子类中对象不干净的情况
//     // virtual ~Animal()
//     // {
//     //     cout << "animal析构函数调用" << endl;
//     // }
//     //纯虚析构
//     //纯虚析构既要声明也要实现
//     //一旦有纯虚析构函数，那么这个类变为抽象类，无法实例化对象
//     // virtual ~Animal() = 0;
//     virtual void speak() = 0;
// };
// // Animal::~Animal()
// // {
// //     cout << "animal纯虚析构函数调用" << endl;
// // }

// class Cat : public Animal
// {
// public:
//     Cat(string name)
//     {
//         cout << "cat构造函数调用" << endl;
//         m_name = new string(name);
//     }
//     ~Cat()
//     {
//         cout << "cat析构函数调用" << endl;
//         if (m_name != NULL)
//         {
//             delete m_name;
//             m_name = NULL;
//         }
//     }
//     void speak()
//     {
//         cout << "小猫在说话" << endl;
//     }
//     string *m_name;
// };

// void test01()
// {
//     Animal *cat = new Cat("Tom");
//     cat->speak();
//     delete cat;
// }

// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//文件操作：
// #include <iostream>
// #include <fstream>
// using namespace std;

// 文本文件-写文件：

// void test01()
// {
//     // 1.包含头文件：

//     // 2.创建流对象：
//     ofstream ofs;
//     // 3.指定打开方式：
//     ofs.open("test.txt", ios::out);
//     // 4.写内容：
//     ofs << "姓名是：张三" << endl;
//     ofs << "相别：男" << endl;
//     ofs << "年龄:20" << endl;
//     // 5.关闭文件：
//     ofs.close();
// }

// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//文本文件-读文件
// #include <iostream>
// #include <fstream>
// #include <string>
// using namespace std;

// void test01()
// {
//     // 1.包含头文件：

//     // 2.创建流对象：
//     ofstream ifs;
//     // 3.打开方式：
//     ifs.open("test.txt", ios::in);

//     if (!ifs.is_open())
//     {
//         cout << "文件打开失败" << endl;
//         return;
//     }
//     // 4.读数据:

//     //第一种
//     // char buf[1024] = {0};
//     // while (ifs >> buf)
//     // {
//     //     cout << buf << endl;
//     // }

//     //第二种
//     // char buf[1024] = {0};
//     // while (ifs.getline(buf, sizeof(buf))
//     // {
//     //     cout << buf << endl;
//     // }

//     //第三种
//     // string buf;
//     // while (getline(ifs, buf))
//     // {
//     //     cout << buf << endl;
//     // }

//     //第四种
//     char c;
//     while ((c = ifs.get()) != EOF) // end of file
//     {
//         cout << c << endl;
//     }
//     // 5.关闭文件
//     ifs.close();
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//二进制文件-写文件
// #include <iostream>
// #include <fstream>
// using namespace std;

// class Person
// {
// public:
//     char m_name[64];
//     int m_age;
// };

// void test01()
// {
//     ofstream ofs("person.txt", ios::out | ios::binary);
//     // ofs.open("person.txt", ios::out | ios::binary);
//     Person p = {"张三", 20};
//     ofs.write((const char *)&p, sizeof(Person));
//     ofs.close();
// }
// int main()
// {
//     test01();
//     system("pause");
//     return 0;
// }

//二进制文件 - 读文件
#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
    char m_name[64];
    int m_age;
};
void test01()
{
    ifstream ifs;
    ifs.open("Person.txt", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "打开文件失败" << endl;
        return;
    }
    Person p;
    ifs.read((char *)&p, sizeof(p));
    cout << "姓名：" << p.m_name << endl;
    cout << "年龄：" << p.m_age << endl;
    ifs.close();
}
int main()
{
    test01();
    system("pause");
    return 0;
}
