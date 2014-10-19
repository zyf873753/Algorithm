#include<stdlib.h>

class StdRandom
{
private:
	int uniformPrivate(int lo,int hi);

public:
	StdRandom() {}
	int uniform(int lo,int hi);
	int *getNums(int N,int lo,int hi);
};
