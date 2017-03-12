#include <iostream> 
using namespace std;

class  InputNum
{
public:
	InputNum()
	{
		cout << "Enter number ";
		cin >> _num;
	}

	int GetValue() const { return _num; }

	void AddInput()
	{
		InputNum aNum;  // get a number from user
		_num = _num + aNum.GetValue();
	}

private:
	int _num;
};

int main()
{
	InputNum num; // InputNum ��ü num�� �����Ѵ�.
	cout << "The value is " << num.GetValue() << "\n";
	num.AddInput(); // aNum ��ü�� �ٽ� �����Ͽ� �Է��� �ް�, num�� ���Ͽ� �ٽ� num�� �����Ѵ�.
	cout << "Now the value is " << num.GetValue() << "\n";
}

// ���α׷��� �����غ���, ���ۿ����� �����Ͻÿ�, 
// ���� �Է����� 2,3�� ����Ͽ��� ���� ����� ����Ͻÿ�.
