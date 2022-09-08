#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

/*stringstream ss;
			ss << count;
			string str = ss.str();*/

			//Компрессия RLE – это способ сжатия данных, в которых
			//имеется много подряд идущих символов.При этом более одного
			//вхождения символа заменяется на пару(количество вхождений -
			//    символ).В входном файле input.txt задан текст, состоящий из букв
			//    латинского алфавита.Примените к нему с помощью написанной
			//    программы преобразование RLE, т.е.замените 𝑁(𝑁 > 1) вхождений
			//    некоторого символа 𝑋, которые подряд идут в строке на 𝑁𝑋.Длина
			//    2
			//    входной строки не более 10000 символов.Преобразованный текст
			//    программа должна поместить в текстовый файл output.txt.Пример:


int main()
{
	string temp = "";
	fstream Input;
	Input.open("C:\\Users\\sulta\\OneDrive\\Рабочий стол\\input.txt", fstream::in | fstream::out | fstream::app);
	if (Input.is_open())
	{
		while (getline(Input, temp))
		{

		}
	}
	Input.close();

	string res = "";
	for (int i = 0; i < temp.size(); i++)
	{
		int count = 1;
		if (temp[i] != temp[i + 1])
		{
			res += temp[i];

		}
		else
		{
			char temp_symb = temp[i];
			while (temp[i] == temp[i + 1])
			{
				count++;
				i++;
			}
			stringstream ss;
			ss << count;
			string str = ss.str();
			res += str + temp_symb;
			count = 1;
		}
	}

	fstream Output;
	Output.open("C:\\Users\\sulta\\OneDrive\\Рабочий стол\\output.txt", fstream::in | fstream::out | fstream::app);
	if (Output.is_open())
	{
		Output << res << endl;
	}
	cout << res << endl;

}
