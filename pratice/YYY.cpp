#include <iostream>

using namespace std;

int cmp(const void *p, const void *q);

void main(){
	/*
	char a[20];


	cin.getline(a, strlen(a));
	cout << a << endl;

	cin >> a;
	cout << a << endl;

	cin >> a;
	cout << a << endl;
	*/

	int a[30] = { 7, 8, 9, 4, 5, 6, 3, 2, 1, 11, 13 };

	qsort(a, 13, sizeof(int), cmp);

	for (int i = 0; i < 13;i++)
		cout << a[i];
}

int cmp(const void *p, const void *q){
	int x = *(const int *)p;
	int y = *(const int *)q;

	if (x > y)
		return 1;
	else
		return -1;

	return 0;
}
