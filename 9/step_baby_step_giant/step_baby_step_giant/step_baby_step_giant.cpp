// step_baby_step_giant.cpp : This file contains the 'main' function. Program execution begins and ends there.
//�������� ��� ������, ��� ��������

#include <iostream>
#include <math.h>
#include<ctime>
using namespace std;

#define ULL unsigned long long

//������ ������� ��� �����
const ULL SIZE = 40000000;
ULL ARR[SIZE];
const ULL SIZE_1 = 40000000;
ULL ARR_1[SIZE_1];

//������� ������ ����� � �������
inline long long Compl( ULL first_arr[SIZE], ULL find_number )
{
    long long result = -1;
    for (ULL i = 0; i < SIZE; i++)
    {
        if (find_number == first_arr[i])
        {
            result = i;
            break;
        }
    }
    return result;
}

//������� ���������� ������
inline ULL mod(const ULL res_pow, const ULL mod)
{
    return res_pow % mod;
}

//������� ���������� ������ � ������� a^c mod p
inline ULL mod_pow(const ULL number, const ULL powe_num, const ULL mod)
{
    ULL res_pow = pow(number, powe_num);
    return res_pow % mod;
}

//���������� ������ ����� A � ������� C �� ������ M
//������ ������� ����������� ��� ������� �����
//����� ������������ ������� ���������� ���������� � ������� �� ������, ������ ��� ��������� �� ���������� ��������
inline ULL MEGA_MOD_POW(const ULL number, const ULL powe, const ULL modul)
{
    ULL OUTPUT = 1;
    ULL RESULT = 1;
    if (powe % 2 == 0)
    {
        for (ULL cicle = 2; cicle <= powe; cicle += 2)
        {
            ULL result = mod_pow(number, 2, modul);
            OUTPUT = OUTPUT * result;
        }
        RESULT = mod(OUTPUT, modul);
    }

    else
    {
        for (ULL cicle = 2; cicle <= powe; cicle += 2)
        {
            ULL result = mod_pow(number, 2, modul);
            OUTPUT = OUTPUT * result;
        }
        OUTPUT = OUTPUT * mod_pow(number, 1, modul);

        RESULT = mod(OUTPUT, modul);
    }

    return RESULT;
}

int main()
{

    setlocale(LC_ALL, "Russian");
    cout << "��� �������� ��� ��������" << endl;

    //���������� ����� ������� �������
    int y = 25;
    int a = 3;
    int p = 31;

restart:

point:
    //�������� ��������� ����� m � k
    srand(time(NULL));
    //int m = 6;
    //int k = 4;

    int m = 1 + rand() % p;
    int k = 1 + rand() % p;

    //��������� �����
    if ((m * k) > p and (m != k) )
    {
        cout << "m = " << m << " k = " << k << endl;
    }

    else
    {
        //���� �� ������������� �������, ��������� ������
        goto point;
    }

    ULL i = 0;//��� ������� ��� ������� ��������

    //��������� �������� �������� ������� (3) � ����������
    for ( i = 0; i < m - 1; ++i)
    {
        if (i == 0)
        {
            cout << "1) "  << y << " mod " << p  << " = "; 
            ARR[i] = mod(y,p); //y mod p = 
            cout << ARR[i] << " ";
            cout << endl;
        }

        if (i == 1)
        {
            cout << "2) " << a << " * " << y << " mod " << p << " = " ;
            ARR[i] = mod(a * y, p); // a * y mod p = 
            cout << ARR[i] << " ";
            cout << endl;
        }

        if(i >= 2)
        {
            cout << i << ") " << a << " ^ " << i << " * " << y << " mod " << p << " = ";
            ARR[i] = mod(pow(a, i) * y, p); //(a ^ i) * y mod p = 
            cout << ARR[i] << " ";
            cout << endl;
        }
    }

    cout << endl;
    ULL j = 0;//���� ������� ��� ������� ���������

    //��������� �������� �������� ������� (4)
    cout << "��������� ��� " << endl;
    for (j = 0; j < (k * m); ++j)
    {
        if (j == 0)
        {
            cout << j + 1 << ") " << a << " ^ " << m << " mod " << p << " = ";
            ARR_1[j] = mod(pow(a, m), p);//(a^m) mod p = 
            cout << ARR_1[j] << " ";
            cout << endl;
        }

        if(j >= 1)
        {
            cout << j + 1 << ") " << a << " ^ " << (1 + j) * m << " mod " << p << " = ";
            ARR_1[j] = mod(pow(a, 1 + j), p);// a ^ (1 + j) mod p = 
            cout << ARR_1[j] << " ";
            cout << endl;
        }

        //���� ������ ����� �� ������� ������� � ������������ ������
        ULL NUMBER = ARR_1[j];
        if (Compl(ARR, NUMBER) != -1)
        {
            i = Compl(ARR, NUMBER);
            if (i == 0)
            {
                ++i;
            }
            ++j;
            break;//��� ���������� �����, ������� �� �����
        }

    }

    cout << endl;

    cout << "i " << i << " j " << j << endl;

    ULL x = (i * m) - j; //��������� x

    cout << "x " << x <<  endl;

    if (x < 0)
    {
        goto restart;
    }

    //��������� ��������� x
    //� ������ �������������� �������� ������
    ULL ASSERT = MEGA_MOD_POW(a, x, p);//a ^ x mod p = 

    if (ASSERT == y)
    {
        cout << "complite!!" << endl;
    }

    else
    {
        cout << "ERROR!!" << endl;
        goto restart;
    }

    return 0;
}
