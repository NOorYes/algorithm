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
	itemType *stack; // int �� ������
	int p; // ������ ���� �� �ε����� ��Ÿ����.
public:
	Stack1(int max = 100) // ������
	{
		stack = new itemType[max]; p = 0;
	}
	~Stack1() // �Ҹ���
	{
		delete stack;
	}
	inline void push(itemType v) // ���� ������ ����ִ´�.
	{
		stack[p++] = v;
	}
	inline itemType pop() // ���� ������ ������.
	{
		return stack[--p];
	}
	inline int empty() // ������ ������� �ƴ��� ��Ÿ����.
	{
		return !p;
	}
};

int main() { // ������ �̿��� ���� ����.
	
	char c; 
	Stack1 acc(50); // 50���� ���ڸ� ������ �� �ִ� ���� ����.
	int x;
	
	while ((c = cin.get()) != '\n') // ���� (��) �� ������ ���ۿ��� �о���δ�.
	{
		x = 0;
		while (c == ' ') cin.get(c); // �����̸� ������ ������ �о���δ�.
		if (c == '+') x = acc.pop() + acc.pop(); 
		if (c == '*') x = acc.pop() * acc.pop(); // ��� ��ȣ�̸� ���ÿ��� ���ڵ��� ���� ����Ѵ�.
		while (c >= '0' && c <= '9')
		{
			x = 10 * x + (c - '0');  cin.get(c); // ������ ������ �о���δ�. + ���ڸ��� ���
		}
		acc.push(x); 
	}
	cout << acc.pop() << '\n'; // �� �������� �� �������� ���� ���� ����Ѵ�.
}

// �Է� ������:   9  10  15  4  *  +  20  *  7  + 
// ����� = 1407