#include <iostream>
#include "DoublyList.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");
	
	DoublyList<int> a;
	
	a.print_list();

	cout << "Заполнение списка" << endl;
	for (int i = 0; i < 10; i++) {
		a.add(i);
	}
	a.print_list(); 

	cout << endl;

	cout << "Вывод размера" << endl;
	cout << "size: " << a.size() << endl;

	cout << "Удаление элемента " << endl;
	a.erase_el(3);
	cout << "size: " << a.size() << endl;
	a.print_list();

	cout << endl;

	cout << "Удалить первый элемент" << endl;
	a.pop("h");
	cout << "size: " << a.size() << endl;
	a.print_list();

	cout << "Удалить последний элемент" << endl;
	a.pop("t");
	cout << "size: " << a.size() << endl;
	a.print_list();

	cout << endl;

	cout << "Вставка элемента " << endl;
	a.insrt_el(2, 3);
	cout << "size: " << a.size() << endl;
	a.print_list();

	cout << endl;

	cout << "Вставка 5 в начало" << endl;
	a.insrt_el(5, 0);
	a.print_list();
	cout << "size: " << a.size() << endl;

	cout << endl;

	cout << "Вставка 12 в конец" << endl;
	int t = a.size() - 1;
	a.insrt_el(12, t);
	cout << "size: " << a.size() << endl;
	a.print_list();

	cout << endl;

	cout << "Нахождение номера элемента 2" << endl;
	a.print_list();
	cout << a.find(2) << endl;

	cout << endl;

	cout << "Получение значения 3-его элемента" << endl;
	a.print_list();
	cout << a.get_el(3) << endl;

	cout << endl;

	cout << "Добавим несколько элементов" << endl;
	a.add(-13);
	a.add(1);
	a.add(0);

	cout << endl;

	cout << "Сортировка числового списка" << endl;
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
	cout << "Список b: " << endl;
	b.print_list();
	cout << "Список c: " << endl;
	c.print_list();
	
	
	cout << endl << "Объединение списков" << endl;
	DoublyList<double> d;
	d = list_union(c, b);
	d.print_list();

	cout << endl << "Пересечение списков" << endl;
	DoublyList<double> e;
	e = list_intersect(c, b);
	e.print_list();

	b.clear(b);
	c.clear(c);
	d.clear(d);
	e.clear(e);

	return 0;
}