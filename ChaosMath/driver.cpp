#include <iostream>

#include "vec.hpp"

int main() {
	cm::vec2<float> v(2, 4);

	std::cout << v.magnitude << std::endl;
	std::cout << v.normalized << std::endl;

	return 0;
}