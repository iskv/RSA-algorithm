#include "abonent.h"

#define P 19 // число для кодирования (не может превышать p*q)

bool IsTheNumberSimple(BigInteger n); // проверка на - число простое

int main()
{    
    int p = 3; // произвольно выбранные простые числа
    int q = 7;

    if (!IsTheNumberSimple(p) || !IsTheNumberSimple(q)) { cout << "Numbers not simple!\n"; cin.get(); return 0; }

    Abonent Alice(p,q);
    Abonent Bob(p,q);

    cout << "Original: " << P << endl;

    Alice.encrypt(P, Bob); // шифруем число для Боба
    Alice.send_to(Bob); // передаем зашифрованное число Бобу
    Bob.decrypt(); // Дешифрируем у Боба

    cin.get();
    return 0;
}

bool IsTheNumberSimple(BigInteger n)
{
    if (n < 2)
        return false;

    if (n == 2)
        return true;

    for (BigInteger i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}
