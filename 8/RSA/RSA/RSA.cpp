// RSA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//���������� ��������� RSA �� C++

#include <iostream>
#include <ctime>
using namespace std;
#define ULL unsigned long long 

//������� ���������� ������
inline ULL mod(ULL res_pow, ULL mod)
{
    return res_pow % mod;
}

//������� ���������� ��� ���� �����
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

//������� ��������� ����� A � ������� B �� ������ �
inline ULL mod_pow(ULL number, ULL powe_num, ULL mod)
{
    ULL res_pow = pow(number, powe_num);
    return res_pow % mod;
}

//������� ��� ���������� ������� ����� � ������� �� ������
inline ULL MEGA_MOD_POW(ULL number, ULL powe, ULL modul)
{
    ULL OUTPUT = 1;
    ULL ONE = 1;
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
        for (ULL cicle = 2; cicle <= powe; cicle++)
        {
            ULL result = mod_pow(number, 2, modul);
            OUTPUT = OUTPUT * result;
        }

        ONE = mod_pow(number, 1, modul);
        RESULT = mod(ONE * OUTPUT, modul);
    }

    return RESULT;
}

//������� ������
inline ULL elir(ULL n) {
	ULL result = n;
	for (ULL i = 2; i * i <= n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

int main()
{
    srand(time(NULL));
    ULL N, Pa, Qa, da, m, fi, c, e, output;//����������� ��� ������������ �����

    //������� �� ����� ��������� �����
    Pa = 5;
    cout << "P " << Pa << endl;
    Qa = 11;
    cout << "Q " << Qa << endl;
    da = 3;
    cout << "d " << da << endl;
    m = 12;
    cout << "m " << m << endl;

    //��������� N
	N = Pa * Qa;
    cout << "N " << N << endl;

    //������� ��������� N, �� ������� ������, (fiN) - ��������� ������� ������ 
    int fiN = elir(N);
    cout << "fi(N) " << fiN << endl;

point:
    //��������� ��������� ����� C
	c = rand() % fiN;

    //��������� ������������ �, ��� �� ���(fiN � �) = 1
    //� ��� �� �*Da mod fiN = 1
    if (NOD(fiN, c) == 1 and mod( (c * da), fiN) == 1)
    {
        cout << "c " << c << endl;
    }

    else
    {
        //���� ����� �� �������, �������� �������
        goto point;
    }

    //��������� e = m ^ da mod (N)
    e = MEGA_MOD_POW(m, da, N);
    cout << "e = " << m << " ^ " << da << " mod(" << N << ")" << endl;
    cout << "e " << e << endl;

    //��������� m = e ^ c mod (N)
   output = MEGA_MOD_POW(e, c, N);
   cout << "m =" << e << " ^ " << c << " mod(" << N << ")" << endl;

    cout << "result " << output << endl;

    return 0;
}