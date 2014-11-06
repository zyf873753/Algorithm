#include<string>
#include<iostream>
using namespace std;
class MSD
{
private:
	const int R;
	const int M;
	string **aux;
	inline int charAt(string *s, int d)
	{ if(d < s->length()) return s->at(d); else return -1;}
	void sort(string **a, int lo, int hi, int d);
	bool less(string *v, string *w, int d);
	void exchange(string **a, int i, int j);
	void insertionSort(string **a, int lo, int hi, int d);

public:
	MSD(): R(256), M(15) {} 
	MSD(int r, int m): R(r), M(m) {}
	void sort(string **a, int N);
};
