#include <iostream>
#include <typeinfo>

using namespace std;

template < typename T >
class DoublyList {

private:
		
	class Node {
	public:

		T data;
		Node* next;
		Node* prev;

		Node(T data, Node* next, Node* prev) {
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
		~Node() {
			
		}
	};
	Node* head;
	Node* tail;
	int sizelist = 0;

public:

	DoublyList() {
		head = nullptr;
		tail = nullptr;
	}
	~DoublyList() {

	}

	

	void add(T data) {
		
		if (head == nullptr) {
			head = new Node(data, nullptr, nullptr);
			tail = this->head;
		}
		else {

			Node* current = this->head;
			while (current->next != nullptr) {
				current = current->next;
			}
			current->next = new Node(data, nullptr, current);
			tail = current->next;
		}
		sizelist++;
	}

	void insrt_el(T data, int num) {
		if (num < sizelist - 1 && num != 0) {
			Node* nnode = this->head;
			Node* pnode;
			Node* current;
			int i = 0;
			while (nnode->next != nullptr) {

				if (i == num) {
					current = new Node(data, nnode, nullptr);
					pnode = nnode->prev;
					pnode->next = current;
					current->prev = pnode;
					nnode->prev = current;
					break;
				}
				nnode = nnode->next;
				i++;
			}
			sizelist++;
		}
		else {
			cout << "Error: wrong value" << endl;
		}
	}

	T get_el(int num) {
		Node* node = this->head;
		int i = 0;
		while (i < sizelist) {

			if (i == num) {
				return node->data;
				break;
			}
			node = node->next;
			i++;
		}
	}

	void print_list() {
		if (head != nullptr) {

			Node* node = this->head;

			while (node->next != nullptr) {
				cout << node->data << " ";
				node = node->next;
			}
			cout << node->data;
		}
		else {
			cout << "empty list";
		}
		cout << endl;
	}

	void erase_el(int num) {
		Node* node = this->head;
		int i = 0;
		while (node->next != nullptr) {
			
			if (i == num) {
				Node* nnode = node->next;
				Node* pnode = node->prev;
				nnode->prev = pnode;
				pnode->next = nnode;
				delete node;
				break;
			}
			node = node->next;
			i++;
		}
		sizelist--;
	}
	
	void pop(string a) {
		Node* hnode = this->head;
		Node* tnode = this->tail;
		Node* node;
		if (a == "h" && sizelist > 1) {
			node = hnode->next;
			node->prev = nullptr;
			head = node;
			delete hnode;
		}
		if (a == "t" && sizelist > 1) {
			node = tail->prev;
			node->next = nullptr;
			tail = node;
			delete tnode;
		}
		if((a == "t" || a == "h") && sizelist == 1){
			Node* node = this->head;
			tail = NULL;
			head = NULL;
			delete node;
		}
		if (a == "t" || a == "h") {
		
		}
		else {
			cout << "Error: wrong value " << endl;
		}
		sizelist--;
	}

	int size() {
		return sizelist;
	}
	
	template<typename T>
	void clear(DoublyList<T> a) {
		sizelist = 0;
		for (int i = a.size(); i < a.size(); i++) {
			a.erase_el(0);
		}
		a.pop("t");
		a.pop("h");
		a.pop("t");
	}

	void sort() {
			Node* current = this->head;
			Node* nnode = head->next;
			if (typeid(head->data) == typeid(1) || typeid(head->data) ==  typeid(1.0)) {
				for (int i = 0; i < sizelist; i++) {
					if (current->data > nnode->data) {
						T a = nnode->data;
						nnode->data = current->data;
						current->data = a;
						i--;
					}
					current = current->next;
					nnode = current->next;
					if (nnode == nullptr) {
						break;
					}
				}
			}
			else {
				cout << "List is not numeric" << endl;
			}
	}

	int find(T a) {
		Node* node = this->head;
		int i = 0;
		while (node->data != a) {
			if (node->next == nullptr) {
				cout << "Element does not exist" << endl;
			}
			node = node->next;
			i++;
		}
		return i;
	}


};

template<typename T>
DoublyList<T> list_union(DoublyList<T> a, DoublyList<T> b) {

	DoublyList<T> un_list;

	if (a.size() > b.size()) {
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); j++) {
				if (a.get_el(i) == b.get_el(j)) {
					un_list.add(b.get_el(j));
					break;
				}
			}
		}
	}
	else {
		for (int j = 0; j < a.size(); j++) {
			for (int i = 0; i < b.size(); i++) {
				if (b.get_el(i) == a.get_el(j)) {
					un_list.add(a.get_el(j));
					break;
				}
			}
		}
	}

	return un_list;
}

template<typename T>
DoublyList<T> list_intersect(DoublyList<T> a, DoublyList<T> b) {

	DoublyList<T> intrsect, c, d;

	c = list_union(a, b);

	for (int i = 0; i < a.size(); i++) {
		d.add(a.get_el(i));
	}
	for (int i = 0; i < b.size(); i++) {
		d.add(b.get_el(i));
	}
	int u = 0;
	for (int i = 0; i < d.size(); i++) {
		for (int j = 0; j < c.size(); j++) {
			if (d.get_el(i) == c.get_el(j)) {
				u = 1;
			}
		}
		if (u == 0) {
			intrsect.add(d.get_el(i));
		}
		u = 0;
	}
	
	return intrsect;
}
