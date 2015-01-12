#include<string>
#include<iostream>
using namespace std;
class KMP
{
private:
	string pat;
	int **dfa;
public:
	KMP(string p);
	int search(string txt);
};
