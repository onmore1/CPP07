#include "Array.hpp"

int main()
{
	Array<int> test(10);
	std::cout << "size is : " << test.size() << "\n";
	for (int i = 0; i < test.size(); i++)
		test[i] = i * 2;
	try
	{
		std::cout << "Printing out array\n";
		for (int i = 0; i < 11; i++)
		{
			std::cout << "Trying to acces index #"<< i << "\n";
			std::cout << test[i] << "\n";
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Error: ";
		std::cout << e.what();
	}
	Array<char> cTestInvalid(-1);
	Array<char> cTest(255);
	return (0);
}