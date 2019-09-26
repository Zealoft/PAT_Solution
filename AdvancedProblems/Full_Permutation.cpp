/*
print the full permutation in dictionary order.
按照字典序从小到大的顺序输出1~n的全排列。
 */
#include <iostream>

using namespace std;

int* P, * hashTable, n;

void generateP(int index)
{
	if (index == n + 1) {
		for (int i = 1; i <= n; i++)
			cout << P[i] << " ";
		cout << endl;
		return;
	}
	for (int x = 1; x <= n; x++) {
		if (hashTable[x] == 0) {
			P[index] = x;
			hashTable[x] = 1;
			generateP(index + 1);
			hashTable[x] = 0;
		}
	}
}

int main()
{
	cout << "Please input n: ";
	cin >> n;
	if (n > 10 || n < 0) {
		cerr << "Invalid input of n!" << endl;
		return -1;
	}
	// calc the value of n!
	int grade = 1;
	for (int i = n; i >= 1; i--) 
		grade *= i;
	P = new int[grade], hashTable = new int[grade];
	for (int i = 0; i < grade; i++) {
		P[i] = 0;
		hashTable[i] = 0;
	}
	generateP(1);
	return 0;
}