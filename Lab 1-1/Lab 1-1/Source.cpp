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
	InputNum num; // InputNum 객체 num을 생성한다.
	cout << "The value is " << num.GetValue() << "\n";
	num.AddInput(); // aNum 객체를 다시 생성하여 입력을 받고, num과 더하여 다시 num에 대입한다.
	cout << "Now the value is " << num.GetValue() << "\n";
}

// 프로그램을 실행해보고, 동작원리를 설명하시오, 
// 또한 입력으로 2,3을 사용하였을 때의 결과를 출력하시오.
