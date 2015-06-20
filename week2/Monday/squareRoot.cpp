#include <iostream>
#include <iomanip>

using namespace std;

double PRECISION_DIGITS = 5;

double truncateNumber(double number, unsigned int digits)
{
	double f = pow(10, digits);
	return ((int)(number*f))/f;
}

double findRoot(int number)
{
	double precision = 0.00001;
	double mid = double(number) / 2.0;
	double prev = 0.0;

	while(abs(mid - prev) > precision)
	{
		if(mid*mid == double(number)) return mid;
		if(mid*mid > number)
		{
			prev = mid;
			mid = (mid + (double(number) / mid)) / 2.0;
		}
	}
	return truncateNumber(mid, PRECISION_DIGITS);
}

int main()
{
	cout << findRoot(5) << endl;
	
	return 0;
}