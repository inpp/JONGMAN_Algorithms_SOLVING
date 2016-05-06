#include <iostream>
#include <string>
#include <vector>


using namespace std;

string arr[5];

int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };

bool hasword(int x, int y, const string& word){
	if (x < 0 || y < 0 || x > 4 || y > 4)
		return false;
	if (arr[x][y] != word[0])
		return false;
	if (word.size() == 1)
		return true;

	for (int i = 0; i < 8; i++){
		if (hasword(x+dx[i], y+dy[i], word.substr(1)))
			return true;
	}
	return false;
}

int main(){

	int testcase;

	cin >> testcase;

	for (int t = 0; t < testcase; t++){
		for (int i = 0; i < 5; i++)
			cin >> arr[i];
		int num_word;

		cin >> num_word;
		
		if (num_word == 0)
			continue;

		vector<string> word;

		for (int i = 0; i < num_word; i++){
			string ar;
			cin >> ar;
			word.push_back(ar);
		}
		
		for (int i = 0; i < num_word; i++){
			bool check = 0;
			for (int j = 0; j < 5; j++){
				for (int k = 0; k < 5; k++){
					check = hasword(j, k, word[i]);
					if (check)
						break;
				}
				if (check)
					break;
			}
			cout << word[i] << " ";
			if (check)
				cout << "YES";
			else
				cout << "NO";
			cout << endl;
		}
	}

	return 0;
}