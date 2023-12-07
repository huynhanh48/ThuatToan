#include <iostream>
#define d 10
using namespace std;

void settruonghop(int a[][d], int n)
{
    for(int i = 0; i <= n; i++)
    {
        for(int t = 0; t <= d; t++)
        {
            if (i == 0 || t == 0)
            {
                a[i][t] = 0;
            }
        }
    }
}

void xuatmatrix(int f[][d], int n)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= d; j++)
        {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }
}

void Tinhdungtichtoida(int f[][d], int v[], int n)
{
    settruonghop(f, n);
    for (int i = 1; i <= n; i++)
    {
        for (int t = 1; t <= d; t++)
        {
            f[i][t] = f[i - 1][t];
            if (t >= v[i])
            {
                f[i][t] = max(f[i][t], f[i - 1][t - v[i]] + v[i]);
            }
        }
    }
}

void nhapsoluongmay(int v[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << "Nhap May [" << i << "]: ";
        cin >> v[i];
    }
}

int main(int argc, char **argv)
{
    std::cout << "Dung tich toi uu!\n";
    int n;
    cout << "Nhap so luong may: \n";
    cin >> n;
    int v[n];
    int f[n][d];
    nhapsoluongmay(v, n);
    Tinhdungtichtoida(f, v, n);
    cout << "Xuat Matrix!" << endl;
    xuatmatrix(f, n);
    cout << "luong dung tich toi da: " << f[n][d];
    return 0;
}

