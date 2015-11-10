#include <iostream>
using namespace std;

class TestClass
{
private:
	int val;
	void showVal()
	{
		cout << val << endl;
	}
public:
	TestClass(int x)
	{
		val = x;
	}

};

int main()
{
	TestClass test(77);
	test.showVal();
	return 0;
}