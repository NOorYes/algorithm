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
	itemType *stack; // int 형 포인터
	int p; // 스택의 가장 위 인덱스를 나타낸다.
public:
	Stack1(int max = 100) // 생성자
	{
		stack = new itemType[max]; p = 0;
	}
	~Stack1() // 소멸자
	{
		delete stack;
	}
	inline void push(itemType v) // 스택 안으로 집어넣는다.
	{
		stack[p++] = v;
	}
	inline itemType pop() // 스택 밖으로 빼낸다.
	{
		return stack[--p];
	}
	inline int empty() // 스택이 비었는지 아닌지 나타낸다.
	{
		return !p;
	}
};

int main() { // 스택을 이용한 후위 연산.
	
	char c; 
	Stack1 acc(50); // 50개의 숫자를 저장할 수 있는 스택 선언.
	int x;
	
	while ((c = cin.get()) != '\n') // 공백 (끝) 일 때까지 버퍼에서 읽어들인다.
	{
		x = 0;
		while (c == ' ') cin.get(c); // 공백이면 숫자일 때까지 읽어들인다.
		if (c == '+') x = acc.pop() + acc.pop(); 
		if (c == '*') x = acc.pop() * acc.pop(); // 계산 기호이면 스택에서 숫자들을 꺼내 계산한다.
		while (c >= '0' && c <= '9')
		{
			x = 10 * x + (c - '0');  cin.get(c); // 숫자일 때까지 읽어들인다. + 두자릿수 계산
		}
		acc.push(x); 
	}
	cout << acc.pop() << '\n'; // 맨 마지막에 들어간 최종적인 값을 꺼내 출력한다.
}

// 입력 데이터:   9  10  15  4  *  +  20  *  7  + 
// 결과값 = 1407