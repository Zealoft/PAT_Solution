#include <iostream>
#include <cstdio>
using namespace std;
const int CLK_TCK0 = 100;
int main()
{
	int c1, c2;
	cin >> c1 >> c2;
	int seconds = (c2 - c1) / CLK_TCK0;
	// seconds less than 1 left
	if (c2 - c1 - seconds * CLK_TCK0 >= 50) {
		seconds++;
	}
	int hours = seconds / 3600;
	int mins = (seconds - hours * 3600) / 60;
	int secs = seconds - hours * 3600 - mins * 60;
	printf("%02d:%02d:%02d", hours, mins, secs);
	return 0;
}