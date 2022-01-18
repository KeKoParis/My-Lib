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
	a.insrt_el(13, 3);
	a.print_list();
	a.sort();
	a.print_list();
	
	
	
	cout << 6 + 6 << endl;
	return 0;
}