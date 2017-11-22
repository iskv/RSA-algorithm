#include "abonent.h"

void Abonent::decrypt()
{    
    BigInteger temp;
    temp = (BigInteger) pow(enc_num,d) % n;
    cout << "Decrypted num: " << temp << endl;
}

void Abonent::encrypt(int num, Abonent &reciever) // для шифровки используем публичный ключ получателя
{
    BigInteger temp;
    temp = (BigInteger) pow(num,reciever.e) % reciever.n;
    enc_num = temp;
    cout << "Encrypted num: " << enc_num << endl;
}

void Abonent::send_to(Abonent &reciever)
{
    reciever.enc_num = enc_num;
}

BigInteger Abonent::calc_e(BigInteger f)
{
    BigInteger e = 2;
    while ( Nod(e,f) != 1 ) e++;
    return e;
}

BigInteger Abonent::calc_d(BigInteger e, BigInteger f)
{
    BigInteger d = 0;
    while (true) {
        if ((d*e)%f == 1) return d;
        d++;
    }
}

Abonent::Abonent(int p, int q)
{    
    n = p * q; // вычисляем модуль
    f = (p - 1) * (q - 1); // вычисляем функцию Эйлера
    e = calc_e(f); // вычисляем открытую экспоненту
    d = calc_d(e, f);
}
