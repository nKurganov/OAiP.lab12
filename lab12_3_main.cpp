#include <iostream>
#include <string>

#include "time_class.h"
#include "my_vector_12_3.h"

typedef MyVector<Time> MyContainer;

int main()
{
	std::cout << "Enter number of elements: ";
	int n;
	std::cin >> n;

	MyContainer vec(n);
	vec.print("Initial container: ");

	vec.insert_max();
	vec.print("After replace max: ");

	vec.erase_min();
	vec.print("After erase min: ");

	vec.inc_average();
	vec.print("After add average: ");

	std::cin.ignore();
	std::cin.get();
	return 0;
}