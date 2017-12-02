#include <cassert>

#include "solid-ex-lsp.hpp"

bool doSomething(Square& s) {
	s.setSide(5);
	return (s.Area() == 25);
}

int main() {
	Square s = Square();
	
	assert(doSomething(s));
	
	return 0;
}
