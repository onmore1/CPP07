#include "Array.hpp"

int main()
{
	std::cout << "creating int array  of size 10 and filling it\n";
	Array<int> test(10);
	std::cout << "size is : " << test.size() << "\n";
	for (int i = 0; i < test.size(); i++)
		test[i] = i * 2;
	try
	{
		std::cout << "\nread past the end\n";
		for (int i = 0; i < 11; i++)
		{
			std::cout << "Trying to acces index #"<< i << "\n";
			std::cout << test[i] << "\n";
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Error: ";
		std::cout << e.what() << "\n";
	}
	try
	{
		std::cout << "trying with size -1\n";
		Array<char> cTestInvalid(-1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "\nchar arrray of size 1000000, write A-Z\n";
	Array<char> cTest(1000000);
	try 
	{
		for (int i = 65; i < 91; i++)
		{
			cTest[i] = i;
			std::cout << cTest[i];
		}
		std::cout << "\n";
		std::cout << "\nself-assignment\n";
		Array<int> &mirror = test;
		test = mirror;
		std::cout << "Testing mirror\n";
		for (int i = 0; i < mirror.size(); i++)
		{
			std::cout << mirror[i];
		}
		std::cout << "\n";
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}

	try
	{
		std::cout << "creating copy and than changing it\n";
		Array<int> copy(test);
		for (int i = 0; i < copy.size(); i++)
			copy[i] = copy[i] * 2;
		std::cout << "comapring changed copy and src\n";
		for (int i = 0; i < copy.size(); i++)
			std::cout << "copy " << i << "=[" << copy[i] << "] | src " << i << "=[" << test[i] << "]\n";
		std::cout << "trying to acces -1\n";
		copy[-1] = 0;

	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	try
	{
		Array<int> copy;
		copy = test;
		Array<int> empty(0);
		copy = empty;
		std::cout << copy[0];
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "\ndestructor part\n";
	return (0);
}