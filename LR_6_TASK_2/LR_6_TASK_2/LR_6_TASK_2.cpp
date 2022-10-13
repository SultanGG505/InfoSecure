﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;



int n; // размер алфавита
int k; // длина слова
vector<char> CompObj; //комб.объект
vector<char> alphabet; // алфавит

string result = "";

string RW_gen() // рандоматор прав доступа на чтение и запись
{
	int a = rand() % 2;
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
	alphabet = { '1','2','3' };
	/*for (int i = 0; i < n; i++)
	{
		cout << "Введите символ алфавита: " << endl;
		cin >> alphabet[i];
	}
	*/
	cout << "Алфавит введён" << endl;
}

//bool Condition(string inp)
//{
//	/*std::string s = "aaabla-blaaa";
//	std::cout << std::count(s.begin(), s.end(), 'a') << std::endl;*/
//	if (count(inp.begin(), inp.end(), '2') == 2 && count(inp.begin(), inp.end(), '5') == 2)
//		return true;
//	else
//		return false;
//	return true;
//}

void PrintCompObjWithCondition(int k)
{
	string ObjToPrint = "";
	for (int i = 0; i < k; i++)
	{
		ObjToPrint += CompObj[i];
	}
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
	/*InputAlpha(4);
	Process();*/

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

	InputAlpha(n);
	Process();
	ofstream Output_LS;
	Output_LS.open("LS.txt", fstream::in | fstream::out | fstream::trunc);
	if (Output_LS.is_open())
	{
		Output_LS << result << endl;
	}
	Output_LS.close();
	CompObj.clear();
	result = "";

	InputAlpha(m);
	Process();
	ofstream Output_LO;
	Output_LO.open("LO.txt", fstream::in | fstream::out | fstream::trunc);
	if (Output_LO.is_open())
	{
		Output_LO << result << endl;
	}
	Output_LO.close();
	CompObj.clear();
	result = "";

	vector <string> LS_s, LO_s;

	string LS_, LO_;
	ifstream inp_LS("LS.txt");
	while (getline(inp_LS, LS_)) {
		LS_s.push_back(LS_);
	}
	inp_LS.close();

	ifstream inp_LO("LO.txt");
	while (getline(inp_LO, LO_)) {
		LO_s.push_back(LO_);
	}
	inp_LO.close();

	LS_s.pop_back();
	LO_s.pop_back();

	//string temp = "cat";
	//char tab2[1024];
	//strcpy_s(tab2, temp.c_str());

	//char c = '1';
	//int i = c - '0'; // i is now equal to 1, not '1'

	bool ok = false;
	int k = 0, d = 0;
	string TMP_S, TMP_O;
	while (ok != true)
	{	

		TMP_S = LS_s[k];		
		/*vector<int> v(TMP_S.size());*/
		transform(TMP_S.begin(), TMP_S.end(), LS.begin(), [](char c) {return c - '0'; });
		k++;
		if (ok)
			break;
		for (int i = 0; i < n; i++) // субъекты LS
		{
			if (ok)
				break;
			TMP_O = LO_s[d];
			/*vector<int> v(TMP_S.size());*/
			transform(TMP_O.begin(), TMP_O.end(), LO.begin(), [](char c) {return c - '0'; });
			d++;
			for (int j = 0; j < m; j++) // объекты LO
			{
				if (RW[i][j].size() == 2)
				{
					if (((LS[i] > LO[j] && RW[i][j][1] == 'W') || (LS[i] <= LO[j] && RW[i][j][0] == 'R')))
					{
						ok = true;
						break;
					}
				}
				if (RW[i][j].size() == 1)
				{
					if (((LS[i] > LO[j] && RW[i][j] == "W") || (LS[i] <= LO[j] && RW[i][j] == "R")))
					{
						ok = true;
						break;
					}
				}
			}
			
		}
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


	if (ok)
		cout << "Система соответствует критерию безопасности Белла - Лападулы" << endl;
	else
		cout << "Система НЕ соответствует критерию безопасности Белла - Лападулы" << endl;

}