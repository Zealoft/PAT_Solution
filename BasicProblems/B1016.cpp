#include <iostream>
#include <string>

using namespace std;

int main()
{
    string A, B;
    char pa, pb;
    cin >> A >> pa >> B >> pb;
    int a_sum = 0, b_sum = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] == pa) {
            a_sum = a_sum * 10 + pa - '0';
        }
    }
    for (int i = 0; i < B.size(); i++) {
        if (B[i] == pb) {
            b_sum = b_sum * 10 + pb - '0';
        }
    }
    cout << a_sum + b_sum << endl;
    return 0;
}