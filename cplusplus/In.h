/*
 *Author: Zhang Yifan
 *Created time: 2014.8.15 19:56:00
 *Modified time: 
 *Description: This header provides methods for reading numbers(note:not include strings so far) from file input.
 */
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;


class In
{
public:
	vector<int> *VReadInts();
	int * ReadInts(int &n);
	int ReadInt();
	double ReadDouble();
	In(char *file);
private:
    ifstream ifs;
};
