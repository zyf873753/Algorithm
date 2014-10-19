/*
 *Author: Zhang Yifan
 *Created time: 2014.8.31
 *Modified time:
 *Description: This class implement StdRandom.h which provides some functions to   return randomize and specified range number.
 */
#include"StdRandom.h"
#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;



/*private function*/

int StdRandom::uniformPrivate(int lo,int hi)
{
//	for(int i=0;i<10;i++);
	int half=(hi-lo)/2;
	int offset=(lo+hi)/2;
	return pow( -1, rand() ) * (1+(int)(half*(rand()/(RAND_MAX+1.0)))) + offset;

}


/*public function*/
int StdRandom::uniform(int lo,int hi)
{
	srand((int)time(NULL));
	return uniformPrivate(lo,hi);
}

int * StdRandom::getNums(int N,int lo,int hi)
{
	srand((int)time(NULL));
	int *nums=new int[N];
	int *numstemp=nums;
	for(int i=0;i<N;i++)
	{
		*numstemp++=uniformPrivate(lo,hi);
	}
	return nums;

}

//
//int main()
//{
//	StdRandom *r=new StdRandom();
//	int *nums=r->getNums(30,-100,1000);
//	for(int i=0;i<30;i++)
//	{
//		cout<<*nums++<<endl;
//	}
//}

