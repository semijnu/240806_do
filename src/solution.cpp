#include <iostream>
#include <vector>
using namespace std;

string checkMagicSquare(vector<vector<int>>& arr) {
	int rows[100] = { 0 }, cols[100] = { 0 }, diagonal1 = 0, diagonal2 = 0;

	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr.size(); j++) {
			rows[i] += arr[i][j];
			cols[j] += arr[i][j];
		}
		diagonal1 += arr[i][i];
		diagonal2 += arr[i][arr.size() - i - 1];
	}

	for (int i = 1; i < arr.size(); i++) {
		if (rows[i] != rows[i - 1] || cols[i] != cols[i - 1])
			return "NO";
	}
	return (rows[0] == cols[0] && rows[0] == diagonal1 && rows[0] == diagonal2) ? "YES" : "NO";
}

int main() {
	int N;
	cin >> N;

	vector<vector<int>> arr(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	cout << checkMagicSquare(arr) << endl;
	return 0;
}