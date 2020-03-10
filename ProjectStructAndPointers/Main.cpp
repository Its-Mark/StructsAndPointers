//Mark Garcia
//Class (CECS 282-07)
//Prog 3 Structs and Pointers
//Due: March 16, 2020

#include "myDate.h"
#include <iostream>
using namespace std;


struct Student {
	char name[20];
	int SID;
	myDate bDay;
	char grade;
	string homeTown;
};

int main() {
	Student *s1[10];
	populate(s1);
	cout << s1;
	return 0;
};

void populate(Student *s[]) {
	char grades[] = { 'A','B','C','D','F' };
	string cities[] = {"Downey", "Longbeach", "Compton", "Carson", "San Fransisco", "San Antonio", "Dalas", "Bronx", "Queens", "Brooklyn", "Harlem", "Las Vegas", "Detroit"};
	for (int i = 0; i < 10; i++) {
		s[i] = new Student;
		s[i]->SID = rand() % 9000 + 1000;
		int randGrade = rand() % 5;
		s[i]->grade = grades[randGrade];
		int randDay = rand() % 31 + 1;
		int randMonth = rand() % 13;
		int randYear = rand() % 6 + 1999;
		s[i]->bDay = myDate(randMonth, randDay, randYear);
		int randCity = rand() % 14;
		s[i]->homeTown = cities[randCity];
	}
}