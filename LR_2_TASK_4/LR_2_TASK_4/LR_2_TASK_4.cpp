#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

//Super RLE.Можно пойти и дальше(см.задачу № 0), попытавшись
//написать программу, реализующую преобразование Super RLE.Для
//этого повторяющийся 𝑁 раз фрагмент 𝐹 исходного текста заменить
//на 𝑁(𝐹).Например, текст AAAA заменяется на 4(A), текст ABCBCD
//заменяется на A2(BC)D, а текст AAABBAAABBCCCCD заменяется
//на 2(3(A)2(B))4(C)D.Сжатый в такой форме текст выводится в файл
//output.txt.Если возможно несколько вариантов свёртки, то в output.txt
//помещается свёртка по возможности наименьшей длины.


int main()
{
	string s = "AAABBAAABBCCCCD";
	fstream Input;
	Input.open("C:\\Users\\sulta\\OneDrive\\Рабочий стол\\input_LR_2_TASK_4.txt", fstream::in | fstream::out | fstream::app);
	if (Input.is_open())
	{
		while (getline(Input, s))
		{

		}
	}
	Input.close();

	string pattern = "";
	for (int mid = 1; mid <= s.size() / 2; mid++)
	{
		pattern = "";
		for (int i = 0; i <= s.size() - 2 * mid; i++)
		{
			if (s.substr(i, mid) == s.substr(i + mid, mid))
			{
				pattern = s.substr(i, mid);
				int c = 2;
				while ((i + mid * (c + 1) <= s.size()) && (s.substr(i + mid * c, mid) == pattern))
				{
					c++;
				}
				s = s.substr(0, i) + to_string(c) + "(" + pattern + ")" + s.substr(mid * c + i, s.size() - mid * c - i);
			}
		}
	}
	cout << s << endl;

	fstream Output;
	Output.open("C:\\Users\\sulta\\OneDrive\\Рабочий стол\\output_LR_2_TASK_4.txt", fstream::in | fstream::out | fstream::app);
	if (Output.is_open())
	{
		Output << s << endl;
	}




















}

