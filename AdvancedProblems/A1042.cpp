#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int main()
{
	string cards[54];
	int start[54];
	for (int i = 0; i < 54; i++)
		start[i] = i;
	for (int i = 0; i < 54; i++) {
		if (i >= 0 && i < 13)
			cards[i] = "S";
		else if (i >= 13 && i < 26)
			cards[i] = "H";
		else if (i >= 26 && i < 39)
			cards[i] = "C";
		else if (i >= 39 && i < 52)
			cards[i] = "D";
		else
			cards[i] = "J";
		char num[3];
		if (i % 13 < 9) {
			num[0] = i % 13 + 1 + '0', num[1] = 0;
		}
		else if (i % 13 == 9) {
			num[0] = '1', num[1] = '0', num[2] = 0;
		}
		else {
			stringstream ss;
			ss << i % 13 / 10 << i % 13 % 10 + 1;
			string nums;
			ss >> nums;
			strncpy(num, nums.c_str(), 3);
		}
			
		cards[i].append(num);
	}
	int repeat, order[54];
	cin >> repeat;
	for (int i = 0; i < 54; i++) {
		cin >> order[i];
		order[i] -= 1;
	}
	for (int i0 = 0; i0 < repeat; i0++) {
		int temp[54];
		for (int i = 0; i < 54; i++) {
			temp[order[i]] = start[i];
		}
		for (int i = 0; i < 54; i++)
			start[i] = temp[i];
	}
	for (int i = 0; i < 54; i++) {
		cout << cards[start[i]];
		if (i != 53)
			cout << " ";
	}
	return 0;
}