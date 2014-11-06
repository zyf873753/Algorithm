#include"MSD.h"

bool MSD::less(string *v, string *w, int d)
{
	return v->substr(d) < w->substr(d);
}

void MSD::insertionSort(string **a, int lo, int hi, int d)
{
	for(int i=lo; i<=hi; i++)
		for(int j=i; j>lo && less(a[j], a[j-1], d); j--)
			exchange(a, j, j-1);
}

void MSD::exchange(string **a, int i, int j)
{
	string *temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void MSD::sort(string **a, int lo, int hi, int d)
{
	if(lo+M > hi)
	{
		insertionSort(a, lo, hi, d);
		return;
	}

	int *count = new int[R+2]();
	for(int i=0; i<R+2; i++)
		count[i] = 0;

	for(int i=lo; i<=hi; i++)
		count[charAt(a[i], d) + 2]++;

	for(int i=0; i<R+1; i++)
		count[i+1] += count[i];

	for(int i=lo; i<=hi; i++)
		aux[count[charAt(a[i], d) + 1]++] = a[i];

	for(int i=lo; i<=hi; i++)
		a[i] = aux[i-lo];

	for(int i=0; i<R; i++)
		sort(a, lo+count[i], hi+count[i+1]-1, d+1);
}

void MSD::sort(string **a, int N)
{
	aux = new string *[N];
	sort(a, 0, N-1, 0);
}


int main()
{
	int N;
	cin>>N;
	string **a = new string *[N];
	for(int i=0; i<N; i++)
	{
		string *temp = new string();
		cin>>*temp;
		a[i] = temp;
	}
	MSD *msd = new MSD();
	msd->sort(a, N);
	for(int i=0; i<N; i++)
		cout<<*a[i]<<endl;
}
