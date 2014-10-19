#include<string>
#include<queue>
using namespace std;

class BinarySearchST
{
private:
	int N;

public:
	string *keys;
	int *vals;
	BinarySearchST(int capacity):N(0)
	{
		keys = new string[capacity];
		vals = new int[capacity];
	}
	int rank(string key);
	void put(string key, int val);
	int get(string key);
	void del(string key);
	bool contains(string key);
	bool isEmpty();
	int size();
	string min();
	string max();
	string floor(string key);
	string ceiling(string key);
	string select(int k);
	void deleteMin();
	void deleteMax();
	int size(string lo, string hi);
	queue<string> *getKeys(string lo, string hi);
};
