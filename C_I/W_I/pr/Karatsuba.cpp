
// Author: Babak Poursartip
// Assignment I

#include <string>
#include <iostream>
#include <cmath>

/*
int NumDigits(int num)
{
digits = 1;

if (num < 0) num = -num;

while (num > 10)
{
digits += 1;
num = num /10;
};

return digits;
};
*/

long long Karatasuba(long long num1, long long num2)
{

std::cout << " in the Karatasuba function ..." << std::endl;

if (num1 < 10 && num2 <10) return {num1*num2};
else
{
//digits1 = NumDigits(num1);
//digits2 = NumDigits(num2);

int digits1 = (std::to_string(num1)).length();
int digits2 = (std::to_string(num2)).length();

std::cout<< " first number has " << digits1 << " digits." << std::endl;
std::cout<< " second number has " << digits2 << " digits." << std::endl;

long long splitPosition = ((digits1<digits2) ? digits2:digits1) /2;

long long high1 = (long long)(num1/pow(10.0,splitPosition));
long long low1  = num1-high1*pow(10.0,splitPosition);

std::cout << " split of the first number: " << high1 << " and " << low1 << std::endl;

long long high2 = (long long)(num2/pow(10.0,splitPosition));
long long low2  = num2-high2*pow(10.0,splitPosition);

std::cout << " split of the second number: " << high2 << " and " << low2 << std::endl;

long long z0 = Karatasuba(low1, low2);
std::cout << " call 0: z0 =" << z0 << std::endl;

long long z1 = Karatasuba((low1 + high1), (low2 + high2));
std::cout << " call 1: z1 =" << z1 << std::endl;

long long z2 = Karatasuba(high1, high2);
std::cout << " call 2: z2 =" << z2 << std::endl;

std::cout << " The final result is  =" << z2*(pow(10.0,2*splitPosition)) +  (z1-z2-z0)*(pow(10.0,splitPosition)) +z0 << std::endl<< std::endl;


return z2*(pow(10.0,2*splitPosition)) +  (z1-z2-z0)*(pow(10.0,splitPosition)) +z0;
}
}

// the main code
int main()
{

std::cout << std::endl <<" This is the Karatasuba algorithm."  << std::endl;

// Integer mulitiplication
//long long number_1 = 1235;
//long long number_2 = 987;

//long long number_1 = 9;
//long long number_2 = 9;

long long number_1 = 3141592653589793238462643383279502884197169399375105820974944592;
long long number_2 = 2718281828459045235360287471352662497757247093699959574966967627;

long long results = Karatasuba(number_1, number_2);

std::cout << number_1 << "*" << number_2<< "="<< results << std::endl;
std::cout<< std::endl  << " End of the code." << std::endl << std::endl;

return 0;
}

