/*
 * Author: Zhang Yifan
 * Created time: 2014.8.17
 * Modified time:  
 * Description:This class provides methods to read Numbers from standard input.
*/
#include<iostream>
#include<vector>
using namespace std;
class StdIn
{
public:
	vector<int> * VReadInts();
	int *ReadInts(int &n);
	StdIn() {};
};	
