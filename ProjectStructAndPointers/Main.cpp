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

int menuCoice();
void populate(Student *[]);
void display(Student *[]);
void swap(Student *[], Student *[]);
void sortName(Student *[]);
void sortID(Student *[]);
void sortGrade(Student *[]);
void sortBirthday(Student *[]);
void sortHTown(Student *[]);

int main() {
	Student *s1[10];
	populate(s1);
	cout << s1[2]->name << endl;
	cout << s1[2]->SID << endl;
	cout << s1[2]->bDay.toString() << endl;
	cout << s1[2]->grade << endl;
	cout << s1[2]->homeTown << endl;
	return 0;
};

//populate the array with students
void populate(Student *s[]) {
	string names[10] = {"Steve", "Jeremy", "Calvin", "Mark", "Michael", "Josie", "Linda", "Maddison", "Tyler", "Wendy"};
	char grades[5] = { 'A','B','C','D','F' };
	string cities[10] = {"Downey", "Long Beach", "Compton", "Carson", "Dalas", "Bronx", "Queens", "Brooklyn", "Harlem", "Detroit"};
	for (int i = 0; i < 10; i++) {
		s[i] = new Student;
		strcpy_s(s[i]->name, names[i].c_str());
		s[i]->SID = rand() % 9000 + 1000;
		int randGrade = rand() % 5;
		s[i]->grade = grades[randGrade];
		int randDay = rand() % 31 + 1;
		int randMonth = rand() % 13;
		int randYear = rand() % 6 + 1999;
		s[i]->bDay = myDate(randMonth, randDay, randYear);
		int randCity = rand() % 10;
		s[i]->homeTown = cities[randCity];
	}
}