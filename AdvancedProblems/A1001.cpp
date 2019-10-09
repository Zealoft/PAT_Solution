#include <iostream>
#include <stack>
using namespace std;
int main()
{
	int a, b;
	stack<char> res;
	cin >> a >> b;
	int sum = a + b, count = 0;
	bool negative = false;
	if (sum < 0) {
		negative = true;
		sum = -1 * sum;
	}
	else if (sum == 0) {
		printf("%d", sum);
		return 0;
	}
	while (sum) {
		int num = sum % 10;
		char in = num + '0';
		res.push(in);
		sum /= 10;
		if (sum && ++count == 3) {
			count = 0;
			res.push(',');
		}
	}
	if (negative)
		printf("-");
	while (!res.empty()) {
		printf("%c", res.top());
		res.pop();
	}
	return 0;
}