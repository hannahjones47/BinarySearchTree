#include "dictionary.h"
#include <iostream>

TNode::TNode(int k, string v, TNode* l, TNode* r) {
	key = k;
	value = v;
	left = l;
	right = r;
}

Dictionary::Dictionary() {
	root = nullptr;
}

void Dictionary::doDelete(TNode *root) {

	if (root == nullptr)
		return;

	doDelete(root->left);
	doDelete(root->right);
	delete root;
}

Dictionary::~Dictionary() {
	doDelete(root);
}

TNode* Dictionary::deepCopy(TNode* root) {

	if (root == nullptr)
		return nullptr;

	TNode* l = deepCopy(root->left);
	TNode* r = deepCopy(root->right);

	return new TNode(root->key, root->value, l , r);
}

Dictionary::Dictionary(const Dictionary& d) {
	root = deepCopy(d.root);
}

Dictionary::Dictionary(Dictionary&& d) {
	root = d.root;
	d.root = nullptr;	
}

Dictionary& Dictionary::operator=(const Dictionary& d) {

	if (this != &d) {
		this->~Dictionary();
		root = deepCopy(d.root);
	}
	return *this;
}

Dictionary& Dictionary::operator=(Dictionary&& d) {
	
	if (this != &d) {
		this->~Dictionary();
		root = d.root;
		d.root = nullptr;
	}
	return *this;
}

void Dictionary::insert(int k, string v) {
	if (root == nullptr) 
		root = new TNode(k, v);
	else {
		TNode* p = root;
		bool inserted = false;
		while (p!= nullptr && !inserted) {
			if (p->key == k) {
				p->value = v;
				inserted = true;
			}
			else if (k< p->key) {
				if (p->left == nullptr) {
					p->left = new TNode(k, v);
					inserted = true;
				}
				else 
					p = p->left;
			}
			else {
				if (p->right == nullptr) {
					p->right = new TNode(k, v);
					inserted = true;
				}
				else 
					p = p->right;
			}
		}
	}
}

string* Dictionary::lookup(int k) {
	TNode* p = root;
	string* r = nullptr;
	bool found = false;

	while (p != nullptr && !found) 
		if (p->key == k) {
			r = &(p->value);
			found = true;
		}
		else if (k < p->key) 
			p = p->left;
		else 
			p = p->right;

	return r;
}

void Dictionary::doInsert(TNode** root, int k, string v) {

	if (*root == nullptr)
		*root = new TNode(k, v);
	else {
		TNode* p = *root;
		if (p->key == k) 
			p->value = v;
		else if (k < p->key) 
			doInsert(&p->left, k, v);
		else
			doInsert(&p->right, k, v);
	}
}

void Dictionary::insert_rec(int k, string v) {
	doInsert(&root, k, v);
}

string* Dictionary::doLookup(TNode* p, int k) {

	string* r = nullptr;
	if (p != nullptr) {
		if (p->key == k) 
			r = &(p->value);
		else if(k < p->key)
			r = doLookup(p->left, k);
		else 
			r = doLookup(p->right, k);
	}
	
	return r;
}

string* Dictionary::lookup_rec(int k) {
	return doLookup(root, k);
}

TNode* Dictionary::findMinNode(TNode* p) {

	while (p != nullptr && p->left != nullptr) 
		p = p->left;

	return p;
}
void Dictionary::doRemove(TNode**root, int k) {
	
	TNode* p = *root;
	if (p == nullptr)
		return;
	
	if (k < p->key)
		doRemove(&p->left, k);
	else if (k > p->key)
		doRemove (&p->right, k);
	else {
		if (p->left == nullptr && p->right == nullptr) {
			delete p;
			*root = nullptr;
		}
		else if (p->left == nullptr) {
			*root = p->right;
			delete p;
		}
		else if (p->right == nullptr) {
			*root = p->left;
			delete p;
		}
		else {
			TNode* n = findMinNode(p->right);
			(*root)->key = n->key;
			(*root)->value = n->value;
			doRemove(&p->right, n->key);
		}
	}
}

void Dictionary::remove(int k) {
	doRemove(&root, k);
}

void Dictionary::doDisplayEntries(TNode* p) {

	if (p == nullptr)
		return;
	
	doDisplayEntries (p->left);

	cout << "(" << p->key << ", " << p->value << ")\n";

	doDisplayEntries (p->right);
}

void Dictionary::displayEntries() {
	doDisplayEntries(root);
}

void Dictionary::doDisplayTree(TNode* p, string s) {
	if (p == nullptr) {
		cout << s << "(*)\n";
		return;
	}
	else 
		cout << s << "(" << p->key << ", " << p->value << ")\n";
	
	doDisplayTree(p->left, s + "   ");
	doDisplayTree(p->right, s + "   ");
}

void Dictionary::displayTree() {
	doDisplayTree(root, "");
}

void Dictionary::doRotateRightOn(TNode** root, int k) {

	TNode* p = *root;

	if (p == nullptr)
		return;
	
	if (k < p->key) 
		doRotateRightOn(&p->left, k);
	else if (k > p->key)
		doRotateRightOn(&p->right, k);
	else 
		rotateRight(root);
}

void Dictionary::rotateRightOn(int k) {
	doRotateRightOn(&root, k);
}

void Dictionary::doRotateLeftOn(TNode** root, int k) {

	TNode* p = *root;

	if (p == nullptr)
		return;
	
	if (k < p->key) 
		doRotateLeftOn(&p->left, k);
	else if (k > p->key)
		doRotateLeftOn(&p->right, k);
	else 
		rotateLeft(root);
}

void Dictionary::rotateLeftOn(int k) {
	doRotateLeftOn(&root, k);
}

void Dictionary::rotateRight(TNode **root) {

	TNode* p = *root;
	if (p == nullptr || p->left == nullptr)
		return;
	
	TNode* pA = p->left;
	p->left = pA->right;
	pA->right = p;
	*root = pA;
}

void Dictionary::rotateLeft(TNode **root) {

	TNode* p = *root;
	if (p == nullptr || p->right == nullptr)
		return;
	
	TNode* pB = p->right;
	p->right = pB->left;
	pB->left = p;
	*root = pB;
}

int Dictionary::doCalculateHeight(TNode* node) const {
    if (node == nullptr) {
        return 0;  
    }
    int leftHeight = doCalculateHeight(node->left);
    int rightHeight = doCalculateHeight(node->right);
    return std::max(leftHeight, rightHeight) + 1;
}

int Dictionary::calculateHeight() const {
    return doCalculateHeight(root);
}
