#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d = 0;
	int sma, big;
	cin >> a >> b >> c >> d;
	if (a < b)
	{
		sma = a;
		big = b;
	}
	else
	{
		sma = b;
		big = a;
	}

	if (sma < c && c < big && sma < d && d < big)
	{
		cout << "not cross" << endl;
	}
	else
	{
		if (sma<c&&c<big||sma<d&&d<big)
		{
			cout << "cross" << endl;
		}
		else
		{
			cout << "not cross" << endl;
		}
	}
}