﻿
#include <iostream>
#include <vector>
//
//4 Множители.Основная теорема арифметики утверждает, что каждое
//целое число, большее 1, может быть однозначно представлено как
//произведение
//одного
//или
//нескольких
//простых
//чисел.
//При
//уникальном наборе простых множителей возможно несколько их
//упорядочений.Например, 10 = 2 * 5, 10 = 5 * 2. 20 = 2 * 2 * 5, 20 = 2 * 5 * 2,
//20 = 5 * 2 * 2. Пусть() будет числом различных расположений
//простых множителей натурального числа.Так что(10) = 2,
//(20) = 3 Дано натуральное число, всегда существует по крайней
//мере одно такое натуральное, для которого() = .Требуется
//вычислить по заданному такое наименьшее число .
//Входные данные берутся из файла naturals.in.Файл содержит какое -
//то количество произвольных натуральных чисел из диапазона 2 . 263
//В одной строке содержится ровно одно число.Выходные данные

using namespace std;

int factorize(int x) {
    vector<int> factors;

    for (int i = 2; i <= sqrt(x); i++) {
        while (x % i == 0) {
            factors.push_back(i);
            x /= i;
        }
    }

    if (x != 1) {
        factors.push_back(x);
    }

    return factors.size();
}

int main()
{
    cout << factorize(12) << endl;
}
