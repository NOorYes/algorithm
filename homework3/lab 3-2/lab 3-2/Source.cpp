#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

typedef int itemType;
void shellSort(itemType a[], int n);

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

	shellSort(N_vectorA, N); // A 삽입 정렬

	Compare_Cnt_A = Compare_Cnt;
	DataMove_Cnt_A = DataMove_Cnt;

	DataMove_Cnt = 0;
	Compare_Cnt = 0;

	shellSort(N_vectorB, N); // B 삽입 정렬

	Compare_Cnt_B = Compare_Cnt;
	DataMove_Cnt_B = DataMove_Cnt;

	cout << "SortedData_A: ";
	//*
	for (int x = 0; x < 30; x++)
	{
	printf("%d ",N_vectorA[x]);
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

void shellSort(itemType a[], int n)
{
	int i, j, h; 
	itemType v;
	h = 1;  
	
	do h = 3 * h + 1; 
	while (h < n);
	Compare_Cnt++;
	do {
		h = h / 3;
		for (i = h; i < n; i++)
		{
			Compare_Cnt++;
			v = a[i]; 
			j = i;
			DataMove_Cnt++;
			while (a[j - h] > v)
			{
				Compare_Cnt++;
				a[j] = a[j - h]; 
				DataMove_Cnt++;
				j -= h;  
				if (j < h - 1) {break;}
			}
			a[j] = v;
			DataMove_Cnt++;
		}
	} while (h > 1);
}

