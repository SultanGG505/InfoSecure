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

	vector < vector <string> > RW_FROM_FILE_RZLT(n, vector <string>(m));
	string input = "";
	regex re("[ ]");

	for (int i = 0; i < n; i++) // субъекты
	{
		input = temp_N_M_A[i];
		sregex_token_iterator first{ input.begin(), input.end(), re, -1 }, last;
		vector<string> tokens{ first, last };
		for (int j = 0; j < m; j++) // объекты
		{
			RW_FROM_FILE_RZLT[i][j] = tokens[j];
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





	//InputAlpha(n);
	//Process();
	//ofstream Output_LS;
	//Output_LS.open("LS.txt", fstream::in | fstream::out | fstream::trunc);
	//if (Output_LS.is_open())
	//{
	//	Output_LS << result << endl;
	//}
	//Output_LS.close();
	//CompObj.clear();
	//result = "";

	//InputAlpha(m);
	//Process();
	//ofstream Output_LO;
	//Output_LO.open("LO.txt", fstream::in | fstream::out | fstream::trunc);
	//if (Output_LO.is_open())
	//{
	//	Output_LO << result << endl;
	//}
	//Output_LO.close();
	//CompObj.clear();
	//result = "";

	//vector <string> LS_s, LO_s;

	//string LS_, LO_;
	//ifstream inp_LS("LS.txt");
	//while (getline(inp_LS, LS_)) {
	//	LS_s.push_back(LS_);
	//}
	//inp_LS.close();

	//ifstream inp_LO("LO.txt");
	//while (getline(inp_LO, LO_)) {
	//	LO_s.push_back(LO_);
	//}
	//inp_LO.close();

	//LS_s.pop_back();
	//LO_s.pop_back();

	////string temp = "cat";
	////char tab2[1024];
	////strcpy_s(tab2, temp.c_str());

	////char c = '1';
	////int i = c - '0'; // i is now equal to 1, not '1'

	//bool ok = false;
	//int k = 0, d = 0;
	//string TMP_S, TMP_O;
	//while (ok != true)
	//{

	//	TMP_S = LS_s[k];
	//	/*vector<int> v(TMP_S.size());*/
	//	transform(TMP_S.begin(), TMP_S.end(), LS.begin(), [](char c) {return c - '0'; });
	//	k++;
	//	if (ok)
	//		break;
	//	for (int i = 0; i < n; i++) // субъекты LS
	//	{
	//		if (ok)
	//			break;
	//		TMP_O = LO_s[d];
	//		/*vector<int> v(TMP_S.size());*/
	//		transform(TMP_O.begin(), TMP_O.end(), LO.begin(), [](char c) {return c - '0'; });
	//		d++;
	//		for (int j = 0; j < m; j++) // объекты LO
	//		{
	//			if (RW[i][j].size() == 2)
	//			{
	//				if (((LS[i] > LO[j] && RW[i][j][1] == 'W') || (LS[i] <= LO[j] && RW[i][j][0] == 'R')))
	//				{
	//					ok = true;
	//					break;
	//				}
	//			}
	//			if (RW[i][j].size() == 1)
	//			{
	//				if (((LS[i] > LO[j] && RW[i][j] == "W") || (LS[i] <= LO[j] && RW[i][j] == "R")))
	//				{
	//					ok = true;
	//					break;
	//				}
	//			}
	//		}

	//	}
	//}
	//cout << "Вывод сгенерированной матрицы на права записи и чтения" << endl;

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//		cout << RW[i][j] << ' ';
	//	cout << endl;
	//}

	//cout << "Вывод сгенерированного массива уровней допуска субъектов S" << endl;

	//for (int i = 0; i < n; i++)
	//	cout << LS[i] << " ";

	//cout << endl;

	//cout << "Вывод сгенерированного массива уровней секретности объектов O" << endl;

	//for (int i = 0; i < m; i++)
	//	cout << LO[i] << " ";

	//cout << endl;


	//if (ok)
	//	cout << "Система соответствует критерию безопасности Белла - Лападулы" << endl;
	//else
	//	cout << "Система НЕ соответствует критерию безопасности Белла - Лападулы" << endl;

}