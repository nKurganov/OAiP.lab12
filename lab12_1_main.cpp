#include <iostream>
#include <map>
#include <string>

typedef std::multimap<int, double> MyContainer;

void print(MyContainer&, const std::string&);
void fill(MyContainer&);
void insert_max(MyContainer&);
void erase_min(MyContainer&);
void add_average(MyContainer&);

int main()
{
    MyContainer vec;
    
    fill(vec);
    print(vec, "Initial container: ");
    
    insert_max(vec);
    print(vec, "After replace max: ");
    
    erase_min(vec);
    print(vec, "After erase min: ");
   
    add_average(vec);
    print(vec, "After add average: ");
    
	std::cin.ignore();
	std::cin.get();
	return 0;
}

void print(MyContainer& c, const std::string& message)
{
    std::cout << message << "\n";
	for (MyContainer::iterator it = c.begin(); it != c.end(); ++it)
		std::cout << "\t" << it->first << ": " << it->second << "\n";
    std::cout << "\n\n";
}

void fill(MyContainer& c)
{
    std::cout << "Enter number of elements: ";
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        std::cout << "Element #" << i + 1 << ": ";
        double t;
        std::cin >> t;        
        c.emplace(i, t);
    }
}

void insert_max(MyContainer& c)
{    
	MyContainer::iterator max = c.begin();
	for (MyContainer::iterator it = c.begin(); it != c.end(); ++it)
	{
		if (max->second < it->second)
			max = it;
	}

    std::cout << "Max element: " << max->second << "\n";
	c.insert(*max);
}

void erase_min(MyContainer& c)
{
	MyContainer::iterator min = c.begin();
	for (MyContainer::iterator it = c.begin(); it != c.end(); ++it)
	{
		if (it->second < min->second)
			min = it;
	}
	
	std::cout << "Min element: " << min->second << "\n";
    c.erase(min);
}

void add_average(MyContainer& c)
{
	double avg = 0.0;
	for (MyContainer::iterator it = c.begin(); it != c.end(); ++it)
		avg += it->second;
	avg /= c.size();

    std::cout << "Average: " << avg << "\n";
	for (MyContainer::iterator it = c.begin(); it != c.end(); ++it)
		it->second += avg;
}
