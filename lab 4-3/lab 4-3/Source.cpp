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
		while (!input.eof()) // 파일이 끝날 때까지
		{
			count++;
			input >> inputString;
			// 여기서 문자열을 특수 문자로 자르면 됨.
			if (inputString.find("/") != string::npos)
			{	
				string one(inputString, 0, inputString.find("/"));
				string two(inputString, inputString.find("/") + 1);
				
				// /을 기준으로 두 스트링으로 분리한다.
				
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
				// 특수 문자들을 찾고, 만약 있으면 거기까지를 복사해서 넣는다.
				// / 의 경우 거기까지랑 문자의 끝까지를 복사해서 두 스트링을 각각 넣으면 될거같기도.
				if (temp.count(inputString)) temp[inputString]++;
				else temp[inputString] = 1;
			}
			
			//cout << count << "번째 문자열 : " << inputString << endl;
			
		}
		
		// 정렬해야 한다. 먼저 값이 큰 순서대로 나열하고, 같은 구간이 있으면 아스키코드 비교하면 될 듯.


		for (map<string, int>::iterator iter = temp.begin(); iter != temp.end(); iter++)
		{
			temp2.first = iter->second; // 빈도
			temp2.second = iter->first; // 단어
			temp3.push_back(temp2);

			//cout << iter->first << ": " << iter->second << endl;
		}
	}
		sort(temp3.begin(), temp3.end());
		//reverse(temp3.begin(), temp3.end());

		for (int x = temp3.size() - 1; x >= 0; x--)
		{ 
			if (temp3[x].first == 1) { // 1을 만나는 순간 그냥 거기부터 처음까지 출력.
				for (int u = 0; u <= x+1; u++) {
					cout << temp3[u].second << ": " << temp3[u].first << endl;
				}
				break;
			}

			if (t != temp3[x].first) {// 빈도가 같지 않으면
				if (flag == true) // 빈도가 같지 않고 이미 한번 돌아왔다면
				{
					temp4.push_back(temp3[x]);
					t = temp3[x].first;
					for (int z = 0; z < temp4.size(); z++)
						cout << temp4[z].second << ": " << temp4[z].first << endl;
					temp4.clear();
					flag = false; // 돌아오지 않은 상태로.
				}
				else {// 한번 리턴됐던 상태가 아니면
					t = temp3[x].first; // 값을 갱신하고
					temp4.push_back(temp3[x]);
					flag = true; // 돌아가!
					continue;
				}
			}//*
			else {// 빈도가 같으면
				for (int y = x; y >= 0; y--) { // 계속 돌아서
					if (t != temp3[y].first) { // 빈도가 같지 않게 되면
						t = temp3[x].first; // 값을 갱신하고
						x = y; // x를 갱신
						
						for (int z = temp4.size() - 1; z >= 0; z--) // 출력한다.
							cout << temp4[z].second << ": " << temp4[z].first << endl;
						
						break;
					}
					temp4.push_back(temp3[x]);
				}
			} //*/
			
		}
		// 애초부터 맵에 저장했기 때문에 사전 순서대로(아스키 코드대로) 배열되어 있다.
		/*
		for (size_t i = 0; i < temp3.size(); i++)
		{
			cout << temp3[i].second << ": " << temp3[i].first << endl;
		}
		//*/
		input.close();
		return 0;
}

