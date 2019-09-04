#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string input;
    stack<int> nums;
    int sum = 0;
    cin >> input;
    for(int i = 0; i < input.size(); i++) {
        sum += input[i] - '0';
    }
    while(sum) {
        nums.push(sum % 10);
        sum /= 10;
    }
    while (!nums.empty()) {
        int res = nums.top();
        if (res == 0) {
            printf("ling");
        }
        else if (res == 1) 
            printf("yi");
        else if (res == 2) 
            printf("er");
        else if (res == 3) 
            printf("san");
        else if (res == 4) 
            printf("si");
        else if (res == 5) 
            printf("wu");
        else if (res == 6) 
            printf("liu");
        else if (res == 7) 
            printf("qi");
        else if (res == 8) 
            printf("ba");
        else if (res == 9) 
            printf("jiu");
        nums.pop();
        if (!nums.empty())
            printf(" ");
    }
    return 0;
}