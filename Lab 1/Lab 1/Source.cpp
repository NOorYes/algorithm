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
	int pnum; // �� ���ں��� '����' �Ҽ��� ����.

	while (1) {

		printf("N�� �Է��ϼ���.\n");

		cin >> N_; // N�� �Է¹޴´�.

		for (int i = 0; i < N_.length(); i++) { // ���ڿ��� ��ü �м�
			temp = N_.at(i);
			if (!isdigit(temp)) { // �ϳ��� ���ڰ� �ƴ϶��

				cout << N_;
				cout << "�� ���ڰ� �ƴմϴ�. ���α׷� ����! " << endl;

				return 0; // ���ڰ� �ƴ� �� ���α׷� ����
			}
			else if (isdigit(temp) && (i == N_.length() - 1)) {

				// ��� ���ڰ� 1�̰� ���ڿ��� ���̶��,

				cout << N_;
				cout << "�� �����Դϴ�. �� ���� ������ �Ҽ��� ����մϴ� " << endl;

				N = stoi(N_); // ���ڷ� �ٲ۴�.

				int* a = new int[N + 1]; // ���ڶ�� ���� �Ҵ�

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

// ���α׷��� �����غ���, ���ۿ����� �����Ͻÿ�, 
// ���� �Է����� 2,3�� ����Ͽ��� ���� ����� ����Ͻÿ�.

/*
printf("The number N is prime."); // �� ���� �Ҽ����
printf("The number N is not prime."); // �� ���� �Ҽ��� �ƴ϶��
*/

// N_ >= 48 && N_ <= 57