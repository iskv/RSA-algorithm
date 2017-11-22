#ifndef ABONENT_H
#define ABONENT_H

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

#define BigInteger unsigned long long

using namespace std;

class Abonent
{
private:
    BigInteger f; // значение функции Эйлера
    BigInteger d; // секретная экспонента

    BigInteger calc_e(BigInteger f);
    BigInteger calc_d(BigInteger e, BigInteger f);

    BigInteger Nod(BigInteger a, BigInteger b)
    {
        while (a && b)
            if (a >= b)
               a %= b;
            else
               b %= a;
        return a | b;
    }

public:
    Abonent(int p, int q);

    void send_to(Abonent& a);
    void encrypt(int num, Abonent& sender);
    void decrypt();

    BigInteger e; // открытая экспонента
    BigInteger n; // модуль, часть открытого и закрытого ключа

    BigInteger enc_num;
};

#endif // ABONENT_H
