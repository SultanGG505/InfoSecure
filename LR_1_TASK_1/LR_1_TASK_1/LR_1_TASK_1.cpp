#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <Windows.h>

using namespace std;

//Шифрограмма.Слово зашифровано «циклическим сдвигом
//на 3 символа назад».Например, слово СЕЛО, шифр – ОСЕЛ, слово
//КООРДИНАТА, шифр – РДИНАТАКОО.Написать функцию decode, которая
//по заданному шифру восстанавливает зашифрованное слово.Задан
//зашифрованный как указано выше текст, например, в виде текстового файла.
//Слова в тексте разделяются одним или несколькими пробелами.Написать
//программу, использующую функцию decode, расшифровки этого текста,
//например, в результирующий текстовый файл.

void decode(vector <string> V)
{
	string temp;
	fstream Result;
	Result.open("C:\\Users\\sulta\\OneDrive\\Рабочий стол\\Unshifred.txt", fstream::in | fstream::out | fstream::app);
	if (Result.is_open())
	{
		for (int i = 0; i < V.size(); i++) {
			temp = V[i];
			rotate(temp.rbegin(), temp.rbegin() + 3, temp.rend());
			cout << temp << endl;
			Result << temp << endl;
		}
	}
	Result.close();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	string Shifred, UnSpcShifred, temp;
	vector <string> vec_string;
	ifstream Stream("C:\\Users\\sulta\\OneDrive\\Рабочий стол\\shifred.txt", fstream::in | fstream::out | fstream::app);
	if (Stream.is_open())
	{
		while (!Stream.eof())
		{
			getline(Stream, temp);
			Shifred += temp;
		}
	}
	Stream.close();
	stringstream SpaceCutter(Shifred);
	while (SpaceCutter >> UnSpcShifred)
	{
		vec_string.push_back(UnSpcShifred);
	}
	decode(vec_string);
	return 0;
}
