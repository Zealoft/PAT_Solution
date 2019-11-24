#include <cmath>
#include <iostream>

using namespace std;

/* Basic way to tell if a number is a prime: O(sqrt(n))*/
bool is_Prime(int n)
{
	int sqr = (int)sqrt(1.0 * n);
	for (int i = 2; i <= sqr; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

// return num of prime numbers
int Find_Prime_Basic(int *prime, bool *p, int maxn)
{
	int pNum = 0;
	for (int i = 1; i <= maxn; i++) {
		if (is_Prime(i)) {
			prime[pNum++] = i;
			p[i] = true;
		}
	}
	return pNum;
}

/* Eratosthenes筛法 O(nloglogn) */
int Find_Prime(int* prime, bool* p, int maxn)
{
	int pNum = 0;
	for (int i = 0; i < maxn; i++)
		p[i] = false;
	for (int i = 2; i < maxn; i++) {
		if (p[i] == false) {
			prime[pNum++] = i;
			for (int j = i + i; j < maxn; j += i)
				p[j] = true;
		}
	}
	return pNum;
}

int main()
{
	int maxn = 10100;
	int* prime = new int[maxn];
	bool* p = new bool[maxn];
	int pNum = Find_Prime(prime, p, maxn);
	for (int i = 0; i < pNum; i++)
		cout << prime[i] << " ";
	cout << endl;
	return 0;
}