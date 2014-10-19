
class MaxPQ
{
private:
	int *pq;
	int N;
	bool less(int i, int j);
	void exchange(int i, int j);
	void swim(int k);
	void sink(int k);

public:
	MaxPQ(): N(0){ pq = new int[1024]; } //default constructor
	MaxPQ(int maxN): N(0){ pq = new int[maxN+1]; }
	void insert(int v);
	int max();
	int delMax();
	bool isEmpty();
	int size();

};
