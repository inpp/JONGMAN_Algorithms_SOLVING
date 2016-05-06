#include <iostream>
#include <string.h>


using namespace std;



bool isfriend[10][10];
bool check[10];
int pairing(bool *check, int n){
	int rtn = 0;
	int small = -1;

	for (int i = 0; i < n; i++)
	if (!check[i])
	{
		small = i;
		break;
	}

	if (small == -1) return 1;

	check[small] = true;
	for (int i = small + 1; i < n; i++){
		if (isfriend[small][i] == true && check[i]==false){
			check[i] = true;
			rtn += pairing(check, n);
			check[i] = false;
		}
	}
	check[small] = false;
	return rtn;
}

int main(){
	
	int testcase;
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	cin >> testcase;

	for (int t = 0; t < testcase; t++){
		int num_stu;
		int num_pair;
		for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			isfriend[i][j] = false;
		memset(check, 0, sizeof(bool));
		cin >> num_stu >> num_pair;

		for (int i = 0; i < num_pair; i++){
			int a, b;
			cin >> a >> b;
			isfriend[a][b] = isfriend[b][a] = true;
		}
		cout << pairing(check, num_stu) << "\n";
	}

	return 0;
}