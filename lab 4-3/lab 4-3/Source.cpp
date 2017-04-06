#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <utility>

using namespace std;

int main()
{
	int i, j = 0;
	ifstream input("datafile.txt");
	string inputString;
	int count = 0;
	int fin = 0;
	int t = 0;
	int start = 0;
	int end = 0;
	map<string, int> temp;
	pair<int, string> temp2;
	vector<pair<int, string>> temp3;
	vector<pair<int, string>> temp4;
	bool flag = false;

	if (!input.is_open())
	{
		cout << "Not found." << endl;
	}
	else
	{
		while (!input.eof()) // ������ ���� ������
		{
			count++;
			input >> inputString;
			// ���⼭ ���ڿ��� Ư�� ���ڷ� �ڸ��� ��.
			if (inputString.find("/") != string::npos)
			{	
				string one(inputString, 0, inputString.find("/"));
				string two(inputString, inputString.find("/") + 1);
				
				// /�� �������� �� ��Ʈ������ �и��Ѵ�.
				
				if (temp.count(one)) temp[one]++;
				else temp[one] = 1;
				
				if (temp.count(two)) temp[two]++;
				else temp[two] = 1;

				one.clear();
				two.clear();

				continue;
			}
			else if (inputString.find(".") != string::npos) {
				string one(inputString, 0, inputString.find("."));
				if (temp.count(one)) temp[one]++;
				else temp[one] = 1;
				one.clear();
			}
			else if (inputString.find(",") != string::npos) {
				string one(inputString, 0, inputString.find(","));
				if (temp.count(one)) temp[one]++;
				else temp[one] = 1;
				one.clear();
			}
			else {
				// Ư�� ���ڵ��� ã��, ���� ������ �ű������ �����ؼ� �ִ´�.
				// / �� ��� �ű������ ������ �������� �����ؼ� �� ��Ʈ���� ���� ������ �ɰŰ��⵵.
				if (temp.count(inputString)) temp[inputString]++;
				else temp[inputString] = 1;
			}
			
			//cout << count << "��° ���ڿ� : " << inputString << endl;
			
		}
		
		// �����ؾ� �Ѵ�. ���� ���� ū ������� �����ϰ�, ���� ������ ������ �ƽ�Ű�ڵ� ���ϸ� �� ��.


		for (map<string, int>::iterator iter = temp.begin(); iter != temp.end(); iter++)
		{
			temp2.first = iter->second; // ��
			temp2.second = iter->first; // �ܾ�
			temp3.push_back(temp2);

			//cout << iter->first << ": " << iter->second << endl;
		}
	}
		sort(temp3.begin(), temp3.end());
		//reverse(temp3.begin(), temp3.end());

		for (int x = temp3.size() - 1; x >= 0; x--)
		{ 
			if (temp3[x].first == 1) { // 1�� ������ ���� �׳� �ű���� ó������ ���.
				for (int u = 0; u <= x+1; u++) {
					cout << temp3[u].second << ": " << temp3[u].first << endl;
				}
				break;
			}

			if (t != temp3[x].first) {// �󵵰� ���� ������
				if (flag == true) // �󵵰� ���� �ʰ� �̹� �ѹ� ���ƿԴٸ�
				{
					temp4.push_back(temp3[x]);
					t = temp3[x].first;
					for (int z = 0; z < temp4.size(); z++)
						cout << temp4[z].second << ": " << temp4[z].first << endl;
					temp4.clear();
					flag = false; // ���ƿ��� ���� ���·�.
				}
				else {// �ѹ� ���ϵƴ� ���°� �ƴϸ�
					t = temp3[x].first; // ���� �����ϰ�
					temp4.push_back(temp3[x]);
					flag = true; // ���ư�!
					continue;
				}
			}//*
			else {// �󵵰� ������
				for (int y = x; y >= 0; y--) { // ��� ���Ƽ�
					if (t != temp3[y].first) { // �󵵰� ���� �ʰ� �Ǹ�
						t = temp3[x].first; // ���� �����ϰ�
						x = y; // x�� ����
						
						for (int z = temp4.size() - 1; z >= 0; z--) // ����Ѵ�.
							cout << temp4[z].second << ": " << temp4[z].first << endl;
						
						break;
					}
					temp4.push_back(temp3[x]);
				}
			} //*/
			
		}
		// ���ʺ��� �ʿ� �����߱� ������ ���� �������(�ƽ�Ű �ڵ���) �迭�Ǿ� �ִ�.
		/*
		for (size_t i = 0; i < temp3.size(); i++)
		{
			cout << temp3[i].second << ": " << temp3[i].first << endl;
		}
		//*/
		input.close();
		return 0;
}

