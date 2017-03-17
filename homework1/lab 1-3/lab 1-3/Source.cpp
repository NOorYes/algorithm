#include <iostream>  
#include <ctype.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
	int key; // 키.
	struct node *next; // 다음 노드를 가리키는 포인터.
};

int main()
{
	// 3번째씩 돌면서 노드 삭제.
	int i, N, M;
	struct node *t, *x;
	int count = 0;
	
	cin >> N >> M; // N과 M을 받는다.
	
	t = new node; // 새로운 노드를 만들고 t포인터가 그것을 가리키게 함.
	t->key = 1; // 새로운 노드의 key값에 1 대입.
	x = t; // x도 t가 가리키는 새로운 노드를 가리키게 한다.

	for (i = 2; i <= N; i++)
	{  
		t->next = new node; // 첫 번째 노드의 next 노드가 새로운 노드를 가리키게 한다.
		t = t->next; t->key = i; 
		// t가 다음 노드를 가리키게 바꾸고, 키값을 2부터 N까지 증가시키며 넣는다.
	}
	t->next = x; // 마지막 노드의 next 포인터가 첫 번째 노드를 가리키게 한다.
	
	while (t != t->next) 
	// 노드가 하나만 남으면 종료
	{ 
		for (i = 1; i < M; i++) // M - 1 만큼 반복.
		{
			t = t->next; // t가 다음 노드를 가리키도록 한다.
		} 
		
		cout << t->next->key << ' '; // 그 다음 노드를 가리키게 한뒤 키값 출력
		x = t->next; // 키값 출력한 노드를 x가 가리키게 한 뒤,
		t->next = x->next; // 키값 출력한 노드 전 노드의 next 노드가 다다음 노드를 가리키게 한다.
		count++;
		delete x; // x가 가리키고 있는 노드를 삭제한다. 
	}
	cout << t->key << '\n'; // 마지막 t가 가리키는 노드의 키값을 출력.
	// 이 노드는 딜리트가 되지 않은 상태이다.
	cout << "delete 연산 횟수 : ";
	cout << count << endl; // 카운트 출력.
}

