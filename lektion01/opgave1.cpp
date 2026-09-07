#include <iostream>
#include <vector>

int logTwo(int x);
int sum(int n);
bool binarySearch(std::vector<int> arr, int find);

int main() {

  	std::cout << logTwo(32) << std::endl;
	std::cout << logTwo(4096) << std::endl;

	std::cout << sum(13) << std::endl;

	std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 8, 12, 15, 16, 19, 24, 26, 29, 34, 39, 41, 43, 47};
	std::cout << binarySearch(numbers, 26) << std::endl;
	
  	return 0;
}

// Precondition: x is power of 2
int logTwo(int x) {
	if (x == 1) {
		return 0;
	} else {
		return 1 + logTwo(x / 2);
	}
}

int sum(int n) {
	if (n < 1) {
		return 0;
	}

	return n + sum(n - 2);
}

bool binarySearch(std::vector<int> arr, int n) {
	if (arr[0] == n) {
		return true;
	}

	int start = 0;
	int mid = 0;
	int end = arr.size();

	while (start <= end) {
		mid = (start + end)/2;
		if (arr[mid] < n) {
			start = mid + 1;
		} else if (arr[mid] > n) {
			end = mid - 1;
		} else {
			return true;
		}
	}

	return false;
}