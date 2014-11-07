#include"TrieST.h"

int TrieST::R = 127;

int TrieST::get(string key)
{
	Node *x = get(root, key, 0);
	if(x == NULL) return -1;
	return x->val;
}

TrieST::Node *TrieST::get(Node *x, string key, int d)
{
	if(x == NULL) return NULL;
	if(d == key.length()) return x;
	char c = key.at(d);
	return get(x->next[c], key, d+1);
}

void TrieST::put(string key, int val)
{
	root = put(root, key, val, 0);
}

TrieST::Node *TrieST::put(Node *x, string key, int val, int d)
{
	if(x == NULL) x = new Node();
	if(d == key.length()) { x->val = val;  return x; }
	char c = key.at(d);
	x->next[c] = put(x->next[c], key, val, d+1);
	return x;
}

Queue<string> *TrieST::keysWithPrefix(string pre)
{
	Queue<string> *q = new Queue<string>();
	collect(get(root, pre, 0), pre, q);
	return q;
}

void TrieST::collect(Node *x, string pre, Queue<string> *q)
{
	if(x == NULL) return;
	if(x->val != -1) q->enqueue(pre);
	for(char c=0; c<R; c++)
		collect(x->next[c], pre+c, q);
}

Queue<string> *TrieST::keysThatMatch(string pat)
{
	Queue<string> *q = new Queue<string>();
	collect(root, "", pat, q);
	return q;
}

void TrieST::collect(Node *x, string pre, string pat, Queue<string> *q)
{
	int d = pre.length();
	if(x == NULL) return;
	if(d == pat.length() && x->val != -1) q->enqueue(pre);
	if(d == pat.length()) return ;
	char next = pat.at(d);
	for(char c=0; c<R; c++)
	{
		if(next=='.' || next==c)
			collect((x->next)[c], pre+c, pat, q);
	}
}

string TrieST::longestPrefixOf(string s)
{
	int length = search(root, s, 0, 0);
	return s.substr(0, length);
}

int TrieST::search(Node *x, string s, int d, int length)
{
	if(x==NULL) return length;	
	if(x->val != -1) length = d;
	if(d == s.length()) return length;
	char c = s.at(d);
	return search(x->next[c], s, d+1, length);
}

int TrieST::recurse(int n)
{
	if(n == 1) return 1;
	return n*(n-1);
}

int main()
{
	TrieST *st = new TrieST();
	string temp;
	for(int i=0; cin>>temp; i++)
		st->put(temp, i);
	/****************get*****************/
	int index = st->get("shells");
	if(index == -1)
		cout<<"not found"<<endl;
	else
		cout<<"temp: "<<index<<endl;

	
	/**********keysWithPrefix*****************/
	Queue<string> *q1 = st->keysWithPrefix("");
	while(!q1->isEmpty())
		cout<<q1->dequeue()<<endl;
	cout<<endl;
	
	

	/************keysThatMatch***************/
	Queue<string> *q = st->keysThatMatch("s.e");
	cout<<"keysThatMatch:"<<endl;
	while(!q->isEmpty())
		cout<<q->dequeue()<<endl;
	/************longestPrefixOf***************/
	string ss = st->longestPrefixOf("shellsdjflkdsjlf");
	cout<<ss<<endl;
}
