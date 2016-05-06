#include <iostream>
#include <vector>
#include<string>

using namespace std;

vector<string> sch = {
	"oooxxxxxxxxxxxxx",
	"xxxoxxxoxoxoxxxx", 
	"xxxxoxxxxxoxxxoo", 
	"oxxxooooxxxxxxxx", 
	"xxxxxxoooxoxoxxx", 
	"oxoxxxxxxxxxxxoo", 
	"xxxoxxxxxxxxxxoo", 
	"xxxxooxoxxxxxxoo", 
	"xoooooxxxxxxxxxx", 
	"xxxoooxxxoxxxoxx"
};

void check(vector<int> &Clock, int Num_Sch, int &min, int n);
bool push(vector<int> &Clock, int Switch);

int main() {

	int testcase;
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	cin >> testcase;

	for (int t = 0; t < testcase; t++) {
		int min = 987654321;
		vector<int> clock;
		int a;

		for (int i = 0; i < 16; i++) {
			cin >> a;
			a = a % 12;
			clock.push_back(a);
		}
		check(clock, 0, min, 0);
		if (min < 123456789)
			cout << min << endl;
		else
			cout << "-1" << endl;
	}

	return 0;
}

void check(vector<int> &Clock, int Num_Sch, int &min, int n) {
	if (Num_Sch == 10)
		return;
	check(Clock, Num_Sch + 1, min, n);

	n++;
	if (push(Clock, Num_Sch)) {
		if (min > n)
			min = n;
	}
	check(Clock, Num_Sch + 1, min, n);

	n++;
	if (push(Clock, Num_Sch)) {
		if (min > n)
			min = n;
	}
	check(Clock, Num_Sch + 1, min, n);

	n++;
	if (push(Clock, Num_Sch)) {
		if (min > n)
			min = n;
	}
	check(Clock, Num_Sch + 1, min, n);

	push(Clock, Num_Sch);
}

bool push(vector<int> &Clock, int Switch) {
	bool Check = true;
	for (int i = 0; i < 16; i++) {
		if (sch[Switch][i] == 'o') {
				Clock[i] = (Clock[i] + 3) % 12;
		}
	}


	for (int i = 0; i < 16; i++) {
		if (Clock[i] != 0) {
			Check = false;
			break;
		}
	}
	return Check;
}