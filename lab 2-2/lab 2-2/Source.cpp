#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct treeNode // Ʈ�� ���
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

class Stack // �迭�� ������ ����
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
		Stack stack(50); // ���� ��ü ����

		z = new treeNode; // Ʈ����带 �����ϰ� z�� ����Ų��.
		z->l = z;
		z->r = z;
		
		while ((c = cin.get()) != '\n')
		{
			while (c == ' ') cin.get(c); // �����̸� ��� ����
			
			x = new treeNode; // ���ڸ� ���ο� Ʈ����带 ����� x�� ����Ŵ
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
		
		traverse(stack.pop()); // ���� ��ȸ
		
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