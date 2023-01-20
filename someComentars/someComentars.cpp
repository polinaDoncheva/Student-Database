//void fillArr(char* arr, int size) {
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = '\0';
//	}
//	return;
//}

//void putStudentInfo(Student* students, int& countOfCurrentStudent, char* input) {
//
//	Student currentStudent = students[countOfCurrentStudent];
//	for (int i = 0; input[i] != ' '; i++)
//	{
//
//	}
//}
//void putStudentInArray(Student& student, string name, string fn,string* subjects,double* grades, int countOfSubjects) {
//	student.name = name;
//	student.fn = fn;
//	double average;
//
//	for (int i = 0; i < countOfSubjects; i++)
//	{
//		student.subjects[i] = subjects[i];
//		student.grades[i] = grades[i];
//		average += grades[i];
//	}
//	average /= countOfSubjects;
//	student.averageGrade = average;
//}

//void readInput(int operation) {
//	if (operation == 1)
//	{
//		/*cout << "Enter group, first name, last name and faculty number of student:\n";
//		string studentData;
//		cin >> studentData;*/ 
//		int group;
//		string name;
//		string facultyNumber;
//		int numOfSubjects;
//		cout << endl << "Enter group of student: ";
//		cin >> group;
//		cout << endl << "Name: ";
//		cin >> name;
//		cout << endl << "Faculty number: ";
//		cin >> facultyNumber;
//		cout << "Enter how many subjects will be registered: ";
//		cin >> numOfSubjects;
//
//		string subjects[10];
//		double grades[10];
//
//		for (int i = 0; i < numOfSubjects; i++)
//		{
//			string subject;
//			double grade;
//			cout << endl<<"Enter subject: ";
//			cin >> subject;
//			subjects[i] = subject;
//
//			cout << endl << "Enter grade: ";
//			cin >> grade;
//			grades[i] = grade;
//		}
//
//		string subjectsAndGrades;
//		cin >> subjectsAndGrades;
//
//	}
//}

//void saveStudentData(string studentData, Student& student) {
//	int inputIndex = 2;
//	fillArr(student.firstName, 20);
//	fillArr(student.lastName, 20);
//	fillArr(student.fn, 20);
//
//	for (int i = 0; studentData[inputIndex] != ' ' && studentData[inputIndex] != ','; i++, inputIndex++)
//		student.firstName[i] = studentData[inputIndex];
//	inputIndex++;
//
//	for (int i = 0; studentData[inputIndex] != ' ' && studentData[inputIndex] != ','; i++, inputIndex++)
//		student.lastName[i] = studentData[inputIndex];
//	inputIndex++;
//
//	for (int i = 0; studentData[inputIndex] != ' ' && studentData[inputIndex] != ',' && studentData[inputIndex] != '\0'; i++, inputIndex++)
//		student.fn[i] = studentData[inputIndex];
//}

//void saveStudentInformation(string studentData, Student** collectionOfStudentGroups, int& numberOfStudentsInGroup) {
//	int group = studentData[0];
//	Student student = collectionOfStudentGroups[group - 1][numberOfStudentsInGroup];
//
//	saveStudentData(studentData, student);
//
//
//}

//void saveStudentSubjects(string inputSubjects, Student& student) {
//	int inputIndex = 0;
//	int subjectCounter = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		if (inputSubjects[inputIndex] == '\0')
//			break;
//		string currentSubject;
//		for (int j = 0; inputSubjects[inputIndex] != ' ' && inputSubjects[inputIndex] != ','; j++, inputIndex++)
//			currentSubject += inputSubjects[inputIndex];
//
//		inputIndex++;
//		subjectCounter++;
//		student.subjects[i] = currentSubject;
//
//		//if (inputSubjects[inputIndex + 3] < 58 && inputSubjects[inputIndex + 3]>47)
//		//{
//		//	//double grade = ((inputSubjects[inputIndex] - '0')*100) + ((inputSubjects[inputIndex + 2] - '0')*10) + (inputSubjects[inputIndex + 3]  -'0');
//		//	string stringGrade = inputSubjects[inputIndex];
//		//	double grade =stod( inputSubjects[inputIndex] + (inputSubjects[inputIndex+1]+inputSubjects[inputIndex + 2] + inputSubjects[inputIndex]);
//		//	student.grades[i] = grade/100;
//		//	inputIndex += 3;
//		//}
//		student.grades[i] = stod(inputSubjects[inputIndex]);
//		inputIndex++;
//	}
//	double averageGrade = calculateAverageGrade(student, subjectCounter);
//	student.averageGrade = averageGrade;
//}

/* fstream file("myFile.txt");

	 if (!file.is_open())
	 {
		 cout << "Error!" << endl;
		 return -1;
	 }
	 int a, b;

	 file >> a >> b;

	 file.close();*/
/*fstream file;
	  file.open("input.txt", ios::out | ios::in);
	  if (!file.is_open())
	  {
		  cout << "Error!" << endl;
		  return -1;
	  }
		  file.close(); */



/*string input;
		  getline(cin, input);
		  Student tomison;
		  saveStudentSubjects(input, tomison);
		  cout << tomison.subjects[0] << ' ' << tomison.grades[0] << endl;
		  cout << tomison.subjects[1] << ' ' << tomison.grades[1] << endl;
		  cout << tomison.subjects[2] << ' ' << tomison.grades[2] << endl;
		  cout << tomison.subjects[3] << ' ' << tomison.grades[3] << endl;
		  cout << tomison.subjects[4] << ' ' << tomison.grades[4] << endl;
		  cout << tomison.subjects[5] << ' ' << tomison.grades[5] << endl;*/
/*if (number==1)
		  {
			  cout << "Enter group, first name, last name and faculty number of student:\n";
			  string studentData;
			  cin >> studentData;
			  char currentDigit = studentData[0];
			  cout << currentDigit;
		  }*/


/*file.open("input.txt", ios::in);
		  if (!file.is_open())
		  {
			  cout << "Error!" << endl;
			  return -1;
		  }*/

/*char studentInfo[60];
		  cin.getline(studentInfo, 60);

		  for (int i = 0; studentInfo[i]!=' '; i++)
		  {

		  }

		  cout << "name of student : " << tom.name << endl;
		  cout << "faculty number of student : " << tom.subjects << endl;

		  tom.arrayOfSubject->name;
		  student students[25];

		  for (int i = 0; i < 25; i++)
		  {
			  cin >> students[i].name;
		  }*/