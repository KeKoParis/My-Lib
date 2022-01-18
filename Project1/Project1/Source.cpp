#include <iostream>
#include "DoublyList.h"

using namespace std;

int main() {

	
	DoublyList<int> a;
	a.add(-3);
	a.add(2);
	a.add(5);
	a.add(6);
	a.add(8);
	a.print_list();
	
	DoublyList<int> b;
	b.add(74);
	b.add(-3);
	b.add(5);
	b.add(0);
	b.print_list();
	
	DoublyList<int> c;
	c = list_intersect(a, b);
	c.print_list();
	
	cout << 6 + 6 << endl;
	return 0;
}