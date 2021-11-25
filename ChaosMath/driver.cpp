#include <iostream>

#include "vec.hpp"

int main() {
	cm::vec2<float> v(2, 2);

	std::cout << v << std::endl;

	//+ += - -= * *= / /= -v

	//v = v.xy * 10;
	//v.xy *= 10;

	std::cout << v.x << std::endl;

	return 0;
}