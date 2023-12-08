#include <array>
#include <vector>
#include "Containers/array.h"

int main() {
	std::vecot<int, 2> a = {
		1, 2
	};
	alx::array_h<int, 2> b;
	b[0] = 1;
	b[1] = 2;
	alx::array_h<int, 2> c;
	c[0] = 3;
	c[1] = 4;

	b = std::move(c);

	int o = 76;
}