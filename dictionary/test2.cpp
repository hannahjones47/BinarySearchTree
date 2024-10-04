#include <iostream>
#include "dictionary.h"
using namespace std;

int main() {
	Dictionary d = Dictionary();

	d.insert_rec(1, "Lisbon");
	d.insert_rec(2, "Madrid");
	d.insert_rec(3, "Nottingham");
	d.insert_rec(0, "London");

	cout << "The item with key 1 is " << *(d.lookup_rec(1)) << endl;
	cout << "The item with key 2 is " << *(d.lookup_rec(2)) << endl;
	cout << "The item with key 3 is " << *(d.lookup_rec(3)) << endl;
	cout << "The item with key 0 is " << *(d.lookup_rec(0)) << endl;

	d.insert_rec(2, "Istanbul");
	d.insert_rec(-1, "Manchester");

	cout << "The item with key 2 is " << *(d.lookup(2)) << endl;

	string* s = d.lookup(4);

	if (s == nullptr) 
		cout << "No item with key 4\n";
	else 
		cout << "Item with key 4 is " << *s << endl;

	/*d.displayEntries();

	d.remove(2);
	cout << "After removing Istanbul\n";
	d.displayEntries();

	d.remove(3);
	cout << "After removing Nottingham\n";*/
	d.displayEntries();
	d.displayTree();

	Dictionary d2(d);
	d2.rotateLeftOn(2);
	cout << "After the rotation\n";
	d2.displayTree();

	Dictionary d3(d);
	d2.rotateRightOn(1);
	cout << "After the rotation\n";
	d2.displayTree();
}