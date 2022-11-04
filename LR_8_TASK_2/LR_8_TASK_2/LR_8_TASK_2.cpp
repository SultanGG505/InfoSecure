
#include <iostream>
#include <vector>

/*
В модели безопасности "Chinese Wall" система считается безопасной, если соблюдены следующие два условия:
1) субъект может читать объекты только в компании А либо в другой компании, которая не в конфликте с компанией А
2) субъект может писать в объекты только в компании А
*/
using namespace std;

struct Object {
	string ObjName;
	string ObjFirmName;
	string HistoryOfOpers;
};


struct Firm {
	string FirmName;
	vector <Object> Objects = vector <Object>();
	vector <string> ConflictsName = vector <string>();
};

int main()
{
	setlocale(LC_ALL, "RUS");
	int F, O, S; // фирмы, объекты, субъекты, а точнее - их количество

	vector <Firm> Firms = vector <Firm>();
	vector <Object> Objects = vector <Object>();
	cout << "Введите кол-во фирм" << endl;
	cin >> F;

	int i = 0;
	while (i != F)
	{
		Firm tempFirm;
		Object tempObj;
		string FirmName;
		cout << "Введите имя фирмы" << endl;
		cin >> FirmName;
		tempFirm.FirmName = FirmName;
		tempObj.ObjFirmName = FirmName;
		int k;
		cout << "Введите кол-во объектов в фирме "  << FirmName << endl;
		cin >> k;
		while (k != 0)
		{
			string ObjName;
			cout << "Введите имя объекта" << endl;
			cin >> ObjName;
			tempObj.ObjName = ObjName;

			tempFirm.Objects.push_back(tempObj);
			Objects.push_back(tempObj);
			k--;
		}
		Firms.push_back(tempFirm);
		i++;
	}

	cout << "Мы не ввели конфликты фирм, введём" << endl;
	cout << "Конфликтных фирм для одной фирмы может быть всего " << Firms.size() - 1 << endl;

	i = 0;
	while (i != F)
	{
		int k;
		cout << "Введите кол-во конфликтных фирм в фирме " << Firms[i].FirmName << endl;
		cin >> k;
		if (k > Firms.size() - 1)
		{
			k = Firms.size() - 1;
		}
		while (k != 0)
		{
			string tempConfl;
			cout << "Введите конфликтную фирму" << endl;
			cin >> tempConfl;
			Firms[i].ConflictsName.push_back(tempConfl);
			k--;
			/*for (int d = 0; d < Firms.size(); d++)
			{
				if (Firms[d].FirmName == tempConfl)
				{
					Firms[d].ConflictsName.push_back(Firms[i].FirmName);
				}
			}*/
		}
		i++;
	}



}


