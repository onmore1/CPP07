#include "iter.hpp"
#include <string>

template <typename T> void incremnet(T &t)
{
	std::cout << t;
	t++;
	std::cout << " becomes " << t << "\n";
}

template <typename T> void addExclaim(T &t)
{
	std::cout << t;
	t += "!";
	std::cout << " becomes " << t << "\n";
}

template <typename T> void printOut(const T &t)
{
	std::cout << "Printing out: '" << t << "'\n";
}

int main()
{
	char arr[3] = {'a', 'b', 'c'};
	iter(arr, 3, printOut);
	iter(arr, 3, incremnet);
	iter(arr, 3, printOut);
	std::cout << "\ntesting with int\n";
	int iArr[3] = {1, 2, 3};
	iter(iArr, 3, printOut);
	iter(iArr, 3, incremnet);
	iter(iArr, 3, printOut);
	std::cout << "\ntesting with double\n";
	double dArr[3] = {4.5, 5.6, 6.7};
	iter(dArr, 3, printOut);
	iter(dArr, 3, incremnet);
	iter(dArr, 3, printOut);
	std::cout << "\ntesting with std::string\n";
	std::string sArr[3] = {"hello", "lol", "world"};
	iter(sArr, 3, printOut);
	iter(sArr, 3, addExclaim);
	iter(sArr, 3, printOut);

	std::cout << "\nALL THE SAME BUT CONST\n";
	const char carr[3] = {'a', 'b', 'c'};
	iter(carr, 3, printOut);
	std::cout << "\ntesting with const int\n";
	const int ciArr[3] = {1, 2, 3};
	iter(ciArr, 3, printOut);
	std::cout << "\ntesting with const double\n";
	const double cdArr[3] = {4.5, 5.6, 6.7};
	iter(cdArr, 3, printOut);
	std::cout << "\ntesting with const std::string\n";
	const std::string csArr[3] = {"hello", "lol", "world"};
	iter(csArr, 3, printOut);
	std::cout << "\ntesting with C strings\n";
	const char *strs[3] = {"lol", "olo", "ooo"};
	iter(strs, 3, printOut);
	return (0);
}