// limits.cpp -- some integer limits

#include <iostream>
#include <climits>

int main()
{
	using namespace std;

	cout << "Maximums: \n";
	cout << "	int: " << INT_MAX << endl;
	cout << "	short: " << SHRT_MAX << endl;
	cout << "	unsigned short: " << USHRT_MAX << endl;
	cout << "	long: " << LONG_MAX << endl;
	cout << "	unsigned long: " << ULONG_MAX << endl;
	cout << "	long long: " << LLONG_MAX << endl;
	
	cout << endl;

	cout << "Minimums: \n";
	cout << "	int: " << INT_MIN << endl;
	cout << "	short: " << SHRT_MIN << endl;
	cout << "	long: " << LONG_MIN << endl;
	cout << "	long long: " << LLONG_MIN << endl;

	cout << endl;

	cout << "Bits per byte: " << CHAR_BIT << endl;
}