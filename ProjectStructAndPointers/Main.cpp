//Mark Garcia
//Class (CECS 282-07)
//Prog 3 Structs and Pointers
//Due: March 25, 2020

#include "myDate.h"
#include <iostream>
#include <iomanip>
using namespace std;


struct Student {
	char name[20];
	int SID;
	myDate bDay;
	char grade;
	string homeTown;
};

void populate(Student *[]);
void display(Student *[]);
void swap(Student *[], Student *[]);
void sortName(Student *[]);
void sortSID(Student *[]);
void sortGrade(Student *[]);
void sortBirthday(Student *[]);
void sortHTown(Student *[]);

int main() {
	Student *s1[10];
	populate(s1);
	int choice = 0;
	while (choice != 6) {
		//display menu
		cout << "1) Display list sorted by Name" << endl;
		cout << "2) Display list sorted by Student ID" << endl;
		cout << "3) Display list sorted by Grade" << endl;
		cout << "4) Display list sorted by Birthday" << endl;
		cout << "5) Display list sorted by Home Town" << endl;
		cout << "6) Exit" << endl;
		//takes input
		cin >> choice;
		if (choice == 1) {
			cout << "Sorted by Name..." << endl;
			sortName(s1);
			display(s1);
		}
		else if (choice == 2) {
			cout << "Sorted by Student ID..." << endl;
			sortSID(s1);
			display(s1);
		}
		else if (choice == 3) {
			cout << "Sorted by Grade..." << endl;
			sortGrade(s1);
			display(s1);
		}
		else if (choice == 4) {
			cout << "Sorted by Birthday..." << endl;
			sortBirthday(s1);
			display(s1);
		}
		else if (choice == 5) {
			cout << "Sorted by Home Town..." << endl;
			sortHTown(s1);
			display(s1);
		}

	}

	return 0;
};

//populate the array with students
void populate(Student *s[]) {
	string names[] = {"Steve", "Jeremy", "Calvin", "Mark", "Michael", "Josie", "Linda", "Maddison", "Tyler", "Wendy"};
	//there are multiple A B C just because for some reason a lot of the students were only given D's and F's
	//doesn't change functionality, just wanted there to be more A's B's and C's
	char grades[] = { 'A','A','A','B','B','C','C','D','F',};
	string cities[] = {"Downey", "Long Beach", "Compton", "Carson", "Dalas", "Bronx", "Queens", "Brooklyn", "Harlem", "Detroit"};
	for (int i = 0; i < 10; i++) {
		s[i] = new Student;
		strcpy_s(s[i]->name, names[i].c_str());
		s[i]->SID = rand() % 9000 + 1000;
		int randGrade = rand() % 9;
		s[i]->grade = grades[randGrade];
		int randDay = rand() % 31 + 1;
		int randMonth = rand() % 13;
		int randYear = rand() % 6 + 1999;
		s[i]->bDay = myDate(randMonth, randDay, randYear);
		int randCity = rand() % 10;
		s[i]->homeTown = cities[randCity];
	}
}

//swaping two students
void swap(Student **x, Student **y) {
	Student *temp;
	temp = *y;
	*y = *x;
	*x = temp;
}

//sort array by name
void sortName(Student *s[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			int comparison = strcmp(s[j]->name, s[j + 1]->name);
			if (comparison > 0) {
				swap(s[j], s[j + 1]);
			}
		}
	}
}

//sort array by SID
void sortSID(Student *s[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (s[j]->SID > s[j+1]->SID) {
				swap(s[j], s[j + 1]);
			}
		}
	}
}

//sort array by Grade
void sortGrade(Student *s[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if (s[j]->grade > s[j+1]->grade) {
				swap(s[j], s[j + 1]);
			}
		}
	}
}

//sort array by birthday
void sortBirthday(Student *s[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			int m1, d1, y1, m2, d2, y2, jd1, jd2;
			m1 = s[j]->bDay.getMonth();
			d1 = s[j]->bDay.getDay();
			y1 = s[j]->bDay.getYear();
			m2 = s[j + 1]->bDay.getMonth();
			d2 = s[j + 1]->bDay.getDay();
			y2 = s[j + 1]->bDay.getYear();
			jd1 = Greg2Julian(m1, d1, y1);
			jd2 = Greg2Julian(m2, d2, y2);
			if (jd1 > jd2) {
				swap(s[j], s[j + 1]);
			}
		}
	}
}

//sort by hometown
void sortHTown(Student *s[]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9 - i; j++) {
			if ((s[j]->homeTown).compare(s[j + 1]->homeTown) > 0) {
				swap(s[j], s[j + 1]);
			}
		}
	}
}

//display the list in columns. All columns should be left-justified
//for this one use left keyword and setw(int n)
void display(Student* s[]) {
	cout << setw(10) << left << "Name:" << setw(15) << left << "Student ID:" << setw(15) << left << "Grade:" << setw(20) << left << "Birthday:" << setw(20) << left << "Home Town:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << setw(10) << left << s[i]->name << setw(15) << left << s[i]->SID << setw(15) << left << s[i]->grade << setw(20) << left << s[i]->bDay.toString() << setw(21) << left << s[i]->homeTown << endl;
	}
	
}