#include <iostream>

#include "maths\Vector3.h"

int main()
{
	using namespace wicked;
	maths::Vector3 u(1, 0, 0);
	maths::Vector3 v(0, 0, 1);

	std::cout << maths::Vector3::cross(v, u).x << std::endl;
	std::cin.get();
	return 0;
}