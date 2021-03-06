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
#include <sstream>
#include <iterator>
#include <vector>
using namespace std;

const enum {
	QUIT,
	GRASSMANN_NECKLACE,
	FIND_BASES,
	FIND_RANK,
	FIND_FLATS,
	CHECK_CONCORDANT
};

// Displays the menu and returns the option number elected.
void displayMenu();

// Function to get a permutation from input string
vector<int> getPerm(string entry);

int main() {	

	int choice = -1;
	
	while (choice != QUIT) {
		displayMenu();
		cin >> choice;

		if (choice == GRASSMANN_NECKLACE) {
			string entry;
			cin.clear();
			cin.ignore(10000, '\n');

			cout << "*********GET GRASSMANN NECKLACE*********" << endl;
			cout << "Enter permutation (seperated by spaces): ";
			getline(cin, entry);
			vector<int> perm = getPerm(entry);
			vector<vector<int>> gm = grassmannNecklace(perm);

			int gmSize = gm.size();
			int baseSize = gm[0].size();
			cout << endl << endl;
			for (int i = 0; i < gmSize; i++) {
				cout << "{ ";
				for (int j = 0; j < baseSize; j++) {
					cout << gm[i][j] << ",";
				}
				cout << "}";
			}

			cout << endl << "OK?(press enter)" << endl << endl;
			cin;

			cin.clear();
			cin.ignore(10000, '\n');
		}
		else if (choice == FIND_BASES) {

		}
		else if (choice == FIND_RANK) {

		}
		else if (choice == FIND_FLATS) {

		}
		else if (choice == CHECK_CONCORDANT) {
			string entry1;
			string entry2;
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "*********CHECK IF CONCORDANT************" << endl;
			cout << "Enter permutation 1 (smaller permutation, seperated by spaces): ";
			getline(cin, entry1);
			vector<int> perm1 = getPerm(entry1);

			cout << "Enter permutation 2 (larger permutation, seperated by spaces): ";
			getline(cin, entry2);
			vector<int> perm2 = getPerm(entry2);

			bool concordant = isConcordant(perm1, perm2);

			cout << endl << endl;
			if (concordant) {
				cout << "These permutations ARE concordant." << endl << endl;
			}
			else {
				cout << "NOT concordant." << endl << endl;
			}
			cout << "OK?(press enter)" << endl << endl;
			cin;

			cin.clear();
			cin.ignore(10000, '\n');
		}
	}

	return 0;
}

// Displays menu
void displayMenu()
{
	cout << "Welcome to the matroid utilities set by Patrick Martinez." << endl
		<< "Please select one of the following menu options." << endl << endl
		<< "1) Display grassmann necklace of permutation." << endl
		<< "2) Find bases of a permutation." << endl
		<< "3) Find rank of a certain subset in a permutation." << endl
		<< "4) Find all flats of a permutation." << endl
		<< "5) Check if two permutations are concordant" << endl
		<< "0) Quit program" << endl << endl << "Choice:";
}

vector<int> getPerm(string entry)
{
	istringstream iss(entry);

	vector<int>	perm((istream_iterator<int>(iss)),
		istream_iterator<int>());

	return perm;
}
