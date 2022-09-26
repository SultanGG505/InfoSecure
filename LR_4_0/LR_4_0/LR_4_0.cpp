#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n; // размер алфавита
int k; // длина слова
vector<char> CompObj; //комб.объект
vector<char> alphabet; // алфавит


void InputAlpha() // Ввод алфавита // CompObjects()
{
	cout << "Введите размер алфавита: " << endl;
	cin >> n;
	cout << "Введите длину слова " << endl;
	cin >> k;
	alphabet.resize(n);
	for (int i = 0; i < n; i++)
	{
		cout << "Введите символ алфавита: " << endl;
		cin >> alphabet[i];
	}
	cout << "Алфавит введён" << endl;
}

void PrintCompObj(int k)
{
	string ObjToPrint = "";
	for (int i = 0; i < k; i++)
	{
		ObjToPrint += CompObj[i];
	}
	cout << ObjToPrint << endl;
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
		PrintCompObj(k);
		NextCompObj();
	}
	PrintCompObj(k);
}


void main()
{
	setlocale(LC_ALL, "RUS");
	InputAlpha();
	Process();
}