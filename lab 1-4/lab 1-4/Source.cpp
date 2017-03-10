#include <iostream>  
#include <ctype.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
typedef int itemType;

class Stack1
{
private:
	itemType *stack;
	int p;
public:
	Stack1(int max = 100)
	{
		stack = new itemType[max]; p = 0;
	}
	~Stack1()
	{
		delete stack;
	}
	inline void push(itemType v)
	{
		stack[p++] = v;
	}
	inline itemType pop()
	{
		return stack[--p];
	}
	inline int empty()
	{
		return !p;
	}
};

int main() { // 스택을 이용한 후위 연산.
	
	char c; 
	Stack1 acc(50); 
	int x;
	
	while ((c = cin.get()) != '\n')
	{
		x = 0;
		while (c == ' ') cin.get(c);
		if (c == '+') x = acc.pop() + acc.pop();
		if (c == '*') x = acc.pop() * acc.pop();
		while (c >= '0' && c <= '9')
		{
			x = 10 * x + (c - '0');  cin.get(c);
		}
		acc.push(x);
	}
	cout << acc.pop() << '\n';
}

// 입력 데이터:   9  10  15  4  *  +  20  *  7  + 
// 결과값 = 1407