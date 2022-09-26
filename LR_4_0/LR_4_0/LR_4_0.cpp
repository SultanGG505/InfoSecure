#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

//
//Криптоанализ.Ключ криптограммы состоит из блоков длиной 2
//слова
//(4
//	байта),
//	записанных
//	в
//	16
//	системе
//	(0, 1, …, 9, A, B, C, D, E, F).Криптоаналитику стало известно, что один из
//	блоков состоит из символов 2, 5, 7. Причем символы 2 и 5 повторяются
//	ровно по два раза.Необходимо написать программу, которая выводит
//	в файл output.txt все возможные варианты этого блока.


int n; // размер алфавита
int k; // длина слова
vector<char> CompObj; //комб.объект
vector<char> alphabet; // алфавит

string result = "";

void InputAlpha() // Ввод алфавита // CompObjects()
{
	/*cout << "Введите размер алфавита: " << endl;
	cin >> n;
	cout << "Введите длину слова " << endl;
	cin >> k;*/
	n = 3;
	k = 8;
	alphabet.resize(n);
	alphabet = {'2','5','7'};
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
	cout << result << endl;
	//fstream Result;
	////Result.open("C:\\Users\\SultanGG505_PC\\Desktop\\LR_4_TASK_0_RESULT.txt", fstream::in | fstream::out | fstream::app);
	//Result.open("C:\\Users\\sulta\\OneDrive\\Рабочий стол\\output_LR_2_TASK_4.txt", fstream::in | fstream::out | fstream::app);
	//Result << result << endl;
	//Result.close();

	fstream Output;
	Output.open("C:\\Users\\sulta\\OneDrive\\Рабочий стол\\output_LR_4_TASK_0.txt", fstream::in | fstream::out | fstream::app);
	if (Output.is_open())
	{
		Output << result << endl;
	}


	cout << "work done" << endl;
}