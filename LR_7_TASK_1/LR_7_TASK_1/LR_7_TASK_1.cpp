#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <ctime>
#include <regex>
using namespace std;



int n; // размер алфавита
int k; // длина слова
vector<char> CompObj; //комб.объект
vector<char> alphabet; // алфавит

string result = "";



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

string RWOX_gen() // рандоматор прав доступа на чтение и запись
{

	string M[4] = { "R","W","O","X" };
	int w = 4;

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
	int rander = rand() % 15 + 1; // !!!!!!!!!!!!!!!!!!!!!!!!! + 0 ТИПА НЕТ ВАРИАНТА ОТСУТСВИЯ КОМАНД
	string for_return = RWOX[rander];
	return for_return;

}


string CMD_gen(int n, int m)
{
	int Sub_n = n;
	int Obj_m = m;
	// рандомить нужно
	// <---ЭТО--> и N / M
	// cdo = 'O-' image_N image_M
	//

	string res_cmd = "";

	string rwox[4] = { "R","W","O","X" };


	int cmd1 = rand() % 5 + 0;
	string cmdFirst[6] =
	{
		// число субъектов(программ обработчиков) n ГОРИЗОНТАЛЬНО/СТРОКА
		// число объектов(содержат информацию) m ВЕРТИКАЛЬНО/СТОЛБЕЦ
		/*
		Create object
		cco = 'O+' image_M
		где M - столбец
		'O+' не генерится, так как для нас не имеет значения имя файла(я так понял O - это имя файла)
		*/
		"cco = 'O+' image_", /////////////


		/*
		Create subject
		ccs = 'S+' image_N
		где N - строка
		*/
		"ccs = 'S+' image_",///////////////////

		/*
		Destroy object
		cdo = 'O-' image_M
		где M - столбец
		*/
		"cdo = 'O-' image_",//////////////////


		/*
		Destroy subject
		сds = 'S-' image_N
		где N - строка
		*/
		"cds = 'S-' image_",////////////////////


		/*
		Enter rule P
		Enter P = '{RWOX}' image N image M
		где N - строка
		где M - столбец
		"cer = '{RWOX}' image_N image_M"
		*/
		"cer = ",

		/*
		Delete rule P
		Delete P = '{RWOX}' image N image M
		где N - строка
		где M - столбец
		"cdr = '{RWOX}' image_N image_M
		*/
		"cdr = "
	};

	if (cmd1 == 0) // create object
	{
		//где M - столбец
		res_cmd += cmdFirst[cmd1];
		int rander = rand() % Obj_m + 1;
		res_cmd += to_string(rander);
	}
	if (cmd1 == 1) // create subject
	{
		//где N - строка
		res_cmd += cmdFirst[cmd1];
		int rander = rand() % Sub_n + 1;
		res_cmd += to_string(rander);
	}
	if (cmd1 == 2) // destroy object
	{
		//где M - столбец
		res_cmd += cmdFirst[cmd1];
		int rander = rand() % Obj_m + 1;
		res_cmd += to_string(rander);
	}
	if (cmd1 == 3) // destroy subject
	{
		//где N - строка
		res_cmd += cmdFirst[cmd1];
		int rander = rand() % Sub_n + 1;
		res_cmd += to_string(rander);
	}
	if (cmd1 == 4) // enter rule image_N image_M
	{
		//где N - строка
		//где M - столбец 
		//"cer = '{RWOX}' image_N image_M"
		res_cmd += cmdFirst[cmd1];
		int RWOX_rnd = rand() % 3;

		int randN = rand() % Sub_n + 1;
		int randM = rand() % Obj_m + 1;

		res_cmd += "'";
		res_cmd += rwox[RWOX_rnd];
		res_cmd += "'";
		res_cmd += " image_";
		res_cmd += to_string(randN);
		res_cmd += " image_";
		res_cmd += to_string(randM);
	}
	if (cmd1 == 5) // delete rule image_N image_M
	{
		//где N - строка
		//где M - столбец 
		//"cer = '{RWOX}' image_N image_M"
		res_cmd += cmdFirst[cmd1];
		int RWOX_rnd = rand() % 3;

		int randN = rand() % Sub_n + 1;
		int randM = rand() % Obj_m + 1;

		res_cmd += "'";
		res_cmd += rwox[RWOX_rnd];
		res_cmd += "'";
		res_cmd += " image_";
		res_cmd += to_string(randN);
		res_cmd += " image_";
		res_cmd += to_string(randM);
	}
	return res_cmd;
}

