﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;



int n; // размер алфавита
int k; // длина слова
vector<int> CompObj; //комб.объект
vector<int> alphabet; // алфавит

string result = "";

string RW_gen() // рандоматор прав доступа на чтение и запись
{

	int a = rand() % 3;
	if (a == 0)
		return "R";
	if (a == 1)
		return "W";
	if (a == 2)
		return "RW";
}

void InputAlpha(int x) // Ввод алфавита // CompObjects()
{
	/*cout << "Введите размер алфавита: " << endl;
	cin >> n;
	cout << "Введите длину слова " << endl;
	cin >> k;*/
	n = 3;
	k = x;
	alphabet.resize(n);
	alphabet = { 1,2,3 };
	/*for (int i = 0; i < n; i++)
	{
		cout << "Введите символ алфавита: " << endl;
		cin >> alphabet[i];
	}
	*/
	cout << "Алфавит введён" << endl;
}

bool Condition(string inp)
{
	/*std::string s = "aaabla-blaaa";
	std::cout << std::count(s.begin(), s.end(), 'a') << std::endl;*/
	if (count(inp.begin(), inp.end(), '2') == 2 && count(inp.begin(), inp.end(), '5') == 2)
		return true;
	else
		return false;
	return true;
}

void PrintCompObjWithCondition(int k)
{
	string ObjToPrint = "";
	for (int i = 0; i < k; i++)
	{
		ObjToPrint += CompObj[i];
	}
	if (Condition(ObjToPrint))
		result += ObjToPrint + "\n";

	/*cout << ObjToPrint << endl;*/
}

bool HasNextCompObj()
{
	int kol = 0;
	for (int i = 0; i < k; i++)
		if (CompObj[i] == alphabet[n - 1]) kol++;
	return (kol != k);
}
void NextCompObj()
{
	for (int i = k - 1; i > -1; i--)
	{
		if (CompObj[i] == alphabet[n - 1])
		{
			CompObj[i] = alphabet[0];
			continue;
		}
		CompObj[i]++;

		while (!(find(alphabet.begin(), alphabet.end(), CompObj[i]) != alphabet.end()))
		{
			CompObj[i]++;
		}
		break;
	}
}

void Process()
{
	CompObj.resize(k);
	for (int i = 0; i < k; i++)
		CompObj[i] = alphabet[0];
	while (HasNextCompObj())
	{
		PrintCompObjWithCondition(k);
		NextCompObj();
	}
	PrintCompObjWithCondition(k);
}

void main()
{
	setlocale(LC_ALL, "RUS");
	InputAlpha(4);
	Process();

	int n, m; // число субъектов(программ обработчиков) n и число объектов(содержат информацию) m 
	cout << "Введите число субъектов и объектов через строку" << endl;
	cin >> n >> m;
	cout << "Ручной ввод - 0, автоматический - 1" << endl;
	int inp = 0;
	cin >> inp;

	vector < vector <string> > RW(n, vector <string>(m));
	vector <int> LS(n); // уровни допуска субъектов S
	vector <int> LO(m); // уровень секретности объектов O
	srand(time(0));
	cout << "Генерация RW" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (inp == 0)
				cin >> RW[i][j];
			else
				RW[i][j] = RW_gen();
		}

	cout << "Генерация LS" << endl;

	for (int i = 0; i < n; i++)
	{
		if (inp == 0)
			cin >> LS[i];
		else
			LS[i] = rand() % 3 + 1;
	}

	cout << "Генерация LO" << endl;

	for (int i = 0; i < m; i++)
	{
		if (inp == 0)
			cin >> LO[i];
		else
			LO[i] = rand() % 3 + 1;
	}

	cout << "Вывод сгенерированной матрицы на права записи и чтения" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << RW[i][j] << ' ';
		cout << endl;
	}

	cout << "Вывод сгенерированного массива уровней допуска субъектов S" << endl;

	for (int i = 0; i < n; i++)
		cout << LS[i] << " ";

	cout << endl;

	cout << "Вывод сгенерированного массива уровней секретности объектов O" << endl;

	for (int i = 0; i < m; i++)
		cout << LO[i] << " ";

	cout << endl;

	bool ok = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((LS[i] > LO[j] && RW[i][j] != ""))
			{
				ok = false;
				break;
			}
		}
	}
	if (ok)
		cout << "Система соответствует критерию безопасности Белла - Лападулы" << endl;
	else
		cout << "Система НЕ соответствует критерию безопасности Белла - Лападулы" << endl;
	
}