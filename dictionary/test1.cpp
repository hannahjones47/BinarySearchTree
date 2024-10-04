#include <iostream>
#include "dictionary.h"
using namespace std;

int main() {
	Dictionary d = Dictionary();

	d.insert(1, "Lisbon");
	d.insert(2, "Madrid");
	d.insert(3, "Nottingham");
	d.insert(0, "London");

	cout << "The item with key 1 is " << *(d.lookup(1)) << endl;
	cout << "The item with key 2 is " << *(d.lookup(2)) << endl;
	cout << "The item with key 3 is " << *(d.lookup(3)) << endl;
	cout << "The item with key 0 is " << *(d.lookup(0)) << endl;

	d.insert(2, "Istanbul");
	d.insert(-1, "Manchester");

	cout << "The item with key 2 is " << *(d.lookup(2)) << endl;

	string* s = d.lookup(4);

	if (s == nullptr) 
		cout << "No item with key 4\n";
	else 
		cout << "Item with key 4 is " << *s << endl;

	d.displayEntries();
	d.displayTree();

	cout << "Height of d: " << d.calculateHeight() << endl;
}