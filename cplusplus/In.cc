/*
 *Author: Zhang Yifan
 *Created time: 2014.8.15
 *Modified time:
 *Description: This class implement In.h which provides methods for reading numbers(note:not include strings so far) from file input.
 */
#include"In.h"
using namespace std;

/*This Constructor initiate the stringstream object 'ifs' with a file*/
In::In(char *file):ifs(file)
{
	
}

/*This method reads numbers from file input with vector*/
vector<int> *In::VReadInts()/*{{{*/
{
	string tempStr;
	int tempNum;
	vector<int> *vec=new vector<int>();
	while(ifs>>tempNum)
	{
		vec->push_back(tempNum);
	//	cout<<tempNum<<endl; //for debug
	}
//	cout<<vec->size()<<endl;
	return vec;
}/*}}}*/

/*There is a problem with following function witch I hava't figured it out. */
int * In::ReadInts(int &n)/*{{{*/
{
	int *data=new int;
	int *tempdata=data;
	int tempNum;
	n=0;
	while(ifs>>tempNum)
	{
		*tempdata=tempNum;
		tempdata++;
		n++;
	}
	return data;
}/*}}}*/

int In::ReadInt()
{
	int temp;
	ifs>>temp;
	return temp;	
}

/*Following code is for testing*/
//int main(int argc,char *argv[])/*{{{*/
//{
//	//test member function VReadInts()/*{{{*/
//	
////	if(argc!=2)
////	{
////		cout<<"please enter correct parameter!"<<endl;
////		return 0;
////	}
////	//In in(argv[1]);
////    vector<int> *vec  = In(argv[1]).VReadInts();
////	for(vector<int>::iterator iter=vec->begin();iter!=vec->end();iter++)
////	{
////		cout<<*iter<<endl;
////	}/*}}}*/
//
//	//test member function ReadInts()	
//	/*
//	if(argc!=2)
//	{
//		cout<<"please enter correct parameter!"<<endl;
//		return 0;
//	}
//	int n;
//	int *ptr=In(argv[1]).ReadInts(n);
//	for(int i=0;i<n;i++)	
//	{
//		cout<<*ptr<<endl;
//		ptr++;
//	}
////	while(ptr!=NULL)
////	{
////		cout<<*ptr++<<endl;
////	}
//*/
	
//	if(argc!=2)
//	{
//		cout<<"please enter correct parameter!"<<endl;
//		return 0;
//	}
//	In *in = new In(argv[1]);
//	int temp = in->ReadInt();
//	cout<<temp<<endl;
//	temp = in->ReadInt();
//	cout<<temp<<endl;
//	
//}/*}}}*/

