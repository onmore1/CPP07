#pragma once
#include <iostream>
#include <string>
#include <exception>

template <typename T> class Array
{
	private:
		T *_elements;
		unsigned int _size;
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &src);
		~Array();

		Array &operator=(Array const &src);
		T &operator[](unsigned int index);
		T const &operator[](unsigned int index) const;

		unsigned int size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

///////////////////////////////////////////////////////////////////////////////

template <typename T> Array<T>::Array(void) : _elements(NULL), _size(0)
{
}

template <typename T> Array<T>::Array(unsigned int n) : _elements(NULL), _size(n)
{
	if (n > 0)
		_elements = new T[n]();
}

template <typename T> Array<T>::Array(Array const &src) : _elements(NULL), _size(0)
{
	*this = src;
}

template <typename T> Array<T>::~Array()
{
	delete[] _elements;
}

template <typename T> Array<T> &Array<T>::operator=(Array const &src)
{
	if (this != &src)
	{
		T *newElements = NULL;
		if (src._size > 0)
		{
			newElements = new T[src._size]();
			for (unsigned int i = 0; i < src._size; i++)
				newElements[i] = src._elements[i];
		}
		delete[] _elements;
		_elements = newElements;
		_size = src._size;
	}
	return *this;
}

template <typename T> T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elements[index];
}

template <typename T> T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elements[index];
}

template <typename T> unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T> const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "Index is out of bounds";
}