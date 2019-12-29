 #include<iostream>
#include<vector>
using namespace std;

void QuickSort(int array[], int start, int end){
	int i = start, j = end;
	int temp = array[i];
	if (i < j){
		while (i < j){
			while (i < j && temp <= array[j]) j--;
			if (i < j) array[i++] = array[j];

			while (i < j && array[i] <= temp) i++;
			if (i < j) array[j--] = array[i];
		}
		//把基准数放到i位置
		array[i] = temp;
		//递归方法
		QuickSort(array, start, i - 1);
		QuickSort(array, i + 1, end);
	}
}

void BubbleSort(vector<int> &arr){
	int i, j;
	for (i = 1; i < arr.size(); i++)
		for (j = 0; j < arr.size() - i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

int main() {
	int array[] = {3, 56, 4, 2, 4, 42, 4, 1};
	//QuickSort(array, 0, 7);
	vector<int> a(array, array+8);
	cout << a.size() << endl;
	a.push_back(1);
	cout << a.size() << endl;
	a.resize(10);
	cout << a.size() << endl;
	cout << a.capacity() << endl;
	BubbleSort(a);
	for (int item : a)
		cout << item << ' ';
	cout << endl;
	for (int item : array)
		cout << item << ' '; 
	cout << endl;
	cin >> array[0];
	return 0;
}