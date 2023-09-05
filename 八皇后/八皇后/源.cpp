#include<iostream>
#include<cmath>
#include<ctime>
using namespace std;
#define M 200

int check(int * lie,int t = 0) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M ; j++) {
			if (i != j) {
				if ((lie[i] == lie[j]) || (abs(lie[i] - lie[j]) == abs(i - j))) {
					t++;
				}
			}
		}
	}
	return t;
}

bool check1(int* lie, bool t = 1) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < i; j++) {
			if ((lie[i] == lie[j]) || (abs(lie[i] - lie[j]) == abs(i - j))) {
				t = 0;
				return t;
			}
		}
	}
	return t;
}

int main() {
	srand(time(0));
	int m = 1;
	int lie[M];
	for (int i = 0; i <= M - 1; i++) lie[i] = i ;
	int n = 0,j=0,t=0;
	while (check(lie, t)) {
		int tt = check(lie, t);
		int x = (M - 1) * rand() / RAND_MAX;
		int y = (M - 1) * rand() / RAND_MAX;
		int z1= lie[x];
		int z2 = lie[y];
		lie[x] = z2 ;
		lie[y] = z1 ;
		if (check(lie, t)> tt) {
			lie[x] = z1;
			lie[y] = z2;
		}
	}
				
	for (int i = 0; i <= M - 1; i++)cout << lie[i] << " ";
	cout << endl;

	bool l=1;
	cout << check1(lie, l) << endl;

	return 0;
}