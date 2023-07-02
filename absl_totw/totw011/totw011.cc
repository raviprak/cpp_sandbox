// https://abseil.io/tips/11
#include <iostream>

using namespace std;

class SomeBigObject
{
public:
	SomeBigObject()
	{
		std::cout << "Called constructor for SomeBigObject. ";
	}

	SomeBigObject(const SomeBigObject &copy)
	{
		std::cout << "Called copy constructor for SomeBigObject. ";
	}

	SomeBigObject &operator=(const SomeBigObject &assign)
	{
		std::cout << "Called copy assignment for SomeBigObject. ";
		return *this;
	}
};

SomeBigObject FunctionReturnsSomeBigObject()
{
	SomeBigObject object;
	return object;
}

SomeBigObject FunctionReturnsSomeBigObjectWithConditional(bool cond)
{
	if (cond)
	{
		SomeBigObject object;
		return object;
	}
	else
	{
		SomeBigObject object;
		return object;
	}
}

int main()
{
	std::cout << "Calling FunctionReturnsSomeBigObject(). ";
	SomeBigObject object_1 = FunctionReturnsSomeBigObject();

	std::cout << endl;
	std::cout << "Calling FunctionReturnsSomeBigObject() again assigning to the same variable. ";
	object_1 = FunctionReturnsSomeBigObject();

	std::cout << endl;
	std::cout << "Calling FunctionReturnsSomeBigObjectWithConditional(). ";
	SomeBigObject object_2 = FunctionReturnsSomeBigObjectWithConditional(false);

	std::cout << endl;
	return 0;
}

/* Output
$ ./totw011
Calling FunctionReturnsSomeBigObject(). Called constructor for SomeBigObject.
Calling FunctionReturnsSomeBigObject() again assigning to the same variable. Called constructor for SomeBigObject. Called copy assignment for SomeBigObject.
Calling FunctionReturnsSomeBigObjectWithConditional(). Called constructor for SomeBigObject. Called copy constructor for SomeBigObject.
*/