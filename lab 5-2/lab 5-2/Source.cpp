#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

typedef int itemType;

itemType *a; // 원래 배열을 가리키는 포인터
itemType *b; // 새로 담을 배열을 가리키는 포인터
itemType *N_; // 카운터용 포인터


using namespace std;
void CountSort(itemType *a, itemType *b, itemType *N, int n, int k);

int Compare_Cnt;
int DataMove_Cnt;

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

	int* N_vectorA = new int[N]; // 원래 배열을 가리키는 배열
	int* N_vectorB = new int[N]; // 원래 배열을 가리키는 배열
	int* N_vectorC = new int[N]; // 원래 배열을 가리키는 배열

	int* temp_A = new int[N]; // 저장용
	int* temp_B = new int[N]; // 저장용

	b = new itemType[N]; // 새로 담을 배열을 가리키는 포인터
	N_ = new itemType[N]; // 카운트용 배열, N[i] 는 i가 나온 갯수.

	for (int i = 0; i < N; i++)
	{
		N_vectorA[i] = i + 1; // 0은 비우고, 1~N까지.
	}

  	copy(N_vectorA, N_vectorA + N, N_vectorB);
	// A의 내용을 B에 복사.
	random_shuffle(N_vectorB, N_vectorB + N);
	// 랜덤하게 재배치

 	srand((unsigned)time(NULL));

	for (int x = 0; x < N; x++)
	{
		N_vectorC[x] = (int)rand() % N + 1; // 1에서 N까지를 넣는다.
	}

	reverse(N_vectorA, N_vectorA + N); // A를 내림차순으로 바꾼다.

	CountSort(N_vectorA, b, N_, N, N); // A counting 정렬
	
	for (int x = 0; x <= 30; x++)
	{
		temp_A[x] = b[x];
	} // 저장

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

	CountSort(N_vectorB, b, N_, N, N); // B counting 정렬

	for (int x = 0; x <= 30; x++)
	{
		temp_B[x] = b[x];
	} // 저장

	Compare_Cnt_B = Compare_Cnt;
	DataMove_Cnt_B = DataMove_Cnt;

	DataMove_Cnt = 0;
	Compare_Cnt = 0;

	CountSort(N_vectorC, b, N_, N, N); // C counting 정렬

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
{ // 넘겨줄 배열 a, 빈 배열 b, 빈 카운팅용 배열 N, n 숫자의 수, k 배열의 크기?
	int i;

	for (i = 0; i <= k; i++)
		N[i] = 0;  // 모든 N[i] 배열을 0으로 채운다.

	for (i = 1; i < n; i++)
		N[a[i]] = N[a[i]] + 1; // 1 ~ N 까지 나온 횟수를 카운트한다.

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
