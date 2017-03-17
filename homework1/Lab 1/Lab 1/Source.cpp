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

	while (1) { // ���� �ݺ�.

		temp_.clear(); // ���� �ʱ�ȭ 

		printf("N�� �Է��ϼ���.\n");

		cin >> N_; // N�� �Է¹޴´�.

		for (int x = 0; x < N_.length(); x++) { // ���ڿ��� ��ü �м�
			temp = N_.at(x);
			if (temp < 0) // ���� ���� ������ ��� ������ ����Ǳ� ������ �̸� �Ÿ���.
			{
				cout << "�� ���ھƴϾ�~" << endl;
				return 0;
			}
			else if (!isdigit(temp)) { // �ϳ��� ���ڰ� �ƴ϶��

				cout << N_;
				cout << "�� ���ڰ� �ƴմϴ�. ���α׷� ����! " << endl;

				return 0; // ���ڰ� �ƴ� �� ���α׷� ����
			}
			else if (isdigit(temp) && (x == N_.length() - 1)) {

				// ��� ���ڰ� 1�̰� ���ڿ��� ���̶��,

				cout << N_;
				cout << "�� �����Դϴ�. �� ���� ������ �Ҽ��� ����մϴ� " << endl;

				N = stoi(N_); // ��Ʈ���� ���ڷ� �ٲ۴�.

				int* a = new int[N + 1]; // ���ڶ�� �迭�� ���� �Ҵ�
				// �����佺�׳׽��� ü �˰���.
				for (a[1] = 0, i = 2; i <= N; i++) { a[i] = 1; }
				// a[1]�� 0����, i=2���� N���� ��� �ε������� 1�� �ʱ�ȭ.
				// ��, 1�� ������ ���ڵ��� �Ҽ��� ���� ����.
				for (i = 2; i <= N / 2; i++) { // 
					for (j = 2; j <= N / i; j++)
					{
						a[i*j] = 0; // i�� ������� ��� �Ҽ��� �ƴ� ������.
					}
				} // �� ������ ������ 1�� �ڽŸ��� ����� �Ҽ��� ���� �ȴ�.

				for (i = 1; i <= N; i++) {
					if (a[i]) { 
						cout << i << ' ';
						temp_.push_back(i);
						// a[i]�� 0�� �ƴ϶�� ��� �� ���Ϳ� �ִ´�.
					}
				}
						
				cout << '\n';
			}
			else
				continue;
		}

		iter = find(temp_.begin(), temp_.end(), N); // N�� �ִ��� Ž��.

		if (iter == temp_.end()) // N�� �Ҽ��� �ƴ϶��
		{
			printf("The number %d is not prime.\n", N);
			printf("There is %d prime numbers smaller than %d\n", temp_.size(), N);
		}
		else // �Ҽ����
		{
			printf("The number %d is prime.\n", N);
			printf("There is %d prime numbers smaller than %d\n", temp_.size() - 1, N);
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

/*
1. �ѱ� ������?
*/
