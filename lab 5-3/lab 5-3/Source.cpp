#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

typedef int itemType;
using namespace std;

int Compare_Cnt;
int DataMove_Cnt;

typedef struct node *node_pointer;
typedef struct node {
	itemType value;
	node_pointer next;
};
node_pointer TABLE[10], x, z, temp;
void radixSort(itemType *a, int n);

int main()
{
	int N = 0; // �����Ϸ��� �迭�� ũ��

	int Compare_Cnt_A = 0;
	int Compare_Cnt_B = 0;
	int Compare_Cnt_C = 0;

	int DataMove_Cnt_A = 0;
	int DataMove_Cnt_B = 0;
	int DataMove_Cnt_C = 0;

	cin >> N;

	int* N_vectorA = new int[N];
	int* N_vectorB = new int[N];
	int* N_vectorC = new int[N];

	for (int i = 0; i < N; i++)
	{
		N_vectorA[i] = i + 1;
	}

	copy(N_vectorA, N_vectorA + N, N_vectorB);
	// A�� ������ B�� ����.
	random_shuffle(N_vectorB, N_vectorB + N);
	// �����ϰ� ���ġ

	srand((unsigned)time(NULL));

	for (int x = 0; x < N; x++)
	{
		N_vectorC[x] = (int)rand() % N + 1;
	}

	reverse(N_vectorA, N_vectorA + N); // A�� ������������ �ٲ۴�.

	radixSort(N_vectorA, N); // A ���� ����

	Compare_Cnt_A = Compare_Cnt;
	DataMove_Cnt_A = DataMove_Cnt;

	DataMove_Cnt = 0;
	Compare_Cnt = 0;

	radixSort(N_vectorB, N); // B ���� ����

	Compare_Cnt_B = Compare_Cnt;
	DataMove_Cnt_B = DataMove_Cnt;

	DataMove_Cnt = 0;
	Compare_Cnt = 0;

	radixSort(N_vectorC, N); // C ���� ����

	Compare_Cnt_C = Compare_Cnt;
	DataMove_Cnt_C = DataMove_Cnt;

	cout << "SortedData_A: ";
	//*
	for (int x = 0; x <30; x++)
	{
		printf("%d ", N_vectorA[x]);
	}
	//*/

	cout << "\n";

	cout << "SortedData_B: ";
	//*
	for (int y = 0; y < 30; y++) {
		cout << N_vectorB[y] << " ";
	}
	//*/

	cout << "\n";

	cout << "SortedData_C: ";
	//*
	for (int z = 0; z < 30; z++) {
		cout << N_vectorC[z] << " ";
	}
	//*/

	cout << "\n";
	cout << "\n";

	cout << "Compare_Cnt_A : " << Compare_Cnt_A;
	cout << ", DataMove_Cnt_A : " << DataMove_Cnt_A << endl;

	cout << "Compare_Cnt_B : " << Compare_Cnt_B;
	cout << ", DataMove_Cnt_B : " << DataMove_Cnt_B << endl;

	cout << "Compare_Cnt_C : " << Compare_Cnt_C;
	cout << ", DataMove_Cnt_C : " << DataMove_Cnt_C << endl;

	cout << "\n";

	return 0;
}

void radixSort(itemType *a, int n) {
	int i, j, cnt, radix, radix_mod = 10, cipher = 0;
	i = n;
	
	while (i>0) { i = i / 10; cipher++; } // cipher : �Է� �������� �ڸ��� (ex. 450 -> 3)
	
	for (i = 0; i<cipher; i++) {
		for (j = 0; j<n; j++) {
			cnt = 0; 
			radix = (a[j] % radix_mod) / (radix_mod / 10);
			/* radix_mod = 10 �̸� radix�� a[j]�� ���� �ڸ���
			radix_mod = 100 �̸� radix�� a[j]�� ���� �ڸ��� */
			temp = new node; 
			temp->value = a[j]; 
			temp->next = z;
			DataMove_Cnt++; // 100000 (����)
			if (TABLE[radix] == z) {
				// z�� list�� ���� Ȯ���ϱ� ���� ��� ������ (NULL�� �ش�)
				TABLE[radix] = temp;
				DataMove_Cnt++; // 43
				DataMove_Cnt++;
			}
			else {
				x = TABLE[radix];
				while (x->next != z) {
					x = x->next;
				}
				x->next = temp;
			}
		}

		for (j = 0; j<10; j++) {
			if (TABLE[j] != z) {
				x = TABLE[j];
				while (x != z) {
					a[cnt++] = x->value;
					temp = x; // �޸𸮿��� ��带 �����ϱ� ���� �ӽ� ����
					x = x->next;
					DataMove_Cnt++; // 10000 (����)
					delete temp; // �迭�� �̹� ���� ��带 �޸𸮿��� ����
				}
			}
			TABLE[j] = z;
			// 50
		}
		radix_mod *= 10;
	}
}
