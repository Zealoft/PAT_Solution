#include <cstdio>
#include <map>

using namespace std;
int main()
{
	int N;
	map<int, int> marks;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int no, mark;
		scanf("%d %d", &no, &mark);
		if (marks.count(no) == 0) {
			marks[no] = mark;
		}
		else
			marks[no] += mark;
	}
	int max_no = 0, max_mark = 0;
	for (auto i = marks.begin(); i != marks.end(); ++i) {
		if (i->second > max_mark) {
			max_no = i->first;
			max_mark = i->second;
		}
	}
	printf("%d %d", max_no, max_mark);
	return 0;
}