#include <iostream>
#include "DoublyList.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	
	DoublyList<int> a;
	
	a.print_list();

	cout << "���������� ������" << endl;
	for (int i = 0; i < 10; i++) {
		a.add(i);
	}
	a.print_list(); 

	cout << endl;

	cout << "����� �������" << endl;
	cout << "size: " << a.size() << endl;

	cout << "�������� �������� " << endl;
	a.erase_el(3);
	cout << "size: " << a.size() << endl;
	a.print_list();

	cout << endl;

	cout << "������� ������ �������" << endl;
	a.pop("h");
	cout << "size: " << a.size() << endl;
	a.print_list();

	cout << "������� ��������� �������" << endl;
	a.pop("t");
	cout << "size: " << a.size() << endl;
	a.print_list();

	cout << endl;

	cout << "������� �������� " << endl;
	a.insrt_el(2, 3);
	cout << "size: " << a.size() << endl;
	a.print_list();

	cout << endl;

	cout << "������� 5 � ������" << endl;
	a.insrt_el(5, 0);
	a.print_list();
	cout << "size: " << a.size() << endl;

	cout << endl;

	cout << "������� 12 � �����" << endl;
	int t = a.size() - 1;
	a.insrt_el(12, t);
	cout << "size: " << a.size() << endl;
	a.print_list();

	cout << endl;

	cout << "���������� ������ �������� 2" << endl;
	a.print_list();
	cout << a.find(2) << endl;

	cout << endl;

	cout << "��������� �������� 3-��� ��������" << endl;
	a.print_list();
	cout << a.get_el(3) << endl;

	cout << endl;

	cout << "������� ��������� ���������" << endl;
	a.add(-13);
	a.add(1);
	a.add(0);

	cout << endl;

	cout << "���������� ��������� ������" << endl;
	a.print_list();
	a.sort();
	a.print_list();

	a.clear(a);

	cout << endl;

	DoublyList<double> b, c;

	for (int i = 23; i > 9; i--) {
		c.add(i);
	}
	for (int i = 0; i < 16; i++) {
		b.add(i);
	}
	cout << "������ b: " << endl;
	b.print_list();
	cout << "������ c: " << endl;
	c.print_list();
	
	
	cout << endl << "����������� �������" << endl;
	DoublyList<double> d;
	d = list_union(c, b);
	d.print_list();

	cout << endl << "����������� �������" << endl;
	DoublyList<double> e;
	e = list_intersect(c, b);
	e.print_list();

	b.clear(b);
	c.clear(c);
	d.clear(d);
	e.clear(e);

	return 0;
}