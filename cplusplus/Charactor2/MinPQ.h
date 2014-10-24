
template <typename T> class MinPQ
{
private:
	T *pq;
	int N;
	bool less(int i, int j);
	void exchange(int i, int j);
	void swim(int k);
	void sink(int k);
public:
	MinPQ(): N(0){ pq = new T[1024]; }
	MinPQ(int maxN): N(0){ pq = new T[maxN+1]; }
	void insert(T v);
	T min();
	T delMin();
	bool isEmpty();
	int size();
};

