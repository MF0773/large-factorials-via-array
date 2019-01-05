#include <iostream>
#include <cmath>

using namespace std;

void makeDigitArray(int number);
void factorial(unsigned int number);
int getDigitNum(unsigned int number);
void printResult();

unsigned int *digits; //digit array
unsigned int digitNum=0;

int main() {
	
	unsigned int number;
	
	cin>> number;
	makeDigitArray(number);
	
	factorial(number);
	printResult();
	return 0;
}


void makeDigitArray(int number){
	digitNum = getDigitNum(number);
	digits = new unsigned int[digitNum];
	
	digits[0]=1 ;
	for(int i = 1 ; i < digitNum ; i++ )
		digits[i] = 0;
}

int getDigitNum(unsigned int number){
	float logSum=0;
	for (int i=number; i > 0 ; i--){
		logSum += log10(i);
	}
	return (int)logSum+1;
}

void factorial(unsigned int number){
	unsigned int endFigure=0,odd=0;
	
	for ( int i = number; i > 0 ; i--){
		
		for ( int j = 0 ; j <= endFigure ; j++){
			digits[j] *= i;
			digits[j] +=odd;
			
			odd = digits[j]/10;
			digits[j] %= 10;
		}
		while (odd != 0){
			endFigure++;
			digits[endFigure] += odd%10;
			odd /= 10;
		}
	}
}

void printResult(){
	for ( int i=digitNum-1; i >= 0 ; i--){
		cout << digits[i];
	}
}

