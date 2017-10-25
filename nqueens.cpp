#include <iostream>
using namespace std;

bool isValid(int **a, int n, int i, int j) {
	for (int x = 0; x < n; x++) {
		if (a[x][j] == 1) {
			return false;
		}
	}

	for (int y = 0; y < n; y++) {
		if (a[i][y] == 1) {
			return false;
		}
	}
	
	for (int k = 1; i - k >= 0 && j + k < n; k++) {
		if (a[i-k][j+k] == 1) {
			return false;
		}
	}

	for (int k = 1; i - k >= 0 && j - k >= 0; k++) {
		if (a[i-k][j-k] == 1) {
			return false;
		}
	}
	
	for (int k = 1; i + k < n && j - k >= 0; k++) {
		if (a[i+k][j-k] == 1) {
			return false;
		}
	}

	for (int k = 1; i + k < n && j + k < n; k++) {
		if (a[i+k][j+k] == 1) {
			return false;
		}
	}
	
	return true;
}

bool printQueen(int **a, int n, int d = 0) {
	if (d == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return true;
	}

	int i = d;
	for (int j = 0; j < n; j++) {
		if (a[i][j] == 1) {
			continue;
		}
		if (isValid(a, n, i, j)) {
			a[i][j] = 1;
			if(printQueen(a, n, d + 1)) {
				return true;
			}
			a[i][j] = 0;
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	int **a = new int*[n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}
	printQueen(a, n, 0);
}

