﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

#define infoNIL 0
#define itemMIN -1

typedef int itemType;
typedef int infoType;

using namespace std;


class BST {
private:
	struct node {
		itemType key; 
		infoType info;
		struct node *l, *r;
		node(itemType k, infoType i, struct node *ll, struct node *rr)  // node 생성시 초기값 부여 가능 
		{
			key = k; info = i; l = ll; r = rr;
		};
	};
	struct node *head, *z; // z : List의 끝을 대표하는 node pointer – NULL에 해당

public:
	BST(int max) {
		z = new node(0, infoNIL, 0, 0);
		head = new node(itemMIN, infoNIL, z, z);
	}
	
	~BST()
	{
	};

	infoType BSTsearch(itemType v);
	void BSTinsert(itemType v, infoType info);
	//void BSTdelete(itemType v);
	float Compare_Cnt = 0;
};

infoType BST::BSTsearch(itemType v) {
	struct node *x = head->r;
	z->key = v; // 아래 반복문을 간결히 만들기 위함
	while(v != x->key)
	{
		x = (v < x->key) ? x->l : x->r;
		Compare_Cnt++;
	}
	return x->info;
}

void BST::BSTinsert(itemType v, infoType info) {
	struct node *p, *x;
	p = head; x = head->r;
	while (x != z) {
		p = x;
		x = (v < x->key) ? x->l : x->r;
	}
	x = new node(v, info, z, z);
	if (v < p->key)
	{
	p->l = x;
	}
	else p->r = x;
}

int main()
{
	int N = 0; // 정렬하려는 배열의 크기
	BST bst(10000); // 이진 트리 객체
	vector <int> N_vectorA; // 데이터 저장용 벡터.
	int temp = 0;
	float result = 0;
	vector <int>::iterator itr;

	cin >> N;

	srand((unsigned)time(NULL));

	for (int x = 0; x < N; x++) // N개의 난수 발생시켜 저장
	{
		temp = (int)rand() % N + 1;

		itr = find(N_vectorA.begin(), N_vectorA.end(), temp); // 동일한 값이 있는지 찾음.

		if (itr != N_vectorA.end()) { // 이미 있다면 다시 랜덤값 생성
			x -= 1;
			continue;
		}
		else
		{
			N_vectorA.push_back(temp); // 없으면 그냥 집어넣는다.
		}
	}

	// reverse(N_vectorA, N_vectorA + N); // A를 내림차순으로 바꾼다.

	for (int i = 0; i < N; i++)
		bst.BSTinsert(N_vectorA[i], i);// A 삽입 정렬

	for (int i = 1; i <= N; i++) {
		bst.BSTsearch(i);
		result += bst.Compare_Cnt;
		bst.Compare_Cnt = 0;
	}

	cout << "Compare_Cnt_A : " << result / N << endl;

	return 0;
}
