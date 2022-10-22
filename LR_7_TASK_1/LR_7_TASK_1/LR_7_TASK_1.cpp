#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <ctime>
#include <regex>
using namespace std;


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


	int cmd1 = rand() % 6 + 0;
	/*if (cmd1 == 2 || cmd1 == 3)
	{
		cmd1 = rand() % 5 + 0;
	}*/
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
				cout << i << " " << "cco" << endl;
				int ind = stoi(structed_CMD[i][1]);
				ind--;
				if (!(RW_FROM_FILE_RZLT.size() == 0 || RW_FROM_FILE_RZLT[0].size() == 0))
				{
					try
					{
						if (RW_FROM_FILE_RZLT[0].size() >= ind)
							for (int d = 0; d < RW_FROM_FILE_RZLT.size(); d++)
							{
								RW_FROM_FILE_RZLT[d].insert(RW_FROM_FILE_RZLT[d].begin() + ind, "R");
							}
						else
							for (int d = 0; d < RW_FROM_FILE_RZLT.size(); d++)
							{
								RW_FROM_FILE_RZLT[d].push_back("R");
							}
					}
					catch (...)
					{
						cout << "выполнить команду невозможно, команда -" << structed_CMD[i][0] << endl;
					}
				}
				else
					cout << "выполнить команду невозможно, команда -" << structed_CMD[i][0] << endl;


			}


			if (structed_CMD[i][0].find("ccs") != string::npos)
			{
				cout << i << " " << "ccs" << endl;
				int ind = stoi(structed_CMD[i][1]);
				ind--;
				vector <string> row = vector <string>(RW_FROM_FILE_RZLT[0].size(), "R");
				if (!(RW_FROM_FILE_RZLT.size() == 0 || RW_FROM_FILE_RZLT[0].size() == 0))
				{
					try
					{
						if (ind <= RW_FROM_FILE_RZLT.size())
							RW_FROM_FILE_RZLT.insert(RW_FROM_FILE_RZLT.begin() + ind, row);
						else
							RW_FROM_FILE_RZLT.push_back(row);
					}
					catch (...)
					{
						cout << "выполнить команду невозможно, команда -" << structed_CMD[i][0] << endl;
					}
				}
				else
					cout << "выполнить команду невозможно, команда -" << structed_CMD[i][0] << endl;


			}

			if (structed_CMD[i][0].find("cdo") != string::npos)
			{
				cout << i << " " << "cdo" << endl;
				int ind = stoi(structed_CMD[i][1]);
				ind--;

				if (!(RW_FROM_FILE_RZLT.size() == 0 || RW_FROM_FILE_RZLT[0].size() <= ind))
				{
					try
					{
						for (int d = 0; d < RW_FROM_FILE_RZLT.size(); d++)
						{
							RW_FROM_FILE_RZLT[d].erase(RW_FROM_FILE_RZLT[d].begin() + ind);
						}
					}
					catch (...)
					{
						cout << "выполнить команду невозможно, команда -" << structed_CMD[i][0] << endl;
					}
				}
				else
					cout << "выполнить команду невозможно, команда -" << structed_CMD[i][0] << endl;

			}

		if (structed_CMD[i][0].find("cds") != string::npos)
			{
				cout << i << " " << "cds" << endl;
				int ind = stoi(structed_CMD[i][1]);
				ind--;
				if (!(RW_FROM_FILE_RZLT.size() == 0 || RW_FROM_FILE_RZLT.size() <= ind))
				{
					try
					{
						RW_FROM_FILE_RZLT.erase(RW_FROM_FILE_RZLT.begin() + ind);
					}
					catch (...)
					{
						cout << "выполнить команду невозможно, команда -" << structed_CMD[i][0] << endl;
					}
				}
				else
					cout << "выполнить команду невозможно, команда -" << structed_CMD[i][0] << endl;


			}

		if (structed_CMD[i][0].find("cer") != string::npos) // добавить право
		{
			cout << i << " " << "cer" << endl;
			int ind_S = stoi(structed_CMD[i][1]);
			int ind_O = stoi(structed_CMD[i][2]);
			ind_S--; ind_O--;

			if (!(RW_FROM_FILE_RZLT.size() == 0 || RW_FROM_FILE_RZLT.size() <= ind_S || RW_FROM_FILE_RZLT[0].size() <= ind_O))
			{
				string input2 = structed_CMD[i][0];
				regex re2("cer = ");
				sregex_token_iterator first{ input2.begin(), input2.end(), re2, -1 }, last;//the '-1' is what makes the regex split (-1 := what was not matched)
				vector<string> tokens{ first, last };

				string temp = "";
				for (int z = 0; z < tokens.size(); z++)
					temp += tokens[z];

				regex re("'");
				sregex_token_iterator first2{ temp.begin(), temp.end(), re, -1 }, last2;
				vector<string> tokens2{ first2, last2 };
				string res = "";
				for (int z = 0; z < tokens2.size(); z++)
					res += tokens2[z];


				for (int inputInd = 0; inputInd < res.size(); inputInd++)
				{
					bool f = true;
					for (int nowInd = 0; nowInd < RW_FROM_FILE_RZLT[ind_S][ind_O].size(); nowInd++)
					{
						if (res[inputInd] == RW_FROM_FILE_RZLT[ind_S][ind_O][nowInd])
						{
							f = false;
							break;
						}
					}
					if (f)
					{
						RW_FROM_FILE_RZLT[ind_S][ind_O] += res[inputInd];
					}
				}


			}
		}

		if (structed_CMD[i][0].find("cdr") != string::npos)
		{
			cout << i << " " << "cdr" << endl;
			int ind_S = stoi(structed_CMD[i][1]);
			int ind_O = stoi(structed_CMD[i][2]);
			ind_S--; ind_O--;
			if (!(RW_FROM_FILE_RZLT.size() == 0 || RW_FROM_FILE_RZLT.size() <= ind_S || RW_FROM_FILE_RZLT[0].size() <= ind_O))
			{

				string input2 = structed_CMD[i][0];
				regex re2("cdr = ");
				sregex_token_iterator first{ input2.begin(), input2.end(), re2, -1 }, last;//the '-1' is what makes the regex split (-1 := what was not matched)
				vector<string> tokens{ first, last };

				string temp = "";
				for (int z = 0; z < tokens.size(); z++)
					temp += tokens[z];

				regex re("'");
				sregex_token_iterator first2{ temp.begin(), temp.end(), re, -1 }, last2;
				vector<string> tokens2{ first2, last2 };
				string res = "";
				for (int z = 0; z < tokens2.size(); z++)
					res += tokens2[z];

				for (int inputInd = 0; inputInd < res.size(); inputInd++)
				{
					for (int nowInd = 0; nowInd < RW_FROM_FILE_RZLT[ind_S][ind_O].size(); nowInd++)
					{
						if (res[inputInd] == RW_FROM_FILE_RZLT[ind_S][ind_O][nowInd])
						{
							RW_FROM_FILE_RZLT[ind_S][ind_O] = RW_FROM_FILE_RZLT[ind_S][ind_O].substr(0, nowInd) + RW_FROM_FILE_RZLT[ind_S][ind_O].substr(nowInd + 1, RW_FROM_FILE_RZLT[ind_S][ind_O].size() - nowInd - 1);
							break;
						}
					}
				}
				 
			}
		}
	}




	ofstream output_rzlt;
	output_rzlt.open("rzlt.txt", fstream::in | fstream::out | fstream::trunc);
	if (output_rzlt.is_open())
	{

		for (int i = 0; i < RW_FROM_FILE_RZLT.size(); i++) // строки
		{
			for (int j = 0; j < RW_FROM_FILE_RZLT[i].size(); j++) // столбцы
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