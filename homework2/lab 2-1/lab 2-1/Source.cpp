#include <iostream>
#include <wtypes.h>
#include <random>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int M, N = 0;
	vector<int> M_;
	vector<int> N_;
	vector <int>::iterator itr;
	int temp = 0;
	
	cin >> N >> M;
	vector <int> result1(100), result2(100); // 합, 교집합.

	cout << '\n';

	random_device rd;
	mt19937 gen_1(rd());

	uniform_int_distribution<__int64> dist1(0, 100); // 0~100까지의 랜덤한 숫자 생성

	for (int i = 0; i < N; i++) {

		temp = dist1(gen_1);
		itr = find(N_.begin(), N_.end(), temp); // 동일한 값이 있는지 찾음.

		if (itr != N_.end()) { // 이미 있다면 다시 랜덤값 생성
			i -= 1;
			continue;
		}
		else
		{
			N_.push_back(temp); // 없으면 그냥 집어넣는다.
		}
	}
	
	for (int j = 0; j < M; j++) { // B에 대해서도 같은 것을 반복.
		
		temp = dist1(gen_1);
		itr = find(M_.begin(), M_.end(), temp);

		if (itr != M_.end()) {
			j -= 1;
			continue;
		}
		else 
		{ M_.push_back(temp); }
	}

	sort(N_.begin(), N_.end());
	sort(M_.begin(), M_.end()); // 두 집합을 정렬한다. 정렬하지 않으면 집합 함수들 사용 불가능.

	cout << "집합 A - ";
	for (itr = N_.begin(); itr != N_.end(); itr++) {
		cout << *itr << " ";
	}
	
	cout << "\n";

	cout << "집합 B - ";
	for (itr = M_.begin(); itr != M_.end(); itr++) {
		cout <<  *itr << " ";
	} // 집합들을 출력한다.

	cout << "\n";

	itr = set_union(N_.begin(), N_.end(), M_.begin(), M_.end(), result1.begin());
	result1.resize(itr - result1.begin()); // 합집합을 생성하는 함수

	cout << "합집합 - ";

	for (itr = result1.begin(); itr != result1.end(); itr++) {
		cout << *itr << " ";
	}

	cout << "\n";

	itr = set_intersection(N_.begin(), N_.end(), M_.begin(), M_.end(), result2.begin());
	result2.resize(itr - result2.begin()); // 교집합을 생성하는 함수

	cout << "교집합 - ";

	for (itr = result2.begin(); itr != result2.end(); itr++) {
		cout << *itr << " ";
	}

	cout << "\n";

}