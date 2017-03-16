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

	while ((c = cin.get()) != '\n') // c 가 엔터가 아니라면 계속, 엔터면 중단.
	{
		x = 0; // 연산 값 임시저장.

		while (c == ' ') cin.get(c);
		// 공백 문자라면 공백이 아닐 때까지 다음걸 읽어들여 c에 저장
		
		if (c == '+')
		{
			x = acc.pop() + acc.pop();
		}
		if (c == '*')
		{
			x = acc.pop() * acc.pop();
		}
		
		if (c == '-')
		{
			cin.get(c);

			if (c >= '0' && c <= '9') // 음수인 경우.
			{
				while (c >= '0' && c <= '9') {
					//acc.push(-(c - '0'));
					x = 10 * x + (c - '0'); cin.get(c);
				}
				acc.push(-(x));
				continue;
			}
			
			else if (c == '\n') // 마지막에 연산기호 - 가 붙은 경우.
			{
				y = acc.pop();
				x = acc.pop() - y;
				acc.push(x);
				break;
			}
			else // 그 외 연산기호로 중간에 쓰였을 경우
			{
				y = acc.pop();
				x = acc.pop() - y;
			}
		}

		if (c == '/')
		{
			y = acc.pop();
			x = acc.pop() / y;
		}
		
		while (c >= '0' && c <= '9')
		{
			x = 10 * x + (c - '0'); cin.get(c);
		}
		acc.push(x);
	}
	
	result = acc.pop();

	if(result - (int)result > 0) // 양수 소수인 경우
		printf("값 : %.2lf \n", result);
	else if(result - (int)result < 0) // 음수 소수인 경우
		printf("값 : %.2lf \n", result);
	else // 정수인 경우 (0)
		printf("값 : %d \n", (int)result);
}

// 입력 데이터: 20 15 * 20 4 / + 8 * 5 - 
// 결과값 = 2435
// (주의, 연산된 결과 값에 소수점 이하 값이 있을 경우 소수점 둘째 자리까지 출력한다.)
//  %.2lf 를 쓰면 둘째 자리까지 출력.
// 소수점 이하값이 없을 경우는 그냥 정수로 출력해야 하는건가..?

/*
else if (c == '\n')
{
break;
}
*/