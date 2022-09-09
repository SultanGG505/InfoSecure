#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//
//Шифровка.Мюллер много раз пытался поймать Штирлица с
//поличным, но тот всё время выкручивался.Как - то раз Штирлиц просматривал
//электронную почту.В это время незаметно вошел Мюллер и увидел, как у него
//2
//на экране появился бессмысленный набор символов.«Шифровка», – подумал
//Мюллер.«UTF - 8», – подумал Штирлиц.
//Известно, что Штирлиц шифрует текст следующим образом :
//Убирает все пробелы и знаки препинания.
//Заменяет все подряд идущие одинаковые буквы на одну такую букву.
//Многократно вставляет в произвольное место текста две одинаковых
//буквы.
//Попробуйте восстановить текст, каким он был после второго шага.Для
//этого удалите из текста все пары одинаковых символов, добавленные на
//третьем шаге.
//Исходные данные
//В единственной строке записана шифровка Штирлица, состоящая из
//строчных латинских букв.Длина шифровки не превосходит 200000.
//Результат
//Выведите восстановленный текст.
//В таблице 1 приведен пример файлов входных и выходных данных




int main()
{
	string temp = "";
	fstream Input;
	Input.open("C:\\Users\\sulta\\OneDrive\\Рабочий стол\\input_LR_3_0.txt", fstream::in | fstream::out | fstream::app);
	if (Input.is_open())
		while (getline(Input, temp))
		{

		}
	Input.close();

	vector <char> res;
	for (int i = 0; i < temp.size(); i++)
		res.push_back(temp[i]);


	int status = 1;
	while (status == 1)
	{
		status = 0;
		for (int i = 0; i < res.size() - 1; i++)
			if (res[i] == res[i + 1])
			{
				status = 1;
				res.erase(res.begin() + i + 1);
				res.erase(res.begin() + i);
				i++;
			}
	}

	fstream Output;
	Output.open("C:\\Users\\sulta\\OneDrive\\Рабочий стол\\output_LR_3_0.txt", fstream::in | fstream::out | fstream::app);
	if (Output.is_open())
		for (int i = 0; i < res.size(); i++)
			Output << res[i];
	Output.close();
}

