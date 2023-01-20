#include <iostream>
#include <fstream>
#include <string>;
using namespace std;


//struct student {
//    char name[50];
//    int fn;
//    int subjects;
//};
//
//void addStudent(const char* fullName, int fn,int subjects) {
//    ofstream file("group1.txt");
//
//    if (!file.is_open())
//    {
//        cout << "Error!" << endl;
//        return;
//    }
//
//    student* students;
//    students[0].name;
//
//
//   /* student tomison;
//    for (int i = 0; i < fullName[i]!='\0'; i++)
//    {
//        tomison.name[i] = fullName[i];
//    }*/
//
//   /* tomison.fn = fn;
//    tomison.subjects = subjects;*/
//
//    file << fullName << ' ' << fn << ' ' << subjects;
//    file.close();
//}
struct Student {
	int group;
	string name;
	string facultyNumber;
	string subjects[10];
	double grades[10]{};
	double averageGrade;
};
string intToString(int number) {
	char numIntoChar = number + '0';
	string toString;
	toString += numIntoChar;
	return toString;
}

void putStudentDataIntoStruct(string line, Student student) {
	int inputIndex = 2;
	int countOfSpaces = 0;

	for (int i = 0; countOfSpaces < 2; i++, inputIndex++) {
		if (line[inputIndex] != ' ')
			countOfSpaces++;
		if (countOfSpaces == 2)
			break;
		student.name[i] = line[inputIndex];
	}
	inputIndex++;

	for (int i = 0; line[inputIndex] != '\0' && line[inputIndex] != ' '; i++, inputIndex++)
		student.facultyNumber[i] = line[inputIndex];
}

void putSubjectsIntoStruct(string line, Student student) {
	string currentSubject;
	int inputIndex = 0;
	for (int i = 0; line[i] != '\0'; i++)
	{
		currentSubject = "";
		while (line[inputIndex] != '-')
		{
			currentSubject += line[inputIndex];
			inputIndex++;
		}
		inputIndex++;
		student.subjects[i] = currentSubject;
		student.grades[i] = line[inputIndex];
		inputIndex += 2;
	}
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

void swap(string& firstStudent, string& secondStudent) {
	string temp = firstStudent;
	firstStudent = secondStudent;
	secondStudent = temp;
}

string findPath(int group) {
	string path = "";
	string groupToString = intToString(group);
	path = "group" + groupToString + ".txt";
	return path;
}

int powerOfNum(int num, int power) {
	int result=1;
	for (int i = 0; i < power; i++)
	{
		result *= num;
	}
	return result;
}

void putSudentsFromFileInStruct() {
	
	fstream myFile("group6.txt", ios::in | ios::app);
	if (!myFile.is_open())
	{
		cout << "Error!" << endl;
		return;
	}
	string line;
	//while (getline(myFile, line, '\0'))
	//{
	//	cout << line;
	//}

	while (getline(myFile, line))
	{
		cout << line;

	}
	myFile.close();
}


//void readStudentsFromFile(int group, Student* students) {
//	string path = "";
//	string groupToString = intToString(group);
//	path = "group" + groupToString + ".txt";
//
//
//
//	fstream myFile("group1.txt", ios::in | ios::app);
//	if (!myFile.is_open())
//	{
//		cout << "Error!" << endl;
//		return;
//	}
//	int i = 0;
//	string line;
//
//
//	while (!myFile.eof())
//	{
//		getline(myFile, line);
//		cout << line;
//	}
//
//	myFile.close();
//}

int main()
{

	int result=powerOfNum(5,3);
	cout << result;
	//putSudentsFromFileInStruct();
	
	/*Student students[10];



	cout << students[0].name << " " << students[0].facultyNumber << endl;

	for (int i = 0; students[0].grades[i] != 0; i++)
	{
		cout << students[0].subjects[i] << '-' << students[0].grades[i] << ' ';
	}
	cout << endl;



	cout << students[1].name << " " << students[1].facultyNumber << endl;
	 
	for (int i = 0; students[1].grades[i] != 0; i++)
	{
		cout << students[1].subjects[i] << '-' << students[1].grades[i] << ' ';
	}
	cout << endl;*/



	//string array[10];
	//for (int i = 0; i < 10; i++)
	//{
	//	cin >> array[i];
	//}
	//
	//for (int i = 0; i < 10; i++)
	//{
	//	
	//	for (int j = i + 1; j < 10; j++)
	//	{
	//		if (isFirstStringBigger(array[i], array[j]))
	//			swap(array[i], array[j]);
	//	}
	//}

	//for (int i = 0; i < 10; i++)
	//{
	//	cout <<endl<< array[i];
	//}

	

}