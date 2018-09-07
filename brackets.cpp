#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;
char str[10001];

// (  :  -1      =>   1
// {  :  -2      =>   2
// [  :  -3      =>   3

int solution(int end) {
	stack<int> st;
	for (int i = 0; i <= end; i++) {
		if (str[i] == '[' || str[i] == '{' || str[i] == '(') {
			if(str[i] == '(')
				st.push(-1);
			else if (str[i] == '{')
				st.push(-2);
			else if (str[i] == '[')
				st.push(-3);
		}
		else { 
			long long sum = 0;
			if (str[i] == ')') {
				if (st.top() == -1) {
					st.pop();
					st.push(1);
				}
				else {
					while (st.top() != -1) {
						sum += st.top();
						st.pop();
					}
					st.pop();
					st.push(sum % 100000000);
				}
			}
			else if (str[i] == '}') {
				if (st.top() == -2) {
					st.pop();
					st.push(2);
				}
				else {
					while (st.top() != -2) {
						sum += st.top();
						st.pop();
					}
					st.pop();
					st.push((sum * 2) % 100000000);
				}
			}
			else if (str[i] == ']') {
				if (st.top() == -3) {
					st.pop();
					st.push(3);
				}
				else {
					while (st.top() != -3) {
						sum += st.top();
						st.pop();
					}
					st.pop();
					st.push((sum * 3) % 100000000);
				}
			}
		}
	}

	int sum = 0;
	while (!st.empty()) {
		sum += st.top();
		sum %= 100000000;
		st.pop();
	}

	return sum;
}

bool check(int end) {
	stack<char> st;
	for (int i = 0; i <= end; i++) {
		if (str[i] == '[' || str[i] == '{' || str[i] == '(')
			st.push(str[i]);
		else {
			if (st.empty()) {
				return false;
			}
			else if (str[i] == ']' && st.top() == '[')
				st.pop();
			else if (str[i] == '}' && st.top() == '{')
				st.pop();
			else if (str[i] == ')' && st.top() == '(')
				st.pop();
			else {
				return false;
			}
		}
	}

	if (st.empty())
		return true;
	else if (!st.empty())
		return false;
}

int main() {
	int T;

	scanf("%d\n", &T);

	vector<int> result;
	while (T--) {
		cin.getline(str, 10000);
		if (check(strlen(str) - 1)) {
			result.push_back(solution(strlen(str) - 1));
		}
		else 
			result.push_back(0);
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
	return 0;
}