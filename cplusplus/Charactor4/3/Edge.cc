#include"Edge.h"
#include"iostream"
using namespace std;

double Edge::getWeight() const
{
	return Weight;
}

int Edge::either()
{
	return V;
}

int Edge::other(int v)
{
	if(V == v) return W;
	else if(W == v) return V;
	else return -9999; // need to throw exception there
}

int Edge::compare(Edge *that)
{
	if(this->getWeight() > that->getWeight()) return 1;
	else if(this->getWeight() < that->getWeight()) return -1;
	else return 0;
}

bool Edge::operator<(const Edge &rhs)
{
	return this->getWeight() < rhs.getWeight();
}

bool Edge::operator<(const Edge *rhs)//useless
{
	return this->Weight < rhs->Weight;
}

//int main(int argc, char **argv)
//{
//	Edge *e1 = new Edge(1, 2, 3.00);
//	Edge *e2 = new Edge(2, 3, 4.00);
//	cout<<e2->compare(e1)<<endl;
//	bool isMin = (*e1) < (*e2);
//	cout<<isMin<<endl;
//}
