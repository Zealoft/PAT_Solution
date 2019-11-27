/*
 * 用multiset红黑树实现top k问题
 */
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef multiset<int, less<int>> intSet;
typedef multiset<int, less<int>>::iterator setIterator;

void GetTopNumbers(const vector<int>& data, intSet& greatestNumbers, int k)
{
	greatestNumbers.clear();
	if (k < 1 || data.size() < k)
		return;
	vector<int>::const_iterator iter = data.begin();
	for (; iter != data.end(); ++iter) {
		if (greatestNumbers.size() < k)
			greatestNumbers.insert(*iter);
		else {
			setIterator iterLeast = greatestNumbers.begin();
			if (*iter > * (greatestNumbers.begin())) {
				greatestNumbers.erase(iterLeast);
				greatestNumbers.insert(*iter);
			}
		}
	}
}

int main()
{
	vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
	intSet greatest_k;
	GetTopNumbers(v, greatest_k, 5);
	for (auto i = greatest_k.begin(); i != greatest_k.end(); ++i)
		cout << *i << " ";
	cout << endl;
	return 0;
}