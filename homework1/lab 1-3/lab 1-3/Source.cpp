#include <iostream>  
#include <ctype.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
	int key; // Ű.
	struct node *next; // ���� ��带 ����Ű�� ������.
};

int main()
{
	// 3��°�� ���鼭 ��� ����.
	int i, N, M;
	struct node *t, *x;
	int count = 0;
	
	cin >> N >> M; // N�� M�� �޴´�.
	
	t = new node; // ���ο� ��带 ����� t�����Ͱ� �װ��� ����Ű�� ��.
	t->key = 1; // ���ο� ����� key���� 1 ����.
	x = t; // x�� t�� ����Ű�� ���ο� ��带 ����Ű�� �Ѵ�.

	for (i = 2; i <= N; i++)
	{  
		t->next = new node; // ù ��° ����� next ��尡 ���ο� ��带 ����Ű�� �Ѵ�.
		t = t->next; t->key = i; 
		// t�� ���� ��带 ����Ű�� �ٲٰ�, Ű���� 2���� N���� ������Ű�� �ִ´�.
	}
	t->next = x; // ������ ����� next �����Ͱ� ù ��° ��带 ����Ű�� �Ѵ�.
	
	while (t != t->next) 
	// ��尡 �ϳ��� ������ ����
	{ 
		for (i = 1; i < M; i++) // M - 1 ��ŭ �ݺ�.
		{
			t = t->next; // t�� ���� ��带 ����Ű���� �Ѵ�.
		} 
		
		cout << t->next->key << ' '; // �� ���� ��带 ����Ű�� �ѵ� Ű�� ���
		x = t->next; // Ű�� ����� ��带 x�� ����Ű�� �� ��,
		t->next = x->next; // Ű�� ����� ��� �� ����� next ��尡 �ٴ��� ��带 ����Ű�� �Ѵ�.
		count++;
		delete x; // x�� ����Ű�� �ִ� ��带 �����Ѵ�. 
	}
	cout << t->key << '\n'; // ������ t�� ����Ű�� ����� Ű���� ���.
	// �� ���� ����Ʈ�� ���� ���� �����̴�.
	cout << "delete ���� Ƚ�� : ";
	cout << count << endl; // ī��Ʈ ���.
}

