#include<iostream>
using namespace std;

int main()
{
	int i = 1;
	int j = -i++;
	int i1 = 1;
	int k= i1++ + ++i1;
	cout << j << " " << i << endl;
	cout <<k << " " <<i1 << endl;
	//cout << i;
	return 0;
}