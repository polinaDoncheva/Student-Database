/**
*
* Solution to course project # 5
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2022/2023
*
* @author Polins Doncheva
* @idnumber 9MI0600223* @compiler Visual Studio
*
* <main file>
*
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MIN_COUNT_OF_SUBJECTS = 1;
const int MAX_COUNT_OF_SUBJECTS = 10;
const int FIRST_GROUP_OF_STUDENTS = 1;
const int LAST_GROUP_OF_STUDENTS = 8;
const int MIN_GRADE = 2;
const int MAX_GRADE = 6;
const int FIRST_VALID_METHOD_CHOICE = 1;
const int SECOND_VALID_METHOD_CHOICE = 2;
const int MAX_STUDENTS_IN_GROUP = 20;
const int MAX_STUDENTS_FROM_ALL_GROUPS = 8 * MAX_STUDENTS_IN_GROUP;
const int BUFFER_SIZE = 1024;


struct Student {
	int group;
	string name;
	string facultyNumber;
	string subjects[10]{};
	double grades[10]{};
	double averageGrade;
};

string intToString(int number) {
	char numIntoChar = number + '0';
	string toString;
	toString += numIntoChar;
	return toString;
}

string findPath(int group) {
	string path = "";
	string groupToString;
	if (group > 9)
	{
		for (int i = 0; group != 0; i++)
		{
			if (i == 0)
				groupToString += intToString(group % 10);
			else
				groupToString += "," + intToString(group % 10);
			group /= 10;
		}
	}
	else
		groupToString = intToString(group);
	path = "group" + groupToString + ".txt";
	return path;
}

void validateGroup(int& group) {
	while ((group < FIRST_GROUP_OF_STUDENTS || group>LAST_GROUP_OF_STUDENTS)&& (group < FIRST_GROUP_OF_STUDENTS+'0' || group>LAST_GROUP_OF_STUDENTS+'0'))
	{
		cout << endl << "This group does not exist! Enter valid group: ";
		cin >> group;
	}
	return;
}

void validateNumberOfSubjects(int& numOfSubjects) {
	while (numOfSubjects < MIN_COUNT_OF_SUBJECTS || numOfSubjects>MAX_COUNT_OF_SUBJECTS)
	{
		cout << endl << "You can enter between 1 and 10 subjects: ";
		cin >> numOfSubjects;
	}
	return;
}

void validateGrade(double& grade) {
	while (grade < MIN_GRADE || grade>MAX_GRADE)
	{
		cout << endl << "This grade is invalid! Try again: ";
		cin >> grade;
	}
	return;
}

void validateSortingMethodAndCriteria(int& method) {
	while (method != FIRST_VALID_METHOD_CHOICE && method != SECOND_VALID_METHOD_CHOICE)
	{
		cout << endl << "Please enter one of the present options: ";
		cin >> method;
	}
	return;
}

void putStudentInFile(const Student student, fstream& myFile) {
	myFile << student.name << " " << student.facultyNumber << endl;

	for (int i = 0; student.grades[i] > 0; i++) {
		if (i == 0) {
			myFile << student.subjects[i] << '-' << student.grades[i];
			continue;
		}
		myFile << ' ' << student.subjects[i] << '-' << student.grades[i];
	}
	myFile << endl;
}

void putStudentDataIntoStruct(string line, Student& student) {
	int inputIndex = 0;
	int countOfSpaces = 0;

	for (int i = 0; countOfSpaces < 2; i++, inputIndex++) {
		if (line[inputIndex] == ' ')
			countOfSpaces++;
		if (countOfSpaces == 2)
			break;
		student.name += line[inputIndex];
	}
	inputIndex++;
	for (int i = 0; line[inputIndex] != '\0' && line[inputIndex] != ' '; i++, inputIndex++)
		student.facultyNumber += line[inputIndex];
}

void putSubjectsIntoStruct(string line, Student& student) {
	string currentSubject;
	int inputIndex = 0;
	for (int i = 0; line[inputIndex] != '\0'; i++)
	{
		currentSubject = "";
		while (line[inputIndex] != '-')
		{
			currentSubject += line[inputIndex];
			inputIndex++;
		}
		inputIndex++;
		student.subjects[i] = currentSubject;

		string gradeAsString = "";
		while (line[inputIndex] != ' ' && line[inputIndex] != '\0')
		{
			gradeAsString += line[inputIndex];
			inputIndex++;
		}
		student.grades[i] = stod(gradeAsString);

		if (line[inputIndex] == '\0')
			break;
		inputIndex++;
	}
}

//reading file with students from one group and putting them in array
void putSudentsFromFileInStruct(int group, Student* students, int& indexOfCurrentStudent) {
	string path = findPath(group);
	fstream myFile(path, ios::in | ios::app | ios::out);
	if (!myFile.is_open())
	{
		cout << "Error!" << endl;
		return;
	}
	string line;
	while (!myFile.eof())
	{
		getline(myFile, line);
		if (line == "")
			break;
		putStudentDataIntoStruct(line, students[indexOfCurrentStudent]);
		getline(myFile, line);
		putSubjectsIntoStruct(line, students[indexOfCurrentStudent]);
		indexOfCurrentStudent++;
	}
	myFile.close();
}

bool isFirstStringBigger(string first, string second) {
	for (int i = 0; first[i] != '\0'; i++)
	{
		if (first[i] > second[i])
			return true;
		else if (first[i] < second[i])
			return false;
	}
	return true;
}

//calculating average grades of students in one group
void findAverageGrades(Student* students) {
	int counter;
	double average;
	for (int i = 0; i < MAX_STUDENTS_IN_GROUP; i++)
	{
		counter = 0;
		average = 0;
		for (int j = 0; students[i].grades[j] != 0; j++)
		{
			average += students[i].grades[j];
			counter++;
		}
		average /= counter;
		students[i].averageGrade = average;
	}
}

void swap(Student& firstStudent, Student& secondStudent) {
	Student temp = firstStudent;
	firstStudent = secondStudent;
	secondStudent = temp;
}

//sorting by faculty number both in ascending and descending order
void sortStudentsByFacultyNumber(Student* students, string sortMethod, int countOfStudents) {
	for (int i = 0; i < countOfStudents; i++)
	{
		for (int j = i + 1; j < countOfStudents; j++)
		{
			if (sortMethod == "ascending") {
				if (isFirstStringBigger(students[i].facultyNumber, students[j].facultyNumber))
					swap(students[i], students[j]);
			}
			else if (sortMethod == "descending") {
				if (!isFirstStringBigger(students[i].facultyNumber, students[j].facultyNumber))
					swap(students[i], students[j]);
			}
		}
	}
}

//sorting by average grade both in ascending and descending order 
void sortStudentsByAverageGrade(Student* students, string sortMethod, int countOfStudents) {
	findAverageGrades(students);
	for (int i = 0; i < countOfStudents; i++)
	{
		for (int j = i + 1; j < countOfStudents; j++)
		{
			if (sortMethod == "ascending") {
				if (students[i].averageGrade > students[j].averageGrade)
					swap(students[i], students[j]);
			}
			else if (sortMethod == "descending") {
				if (students[i].averageGrade < students[j].averageGrade)
					swap(students[i], students[j]);
			}
		}
	}
}


//sorting mehanism which can be used for sorting one group or sorting more groups of student
void  sortByGivenArrayOfStudents(Student* studentsInAGroup, int countOfStudents, int group) {
	int sortingCriteria = 0;
	int inputSortingMethod = 0;
	cout << endl << "Do you want to sort by:  1.Average grade or  2.Faculty Number? ";
	cin >> sortingCriteria;
	validateSortingMethodAndCriteria(sortingCriteria);
	cout << endl << "Do you want to sort them in:  1.Ascending order or  2.Descending order: ";
	cin >> inputSortingMethod;
	validateSortingMethodAndCriteria(inputSortingMethod);

	string sortMethod;
	if (inputSortingMethod == 1)
		sortMethod = "ascending";
	else if (inputSortingMethod == 2)
		sortMethod = "descending";

	if (sortingCriteria == 1)
		sortStudentsByAverageGrade(studentsInAGroup, sortMethod, countOfStudents);
	else if (sortingCriteria == 2)
		sortStudentsByFacultyNumber(studentsInAGroup, sortMethod, countOfStudents);

	string path = findPath(group);
	fstream myFile(path, ios::out);
	if (!myFile.is_open())
	{
		cout << "Error!" << endl;
		return;
	}
	for (int i = 0; i < countOfStudents; i++)
		putStudentInFile(studentsInAGroup[i], myFile);
	myFile.close();
}

void sortMoreGroupsOfStudents() {
	int numberOfGroups;
	cout << endl << "Enter how many groups you want to sort: ";
	cin >> numberOfGroups;
	validateGroup(numberOfGroups);

	Student studentsFromMoreGroups[MAX_STUDENTS_IN_GROUP];
	int indexOfStudents = 0;
	int currentGroup;
	int groupsOfAllStudents = 0;

	for (int i = 0; i < numberOfGroups; i++)
	{
		cout << endl << "Enter one of the groups you want to sort: ";
		cin >> currentGroup;
		validateGroup(numberOfGroups);
		
		groupsOfAllStudents = groupsOfAllStudents * 10 + currentGroup;
		string path = findPath(currentGroup);
		fstream myFile(path, ios::in | ios::app);
		if (!myFile.is_open())
		{
			cout << "Error!" << endl;
			return;
		}
		putSudentsFromFileInStruct(currentGroup, studentsFromMoreGroups, indexOfStudents);
		myFile.close();
	}
	sortByGivenArrayOfStudents(studentsFromMoreGroups, indexOfStudents, groupsOfAllStudents);
	cout << endl << "Groups successfully sorted!" << endl;
	cout << endl;
}

void printGroupOfStudents() {
	int group;
	cout << endl << "Enter the group of students you want to see: ";
	cin >> group;
	validateGroup(group);

	Student studentsFromAGroup[MAX_STUDENTS_IN_GROUP];
	int countOfStudents = 0;
	putSudentsFromFileInStruct(group, studentsFromAGroup, countOfStudents);

	for (int i = 0; i < countOfStudents; i++)
		cout << endl << studentsFromAGroup[i].name << ' ' << studentsFromAGroup[i].facultyNumber;
	cout << endl;
	cout << endl << "Group " << group << " successfully visualized!" << endl;
	cout << endl;
}

void sortOneGroupOfStudents() {
	int group;
	cout << endl << "Enter which group of students to be sorted: ";
	cin >> group;
	validateGroup(group);

	Student studentsInAGroup[MAX_STUDENTS_FROM_ALL_GROUPS];
	int countOfStudents = 0;
	putSudentsFromFileInStruct(group, studentsInAGroup, countOfStudents);
	sortByGivenArrayOfStudents(studentsInAGroup, countOfStudents, group);
	cout << endl << "Group " << group << " successfully sorted!" << endl;
	cout << endl;
}

void removeStudentFromGroup() {
	int group;
	string facultyNumOfStudent;
	cout << endl << "Enter group of a student you want to remove:";
	cin >> group;
	validateGroup(group);
	cout << endl << "Enter their faculty number:";
	cin >> facultyNumOfStudent;

	Student studentsFromAGroup[MAX_STUDENTS_IN_GROUP];
	int countOfStudents = 0;
	putSudentsFromFileInStruct(group, studentsFromAGroup, countOfStudents);

	string path = findPath(group);
	fstream myFile(path, ios::out);
	if (!myFile.is_open())
	{
		cout << "Error!" << endl;
		return;
	}
	for (int i = 0; i < countOfStudents; i++)
	{
		if (studentsFromAGroup[i].facultyNumber == facultyNumOfStudent)
			continue;
		putStudentInFile(studentsFromAGroup[i], myFile);
	}
	myFile.close();
	cout << endl << "Student successfully removed!" << endl;
	cout << endl;
}

//reading from console and writing student info in file
void readStudentInfo() {
	Student student;
	int numOfSubjects;

	string group;

	cout << endl << "Enter group of student: ";
	cin >> student.group;
	validateGroup(student.group);
	cout << endl << "Name: ";
	cin.ignore();
	getline(cin, student.name);
	cout << endl << "Faculty number: ";
	cin >> student.facultyNumber;
	cout << endl << "Enter how many subjects will be registered: ";
	cin >> numOfSubjects;
	validateNumberOfSubjects(numOfSubjects);

	for (int i = 0; i < numOfSubjects; i++)
	{
		cout << endl << "Enter subject: ";
		cin >> student.subjects[i];

		cout << endl << "Enter grade: ";
		cin >> student.grades[i];
		validateGrade(student.grades[i]);
	}
	string path = findPath(student.group);
	fstream myFile(path, ios::out | ios::app);
	if (!myFile.is_open())
	{
		cout << "Error!" << endl;
		return;
	}
	putStudentInFile(student, myFile);
	myFile.close();
	cout << endl << "Student registered successfully!" << endl;
	cout << endl;
}


int main()
{
	int inputNumber = 0;
	char input[BUFFER_SIZE]{};

	while (inputNumber != 6)
	{
		system("cls");
		cout << "Enter one of the following numbers:\n";
		cout << " 1.Add a new student.\n";
		cout << " 2.Remove a current student.\n";
		cout << " 3.Sort group of students.\n";
		cout << " 4.Print group of students.\n";
		cout << " 5.Sort students from different groups.\n";
		cout << " 6.Exit the program.\n";

		cin >> inputNumber;

		if (inputNumber == 1)
			readStudentInfo();
		else if (inputNumber == 2)
			removeStudentFromGroup();
		else if (inputNumber == 3)
			sortOneGroupOfStudents();
		else if (inputNumber == 4)
			printGroupOfStudents();
		else if (inputNumber == 5)
			sortMoreGroupsOfStudents();
		else if (inputNumber > 6 || inputNumber < 1)
			cout << endl << "Invalid input! Please try again!"<<endl;

		cin.ignore();
		cout << "Press Enter to continue!";
		cin.getline(input, BUFFER_SIZE);
	}
}
