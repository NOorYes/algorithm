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
			cout << "잘못된 메모리" << endl;
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
			cout << "스택에 아무것도 없어요" << endl;
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
		itemType key; // 숫자를 저장.
		struct node *next; // 다음 노드를 가리키는 포인터
	};
	struct node *head; // top
	struct node *z; // temp
};


int main() { // 스택을 이용한 후위 연산.

	char c; // 문자를 저장
	Stack2 acc;
	float x;
	float y;
	float result;

	while ((c = cin.get()) != '\n')
	{
		x = 0; // 연산 값 임시저장.

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
		printf("값 : %.2lf \n", result);
	else
		printf("값 : %d \n", (int)result);
}

// 입력 데이터: 20 15 * 20 4 / + 8 * 5 - 
// 결과값 = 2435
// (주의, 연산된 결과 값에 소수점 이하 값이 있을 경우 소수점 둘째 자리까지 출력한다.)
//  %.2lf 를 쓰면 둘째 자리까지 출력.
// 소수점 이하값이 없을 경우는 그냥 정수로 출력해야 하는건가..?