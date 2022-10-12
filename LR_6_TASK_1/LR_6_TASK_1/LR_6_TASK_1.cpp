﻿/*1 Для заданных натуральных чисел n и m матрица A[1:n; 1:m] прав
доступа субъектов s1, s2, … , sn к объектам o1, o2, … , om предполагается
заданной так, что P = A[i, j], где P  {‘r’, ‘w’}; ‘r’ - полномочие
чтения субъектом si объекта oj, ‘w’ – полномочие записи субъектом si в
1
объект oj. Кроме того, предполагаются заданными целочисленные массивы
LS и LO : LS[1:n] так что LS[i] – значение уровня допуска субъекта si ;
LO[1:m] так что LO[j] – значение уровня секретности объекта oj . Составить
программу, которая проверяет, верно ли что компьютерная система CS = (n,m,
A, LS, LO) соответствует критерию безопасности Белла – Лападулы.
*/

#include <iostream>   
#include <vector>  
#include <string>
#include <ctime>
using namespace std;

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


int main()
{
	setlocale(LC_ALL, "RUS");
	int n, m; // число субъектов(программ обработчиков) n и число объектов(содержат информацию) m 
	cout << "Введите число субъектов и объектов через строку" << endl;
	cin >> n >> m;

	vector < vector <string> > RW(n, vector <string>(m));
	vector <int> LS(n); // уровни допуска субъектов S
	vector <int> LO(m); // уровень секретности объектов O
	srand(time(0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			RW[i][j] = RW_gen();
		}

	for (int i = 0; i < n; i++)
		LS[i] = rand() % 3 + 1;

	for (int i = 0; i < m; i++)
		LO[i] = rand() % 3 + 1;

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
		cout << "ok" << endl;
	else
		cout << "ne ok" << endl;




}