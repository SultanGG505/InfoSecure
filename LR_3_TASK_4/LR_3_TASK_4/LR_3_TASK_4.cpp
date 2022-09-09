#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <Windows.h>

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

	vector < multiset < char > > frst(n, multiset < char >());
	vector < multiset < char > > scnd(m, multiset < char >());

	vector <string> cutted_text;
	stringstream SpaceCutter(text);
	while (SpaceCutter >> unspaced)
	{
		cutted_text.push_back(unspaced);
	}
	
	cutted_text.erase(cutted_text.begin(), cutted_text.begin()+2);
	
	/*vector < set < int > > vec(count, set< int >());*/
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < cutted_text[i].size(); j++)
		{
			string tmp = cutted_text[i];
			frst[i].insert(tmp[j]);
		}
		
	}
	cutted_text.erase(cutted_text.begin(), cutted_text.begin() + n);
	for (int d = 0; d < m; d++)
	{
		for (int j = 0; j < cutted_text[d].size(); j++)
		{
			string tmp = cutted_text[d];
			scnd[d].insert(tmp[j]);
		}
	}




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


