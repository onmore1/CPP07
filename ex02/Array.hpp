#pragma once
#include <iostream>
#include <string>
#include <exception>

template <typename T> class Array
{
	private:
		T *_elements;
		int _size;
	public:
		Array(void);
		Array(int n);
		Array(Array const &src);
		~Array();

		Array &operator=(Array const &src);
		T &operator[](int index);
		T const &operator[](int index) const;

		int size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};
		class InvalidSizeException : public std::exception
		{
			public:
				const char *what() const noexcept override;
		};
};

///////////////////////////////////////////////////////////////////////////////

template <typename T> Array<T>::Array(void) : _elements(NULL), _size(0)
{
	std::cout << "default constructor called: empty array\n";
}

template <typename T> Array<T>::Array(int n) : _elements(NULL), _size(0)
{
	std::cout << "constructor with size:[" << n << "] was called\n";
	if (n < 0)
		throw InvalidSizeException();
	this->_elements = new T[n]();
	this->_size = n;
}

template <typename T> Array<T>::Array(Array const &src) : _elements(NULL), _size(0)
{
	std::cout << "copy constructor called\n";
	*this = src;
}

template <typename T> Array<T>::~Array()
{
	std::cout << "destructor called: freeing " << this->_size << " elements\n";
	delete[] this->_elements;
}

template <typename T> Array<T> &Array<T>::operator=(Array const &src)
{
	std::cout << "assignment operator called.";
	if (this != &src)
	{
		std::cout << " Copying " << src.size() << " elements\n";
		T *newElements = NULL;
		if (src._size > 0)
		{
			newElements = new T[src._size]();
			for (int i = 0; i < src._size; i++)
				newElements[i] = src._elements[i];
		}
		delete[] this->_elements;
		this->_elements = newElements;
		this->_size = src._size;
	}
	else
		std::cout << " Objects are the same, no need to copy\n";
	return *this;
}

template <typename T> T &Array<T>::operator[](int index)
{
	if (index < 0 || index >= _size)
		throw OutOfBoundsException();
	return this->_elements[index];
}

template <typename T> T const &Array<T>::operator[](int index) const
{
	if (index < 0 || index >= _size)
		throw OutOfBoundsException();
	return this->_elements[index];
}

template <typename T> int Array<T>::size() const
{
	return this->_size;
}

template <typename T> const char *Array<T>::OutOfBoundsException::what() const noexcept
{
	return "Index is out of bounds";
}

template <typename T> const char *Array<T>::InvalidSizeException::what() const noexcept
{
	return "Size must be greater than or equal to 0";
}