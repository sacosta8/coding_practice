// mergeLists.cpp : Defines the entry point for the console application.
//Merge two sorted lists of uneven size

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//position is the place in the array right before where we want to place the number
void placeNumber(vector<int> & arr,int desired_number) {

	arr.push_back(desired_number);
	//continue to swap the desired_number back until it reaches where it has to be
	for (int i = arr.size() - 1; i > 0; i--) {
		if (arr[i - 1] <= arr[i]) {
			return;
		}
		int combination = arr[i - 1] ^ arr[i];
		arr[i - 1] = combination ^ arr[i - 1];
		arr[i] = combination ^ arr[i];
	}
	return;
}


int main()
{
	vector<int> arr1;
	vector<int> arr2;

	arr1.push_back(1);
	arr1.push_back(1);
	arr1.push_back(2);
	arr1.push_back(4);
	arr1.push_back(5);

	arr2.push_back(0);
	arr2.push_back(1);
	arr2.push_back(1);
	arr2.push_back(2);
	arr2.push_back(3);
	arr2.push_back(3);
	arr2.push_back(4);
	arr2.push_back(5);
	arr2.push_back(5);
	arr2.push_back(34);



	while (arr2.size() > 0) {
		int num = arr2[0];
		placeNumber(arr1,num);
		arr2.erase(arr2.begin());

	}



	for (auto num : arr1) {
		cout << num << " , ";
	}
	cout << endl;

	int t;
	cin >> t;



    return 0;
}

