#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <map>
#include <string>
#include <iostream>

template <typename T>
class MyVector
{
public:
	MyVector() {}
	MyVector(int n);

	void print(const std::string & message) const;
	void insert_max();
	void erase_min();
	void inc_average();

private:
	std::multimap<int, T> vec;
};

template <typename T>
MyVector<T>::MyVector(int n)
{
	for (int i = 0; i < n; ++i) {
		std::cout << "Element #" << i + 1 << ":\n";
		T el;
		std::cin >> el;
		vec.emplace(i, el);
	}
}

template <typename T>
void MyVector<T>::print(const std::string & message) const
{
	std::cout << message << "\n";
	for (std::multimap<int, T>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << "\t" << it->first << ": " << it->second << "\n";
	std::cout << "\n\n";
}

template <typename T>
void MyVector<T>::insert_max()
{
	std::multimap<int, T>::iterator max = vec.begin();
	for (std::multimap<int, T>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (max->second < it->second)
			max = it;
	}

	std::cout << "Max element: " << max->second << "\n";
	vec.insert(*max);
}

template <typename T>
void MyVector<T>::erase_min()
{
	std::multimap<int, T>::iterator min = vec.begin();
	for (std::multimap<int, T>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (it->second < min->second)
			min = it;
	}

	std::cout << "Min element: " << min->second << "\n";
	vec.erase(min);
}

template <typename T>
void MyVector<T>::inc_average()
{
	T avg;
	for (std::multimap<int, T>::iterator it = vec.begin(); it != vec.end(); ++it)
		avg += it->second;
	avg = avg / vec.size();

	std::cout << "Average: " << avg << "\n";
	for (std::multimap<int, T>::iterator it = vec.begin(); it != vec.end(); ++it)
		it->second += avg;
}

#endif