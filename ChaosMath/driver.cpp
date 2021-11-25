#include <iostream>

#include "vec.hpp"

int main() {
	cm::vec2<float> v(2, 4);
	cm::vec2<float> v1(2, 4);
	cm::vec2<float> v2(4, 2);

	std::cout << (v.xx == v2.yy) << std::endl;
	std::cout << (v.x == v2.y) << std::endl;
	std::cout << (v.x == 2) << std::endl;

	return 0;
}