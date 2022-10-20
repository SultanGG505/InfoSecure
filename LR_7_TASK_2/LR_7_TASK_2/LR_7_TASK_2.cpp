﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <ctime>
#include <regex>
using namespace std;

string RWOX_gen() // рандоматор прав доступа на чтение и запись
{
	string M[2] = { "R","W" };
	int w = 2;
	int i, j, n;
	string buff;

	n = pow(2, w);
	vector <string> RWOX;

	//m = rand() % 10 + 1; РАНДОМ ОТ 1 ДО 10

	for (int i = 0; i < n; i++)
	{
		for (j = 0; j < w; j++)
			if (i & (1 << j))
			{
				buff += M[j];
			}
		/*cout << buff << endl;*/
		RWOX.push_back(buff);
		buff = "";
	}

	// от 0 до 15
	int rander = rand() % 3 + 1; // !!!!!!!!!!!!!!!!!!!!!!!!! + 0 ТИПА НЕТ ВАРИАНТА ОТСУТСВИЯ КОМАНД
	int rander_empty_or_not = rand() % 2;
	string for_return;
	if (rander_empty_or_not == 1)
		for_return = RWOX[rander];
	else
		for_return = "_";
	return for_return;
}

void task_1() // список объектов, не доступных для всех субъектов
{
	int n, m;
	vector <string> temp_N_M_A;

	string s;
	ifstream environ_file("access_matr.txt");
	while (getline(environ_file, s))
	{
		temp_N_M_A.push_back(s);
	}
	environ_file.close();

	n = stoi(temp_N_M_A[0]);
	m = stoi(temp_N_M_A[1]);

	temp_N_M_A.erase(temp_N_M_A.begin(), temp_N_M_A.begin() + 2);

	vector < vector <string> > RW_FROM_FILE_RZLT = vector < vector <string> >();
	string input = "";
	regex re("[ ]");

	for (int i = 0; i < n; i++) // субъекты
	{
		RW_FROM_FILE_RZLT.push_back(vector<string>());
		input = temp_N_M_A[i];
		sregex_token_iterator first{ input.begin(), input.end(), re, -1 }, last;
		vector<string> tokens{ first, last };
		for (int j = 0; j < m; j++) // объекты
		{
			RW_FROM_FILE_RZLT[i].push_back(tokens[j]);
		}
	}
	vector <int> answer = vector <int>();


	for (int j = 0; j < RW_FROM_FILE_RZLT[0].size(); j++) //столбцы
	{
		bool good = true;
		for (int i = 0; i < RW_FROM_FILE_RZLT.size(); i++)  //строки
		{
			if (RW_FROM_FILE_RZLT[i][j] != "_")
				good = false;
		}
		if (good)
			answer.push_back(j + 1);
	}

	cout << "Вывод списка объектов, у которых нет субъектов с правами" << endl;

	for (int d = 0; d < answer.size(); d++)
		cout << answer[d] << " ";

	cout << endl;

	/*
	cout << "вывод для теста RW_FROM_FILE" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << RW_FROM_FILE_RZLT[i][j] << ' ';
		cout << endl;
	}
	*/

}

void task_2() // список субъектов, не доступных для всех объектов
{
	int n, m;
	vector <string> temp_N_M_A;

	string s;
	ifstream environ_file("access_matr.txt");
	while (getline(environ_file, s))
	{
		temp_N_M_A.push_back(s);
	}
	environ_file.close();

	n = stoi(temp_N_M_A[0]);
	m = stoi(temp_N_M_A[1]);

	temp_N_M_A.erase(temp_N_M_A.begin(), temp_N_M_A.begin() + 2);

	vector < vector <string> > RW_FROM_FILE_RZLT = vector < vector <string> >();
	string input = "";
	regex re("[ ]");

	for (int i = 0; i < n; i++) // субъекты
	{
		RW_FROM_FILE_RZLT.push_back(vector<string>());
		input = temp_N_M_A[i];
		sregex_token_iterator first{ input.begin(), input.end(), re, -1 }, last;
		vector<string> tokens{ first, last };
		for (int j = 0; j < m; j++) // объекты
		{
			RW_FROM_FILE_RZLT[i].push_back(tokens[j]);
		}
	}
	vector <int> answer = vector <int>();

	for (int i = 0; i < RW_FROM_FILE_RZLT.size(); i++) // столбцы
	{
		bool good = true;
		for (int j = 0; j < RW_FROM_FILE_RZLT[0].size(); j++) // строки
		{
			if (RW_FROM_FILE_RZLT[i][j] != "_")
				good = false;
		}
		if (good)
			answer.push_back(i + 1);
	}

	cout << "Вывод списка субъектов, у которых нет объектов с правами" << endl;

	for (int d = 0; d < answer.size(); d++)
		cout << answer[d] << " ";

	cout << endl;

	/*
	cout << "вывод для теста RW_FROM_FILE" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << RW_FROM_FILE_RZLT[i][j] << ' ';
		cout << endl;
	}
	*/

}

void main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));
	int n; // число субъектов(программ обработчиков) n
	int m; // число объектов(содержат информацию) m 
	int k; // число генераций команд
	n = rand() % 10 + 1;
	m = rand() % 10 + 1;

	//vector < vector <string> > RW(n, vector <string>(m));
	//vector <int> LS(n); // уровни допуска субъектов s
	//vector <int> LO(m); // уровень секретности объектов o

	//cout << "генерация rw" << endl;
	//for (int i = 0; i < n; i++)
	//	for (int j = 0; j < m; j++)
	//		RW[i][j] = RWOX_gen();

	//ofstream output_environ;
	//output_environ.open("access_matr.txt", fstream::in | fstream::out | fstream::trunc);
	//if (output_environ.is_open())
	//{
	//	output_environ << n << endl;
	//	output_environ << m << endl;
	//	for (int i = 0; i < n; i++)
	//	{
	//		for (int j = 0; j < m; j++)
	//		{
	//			output_environ << RW[i][j] << " "; ////// !!!!!!!!!!!!!!!!!! ЗДЕСЬ ПРИДУМАТЬ РАЗДЕЛИТЕЛЬ МЕЖДУ пустыми RW смотреть коммент в 120 строке
	//		}
	//		output_environ << endl;
	//	}
	//}
	//output_environ.close();

	task_1();
	task_2();

}