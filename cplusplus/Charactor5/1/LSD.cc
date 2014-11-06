#include"LSD.h"

void LSD::sort(string **a, int N, int W)
{
	int R = 128;
	string **aux = new string *[N];
	
	for(int d=W-1; d>=0; d--)
	{
		int *count = new int[R+1];
		for(int i=0; i<R; i++)
			count[i] = 0;
		//key-indexed counting
		for(int i=0; i<N; i++)
			count[a[i]->at(d) + 1]++;
		//compute frequency counts
		for(int i=0; i<R; i++)
			count[i+1] += count[i];
		//transform counts to indices
		for(int i=0; i<N; i++)
			aux[count[a[i]->at(d)]++] = a[i];

		for(int i=0; i<N; i++)
			a[i] = aux[i];
	}
	delete[] aux;
}

int main()
{
	int N, W;
	cin>>N;
	cin>>W;
	string **a = new string *[N];; 
	
	for(int i=0; i<N; i++)
	{
		string *temp = new string();
		cin>>*temp;
		a[i] = temp;
	}
	LSD *lsd = new LSD();
	lsd->sort(a, N, W);
	
	for(int i=0; i<N; i++)
		cout<<*a[i]<<endl;
}

