#include <iostream>
#include <string>

using namespace std;

int arr[20][20];
int H, W;

int dx[4][3] = { { 0, 1, 1 },
{ 0, 0, 1 },
{ 0, 0, -1 }, 
{ 0, 0, 1 } };

int dy[4][3] = { { 0, 0, 1 },
{ 0, 1, 1 },
{ 0, 1, 1 },
{ 0, 1, 0 } };

int cover(int arr[20][20]){
	int sum = 0;
	int x = -1;
	int y = -1;

	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			if (arr[i][j] == 0)
			{
				x = j;
				y = i;
				break;
			}
		}
		if (x != -1)
			break;
	}

	if (x == -1)
		return 1;

	for (int d = 0; d < 4; d++){
		bool check = true;
		for (int i = 0; i < 3; i++){
			if ((y + dy[d][i]) < 0 || (x + dx[d][i]) < 0 || (y + dy[d][i]) >= H || (x + dx[d][i]) >= W){
				check = false;
				break;
			}
		}
		if (check&&arr[y + dy[d][0]][x + dx[d][0]] + arr[y + dy[d][1]][x + dx[d][1]] + arr[y + dy[d][2]][x + dx[d][2]] == 0){
			arr[y + dy[d][0]][x + dx[d][0]] = arr[y + dy[d][1]][x + dx[d][1]] = arr[y + dy[d][2]][x + dx[d][2]] = 1;
			sum += cover(arr);
			arr[y + dy[d][0]][x + dx[d][0]] = arr[y + dy[d][1]][x + dx[d][1]] = arr[y + dy[d][2]][x + dx[d][2]] = 0;
		}
	}
	return sum;
}


int main(){

	int testcase;
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	cin >> testcase;

	for (int t = 0; t < testcase; t++){
		cin >> H >> W;
		string k;
		getline(cin, k);
		int sum = 0;
		for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			arr[i][j] = 0;

		int FirstWhiteX = -1;
		int FirstWhiteY = -1;

		for (int i = 0; i < H; i++){
			string tmp;
			getline(cin, tmp);
			for (int j = 0; j < W; j++){
				if (tmp[j] == '#')
					arr[i][j] = 1;
				else
				{
					sum += 1;
				}
			}
		}

		if (sum == 0){
			cout << "1\n";
			continue;
		}
		if (sum % 3 != 0){
			cout << "0\n";
			continue;
		}
		
		cout << cover(arr) << "\n";
	}
	return 0;
}