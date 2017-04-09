#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

typedef int itemType;

itemType *a; // ���� �迭�� ����Ű�� ������
itemType *b; // ���� ���� �迭�� ����Ű�� ������
itemType *N_; // ī���Ϳ� ������


using namespace std;
void CountSort(itemType *a, itemType *b, itemType *N, int n, int k);

int Compare_Cnt;
int DataMove_Cnt;

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

	int* N_vectorA = new int[N]; // ���� �迭�� ����Ű�� �迭
	int* N_vectorB = new int[N]; // ���� �迭�� ����Ű�� �迭
	int* N_vectorC = new int[N]; // ���� �迭�� ����Ű�� �迭

	int* temp_A = new int[N]; // �����
	int* temp_B = new int[N]; // �����

	b = new itemType[N]; // ���� ���� �迭�� ����Ű�� ������
	N_ = new itemType[N]; // ī��Ʈ�� �迭, N[i] �� i�� ���� ����.

	for (int i = 0; i < N; i++)
	{
		N_vectorA[i] = i + 1; // 0�� ����, 1~N����.
	}

  	copy(N_vectorA, N_vectorA + N, N_vectorB);
	// A�� ������ B�� ����.
	random_shuffle(N_vectorB, N_vectorB + N);
	// �����ϰ� ���ġ

 	srand((unsigned)time(NULL));

	for (int x = 0; x < N; x++)
	{
		N_vectorC[x] = (int)rand() % N + 1; // 1���� N������ �ִ´�.
	}

	reverse(N_vectorA, N_vectorA + N); // A�� ������������ �ٲ۴�.

	CountSort(N_vectorA, b, N_, N, N); // A counting ����
	
	for (int x = 0; x <= 30; x++)
	{
		temp_A[x] = b[x];
	} // ����

	/*
	for (int x = 1; x <= 30; x++)
	{
		printf("%d ", b[x]);
	}
	//*/

	Compare_Cnt_A = Compare_Cnt;
	DataMove_Cnt_A = DataMove_Cnt;

	DataMove_Cnt = 0;
	Compare_Cnt = 0;

	CountSort(N_vectorB, b, N_, N, N); // B counting ����

	for (int x = 0; x <= 30; x++)
	{
		temp_B[x] = b[x];
	} // ����

	Compare_Cnt_B = Compare_Cnt;
	DataMove_Cnt_B = DataMove_Cnt;

	DataMove_Cnt = 0;
	Compare_Cnt = 0;

	CountSort(N_vectorC, b, N_, N, N); // C counting ����

	Compare_Cnt_C = Compare_Cnt;
	DataMove_Cnt_C = DataMove_Cnt;

	cout << "SortedData_A: ";
	
	//*
	for (int x = 1; x <= 30; x++)
	{
		printf("%d ", temp_A[x]);
	}
	//*/

	cout << "\n";

	cout << "SortedData_B: ";
	//*
	for (int y = 1; y <= 30; y++) {
		cout << temp_B[y] << " ";
	}
	//*/

	cout << "\n";

	cout << "SortedData_C: ";
	//*
	for (int z = 1; z <= 30; z++) {
		cout << b[z] << " ";
	}
	//*/

	cout << "\n";
	cout << "\n";

	cout << "Compare_Cnt_A : " << Compare_Cnt_A;
	cout << ", DataMove_Cnt_A : " << DataMove_Cnt_A << endl;;

	cout << "Compare_Cnt_B : " << Compare_Cnt_B;
	cout << ", DataMove_Cnt_B : " << DataMove_Cnt_B << endl;

	cout << "Compare_Cnt_C : " << Compare_Cnt_C;
	cout << ", DataMove_Cnt_C : " << DataMove_Cnt_C << endl;

	cout << "\n";

	return 0;
}

void CountSort(itemType *a, itemType *b, itemType *N, int n, int k) 
{ // �Ѱ��� �迭 a, �� �迭 b, �� ī���ÿ� �迭 N, n ������ ��, k �迭�� ũ��?
	int i;

	for (i = 0; i <= k; i++)
		N[i] = 0;  // ��� N[i] �迭�� 0���� ä���.

	for (i = 1; i < n; i++)
		N[a[i]] = N[a[i]] + 1; // 1 ~ N ���� ���� Ƚ���� ī��Ʈ�Ѵ�.

	for (i = 2; i <= k; i++) 
		N[i] = N[i] + N[i - 1];

	for (i = n-1; i >= 1; i--) 
	{
		b[N[a[i]]] = a[i];
		N[a[i]] = N[a[i]] - 1;
		DataMove_Cnt++;
	}
	DataMove_Cnt += 1;
}
