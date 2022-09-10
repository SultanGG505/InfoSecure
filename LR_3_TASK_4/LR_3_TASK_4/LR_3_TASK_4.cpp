#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <map>
#include <algorithm>

using namespace std;

int main() {

	string temp, text, unspaced;
	int n, m;
	ifstream Stream("C:\\Users\\sulta\\OneDrive\\Рабочий стол\\lr_3_task_4.txt", fstream::in | fstream::out | fstream::app);
	if (Stream.is_open())
	{
		while (!Stream.eof())
		{
			getline(Stream, temp);
			text += temp + " ";
		}
	}
	Stream.close();

	n = text[0] - '0';
	m = text[2] - '0';

	vector <string> cutted_text, copy_text;
	stringstream SpaceCutter(text);
	while (SpaceCutter >> unspaced)
	{
		cutted_text.push_back(unspaced);
	}

	cutted_text.erase(cutted_text.begin(), cutted_text.begin() + 2);
	copy_text = cutted_text;

	vector<string> frst;
	vector<string> scnd;


	for (int i = 0; i < n; i++)
	{
		frst.push_back(cutted_text[i]);
	}
	cutted_text.erase(cutted_text.begin(), cutted_text.begin() + n);

	for (int d = 0; d < m; d++)
	{
		scnd.push_back(cutted_text[d]);

	}

	//for (int i = 0; i < V.size(); i++) {
	//	temp = V[i];
	//	rotate(temp.rbegin(), temp.rbegin() + 3, temp.rend());
	//	cout << temp << endl;
	//	Result << temp << endl;
	//}

	fstream Result;
	//string ResText;
	//map <string, int> counts;
	vector <int> counts(scnd.size(), 0);
	/*vector <int> for_only_one(scnd.size(), 0);*/
	//vector<string> for_one(scnd.size(), "");
	Result.open("C:\\Users\\sulta\\OneDrive\\Рабочий стол\\LR_3_TASK_4_RESULT.txt", fstream::in | fstream::out | fstream::app);
	if (Result.is_open())
	{

		for (int i = 0; i < m; i++) //scnd
		{
			int k_coun = 0;
			string mem = "";
			for (int d = 0; d < n; d++) //first
			{
				string tmpF = scnd[i];
				string tmpS = frst[d];
				string copy = tmpS;
				string res = "";
				string buf;

				if (tmpF.size() < tmpS.size())
				{
					buf = tmpF;
					tmpF = tmpS;
					tmpS = buf;
				}

				for (int k = 0; k < tmpF.size(); k++)
				{
					if (res.size() <= 1)
					{
						int flag = 1;
						for (int j = 0; j < tmpS.size(); j++)
						{

							if (tmpF[k] == tmpS[j])
							{
								flag = 0;
							}
						}
						if (flag/* && ((tmpF.size() - tmpS.size()) <= 1)*/)
						{
							res += tmpF[k];
						}

					}
				}
				if ((res.size() == 0 || res.size() == 1) && ((tmpF.size() - tmpS.size()) <= 1))
				{
					k_coun++;
					counts[i] = k_coun;
					mem = copy;
				}

				/*if ((res.size() == 0 || res.size() == 1) && ((tmpF.size() - tmpS.size()) <= 1))
				{
					counts.insert(make_pair(mem, 1));
					Result << tmpS << " " << res.size() << " " << tmpF << endl;
					ResText += tmpS + " " + to_string(res.size()) + " " + tmpF;
				}*/


			}

			if (k_coun == 1)
				Result << scnd[i] << " " << counts[i] << " " << mem << endl;
			else
				Result << scnd[i] << " " << counts[i] << endl;
		}
		//for (int i = 0; i < m; i++)
		//{
		//	/*cout << scnd[i] << " " << counts[i] << endl;*/
		//	
		//}
	}

	Result.close();

}

// заполняем каждый объект set в векторе
/*int num = 0;
for (vector < set < int > >::iterator it = frst.begin(); it != frst.end(); ++it, ++num) {
vec[num].insert(num);
vec[num].insert(num + 1);*/


//// выводим содержимое каждого объекта set в векторе
//for (vector < set < int > >::iterator it = vec.begin(); it != vec.end(); ++it) {
//    for (set< int >::const_iterator cit = it->begin(); cit != it->end(); ++cit)
//        cout << *cit << " ";

//    cout << endl;
//}

//
//vector < multiset < char > > frst(n, multiset < char >());
//vector < multiset < char > > scnd(m, multiset < char >());
//
//vector <string> f;
//

///*vector < set < int > > vec(count, set< int >());*/
//
//for (int i = 0; i < n; i++)
//{
//	for (int j = 0; j < cutted_text[i].size(); j++)
//	{
//		string tmp = cutted_text[i];
//		frst[i].insert(tmp[j]);
//	}
//}
//
//cutted_text.erase(cutted_text.begin(), cutted_text.begin() + n);
//
//for (int d = 0; d < m; d++)
//{
//	for (int j = 0; j < cutted_text[d].size(); j++)
//	{
//		string tmp = cutted_text[d];
//		scnd[d].insert(tmp[j]);
//	}
//}
//
//multiset <char> tempp = {};
//
//
//it = std::set_symmetric_difference(frst, frst[1], scnd, scnd[1], v.begin());
////  5 15 25 30 40 50  0  0  0  0
//v.resize(it - v.begin());                      //  5 15 25 30 40 50
//
//std::cout << "The symmetric difference has " << (v.size()) << " elements:\n";
//for (it = v.begin(); it != v.end(); ++it)
//std::cout << ' ' << *it;
//std::cout << '\n';
