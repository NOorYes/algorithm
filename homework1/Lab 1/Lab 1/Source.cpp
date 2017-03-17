#include <iostream> 
#include <ctype.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	string N_;
	char temp;
	int i, j;
	int N = 0;
	vector<int> temp_;
	vector<int>::iterator iter;

	while (1) { // 무한 반복.

		temp_.clear(); // 벡터 초기화 

		printf("N을 입력하세요.\n");

		cin >> N_; // N을 입력받는다.

		for (int x = 0; x < N_.length(); x++) { // 문자열들 전체 분석
			temp = N_.at(x);
			if (temp < 0) // 영어 외의 문자인 경우 음수로 저장되기 때문에 미리 거른다.
			{
				cout << "응 숫자아니야~" << endl;
				return 0;
			}
			else if (!isdigit(temp)) { // 하나라도 숫자가 아니라면

				cout << N_;
				cout << "는 숫자가 아닙니다. 프로그램 종료! " << endl;

				return 0; // 숫자가 아닐 시 프로그램 종료
			}
			else if (isdigit(temp) && (x == N_.length() - 1)) {

				// 모든 문자가 1이고 문자열의 끝이라면,

				cout << N_;
				cout << "는 숫자입니다. 이 숫자 이하의 소수를 출력합니다 " << endl;

				N = stoi(N_); // 스트링을 숫자로 바꾼다.

				int* a = new int[N + 1]; // 숫자라면 배열을 동적 할당
				// 에라토스테네스의 체 알고리즘.
				for (a[1] = 0, i = 2; i <= N; i++) { a[i] = 1; }
				// a[1]은 0으로, i=2부터 N까지 모든 인덱스들을 1로 초기화.
				// 즉, 1을 제외한 숫자들을 소수로 놓은 상태.
				for (i = 2; i <= N / 2; i++) { // 
					for (j = 2; j <= N / i; j++)
					{
						a[i*j] = 0; // i의 배수들은 모두 소수가 아닌 것으로.
					}
				} // 이 과정을 끝내면 1과 자신만이 약수인 소수만 남게 된다.

				for (i = 1; i <= N; i++) {
					if (a[i]) { 
						cout << i << ' ';
						temp_.push_back(i);
						// a[i]가 0이 아니라면 출력 후 벡터에 넣는다.
					}
				}
						
				cout << '\n';
			}
			else
				continue;
		}

		iter = find(temp_.begin(), temp_.end(), N); // N이 있는지 탐색.

		if (iter == temp_.end()) // N이 소수가 아니라면
		{
			printf("The number %d is not prime.\n", N);
			printf("There is %d prime numbers smaller than %d\n", temp_.size(), N);
		}
		else // 소수라면
		{
			printf("The number %d is prime.\n", N);
			printf("There is %d prime numbers smaller than %d\n", temp_.size() - 1, N);
		}

		cout <<" "<< endl;
	}
}

// 프로그램을 실행해보고, 동작원리를 설명하시오, 
// 또한 입력으로 2,3을 사용하였을 때의 결과를 출력하시오.

/*
printf("The number N is prime."); // 이 수가 소수라면
printf("The number N is not prime."); // 이 수가 소수가 아니라면
*/

// N_ >= 48 && N_ <= 57

/*
1. 한글 낱말은?
*/
