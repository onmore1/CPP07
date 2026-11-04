#pragma once

template <typename T> T max(T const &t, T const &t2)
{
	if (t2 >= t)
		return t2;
	else
		return t;
}

template <typename T> T min(T const &t, T const &t2)
{
	if (t2 <= t)
		return t2;
	else
		return t;
}

template <typename T> void swap(T &t, T &t2)
{
	T tmp = t;
	t = t2;
	t2 = tmp;
}