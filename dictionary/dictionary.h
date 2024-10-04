#include <string>
#include <vector>
using namespace std;
struct TNode {
	int key;
	string value;
	TNode* left;
	TNode* right;
	TNode(int, string, TNode* = nullptr, TNode* = nullptr);
};

class Dictionary {
	private:
		TNode* root;
		void doDisplayEntries(TNode* p);
		void doInsert(TNode**, int, string);
		string* doLookup(TNode*, int);
		void doRemove(TNode**, int);
		TNode* findMinNode(TNode*);
		void doDelete(TNode*);
		TNode* deepCopy(TNode*);
		void rotateLeft(TNode**);
		void rotateRight(TNode**);
		void doDisplayTree(TNode*, string);
		void doRotateRightOn(TNode**, int);
		void doRotateLeftOn(TNode**, int);
	public:
		Dictionary();
		~Dictionary();
		Dictionary(const Dictionary&);
		Dictionary(Dictionary&&);
		Dictionary & operator=(const Dictionary&);
		Dictionary & operator=(Dictionary&&);
		void insert(int, string);
		string* lookup(int);
		// vector<int> keys ();
		void displayEntries();
		void insert_rec(int,string);
		string* lookup_rec(int);
		void remove(int);
		void displayTree();
		void rotateRightOn(int key);
		void rotateLeftOn(int key);
};
