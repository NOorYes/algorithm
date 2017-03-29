#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct treeNode // 트리 노드
{ 
	char info; 
	struct treeNode *l, *r; // left, right
};
typedef treeNode* itemType; // itemType을 트리 노드를 가리키는 포인터형으로.

/*
struct node
{
	treeNode pointer;
	struct node *next;
};
*/

treeNode *x, *z; // 트리 노드를 가리키는 포인터

class Stack // 배열로 구현한 스택
{
public:
	Stack(int max = 100) { stack = new itemType[max]; p = 0; }; 
	// 아이템 타입 배열 = 트리노드를 가리키는 포인터를 저장하는 배열 , 즉 이걸 가리키려면 포인터의 포인터를 써야함.
	~Stack() { delete stack; };

	inline void push(itemType v) { stack[p++] = v; };

	inline itemType pop() { return stack[--p]; };

	inline int empty() { return !p; };

private:
	itemType *stack; // 트리 노드 포인터를 가리키는 포인터
	int p; // 스택의 맨 위
};

void visit(struct treeNode *t);
void traverse(struct treeNode *t);

int main()
{
		char c;
		Stack stack(50); // 스택 객체 생성

		z = new treeNode; // 트리노드를 생성하고 z로 가리킨다.
		z->l = z;
		z->r = z; // 자기를 가리키도록 임시 지정
		
		while ((c = cin.get()) != '\n')
		{
			while (c == ' ') cin.get(c); // 공백이면 계속 받음
			
			x = new treeNode; // 숫자면 새로운 트리노드를 만들고 x로 가리킴
			x->info = c; // 정보에 받은 값을 저장
			x->l = z; 
			x->r = z;
			
			if (c == '+' || c == '*' || c == '-')  // 연산기호면 값을 꺼내 하위 노드로 만든다.
			{ 
				x->r = stack.pop(); 
				x->l = stack.pop(); 
			}		
			
			stack.push(x); 
		}
		
		traverse(stack.pop()); // 중위 순회
		
		cout << endl;
		return 0;
}
	
void visit(struct treeNode *t)
{
	cout << t->info << " "; // 방문한 노드 정보 출력
}

void traverse(struct treeNode *t) // 중위 순회
{
	if (t != z)
	{
		traverse(t->l);
		visit(t);
		traverse(t->r);
	}
}