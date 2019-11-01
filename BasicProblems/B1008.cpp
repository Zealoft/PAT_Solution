#include <iostream>

using namespace std;

// 交换num中a到b位置的数
void swap(int* num, int a, int b)
{
	int mid = (a + b) / 2;
	for (int i = a; i <= mid; i++) {
		int temp = num[i];
		num[i] = num[b - i + a];
		num[b - i + a] = temp;
	}
}


int main()
{
	int M, N;
	cin >> N >> M;
	M = M % N;
	int* num = new int[N];
	for (int i = 0; i < N; i++)
		cin >> num[i];
	if (M == 0) {
		for (int i = 0; i < N; i++) {
			cout << num[i];
			if (i != N - 1)
				cout << " ";
		}
		return 0;
	}
	swap(num, 0, N - 1);
	swap(num, 0, M - 1);
	swap(num, M, N - 1);
	for (int i = 0; i < N; i++) {
		cout << num[i];
		if (i != N - 1)
			cout << " ";
	}
	delete[] num;
	return 0;
}