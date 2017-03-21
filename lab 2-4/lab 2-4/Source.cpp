#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void traverse(struct treeNode *t);
void visit(struct treeNode *t);
int getHeight(struct treeNode *t); // ������ ���ϴ� �Լ�
void serach(treeNode * t, const char& key);

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

itemType A;
bool flag = false;
int height_ = 0;

int main()
{
	char c;
	Stack stack(50); // ���� ��ü ����
	char temp;

	z = new treeNode; // Ʈ����带 �����ϰ� z�� ����Ų��. �� ���� ��Ʈ ����̴�.
	z->l = NULL;
	z->r = NULL;

	while ((c = cin.get()) != '\n')
	{
		while (c == ' ') cin.get(c); // �����̸� ��� ���� 

		x = new treeNode; // ���ڸ� ���ο� Ʈ����带 ����� x�� ����Ŵ
		x->info = c;
		x->l = z;
		x->r = z;

		if (c == '+' || c == '*' || c == '-') // ��ȣ�� �� �����Ͱ� ���ڵ��� ����Ű�� ��.
		{
			x->r = stack.pop();
			x->l = stack.pop();
		}
		stack.push(x);
	}

	cin >> temp;
	
	A = stack.pop(); // ���� �������� ���� ��.

	serach(A, temp); // Ž��
	
	if (!flag) // Ž�� ����
	{
		cout << "not found" << endl;
	} 
	else
	{
		getHeight(A);
		cout << (height_ + 1) << endl;
	}

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

int getHeight(struct treeNode *t)
{	
	int height = 0;

	if (t != NULL)
	{
		height = 1 + max(getHeight(t->l), getHeight(t->r));
		height_ += height;
	}
	return height;
}

void serach(treeNode * t, const char& key)
{
	if (t == NULL) { return; }

		if (key == t->info) {
			A = t;
			flag = true;
			return;
		}
		else { // ����� Ž��
			serach(t->l, key);
			serach(t->r, key); 
		}
}


