#include <iostream>
#include <algorithm>

typedef int itemType;
void bubbleSort(itemType a[], int n);
int Bubble(int sorted, itemType *a, int n);
void shellSort(itemType a[], int n);
void insertion(itemType a[], int n);

using namespace std;

long long int result_I = 0;
long long int result_B = 0;
long long int result_S = 0;

int main()
{
	int N = 0; // 정렬하려는 배열의 크기

	cin >> N;

	int* N_vectorA = new int[N];
	int* N_vectorB = new int[N];
	int* N_vectorC = new int[N];
	
	for (int i = 0; i < N; i++)
	{
		N_vectorA[i] = i + 1;
	}
	
	reverse(N_vectorA, N_vectorA + N); // 맨 처음의 선반 상태.

	copy(N_vectorA, N_vectorA + N, N_vectorB);
	copy(N_vectorA, N_vectorA + N, N_vectorC); // 똑같은거 3개 만들기.

	bubbleSort(N_vectorA, N); 
	shellSort(N_vectorB, N);
	insertion(N_vectorC, N); // 정렬 3종세트 실행

	cout << "\n";

	cout << " Insertion Sort : " << result_I << endl;
	cout << " Bubble Sort : " << result_B << endl;
	cout << " ShellSort : " << result_S << endl;

	cout << "\n";

	return 0;
}

int Bubble(int sorted, itemType *a, int n)
{
	int temp;
	if (*(a - 1) > *a) // (a-1) 이 a 보다 더 크다면
	{
		temp = *a; // 큰 물건을 내려 놓고 -> 작은 물건을 내려 놓고,
		*a = *(a - 1); // a -1 의 자리에 a를 놓는다. -> a의 자리에 a-1을 놓는다.
		*(a-1) = temp; // a의 자리에 a -1을 놓는다. -> a-1의 자리에 a를 놓는다.
		result_B += temp + temp + *(a - 1);
		sorted = false;
	}
	return sorted;
}

void bubbleSort(itemType a[], int n)
{
	int i, Sorted;
	Sorted = false;
	while (!Sorted) {
		Sorted = true;
		for (i = 1; i<n; i++)
			Sorted = Bubble(Sorted, &a[i], n);
	}
}

void shellSort(itemType a[], int n)
{
	int i, j, h; 
	itemType v;

	h = 1;  
	do h = 3 * h + 1; 
	while (h < n);
	do {
		h = h / 3;
		for (i = h; i <= n; i++)
		{
			v = a[i];
			j = i;
			while (a[j - h] > v)
			{
				a[j] = a[j - h];
				j -= h;
				result_S += a[i] + a[i] + a[i - h]; // 합 계산
				if (j <= h - 1)
				{
					break;
				}
			}
			a[j] = v;
		}
	} while (h > 1);
}

void insertion(itemType a[], int n)
{
	int i, j; 
	itemType v;
	
	for (i = 1; i < n; i++)
	{
		v = a[i];
		j = i;
		
		while (a[j - 1] > v)
		{
			a[j] = a[j - 1];
			j--;
			result_I += (v + v); // 합 계산
		}
		a[j] = v;
	}
}




