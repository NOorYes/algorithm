#include <iostream>  
#include <ctype.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef float itemType;

class Stack2
{
public:
	Stack2()
	{ 
		head = NULL;
	}
	~Stack2()
	{
	}
	void push(itemType v)
	{
		z = new node;

		if (z == NULL)
		{
			cout << "�߸��� �޸�" << endl;
			return;
		}
		else
		{
			z->key = v;
			z->next = head;
			head = z;
		}
	}
	itemType pop()
	{
		if (empty())
		{
			cout << "���ÿ� �ƹ��͵� �����" << endl;
			exit(1);
		}
		else
		{
			z = head;
			itemType item = z->key;
			head = head->next;
			delete(z);
			return item;
		}
	}
	int empty()
	{
		return head == NULL;
	}

private:
	struct node
	{
		itemType key; // ���ڸ� ����.
		struct node *next; // ���� ��带 ����Ű�� ������
	};
	struct node *head; // top
	struct node *z; // temp
};


int main() { // ������ �̿��� ���� ����.

	char c; // ���ڸ� ����
	Stack2 acc;
	float x;
	float y;
	float result;

	while ((c = cin.get()) != '\n')
	{
		x = 0; // ���� �� �ӽ�����.

		while (c == ' ') cin.get(c);
		
		if (c == '+') x = acc.pop() + acc.pop();
		if (c == '*') x = acc.pop() * acc.pop();
		
		if (c == '-')
		{
				y = acc.pop();
				x = acc.pop() - y;
		}
		
		if (c == '/')
		{
			y = acc.pop();
			x = acc.pop() / y;
		}
		
		while (c >= '0' && c <= '9')
		{
			x = 10 * x + (c - '0');  cin.get(c);
		}
		acc.push(x);
	}
	result = acc.pop();

	if(result - (int)result > 0)
		printf("�� : %.2lf \n", result);
	else
		printf("�� : %d \n", (int)result);
}

// �Է� ������: 20 15 * 20 4 / + 8 * 5 - 
// ����� = 2435
// (����, ����� ��� ���� �Ҽ��� ���� ���� ���� ��� �Ҽ��� ��° �ڸ����� ����Ѵ�.)
//  %.2lf �� ���� ��° �ڸ����� ���.
// �Ҽ��� ���ϰ��� ���� ���� �׳� ������ ����ؾ� �ϴ°ǰ�..?