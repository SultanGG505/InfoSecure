
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
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

vector<int> factorize(int x) {   // vector<int>
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
    return factors; // можно также вернуть сами множители
}

int factorial(int i)
{
    if (i == 0) return 1;
    else return i * factorial(i - 1);
}

int permut(vector<int> factos)
{
    sort(factos.begin(), factos.end());
    int high_fact = factos.size();
    vector <int> step;
    int index = 0;
    int num = 0;
    while (!factos.empty())
    {
        if (count(factos.begin(), factos.end(), num) == 0)
        {
            num++;
            continue;
        }
        if (count(factos.begin(), factos.end(), num) != 0)
        {
            auto begin = factos.cbegin(); // указатель на первый элемент
            auto end = factos.cend();     // указатель на последний элемент
            //numbers2.erase(begin + 2, end - 1); // удаляем с третьего элемента до последнего
            // numbers2 = {1, 2, 6}
            
            index = count(factos.begin(), factos.end(), num);
            step.push_back(index);
            /*num++;*/
            factos.erase(begin , begin + index);
        }
    }
    int result = factorial(high_fact);

    for (int i = 0; i < step.size(); i++)
    {
        result /= factorial(step[i]);
    }
    /*cout << result << endl;*/
    return result;
}

void afterPermut(int n)
{
    int temp = 0;

}

int main()
{
    setlocale(LC_ALL, "RUS");
    vector <int> input{};
   /* ifstream Stream("C:\\Users\\sulta\\OneDrive\\Рабочий стол\\lr_4_4_input.txt", fstream::in | fstream::out | fstream::app);*/
    ifstream Stream("C:\\Users\\SultanGG505_PC\\Desktop\\lr_4_4_input.txt", fstream::in | fstream::out | fstream::app);
    if (Stream.is_open())
    {
        string temp;
        while (!Stream.eof())
        {
            getline(Stream, temp);
            input.push_back(stoi(temp));
        }
        Stream.close();
    }
    else
        cout << "Файл не открыт" << endl;


    int temp = 0, i = 0;
    while (i < input.size())
    {
        if (permut(factorize(temp)) == input[i])
        {
            cout << temp << endl;
            i++; temp++;
        }            
        else
        {
            temp++;
        }
    }

    
   


    //permut(factorize(6)); // 2 - 6
    //permut(factorize(12)); // 3 - 12
    //permut(factorize(720)); // 105 - 720

    


}
