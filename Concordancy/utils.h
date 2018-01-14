#pragma once
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <stdlib.h>
using namespace std;

// Utilities for concordancy test


// Custom mod function since % is only "division remainder"
int mod(int a, int b) {
	{return (a%b + b) % b; }
}

// Does a Gale Comparison of two sets of numbers on a different cyclical order
// Returns true if a <i b.
// a: First value
// b: Second value
// i: "first" digit
// n: ground set
// ALL INTS MUST BE POSITIVE INTEGERS
bool galeCompare(int a, int b, int i, int n) {
	return mod(a - i, n) < mod(b - i, n);
}


// Returns the inverse of a vector assuming it is a valid permutation
vector<int> inverse(const vector<int> permutation, const int length) {
	vector<int> inverse;
	for (int i = 1; i <= length; i++) {
			for (int j = 1; j <= length; j++) {
				if (i == permutation[j-1]) {
					inverse.push_back(j);
					break;
			}
		}
	}
	return inverse;
}

// Computes the grassmann necklace of a derangement and gives each element
// ordered under i. Done by removing k-1 and replacing with item at index k-1
// permutation: The permutation to build a grassmann necklace out of
vector<vector<int>> grassmannNecklace(const vector<int> permutation) {
	int length = permutation.size();
	vector<vector<int>> grassmann;

	// Make initial grassmann bead
	// Using set to add in order using BST
	set<int> tempSet;
	for (int i = 1; i <= length; i++) {
		if (i >= permutation[i - 1]) {
			tempSet.insert(permutation[i - 1]);
		}
	}
	vector<int> prevVect(tempSet.begin(), tempSet.end());
	grassmann.push_back(prevVect);

	// Remove element of last i and replace it with element at perm[i]
	for (int i = 2; i <= length; i++) {
		replace(prevVect.begin(), prevVect.end(), (i - 1), permutation[i - 2]);
		sort(prevVect.begin(), prevVect.end(), [i, length](int a, int b) {
			return galeCompare(a, b, i, length); });
		grassmann.push_back(prevVect);
	}
	return grassmann;
}

vector<vector<int>> subsetsOfSizeN(int n, int k) {
	vector<vector<int>> bases;

	string bitmask(k, 1); // K leading 1's
	bitmask.resize(n, 0); // N-K trailing 0's
	int timesIterated = 0;
						  // print integers and permute bitmask
	do {
		bases.push_back({});
		for (int i = 0; i < n; ++i) // [0..N-1] integers
		{
			if (bitmask[i]) {
				bases[timesIterated].push_back(i+1);
			}
		}
		timesIterated++;
	} while (prev_permutation(bitmask.begin(), bitmask.end()));
	
	return bases;
}

// Finds all of the bases of a specific grassman necklace.
vector<vector<int>> findBases(const vector<vector<int>> grassmann) {
	vector<vector<int>> bases;
	int grassmannLength = grassmann.size();
	int beadSize = grassmann[0].size();

//	vector<int> subset{ values.cbegin(), values.cbegin() + beadSize };

	return bases;
}
