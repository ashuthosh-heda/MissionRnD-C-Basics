/*
OVERVIEW:  Given 2 integers (num1, num2), write a function that returns the count of numbers between the num1..num2 that are divisible by num1.
		E.g.: count(3, 15) returns 5 (3, 6, 9, 12, 15).

INPUTS:  Two numbers num1, num2.
		num1, num2 >= 0.

OUTPUT: Return the count of numbers between the num1..num2 that are divisible by num1.

ERROR CASES: Return -1 in error cases.

NOTES:
*/
int count(int num1, int num2) {
	if (num1 > num2 || num1 == num2){
		return 0;
	}
	
	if (num2 < 0 || num1 <= 0){
		return -1;
	}

	int temp = num1;
	int counter = 0;

	while (temp <= num2){
		temp += num1;
		if (temp % num1 == 0){
			counter++;
		}
	}
	return counter;
}