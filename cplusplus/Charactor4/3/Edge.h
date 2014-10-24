
class Edge
{
private:
	int V;
	int W;
	double Weight;
public:
	Edge(int v, int w, double weight): V(v), W(w), Weight(weight) {}
	double getWeight() const;
	int either();
	int other(int v);
	int compare(Edge *that);
	bool operator<(const Edge &rhs);
	bool operator<(const Edge *rhs);//useless, the parameter must be reference
};
