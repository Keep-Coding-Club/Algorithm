#include <bits/stdc++.h>
using namespace std;

int main() {
	stack<int> s;
	vector <pair<int, int>> line;
	vector <int> raser;

	string inputStr;
	cin >> inputStr;

	//stack을 사용해서 레이저의 위치와 막대기의 위치를 vector에 저장
	for (int i = 0; i < inputStr.length(); i++) {
		if (inputStr[i] == '(')
			s.push(i);
		else {
			if (s.top() == i - 1) {
				raser.push_back(s.top());
				s.pop();
			}
			else {
				line.push_back({ s.top(), i });
				s.pop();
			}
		}
	}

	int totalCnt = line.size();

	//막대기 vector를 조회하면서
	//해당 막대기 길이 안에 몇개의 레이저가 포함되는지 count
	for(int i=0; i<line.size(); i++) {
		int start = line[i].first;
		int end = line[i].second;
		
		for (int j = 0; j < raser.size(); j++) {
			if (start <= raser[j] && end > raser[j])
				totalCnt++;
			else if (end <= raser[j])
				break;
		}


	}

	cout << totalCnt;
}