// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
	// write your code in C++14 (g++ 6.2.0)

	vector<int> found_eq_indexes;
	//test each index for eq. potential
	int max_ind = A.size();
	vector<int> indexes;
	for (int i = 0; i < max_ind; ++i)
		indexes.push_back(i);

	for (int test_index : indexes)
	{
		int left_sum = 0;
		int right_sum = 0;
		// left sum
		for (int l = 0; l < test_index; ++l)
		{
			left_sum += A[l];
		}

		//right sum
		for (int r = test_index + 1; r < max_ind; ++r)
		{
			right_sum += A[r];
		}

		if (left_sum == right_sum)
			found_eq_indexes.push_back(test_index);

	}
	if (found_eq_indexes.empty())
		return -1;

	return found_eq_indexes.at(rand() % found_eq_indexes.size());
}