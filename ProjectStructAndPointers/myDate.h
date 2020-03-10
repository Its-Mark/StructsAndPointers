//Mark Garcia
//Class (CECS 282-07)
//Prog 3 Structs and Pointers
//Due: March 16, 2020

#include <string>
#ifndef MYDATE_H
#define MYDATE_H
int Greg2Julian(int m, int d, int y);
void Julian2Greg(int jd, int& month, int& day, int& year);

class myDate {
private:
	int month;
	int day;
	int year;

public:
	myDate();
	myDate(int M, int D, int Y);
	void display();
	void increaseDate(int N);
	void decreaseDate(int N);
	int daysBetween(myDate D);
	int getMonth();
	int getDay();
	int getYear();
	int dayOfYear();
	std::string dayName();
	std::string toString();

};
#endif

