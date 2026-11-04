#include "iter.hpp"

template <typename T> void printOut(T &t)
{
	std::cout << "Printing out: '" << t << "'\n";
}

template <typename T> void incremnet(T &t)
{
	std::cout << t;
	t++;
	std::cout << " becomes " << t << "\n";
}

int main()
{
	char arr[3] = {'a', 'b', 'c'};
	iter(arr, 3, printOut);
	iter(arr, 3, incremnet);
	iter(arr, 3, printOut);
	std::cout << "\n\ntesting with int\n";
	int iArr[3] = {1, 2, 3};
	iter(iArr, 3, printOut);
	iter(iArr, 3, incremnet);
	iter(iArr, 3, printOut);
	return (0);
}