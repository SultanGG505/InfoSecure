#include <iostream>
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

	int a = rand() % 3;
	if (a == 0)
		return "R";
	if (a == 1)
		return "W";
	if (a == 2)
		return "RW";
}

void InputAlpha() // Ввод алфавита // CompObjects()
{
	/*cout << "Введите размер алфавита: " << endl;
	cin >> n;
	cout << "Введите длину слова " << endl;
	cin >> k;*/
	n = 3;
	k = 8;
	alphabet.resize(n);
	alphabet = { '2','5','7' };
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
	InputAlpha();
	Process();
	
}