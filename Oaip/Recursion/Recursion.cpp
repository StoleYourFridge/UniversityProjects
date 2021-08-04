#include <iostream>
#include <cmath>
using namespace std;


double recursion(int n, int counter)
{
	if (counter == n) return sqrt(n);
	else return sqrt(counter + recursion(n, counter + 1));
}

double notrecursion(int n)
{  
	double y = 0;
    double q = 0;
	for (int i = n; i >= 1; i--)
	{
		y = sqrt(i + q);
			q = y;
	}
	return y;
}

int main()
{
	int n;
	do {
		cout << " Enter n : ";
		cin >> n;
	}
	while (n <= 0);

	cout << " Without recursion : " << notrecursion(n) << endl;
	cout << " With recursion    : " << recursion(n, 1);

}

