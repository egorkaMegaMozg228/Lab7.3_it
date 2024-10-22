#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
int Result(int** a, const int k, const int n, int& S);
void MinSumOfDiagonals(int** a, int k, int n,int& min_sum);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -15;
	int High = 15;
	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	Create(a, k, n, Low, High);
	Print(a, k, n);
	int S = 0;
	int min_sum = 0;
	Result(a, k, n, S);
	cout << "S = " << S << endl;
	MinSumOfDiagonals(a, k, n, min_sum);
	cout << "S1 = " << min_sum << endl;;
	
	
	for (int i = 0; i < k; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int k, const int n, const int Low, const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int Result(int** a, const int k, const int n, int& S)
{
	int tmp=0;
	for (int j = 0; j < n; j++) {

		for (int i = 0; i < k; i++) {
			if (a[i][j] < 0) {
				tmp = 0;
				break;
			}
			else tmp += a[i][j];
		}
		S += tmp;
		tmp = 0;
	}
	return S;	
}
void MinSumOfDiagonals(int** a, int k, int n,int& min_sum) {
	bool first_diagonal = true;

	for (int j = 0; j < n; ++j) {
		int sum = 0;
		for (int i1 = 0, j1 = j; i1 < k && j1 >= 0; ++i1, --j1) {
			sum += abs(a[i1][j1]);
		}


		if (first_diagonal) {
			min_sum = sum;
			first_diagonal = false;
		}
		else if (sum < min_sum) {
			min_sum = sum;
		}
	}



	for (int i = 1; i < k; ++i) {
		int sum = 0;
		for (int i1 = i, j1 = n - 1; i1 < k && j1 >= 0; ++i1, --j1) {
			sum += abs(a[i1][j1]);
		}


		if (sum < min_sum) {
			min_sum = sum;
		}
	}
}