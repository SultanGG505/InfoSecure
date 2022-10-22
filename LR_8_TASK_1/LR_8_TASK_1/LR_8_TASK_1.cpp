#include <iostream>
#include <vector>

// т.к в задаче не сказано про добавление/удаление/какую-либо
// работу с объектами, то будем считать что в рамках данной задачи
// количество объектов из матрицы извлекается один раз и не меняется
// во время работы программы

using namespace std;
struct Item {
	int subj_i; // можно использовать как имя объекта
	int obj_j;
	string value;
	/*int _subj_name;*/
};

string RW_gen() // рандоматор прав доступа на чтение, запись и отсутствие прав(у меня нет прав)
{
	string M[2] = { "R","W" };
	int w = 2;
	int i, j, n;
	string buff;
	n = pow(2, w);
	vector <string> RWOX;
	for (int i = 0; i < n; i++)
	{
		for (j = 0; j < w; j++)
			if (i & (1 << j))
				buff += M[j];
		RWOX.push_back(buff);
		buff = "";
	}
	int rander = rand() % 3 + 1;
	int rander_empty_or_not = rand() % 2;
	string for_return;
	if (rander_empty_or_not == 1)
		for_return = RWOX[rander];
	else
		for_return = "_";
	return for_return;
}

void output(vector <Item> Items)
{
	for (int i = 0; i < Items.size(); i++)
	{
		cout << Items[i].subj_i << " " << Items[i].obj_j << " " << Items[i].value << endl;
		cout << "------" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));
	//int n = rand() % 10 + 2; // число субъектов(программ обработчиков) n
	//int m = rand() % 10 + 2; // число объектов(содержат информацию) m 
	int n = 5;
	int m = 5;
	vector <Item> Items = vector <Item>();

	cout << "генерация rw" << endl;
	for (int i = 0; i < n; i++) // строки-субъекты
	{
		for (int j = 0; j < m; j++) // столбцы-объекты
		{
			string temp_RW = RW_gen();
			if (temp_RW != "_")
			{
				Item temp_item;
				temp_item.subj_i = i;
				temp_item.obj_j = j;
				temp_item.value = temp_RW;
				Items.push_back(temp_item);
			}
		}
	}

	cout << "Вывод сгенерированной разряженной матрицы" << endl;
	cout << "В формате: имя субъекта, имя объекта, права доступа" << endl;
	cout << "" << endl;

	output(Items);
	cout << "----------------------------------------" << endl;

	cout << "Вывод списка команд, выбираемых в консоли" << endl;
	cout << "Окончание ввода - цифра 0" << endl;
	cout << "1 - редактирование содержимого любой ячейки" << endl;
	cout << "2 - добавление нового субъекта в матрицу с указанием его номера" << endl;
	cout << "3 - удаление Eого объекта из матрицы" << endl;
	cout << "4 - вычисление процента заполненности матрицы(общее число/хранимое число)" << endl;
	cout << "5 - формирование списка субъектов, имеющих доступ к указанному объекту" << endl;

	int Inp;
	do
	{
		cout << "Введите число: ";
		cin >> Inp;
		if (Inp == 1)
		{
			cout << "работает" << endl;
		}
	} while (Inp != 0);

	return 0;
}
