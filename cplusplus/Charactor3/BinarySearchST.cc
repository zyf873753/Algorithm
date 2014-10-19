#include"BinarySearchST.h"
#include<iostream>
using namespace std;
int BinarySearchST::rank(string key)
{
	int lo = 0, hi = N - 1;
	int mid;
	while(hi >= lo)
	{
		mid = (lo + hi) / 2;	
		int cmp = key.compare(keys[mid]); //cmp can't be bool
		if(cmp > 0) lo = mid + 1;
		else if(cmp < 0) hi = mid - 1;
		else return mid;
	}
	return lo;
}

int BinarySearchST::size()
{
	return N;
}

bool BinarySearchST::isEmpty()
{
	return N == 0;
}

int BinarySearchST::get(string key)
{
	if(isEmpty()) return -1; //-1 = null, because the class of vals is int
	int i = rank(key);
	if(i < N && key.compare(keys[i]) == 0) return vals[i];
	else return -1;
}

void BinarySearchST::put(string key, int val)
{
	int i = rank(key);
	if(i < N && key.compare(keys[i]) == 0) 
	{
		vals[i] = val;
		return;
	}
	for(int j = N; j > i; j--)
	{
		keys[j] = keys[j - 1];
		vals[j] = vals[j - 1];
	}
	keys[i] = key;
	vals[i] = val;
	N++;
}

void BinarySearchST::del(string key)
{
	int i = rank(key);	
	if(i < N && key.compare(keys[i]) == 0) 
	{
		for(int j = i; j < N - 1; j++)	
		{
			keys[j] = keys[j + 1];
			vals[j] = vals[j + 1];
		}
		keys[N - 1] = ""; // not neccesary
		vals[N - 1] = -1; // not neccesary
		N--;
	}
	else
	{
		cout<<"no such key!"<<endl;
		return;
	}

}

bool BinarySearchST::contains(string key)
{
	if(isEmpty()) return false; //-1 = null, because the class of vals is int
	int i = rank(key);
	if(i < N && key.compare(keys[i]) == 0) return true;
	else return false;
}

string BinarySearchST::min()
{
	return keys[0];
}

string BinarySearchST::max()
{
	return keys[N-1];
}

string BinarySearchST::ceiling(string key)
{
	int i = rank(key);	
	return keys[i];
}

string BinarySearchST::floor(string key)
{
	int i = rank(key);
	if(i < N && key.compare(keys[i]) == 0) return keys[i];
	else return keys[i - 1];
}

string BinarySearchST::select(int k)
{
	return keys[k];
}

void BinarySearchST::deleteMin()
{
	if(isEmpty()) return;
	for(int i = 0; i < (N - 1); i++)
	{
		keys[i] = keys[i + 1];
		vals[i] = vals[i + 1];
	}
	keys[N - 1] = "";
	vals[N - 1] = -1;
	N--;
}

void BinarySearchST::deleteMax()
{
	if(isEmpty()) return;
	keys[N - 1] = "";
	vals[N - 1] = -1;
	N--;
}

int BinarySearchST::size(string lo, string hi)
{
	int i = rank(lo);
	int j = rank(hi);
	if(j < N && hi.compare(keys[j]) == 0) return j - i + 1;
	else return j - i;
}

queue<string> *BinarySearchST::getKeys(string lo, string hi)
{
	queue<string> *q = new queue<string>();
	int i = rank(lo);
	int j = rank(hi);
	int lim;
	if(j < N && hi.compare(keys[j]) == 0)  lim = j;
	else lim = j - 1;
	for(int k = i; k <= lim; k++)
		q->push(keys[k]);
	return q;
}

int main()
{
	BinarySearchST *st = new BinarySearchST(100);
	cout<<"isEmpty: " <<st->isEmpty()<<endl;	
	st->put("a", 1);
	st->put("b", 2);
	st->put("c", 3);
	st->put("d", 4);
	st->put("f", 6);
	cout<<"size: " <<st->size()<<endl;	
	cout<<"size(\"b\",\"f\"):"<<st->size("b", "f")<<endl;
	cout<<"b~f:"<<endl;
	queue<string> *q = st->getKeys("b","f");
	while(!q->empty())
	{
		cout<<q->front()<<endl;
		q->pop();
	}
	cout<<"get(\"a\"): "<<st->get("a")<<endl;
	cout<<"del(\"b\")"<<endl;
	st->del("b");
	cout<<"size: " <<st->size()<<endl;	
	cout<<"contains(\"b\"):"<<st->contains("b")<<endl;
	cout<<"ceiling(\"e\"):"<<st->ceiling("e")<<endl;
	cout<<"floor(\"e\"):"<<st->floor("e")<<endl;
	st->deleteMin();
	st->deleteMax();
	cout<<"deleteMin() deleteMax() size:"<<st->size()<<endl;
	


}
