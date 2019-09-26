#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct testee {
	string id;
	int score;
	int location_num;
	int location_rank;
	int final_rank;

	friend ostream& operator<<(ostream& out, const testee& t) {
		out << t.id << " " << t.final_rank << " " << t.location_num << " " << t.location_rank;
		return out;
	}
};


bool cmp(testee* t1, testee* t2)
{
	if (t1->score > t2->score)
		return true;
	else if (t1->score == t2->score && t1->id < t2->id)
		return true;
	return false;
}


int main()
{
	vector<testee *> all_testees;
	int N, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		sum += K;
		//testee* city_testees = new testee[K];
		vector<testee*> city_testees;
		for (int j = 0; j < K; j++) {
			testee* t = new testee;
			cin >> t->id >> t->score;
			t->location_num = i + 1;
			city_testees.push_back(t);
			all_testees.push_back(t);
		}
		sort(city_testees.begin(), city_testees.end(), cmp);
		int local_rank = 1;
		for (int j = 0; j < K; j++) {
			if (j > 0 && city_testees[j]->score == city_testees[j - 1]->score) {
				city_testees[j]->location_rank = city_testees[j - 1]->location_rank;
			}
			else
				city_testees[j]->location_rank = local_rank;
			local_rank++;
		}
	}
	sort(all_testees.begin(), all_testees.end(), cmp);
	int final_rank = 1;
	for (int j = 0; j < sum; j++) {
		if (j > 0 && all_testees[j]->score == all_testees[j - 1]->score) {
			all_testees[j]->final_rank = all_testees[j - 1]->final_rank;
		}
		else
			all_testees[j]->final_rank = final_rank;
		final_rank++;
	}
	cout << sum << endl;
	for (int i = 0; i < sum; i++)
		cout << *all_testees[i] << endl;
	return 0;
}