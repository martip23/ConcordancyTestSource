// ConcordancyTestSource.cpp : Defines the entry point for the console application.
/*
	By: Patrick Martinez
	ConcordancyTestSource.
	This holds all of the utilities and code needed to check concordancy of two bases of 
	all subsets of a given Matroid.
*/

#include "stdafx.h"
#include "utils.h"
#include <iostream>
using namespace std;

int main()
{
	vector<vector<int>> gm = { { 1,2,4 },{ 2,3,4 },{ 3,4,1 },{ 4,1,6 },{ 1,6,5 },{ 1,6,4 } };
	vector<int> perm = { 3,1,6,5,4,2 };
	grassmannNecklace(perm);
	cout << galeCompare(3, 6, 5, 8) << endl;
	cin.get();
    return 0;
}