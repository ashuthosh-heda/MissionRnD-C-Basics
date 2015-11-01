/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int atoi1(char* a){
	int n = 0;
	for (int i = 0; a[i] != '\0'; i++) {
		n = (n * 10) + a[i] - '0';
	}
	return n;
}

int validDate1(int d, int m, int y){
	int leap = 0;
	if (d <= 0 || m <= 0 || y <= 0) //Date should not be negative or zero
		return -1;
	if (d >= 32 || m >= 13) //Day should not exceed 31 and month 12
		return -1;
	//To find out the given year is leap year or not
	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)){
		leap = 1;
	}
	//To check the days in month
	if (m < 13 && m > 0){
		if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
			if (d > 31)
				return -1;
		}
		else if (m == 4 || m == 6 || m == 9 || m == 11){
			if (d > 30)
				return -1;
		}
		else{
			if (leap == 1)
			if (d > 29)
				return -1;
			if (leap == 0)
			if (d > 28)
				return -1;
		}
	}
	return 0;
}


int isOlder(char *dob1, char *dob2) {
	if (dob1[2] != '-' || dob1[5] != '-' || dob2[2] != '-' || dob2[5] != '-'){
		return -1;
	}

	char d[3], m[3], y[5];
	d[2] = m[2] = y[4] = '\0';
	int d1, d2;
	int m1, m2;
	int y1, y2;

	d[0] = dob1[0];
	d[1] = dob1[1];
	d1 = atoi1(d);

	d[0] = dob2[0];
	d[1] = dob2[1];
	d2 = atoi1(d);

	m[0] = dob1[3];
	m[1] = dob1[4];
	m1 = atoi1(m);

	m[0] = dob2[3];
	m[1] = dob2[4];
	m2 = atoi1(m);

	y[0] = dob1[6];
	y[1] = dob1[7];
	y[2] = dob1[8];
	y[3] = dob1[9];
	y1 = atoi1(y);
 	
	y[0] = dob2[6];
	y[1] = dob2[7];
	y[2] = dob2[8];
	y[3] = dob2[9];
	y2 = atoi1(y);

	if (validDate1(d1, m1, y1) == -1 || validDate1(d2, m2, y2) == -1){
		return -1;
	}

	if (d1 == d2 && m1 == m2 && y1 == y2){
		return 0;
	}

	if (y1 > y2){
		return 2;
	}
	else if (y2 > y1){
		return 1;
	}
	else{
		if (m1 > m2){
			return 2;
		}
		else if (m2 > m1){
			return 1;
		}
		else{
			if (d1 > d2){
				return 2;
			}
			else
				return 1;
		}
	}
}
