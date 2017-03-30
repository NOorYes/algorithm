#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
void traverse(struct treeNode *t);
void visit(struct treeNode *t);
void serach(treeNode * t, int level_,const char& key);

struct treeNode // 트리 노드 
{
	char info;
	struct treeNode *l, *r; // left, right 
};
typedef treeNode* itemType;

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

class Queue // 원형 큐
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
int level = 0;

int main()
{
	char c;
	Stack stack(50); // 스택 객체 생성
	char temp;

	z = new treeNode; // 트리노드를 생성하고 z로 가리킨다. 이 노드는 루트 노드이다.
	z->l = NULL;
	z->r = NULL;

	while ((c = cin.get()) != '\n')
	{
		while (c == ' ') cin.get(c); // 공백이면 계속 받음 

		x = new treeNode; // 문자면 새로운 트리노드를 만들고 x로 가리킴
		x->info = c;
		x->l = z;
		x->r = z;

		if (c == '+' || c == '*' || c == '-') // 기호면 양 포인터가 문자들을 가리키게 함.
		{
			x->r = stack.pop();
			x->l = stack.pop();
		}
		stack.push(x);
	}

	cin >> temp;
	
	A = stack.pop(); // 제일 마지막에 들어온 것.

	serach(A, 1, temp); // 탐색
	
	if (!flag) // 탐색 실패
	{
		cout << "not found" << endl;
	} 
	else
	{
		cout << level << endl;
	}

	cout << endl;
	return 0;
}


void traverse(struct treeNode *t) // 큐를 이용한 레벨 순회
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

void serach(treeNode * t, int level_, const char& key)
{
	if (t == NULL) { return; }
	else {
		level_++;
		if (key == t->info) {
			A = t;
			level = level_ - 1;
			flag = true;
			return;
		}
		else { // 재귀적 탐색
			serach(t->l, level_, key);
			serach(t->r, level_, key);
		}
	}
}


