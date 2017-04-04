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
	int N = 0; // �����Ϸ��� �迭�� ũ��

	cin >> N;

	int* N_vectorA = new int[N];
	int* N_vectorB = new int[N];
	int* N_vectorC = new int[N];
	
	for (int i = 0; i < N; i++)
	{
		N_vectorA[i] = i + 1;
	}
	
	reverse(N_vectorA, N_vectorA + N); // �� ó���� ���� ����.

	copy(N_vectorA, N_vectorA + N, N_vectorB);
	copy(N_vectorA, N_vectorA + N, N_vectorC); // �Ȱ����� 3�� �����.

	bubbleSort(N_vectorA, N); 
	shellSort(N_vectorB, N);
	insertion(N_vectorC, N); // ���� 3����Ʈ ����

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
	if (*(a - 1) > *a) // (a-1) �� a ���� �� ũ�ٸ�
	{
		temp = *a; // ū ������ ���� ���� -> ���� ������ ���� ����,
		*a = *(a - 1); // a -1 �� �ڸ��� a�� ���´�. -> a�� �ڸ��� a-1�� ���´�.
		*(a-1) = temp; // a�� �ڸ��� a -1�� ���´�. -> a-1�� �ڸ��� a�� ���´�.
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
				result_S += a[i] + a[i] + a[i - h]; // �� ���
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
			result_I += (v + v); // �� ���
		}
		a[j] = v;
	}
}




