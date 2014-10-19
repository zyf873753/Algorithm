/*
 * Author: Zhang Yifan
 * Created time: 2014.8.17
 * Modified time:  
 * Description:This class provides methods to read Numbers from standard input.
*/
#include"StdIn.h"
using namespace std;
vector<int> * StdIn::VReadInts()
{
	int tempNo;
	vector<int> * vec=new vector<int>();
	while(cin>>tempNo)
	{
		vec->push_back(tempNo);
	}
	return vec;
}

int *StdIn::ReadInts(int &n)
{
	int *data=new int();
	int *tempdata=data;
	int tempNum;
	n=0;
	while(cin>>tempNum)	
	{
		*tempdata=tempNum;
		tempdata++;
		n++;
	}
	return data;
}
int main()
{
	/*
	vector<int> *vec=StdIn().ReadInts();
	for(vector<int>::iterator iter=vec->begin();iter!=vec->end();iter++)
	{
		cout<<*iter<<endl;
	}
	*/

	int n;
	int *ptr=StdIn().ReadInts(n);
	for(int i=0;i<n;i++)
	{
		cout<<*ptr++<<endl;
	}	
}