void prgrm_writer(int count, int n, int m)
{
	ofstream output_prgrm;
	output_prgrm.open("prgrm.txt", fstream::in | fstream::out | fstream::trunc);
	if (output_prgrm.is_open())
	{
		for (int i = 0; i < count; i++)
		{
			output_prgrm << CMD_gen(n, m) << endl;
		}
	}
	output_prgrm.close();
}

void interpreter()
{
	int n, m;
	vector <string> temp_N_M_A;

	string s;
	ifstream environ_file("environ.txt");
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

	cout << "вывод для теста RW_FROM_FILE" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << RW_FROM_FILE_RZLT[i][j] << ' ';
		cout << endl;
	}

	vector <string> temp_prgrm;

	string s2;
	ifstream prgrm_file("prgrm.txt");
	while (getline(prgrm_file, s))
	{
		temp_prgrm.push_back(s);
	}
	prgrm_file.close();

	int cmd_K = temp_prgrm.size();



	for (int i = 0; i < cmd_K; i++)
	{
		cout << temp_prgrm[i] << endl;
	}

	string input2;
	regex re2(" image_");

	vector < vector <string> > structed_CMD(cmd_K, vector <string>());

	for (int i = 0; i < cmd_K; i++)
	{
		input2 = temp_prgrm[i];
		sregex_token_iterator first{ input2.begin(), input2.end(), re2, -1 }, last;//the '-1' is what makes the regex split (-1 := what was not matched)
		vector<string> tokens{ first, last };
		int k = tokens.size();
		structed_CMD[i].resize(k);
		for (int d = 0; d < k; d++)
		{
			structed_CMD[i][d] = tokens[d];
		}
	}

	//	if (s1.find(s2) != std::string::npos) {
	//		std::cout << "found!" << '\n';
	//	}
	//Note: "found!" will be printed if s2 is a substring of s1, both s1and s2 are of type std::string.


	for (int i = 0; i < cmd_K; i++)
	{
		if (structed_CMD[i][0].find("cco") != string::npos)
		{			
			int ind = stoi(structed_CMD[i][1]);
			

		}
			

		if (structed_CMD[i][0].find("ccs") != string::npos)
		{
			cout << i << " " << "ccs" << endl;
		}

		if (structed_CMD[i][0].find("cdo") != string::npos)
		{
			cout << i << " " << "cdo" << endl;
			/*int ind = stoi(structed_CMD[i][1]);
			RW_FROM_FILE_RZLT.erase(RW_FROM_FILE_RZLT.begin() + ind);*/

		}

		if (structed_CMD[i][0].find("cds") != string::npos)
		{
			cout << i << " " << "cds" << endl;
		}

		if (structed_CMD[i][0].find("cer") != string::npos)
		{
			cout << i << " " << "cer" << endl;
		}

		if (structed_CMD[i][0].find("cdr") != string::npos)
		{
			cout << i << " " << "cdr" << endl;
		}

	}

	ofstream output_rzlt;
	output_rzlt.open("rzlt.txt", fstream::in | fstream::out | fstream::trunc);
	if (output_rzlt.is_open())
	{
		for (int i = 0; i < n; i++) // строки
		{
			for (int j = 0; j < m; j++) // столбцы
				output_rzlt << RW_FROM_FILE_RZLT[i][j] << ' ';
			output_rzlt << endl;
		}
	}
	output_rzlt.close();


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
	k = rand() % 10 + 5;

	vector < vector <string> > RW(n, vector <string>(m));
	vector <int> LS(n); // уровни допуска субъектов s
	vector <int> LO(m); // уровень секретности объектов o

	cout << "генерация rw" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			RW[i][j] = RWOX_gen();

	ofstream output_environ;
	output_environ.open("environ.txt", fstream::in | fstream::out | fstream::trunc);
	if (output_environ.is_open())
	{
		output_environ << n << endl;
		output_environ << m << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				output_environ << RW[i][j] << " "; ////// !!!!!!!!!!!!!!!!!! ЗДЕСЬ ПРИДУМАТЬ РАЗДЕЛИТЕЛЬ МЕЖДУ пустыми RW смотреть коммент в 120 строке
			}

			output_environ << endl;
		}
	}
	output_environ.close();

	prgrm_writer(k, n, m);

	interpreter();


}