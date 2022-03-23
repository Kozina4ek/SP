#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

int main()
{
	int a[7] = { 2, 4, 5, -3, 7, 9, 11 }, sum = 0, A = 4, B = 9;
	for (int i = 0; i < 7; i++)
	{
		if ((a[i] > A) && (a[i] < B) && (a[i] > 0))
                        if (((sum > 0) && (a[i] > (INT_MAX - sum)) ||
						((sum < 0) && (a[i] < (INT_MIN - sum)))))
						cout << ("\n Perepolnenie!"); 
			else sum = sum + a[i];
	}
	cout << sum << endl;
	return 0;
}