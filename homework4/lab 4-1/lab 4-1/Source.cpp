#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

typedef int itemType;
inline void swap(itemType a[], int i, int j);
void quicksort(itemType a[], int l, int r);

using namespace std;

int Compare_Cnt;
int DataMove_Cnt;

int main()
{
	int N = 0; // �����Ϸ��� �迭�� ũ��

	int Compare_Cnt_A = 0;
	int Compare_Cnt_B = 0;

	int DataMove_Cnt_A = 0;
	int DataMove_Cnt_B = 0;

	cin >> N;

	int* N_vectorA = new int[N];
	int* N_vectorB = new int[N]; // �迭 ���� �Ҵ�

	for (int i = 0; i < N; i++)
	{
		N_vectorA[i] = i + 1;
	}

	copy(N_vectorA, N_vectorA + N, N_vectorB);
	// A�� ������ B�� ����.
	random_shuffle(N_vectorB, N_vectorB + N);
	// �����ϰ� ���ġ

	reverse(N_vectorA, N_vectorA + N); // A�� ������������ �ٲ۴�.

	quicksort(N_vectorA, 0, N-1); // A ���� ����

	Compare_Cnt_A = Compare_Cnt;
	DataMove_Cnt_A = DataMove_Cnt;

	DataMove_Cnt = 0;
	Compare_Cnt = 0;

	quicksort(N_vectorB, 0, N-1); // B ���� ����

	Compare_Cnt_B = Compare_Cnt;
	DataMove_Cnt_B = DataMove_Cnt;

	cout << "SortedData_A: ";
	//*
	for (int x = 0; x < 30; x++)
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

	cout << "Compare_Cnt_A : " << Compare_Cnt_A;
	cout << ", DataMove_Cnt_A : " << DataMove_Cnt_A << endl;;

	cout << "Compare_Cnt_B : " << Compare_Cnt_B;
	cout << ", DataMove_Cnt_B : " << DataMove_Cnt_B << endl;

	cout << "\n";

	return 0;
}

inline void swap(itemType a[], int i, int j) // ��ġ�� �ٲٴ� �Լ�
{
	itemType  t = a[i]; // left
	a[i] = a[j]; // right
	a[j] = t;
	DataMove_Cnt++;
	DataMove_Cnt++;
}

int partition(itemType a[], int l, int r) {

	itemType v = a[l];
	int	i = l;
	int j = r + 1;

	if (r >= l) {
		
		for (;;)
		{
			while (a[++i] < v)
			{Compare_Cnt++;
			Compare_Cnt++;
			}
			while (a[--j] > v);
			{Compare_Cnt++;}
			if (i >= j) { break; }
			swap(a, i, j);
			DataMove_Cnt++;
		}
		swap(a, j, l);
		DataMove_Cnt++;
	}
	return j;
}


void quicksort(itemType a[], int l, int r) //�� ��Ʈ
{
	int  j;
	if (r >= l) 
	{	
		j = partition(a, l, r);
		quicksort(a, l, j - 1);
		quicksort(a, j + 1, r);
	}
}


