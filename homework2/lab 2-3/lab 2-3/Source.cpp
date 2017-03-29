#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void traverse(struct treeNode *t);
void visit(struct treeNode *t);

struct treeNode // Ʈ�� ��� 
 {
	 char info;
	 struct treeNode *l, *r; // left, right 
 };
typedef treeNode* itemType;

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

class Queue // ���� ť
{
public:
	Queue(int max)
	{
		this->size = max;
		queue = new itemType[max];
	}
	~Queue()
	{
		delete queue;
	}

	void put(itemType v);
	itemType get();
	int empty();

private:
	itemType *queue;
	int tail = 0;
	int head = 0;
	int size;
};

void Queue::put(itemType v)
{
	queue[tail++] = v;
	if (tail > size) 
		tail = 0;
}

itemType Queue::get()
{
	itemType t = queue[head++];
	if (head > size) head = 0;
	return t;
}

int Queue::empty() { return head == tail; } 

int main()
{
 		char c;
 		Stack stack(50); // ���� ��ü ���� 

 		z = new treeNode; // Ʈ����带 �����ϰ� z�� ����Ų��. �� ���� ��Ʈ ����̴�.
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


void traverse(struct treeNode *t) // ť�� �̿��� ���� ��ȸ
{
	Queue queue(40);
	queue.put(t);

	while (!queue.empty())
	{
		t = queue.get(); 
		visit(t);
		if (t->l != z) queue.put(t->l);
		if (t->r != z) queue.put(t->r);
	}
}

void visit(struct treeNode *t)
{
	cout << t->info << " ";
}
