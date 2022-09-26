
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
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
//помещаются в файл naturals.out.В каждой строке находится два
//числа : число из входного файла и соответствующее ему значение,
//такое, что() = .
//1 2
//2 6
//3 12
//105 720

using namespace std;



int factorize(int x) {   // vector<int>
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

    return factors.size(); // можно также вернуть сами множители
}

int main()
{
    vector <int> input{};
    //ifstream Stream("C:\\Users\\sulta\\OneDrive\\Рабочий стол\\lr_4_4_input.txt", fstream::in | fstream::out | fstream::app);
    ifstream Stream("C:\\Users\\SultanGG505_PC\\Desktop\\lr_4_4_input.txt", fstream::in | fstream::out | fstream::app);
    if (Stream.is_open())
    {
        string temp;
        while (!Stream.eof())
        {
            getline(Stream, temp);            
            input.push_back(stoi(temp));
        }
    }
    Stream.close();
    
    cout << factorize(720) << endl;


}
