#include<string>
#include<iostream>
#include"../../Queue.cc"

using namespace std;
class TrieST
{
private:
	class Node
	{
	public:
		int val;
		Node **next;
		Node():val(-1) 
		{
		   	next = new Node *[R]; 
			for(int i=0; i<R; i++)
				next[i] = NULL;
		}
	};

    static int R;
	Node *root;
	Node *get(Node *x, string key, int d);
	Node *put(Node *x, string key, int val, int d);
	void collect(Node *x, string pre, Queue<string> *q);
	void collect(Node *x, string pre, string pat, Queue<string> *q);
	int search(Node *x, string s, int d, int length);


public:
	TrieST() { root = new Node(); }
	int get(string key);
	void put(string key, int val);
	Queue<string> *keysWithPrefix(string pre);
	Queue<string> *keysThatMatch(string pre);
	string longestPrefixOf(string s);
	int recurse(int n);
};
