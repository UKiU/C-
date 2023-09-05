#include <iostream>
using namespace std;
#define ALEN 5
#define BLEN 10
int mmm(int*& arr, int left, int right) {
	int  mid = arr[left];
	while (left < right) {
		while (left < right && arr[right] >= mid) {
			right--;
		}
		arr[left] = arr[right];
		while (left < right && arr[left] <= mid) {
			left++;
		}
		arr[right] = arr[left];
	}
	arr[left] = mid;
	return left;
}

void Sort(int*& arr, int left, int right) {
	if (left < right) {
		int index = mmm(arr, left, right);
		Sort(arr, left, index - 1);
		Sort(arr, index + 1, right);
	}
}

int inline rand(int n)
{
	return rand() % n;
}

void Initnumber(int * &a, int n) {
	for (int i = 0; i < n; i++) {
		a[i] = rand(10*n);
	}
	Sort(a, 0, n-1);
}

void Combine(int*& arr, int*& brr, int*& crr) {
	for (int i = 0; i < ALEN; i++) {
		crr[i] = arr[i];
	}
	for (int j = ALEN; j <(ALEN+BLEN); j++) {
		crr[j] = brr[j-ALEN];
	}
	Sort(crr, 0, (ALEN+BLEN) - 1);
}
int DeleteRepetition(int*& crr,int Len) {
	int n = 0;
	for (int i = 0; i < Len-n-1; i++) {
		if (crr[i] == crr[i + 1]) {
			for (int j = i; j < Len -n- 1; j++) {
				crr[j] = crr[j + 1];
			}
			n++;
			i--;
		}
	}
	return n;
}
int main()
{
	srand(time(0));
	int * arr=new int[ALEN];
	int * brr=new int[BLEN];
	int * crr = new int[(ALEN+BLEN)];
	
	Initnumber(arr, ALEN);
	Initnumber(brr, BLEN);
	Combine(arr, brr, crr);
	int n = DeleteRepetition(crr, ALEN + BLEN);

	cout << "arr is " << endl;
	for (int i = 0; i < ALEN; i++)cout << arr[i]<<" ";
	cout << endl<< "brr is " << endl;
	for (int j = 0; j < BLEN; j++)cout << brr[j]<<" ";
	cout << endl<<"combination is " << endl;
	for (int k = 0; k < (ALEN+BLEN-n); k++)cout << crr[k] << " ";

	delete[]arr;
	delete[]brr;
	delete[]crr;
}
