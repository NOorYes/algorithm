#include <iostream> 
#include <ctype.h>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

	string N_;
	char temp;
	int i, j;
	int N = 0;
	int pnum; // 이 숫자보다 '작은' 소수의 개수.

	while (1) {

		printf("N을 입력하세요.\n");

		cin >> N_; // N을 입력받는다.

		for (int i = 0; i < N_.length(); i++) { // 문자열들 전체 분석
			temp = N_.at(i);
			if (!isdigit(temp)) { // 하나라도 숫자가 아니라면

				cout << N_;
				cout << "는 숫자가 아닙니다. 프로그램 종료! " << endl;

				return 0; // 숫자가 아닐 시 프로그램 종료
			}
			else if (isdigit(temp) && (i == N_.length() - 1)) {

				// 모든 문자가 1이고 문자열의 끝이라면,

				cout << N_;
				cout << "는 숫자입니다. 이 숫자 이하의 소수를 출력합니다 " << endl;

				N = stoi(N_); // 숫자로 바꾼다.

				int* a = new int[N + 1]; // 숫자라면 동적 할당

				for (a[1] = 0, i = 2; i <= N; i++) { a[i] = 1; }

				for (i = 2; i <= N / 2; i++) {
					for (j = 2; j <= N / i; j++)
					{
						a[i*j] = 0;
					}
				}

				for (i = 1; i <= N; i++)
					if (a[i]) cout << i << ' ';
				
				cout << '\n';
			}
			else
				continue;
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