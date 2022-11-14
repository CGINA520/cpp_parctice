// 高斯赛德尔迭代法：
#include <iostream>
#include <cmath>
using namespace std;

double *Gauss_Seidel(int n, double **a, double *b, double eps)
{
    int i, j;
    double p, t, s, q;
    double *x = new double[n];
    //判断系数矩阵是否对角占优：
    p = 0.0;
    x[i] = 0.0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                p += fabs(a[i][j]);
            }
        }
        if (p <= fabs(a[i][i]))
        {
            cout << "该矩阵高斯赛德尔迭代方法收敛!" << endl;
            break;
        }
        else
        {
            cout << "因为没有判断矩阵是否不可约对角占优,该矩阵高斯赛德尔迭代法方法可能不收敛！" << endl;
            break;
        }
    }
    //迭代过程:
    p = eps + 1.0;
    int count = 0;
    while (p >= eps) //当精度还没达到的时候，继续迭代
    {
        p = 0.0;
        for (i = 0; i < n; i++)
        {
            t = x[i];
            s = 0.0;
            for (j = 0; j < n; j++)
            {
                if (j != i)
                {
                    s += a[i][j] * x[j];
                }
            }
            x[i] = (b[i] - s) / a[i][i];
            q = fabs(x[i] - t) / (1.0 + fabs(x[i]));
            if (q > p)
            {
                p = q;
            }
        }
        count++;
    }
    cout << "迭代次数为：" << endl;
    cout << count << endl;
    return x;
}

int main()
{
    double **A, *b, eps;
    int n;
    cout << "输入系数矩阵的阶数n:" << endl;
    cin >> n;
    cout << "依次输入系数矩阵的每一个元素A[i][j]:" << endl;
    A = new double *[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = new double[n];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
        }
    }
    cout << "输入常数向量每一项b[i]:" << endl;
    b = new double[n];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout << "输入计算解的精度要求eps:" << endl;
    cin >> eps;
    //计算：
    double *x = new double[n];
    x = Gauss_Seidel(n, A, b, eps);
    cout << "通过高斯赛德尔迭代计算得到的解：" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "x" << i + 1 << "=" << x[i] << endl;
    }
    system("pause");
    return 0;
}
