// app.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<ctime>
#define ULL unsigned long long
using namespace std;

//функция вычисления модуля
inline ULL mod(ULL a, ULL b)
{
    return a % b;
}

//функция нахождения НОД двух чисел
inline ULL NOD(ULL first, ULL past)
{
    while (first != 0 and past != 0)
    {
        if (first > past)
        {
            first = first % past;
        }
        else
        {
            past = past % first;
        }
    }
    return first + past;
}

//функция вычисленя числа A в степени B по модулю m
inline ULL powmod(unsigned base, unsigned exp, unsigned modulo)
{
    unsigned res = 1;

    while (exp != 0)
    {
        if ((exp & 1) != 0)
        {
            res = (1ll * res * base) % modulo;
        }

        base = (1ll * base * base) % modulo;
        exp >>= 1;
    }

    return res;
}

// функция вычисления по обобщённому алгоритму Эвклида
//для вычисления числа A в степени -1 по модулю M 
inline int gcdex(int a, int m)
{
    int t = 0;
    int newT = 1;
    int r = m;
    int newR = a;

    while (newR != 0)
    {
        int q = r / newR;

        int nnT = t - q * newT;
        t = newT;
        newT = nnT;

        int nnR = r - q * newR;
        r = newR;
        newR = nnR;
    }
    if (r > 1)
    {
        cout << "Error" << endl;
        return 0;
    }

    if (t < 0)
    {
        t += m;
    }

    return t;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
	ULL NEWn,NEWs, NEWr,  P, Q, c, r, N, n, d, s = 0;
    P = 1 + rand() % 100;
    Q = 1 + rand() % 100;
    c = 1 + rand() % 100;
    N = 1 + rand() % 200;
    d = 1 + rand() % 100;
    n = 1 + rand() % 100;

    //подбараем r, так чтобы НОД(r,N) = 1
point:
    r = 1 + rand() % 100;
    if (NOD(r, N) == 1) {
        cout << "r = " << r << endl;
    }

    else {
        ++r;
        goto point;
    }

    cout << "входные данные " << endl;
    cout << "p = " << P << endl;
    cout << "q = " << Q << endl;
    cout << "c = " << c << endl;
    cout << "N = " << N << endl;
    cout << "d = " << d << endl;
    cout << "n = " << n << endl;
    cout << "r = " << r << endl;
    cout << endl;

    cout << "выходные данные " << endl;
    NEWn = mod((n * pow(r, d)), N);//n = (n * r^d) mod N
    cout << "n = " << NEWn << endl;
    NEWs = powmod(NEWn, c, N);//s = n^c mod N
    cout << "s = " << NEWs << endl;
    NEWr = gcdex(r, N);//r ^-1 mod N
    cout << "r = " << NEWr << endl;
    s = mod((NEWs * NEWr), N);//s = NEWs * r^-1 mod N
    cout << "s = " << s << endl;

    cout << endl;
    cout << "купюра " << endl;
    cout << "( " << n << ", " << s << " )" << endl;

    return 0;
}

