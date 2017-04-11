#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

typedef int itemType;
void heapsort(itemType a[], int N);

using namespace std;

int Compare_Cnt;
int DataMove_Cnt;

class MAKE_HEAP {

private:
	itemType *a;
	int N;

public:

	MAKE_HEAP(int max) { a = new itemType[max]; N = 0; }
	~MAKE_HEAP() { delete a; }

void swap_(itemType a[], int i, int j) 
{
	int temp;
	temp = a[j];
	a[j] = a[i];	
	a[i] = temp;
}

void MakeHeap(itemType a[], int Root, int LastNode)
{		
	int Parent, LeftSon, RightSon, Son;
	
	itemType RootValue;
	
	Parent = Root;
	RootValue = a[Root];
	
	LeftSon = 2 * Parent;
	RightSon = LeftSon + 1;

	while (LeftSon < LastNode) 
	{

		if (RightSon <= LastNode && a[LeftSon] < a[RightSon])
		{
			Compare_Cnt++;
			Son = RightSon; // 오른쪽 자식이 더 크면 오른쪽 자식을 자식으로.
		}
		else {
			Son = LeftSon;
			Compare_Cnt++;
		}
		// 왼쪽 자식이 더 크면 왼쪽 자식을 자식으로.

		if (RootValue < a[Son]) 
		{
			a[Parent] = a[Son];
			Parent = Son;
			LeftSon = Parent * 2;
			RightSon = LeftSon + 1;
			Compare_Cnt++;
			DataMove_Cnt++;
		}
			else break;
		}
		a[Parent] = RootValue;
	}
};

int main()
{
	int N = 0; // 정렬하려는 배열의 크기

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
	// A의 내용을 B에 복사.
	random_shuffle(N_vectorB, N_vectorB + N);
	// 랜덤하게 재배치

	srand((unsigned)time(NULL));

	for (int x = 0; x < N; x++)
	{
		N_vectorC[x] = (int)rand() % N + 1;
	}

	reverse(N_vectorA, N_vectorA + N); // A를 내림차순으로 바꾼다.

	heapsort(N_vectorA, N); // A 삽입 정렬

	Compare_Cnt_A = Compare_Cnt;
	DataMove_Cnt_A = DataMove_Cnt;

	DataMove_Cnt = 0;
	Compare_Cnt = 0;

	heapsort(N_vectorB, N); // B 삽입 정렬

	Compare_Cnt_B = Compare_Cnt;
	DataMove_Cnt_B = DataMove_Cnt;

	DataMove_Cnt = 0;
	Compare_Cnt = 0;

	heapsort(N_vectorC, N); // C 삽입 정렬

	Compare_Cnt_C = Compare_Cnt;
	DataMove_Cnt_C = DataMove_Cnt;

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

	cout << "SortedData_C: ";
	//*
	for (int z = 0; z < 30; z++) {
		cout << N_vectorC[z] << " ";
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

void heapsort(itemType a[], int N) 
{
	
	int i;
	MAKE_HEAP heap(30000);

	for (i = N / 2; i >= 1; i--)  
		heap.MakeHeap(a, i - 1, N - 1);
	for (i = N - 1; i >= 1; i--)
	{
		heap.swap_(a, 0, i);
		heap.MakeHeap(a, 0, i - 1);
	}
}
