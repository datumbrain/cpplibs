#include <iostream>
#include <algorithm>

using namespace std;

int kthlargest(int k, int arr[], int n) {
	sort(arr, arr + n);
	return arr[n - k];
}

int main() {
	int arr[] = {1, 2, 3, -10, 19, 0, -1, -2};
	// sorted: -10, -2, -1, 0, 1, 2, 3, 19

	int k = 3;
	// 3rd largest is 2

	cout << kthlargest(3, arr, sizeof(arr) / sizeof(arr[0])) << endl;

	return 0;
}