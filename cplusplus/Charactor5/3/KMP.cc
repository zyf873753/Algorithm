#include"KMP.h"

KMP::KMP(string p): pat(p)
{
	int M = pat.length();
	int R = 128;

	dfa = new int*[R];
	for(int i=0; i<R; i++)
		dfa[i] = new int[M];

	dfa[pat.at(0)][0] = 1;
	for(int X=0, j=1; j<M; j++)
	{
		for(char c=0; c<R; c++)
		{
			dfa[c][j] = dfa[c][X];
			if(c==R-1)
				break;
		}
		dfa[pat.at(j)][j] = j + 1;
		X = dfa[pat.at(j)][X];
	}
}

int KMP::search(string txt)
{
	int M = pat.length();
	int N = txt.length();
	int i,j;
	for(i=0, j=0; i<N && j<M; i++)
		j = dfa[txt.at(i)][j];
	if(j==M) return i-M;
	else return N;
}

int main(int argc, char **argv)
{
	string pat = argv[1];
	string txt = argv[2];
	KMP *kmp = new KMP(pat);
	int offset = kmp->search(txt);
	cout<<"text:    "<<txt<<endl;
	cout<<"pattern: ";
	for(int i=0; i<offset; i++)
		cout<<" "<<flush;
	cout<<pat<<endl;
}
