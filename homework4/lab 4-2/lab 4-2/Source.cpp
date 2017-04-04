#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

typedef int itemType;
int N_;
void merge(itemType a[], int l, int mid, int r);
void mergesort(itemType a[], int l, int r);

using namespace std;

int Compare_Cnt;
int DataMove_Cnt;

int main() 
{
	int N = 0; // 정렬하려는 배열의 크기

	int Compare_Cnt_A = 0;
	int Compare_Cnt_B = 0;

	int DataMove_Cnt_A = 0;
	int DataMove_Cnt_B = 0;

	cin >> N;
	N_ = N;

	int* N_vectorA = new int[N];
	int* N_vectorB = new int[N];

	for (int i = 0; i < N; i++)
	{
		N_vectorA[i] = i + 1;
	}

	copy(N_vectorA, N_vectorA + N, N_vectorB);
	// A의 내용을 B에 복사.
	random_shuffle(N_vectorB, N_vectorB + N);
	// 랜덤하게 재배치

	reverse(N_vectorA, N_vectorA + N); // A를 내림차순으로 바꾼다.

	mergesort(N_vectorA, 0, N - 1); // A 삽입 정렬

	Compare_Cnt_A = Compare_Cnt;
	DataMove_Cnt_A = DataMove_Cnt;

	DataMove_Cnt = 0;
	Compare_Cnt = 0;

	mergesort(N_vectorB, 0, N - 1); // B 삽입 정렬

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


void merge(itemType a[], int l, int mid, int r) {
	
	int i, j, k, n;
	int *sorted = new itemType[r + 1];

	i = l; 
	j = mid + 1;
	k = l;

	while (i <= mid && j <= r) {

		if (a[i] <= a[j]) 
		{
			sorted[k++] = a[i++];
			DataMove_Cnt++;
		}
		else {
			sorted[k++] = a[j++];
			DataMove_Cnt++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
		}
	}
	if (i > mid) {
		for (n = j; n <= r; n++) {
			sorted[k++] = a[n];
			Compare_Cnt++;
		}
	}
	else {
		for (n = i; n <= mid; n++) {
			sorted[k++] = a[n];
			Compare_Cnt++;
		}
	}
	for (n = l; n <= r; n++)
		a[n] = sorted[n];
}

void mergesort(itemType a[], int l, int r) 
{
	int mid;
	if (l < r) {
		mid = (l + r) / 2;
		mergesort(a, l, mid);
		mergesort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}



