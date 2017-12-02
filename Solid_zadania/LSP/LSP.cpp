#include <cassert>
#include <iostream>

#include "LSP.cpp"

bool doSomething(Square& s) {
	s.setSide(5);
	return (s.Area() == 25);
}

int main() {
	Square s = Square();
	
	assert(doSomething(s));
	
	std::cout << doSomething(s) << std::endl;
	
	return 0;
}
