//Lab03.cpp
//Sam Goering
#include <iostream>
using namespace std;

void sum_Short(short val);
void sum_Long(long val);
void factorial_Long(long val);
void sum_Recip(long val);
int main()
{
	short a(254), b(255), c(256);
	sum_Short(a);
	sum_Short(b);
	sum_Short(c);

	long a_L(65534), b_L(65535), c_L(65536);
	sum_Long(a_L);
	sum_Long(b_L);
	sum_Long(c_L);

	long a2_L(33), b2_L(34), c2_L(35);
	factorial_Long(a2_L);
	factorial_Long(b2_L);
	factorial_Long(c2_L);

	sum_Recip(64);

	for (double i = 3.4; i < 4.4; i +=0.2) {
		cout << "i = " << i << endl;
	}
	return 0;
}

//At the value of 256 there is an overflow error resulting in 
//a negative value. A possible check is to look at the the value 
//of n and if n>255 stop the summation at n = 255
void sum_Short(short val) {
	short sum = 0;
	if (val > 255) {
		cout << "Value to large" << endl;
		val = 0;
	}
	for (short i = val; i > 0; i--) {
		sum += i;
	}
	cout << "The sum of shorts from 0 to " << val << " is:" << sum << endl;
}
//At the value 2^16 = 65536 there is an overflow error resulting in '
//a negative max value. Check the value of n if it is bigger than 2^16 only sum
// up to 2^16.
void sum_Long(long val) {
	if (val > 65535) {
		cout << "Value to large" << endl;
		val = 0;
	}
	long sum = 0;
	for (long i = val; i > 0; i--) {
		sum += i;
	}
	cout << "The sum of longs from 0 to " << val << " is:" << sum << endl;
}

//At the value of 35 there is an overflow error which returns infity
//as the answer to n!. 
void factorial_Long(long val) {
	if (val > 35) {
		cout << "Value to large" << endl;
		val = 0;
	}
	float fact_L = 1;
	for (long i = val; i > 0; i--) {
		fact_L *= i;
	}
	cout << "The factorial of " << val << " is: " << fact_L << endl;

	double fact_D = 1;
	for (long i = val; i > 0; i--) {
		fact_D *= i;
	}
	cout << "The factorial of " << val << " when stored as a double is: " << fact_D << endl;
}

void sum_Recip(long val) {
	long recip(0), sum(0);
	for (long i = val; i > 0; i--) {
		recip = 1 / i;
		sum += recip;
	}
	cout << "The the sum of 0 to 1/" << val << " is: " << sum << endl;
	sum -= 1.0;
	cout << "The sum - 1.0 is " << sum << endl;
}

