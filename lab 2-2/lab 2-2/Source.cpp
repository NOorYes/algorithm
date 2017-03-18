#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct treeNode // 트리 노드
{ 
	char info; 
	struct treeNode *l, *r; // left, right
};
typedef treeNode* itemType;

/*
struct node
{
	treeNode pointer;
	struct node *next;
};
*/

treeNode *x, *z;

class Stack // 배열로 구현한 스택
{
public:
	Stack(int max = 100) { stack = new itemType[max]; p = 0; };
	~Stack() { delete stack; };

	inline void push(itemType v) { stack[p++] = v; };

	inline itemType pop() { return stack[--p]; };

	inline int empty() { return !p; };

private:
	itemType *stack;
	int p;
};

void visit(struct treeNode *t);
void traverse(struct treeNode *t);

int main()
{
		char c;
		Stack stack(50); // 스택 객체 생성

		z = new treeNode; // 트리노드를 생성하고 z로 가리킨다.
		z->l = z;
		z->r = z;
		
		while ((c = cin.get()) != '\n')
		{
			while (c == ' ') cin.get(c); // 공백이면 계속 받음
			
			x = new treeNode; // 숫자면 새로운 트리노드를 만들고 x로 가리킴
			x->info = c; 
			x->l = z; 
			x->r = z;
			
			if (c == '+' || c == '*' || c == '-') 
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
	cout << t->info << " ";
}

void traverse(struct treeNode *t)
{
	if (t != z)
	{
		traverse(t->l);
		visit(t);
		traverse(t->r);
	}
}