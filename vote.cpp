#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct S {
	char name[100];
};

bool compare(S a, S b) {
	if (strcmp(a.name, b.name) < 0) {
		return true;
	}
	return false;
}

int main() {
	vector<S> candidate;

	freopen("11.input.txt", "r", stdin);

	char line[100];
	while (1) {
		cin.getline(line, 100);
		if (cin.eof()) break;
		if (line != "") {
			S s;
			strcpy(s.name,line);
			candidate.push_back(s);
		}
	}

	vector<S> maxname;
	int maxvote = 0;
	int count = 1;

	if (candidate.size() == 1) {
		cout << candidate[0].name << endl;
		return 0;
	}

	sort(candidate.begin(), candidate.end(), compare);
	for (int i = 1; i < candidate.size(); i++) {
		if (!strcmp(candidate[i - 1].name, candidate[i].name)) { 
			count++;
		}
		else {
			if (count == maxvote) {
				maxname.push_back(candidate[i - 1]);
			}
			else if (count > maxvote) {
				maxvote = count;
				maxname.clear();
				maxname.push_back(candidate[i - 1]);
			}
			count = 1;
		}

		if (i == candidate.size() - 1) {
			if (count > maxvote) {
				maxvote = count;
				maxname.clear();
				maxname.push_back(candidate[i]);
			}
			else if (count == maxvote) {
				maxname.push_back(candidate[i]);
			}
		}
	}

	for (int i = 0; i < maxname.size(); i++)
		cout << maxname[i].name << endl;

	return 0;
}