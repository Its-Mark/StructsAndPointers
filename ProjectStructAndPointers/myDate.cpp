//Mark Garcia
//Class (CECS 282-07)
//Prog 3 Structs and Pointers
//Due: March 25, 2020

#include "myDate.h"
#include <iostream>
using namespace std;

//converts Gregorian date to Julian
int Greg2Julian(int m, int d, int y) {
	int i = y;
	int j = m;
	int k = d;
	int jd = k - 32075 + 1461 * (i + 4800 + (j - 14) / 12) / 4 + 367 * (j - 2 - (j - 14) / 12 * 12) / 12 - 3 * ((i + 4900 + (j - 14) / 12) / 100) / 4;
	return jd;
}

//converts Julian date to Gregorian
void Julian2Greg(int jd, int& month, int& day, int& year) {
	int i, j, k;
	int l = jd + 68569;
	int n = 4 * l / 146097;
	l = l - (146097 * n + 3) / 4;
	i = 4000 * (l + 1) / 1461001;
	l = l - 1461 * i / 4 + 31;
	j = 80 * l / 2447;
	k = l - 2447 * j / 80;
	l = j / 11;
	j = j + 2 - 12 * l;
	i = 100 * (n - 49) + i + l;

	day = k;
	month = j;
	year = i;
}

//default constructor: initialize date to May 11, 1959 by default
myDate::myDate() {
	month = 5;
	day = 11;
	year = 1959;
}

//overloaded constructor: Checks for valid date entry (leap years / months with 30/31 days)
//if the params are 'invalid' then they are set to the default date.
myDate::myDate(int M, int D, int Y) {
	if ((M <= 12) && (D <= 31) && (Y >= 0)) {
		if (M != 2) {
			if ((M == 4 || M == 6 || M == 9 || M == 11) && (D <= 30)) {
				month = M;
				day = D;
				year = Y;
			}
			else {
				month = M;
				day = D;
				year = Y;
			}
		}
		else {
			if ((Y % 4 == 0) || (Y && 400 == 0) && (D <= 29)) {
				month = M;
				day = D;
				year = Y;
			}
			else if (D <= 28) {
				month = M;
				day = D;
				year = Y;
			}
			else {
				month = 5;
				day = 11;
				year = 1959;
			}
		}
	}
	else {
		month = 5;
		day = 11;
		year = 1959;
	}
}

//prints the date i.e May 11, 1959
void myDate::display() {
	cout << toString();
}

//Increases date N days.
void myDate::increaseDate(int N) {
	int jd = Greg2Julian(month, day, year);
	jd += N;
	Julian2Greg(jd, month, day, year);
}

//decreases date by N days
void myDate::decreaseDate(int N) {
	int jd = Greg2Julian(month, day, year);
	jd -= N;
	Julian2Greg(jd, month, day, year);
}

//returns the number of days between current date and myDate D
int myDate::daysBetween(myDate D) {
	int dbtwn;
	int jd1 = Greg2Julian(month, day, year);
	int jd2 = Greg2Julian(D.month, D.day, D.year);
	if (jd1 > jd2) {
		dbtwn = jd1 - jd2;
	}
	else {
		dbtwn = jd2 - jd1;
	}
	return dbtwn;
}

int myDate::getMonth() {
	return month;
}

int myDate::getDay() {
	return day;
}

int myDate::getYear() {
	return year;
}

int myDate::dayOfYear() {
	int day1 = Greg2Julian(1, 1, year);
	int jd = Greg2Julian(month, day, year);

	return jd - day1 + 1;
}

std::string myDate::dayName() {
	std::string d = "";
	int jd = Greg2Julian(month, day, year);
	int temp = jd % 7;
	if (temp == 0) {
		d = "Monday";
	}
	else if (temp == 1) {
		d = "Tuesday";
	}
	else if (temp == 2) {
		d = "Wednesday";
	}
	else if (temp == 3) {
		d = "Thursday";
	}
	else if (temp == 4) {
		d = "Friday";
	}
	else if (temp == 5) {
		d = "Saturday";
	}
	else {
		d = "Sunday";
	}
	return d;
}

std::string myDate::toString(){
	string m = "";
	if (month == 1)
		m = "January";
	else if (month == 2)
		m = "February";
	else if (month == 3)
		m = "March";
	else if (month == 4)
		m = "April";
	else if (month == 5)
		m = "May";
	else if (month == 6)
		m = "June";
	else if (month == 7)
		m = "July";
	else if (month == 8)
		m = "August";
	else if (month == 9)
		m = "September";
	else if (month == 10)
		m = "October";
	else if (month == 11)
		m = "November";
	else if (month == 12)
		m = "December";

	return m + " " + to_string(day) + ", " + to_string(year);
}
