#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Student
{
	char name[100];
	char surname [100];
	int date;
	int group;
	int math;
	int oaip;
	int physics;
	int chemistry;
	int AverageMark;
};

const int SIZE_STUDENTS = 100;
const string FILE_OF_STUDENTS = "Data/Students5.txt";

void writeFileStuds(vector<Student>);
void readFileStuds(vector<Student>&);
void showStuds(vector<Student>);
void addStud(vector<Student>&);
void delStud(vector<Student>&);
void manageStud(vector<Student>&);
void taskStuds(vector<Student>);



int main() {
	vector<Student>vec_students;
	vec_students.reserve(SIZE_STUDENTS);
	readFileStuds(vec_students);
	bool flag = true;
	do {
		cout << "Choose what to do:" << endl
			<< "1) Show students" << endl
			<< "2) Add student" << endl
			<< "3) Delete student" << endl
			<< "4) Manage student" << endl
			<< "5) Task" << endl
			<< "6) End" << endl;
		int num;
		cin >> num;
		switch (num) {
		case 1: showStuds(vec_students); break;
		case 2: addStud(vec_students); break;
		case 3: delStud(vec_students); break;
		case 4: manageStud(vec_students);  break;
		case 5: taskStuds(vec_students);  break;
		case 6: flag = false;  break;
		}

	} while (flag == true);
	writeFileStuds(vec_students);
}

void writeFileStuds(vector<Student>vec_students)
{
	ofstream fout(FILE_OF_STUDENTS, ios::out);
	if (!fout.is_open()) cout << "File not exist!" << endl;
	else
	{
		for (int i = 0; i < vec_students.size(); i++) {
			fout << vec_students.at(i).name << " "
				<< vec_students.at(i).surname << " "
				<< vec_students.at(i).date << " "
				<< vec_students.at(i).group << " "
				<< vec_students[i].math << " "
				<< vec_students.at(i).oaip << " "
				<< vec_students.at(i).physics << " "
				<< vec_students.at(i).chemistry << " "
				<< vec_students.at(i).AverageMark;
			if (i < vec_students.size() - 1)
				fout << endl;
		}
	}
	fout.close();
}
void readFileStuds(vector<Student>& vec_students)
{
	ifstream fin(FILE_OF_STUDENTS, ios::in);
	if (!fin.is_open()) cout << "File not exist!" << endl;
	else
	{
		while (!fin.eof())
		{
			Student stud_tmp;
			fin >> stud_tmp.name
				>> stud_tmp.surname
				>> stud_tmp.date
				>> stud_tmp.group
				>> stud_tmp.math
				>> stud_tmp.oaip
				>> stud_tmp.physics
				>> stud_tmp.chemistry
				>> stud_tmp.AverageMark;
			vec_students.push_back(stud_tmp);
		}
	}
	fin.close();
}

void showStuds(vector<Student>vec_students)
{
	int counter = 0;
	for (int i = 0; i < vec_students.size(); i++) {
		counter++;
		cout << "Student " << i + 1 << endl
			<< "Name: " << vec_students.at(i).name << endl
			<< "Surname: " << vec_students.at(i).surname << endl
			<< "Birth date: " << vec_students.at(i).date << endl
			<< "Group: " << vec_students.at(i).group << endl
			<< "Marks: " << endl
			<< "	Math: " << vec_students.at(i).math << endl
			<< "	OAIP: " << vec_students.at(i).oaip << endl
			<< "	Physics: " << vec_students.at(i).physics << endl
			<< "	Chemistry: " << vec_students.at(i).chemistry << endl
			<< "	Average: " << vec_students.at(i).AverageMark << endl << "----------------------------------------------------------" << endl;
	};
	if (counter == 0) {
		cout << "No students found" << endl;
	};
}

void addStud(vector<Student>& vec_students)
{
	double avg;
	Student stud_tmp;
	cout << "Input name: " << endl;
	cin >> stud_tmp.name;
	cout << "Input surname: " << endl;
	cin >> stud_tmp.surname;
	cout << "Input date of birth: " << endl;
	cin >> stud_tmp.date;
	cout << "Input group: " << endl;
	cin >> stud_tmp.group;
	cout << "Input math mark: " << endl;
	cin >> stud_tmp.math;
	cout << "Input OAIP mark: " << endl;
	cin >> stud_tmp.oaip;
	cout << "Input physics: " << endl;
	cin >> stud_tmp.physics;
	cout << "Input chemistry: " << endl;
	cin >> stud_tmp.chemistry;
	avg = (stud_tmp.math + stud_tmp.oaip + stud_tmp.physics + stud_tmp.chemistry) / 4;
	cout << "Calculated average mark: " << avg << endl;
	stud_tmp.AverageMark = avg;
	vec_students.push_back(stud_tmp);
	cout << "New student added" << endl;
}

void delStud(vector<Student>& vec_students)
{
	int number_of_deleted_item;
	int confirm;
	cout << "Input number of student to delete: " << endl;
	cin >> number_of_deleted_item;
	number_of_deleted_item--;
	if (number_of_deleted_item >= 0 &&
		number_of_deleted_item < vec_students.size())
	{
		vec_students.erase(vec_students.begin() + number_of_deleted_item);
		cout << "Student deleted" << endl;
	}
	else cout << "Incorrect number!" << endl;
}

void manageStud(vector<Student>& vec_students)
{
	int num_manage, par_manage, alert = 0;
	double avg;
	cout << "Input number of student to manage" << endl;
	cin >> num_manage;
	num_manage--;
	cout << "Choose parameter to manage:" << endl
		<< "1) Name" << endl
		<< "2) Surname" << endl
		<< "3) Birth date" << endl
		<< "4) Group" << endl
		<< "5) Math mark" << endl
		<< "6) OAIP mark" << endl
		<< "7) Physics mark" << endl
		<< "8) Chemistry mark" << endl;
	cin >> par_manage;
	switch (par_manage)
	{
	case 1:
		cout << "Input new name" << endl;
		cin >> vec_students.at(num_manage).name;
		break;
	case 2:
		cout << "Input new surname" << endl;
		cin >> vec_students.at(num_manage).surname;
		break;
	case 3:
		cout << "Input new date of birth" << endl;
		cin >> vec_students.at(num_manage).date;
		break;
	case 4:
		cout << "Input new group" << endl;
		cin >> vec_students.at(num_manage).group;
		break;
	case 5:
		cout << "Input new math mark" << endl;
		cin >> vec_students.at(num_manage).math;
		alert++;
		break;
	case 6:
		cout << "Input new OAIP mark" << endl;
		cin >> vec_students.at(num_manage).oaip;
		alert++;
		break;
	case 7:
		cout << "Input new physics mark" << endl;
		cin >> vec_students.at(num_manage).physics;
		alert++;
		break;
	case 8:
		cout << "Input new chemistry mark" << endl;
		cin >> vec_students.at(num_manage).chemistry;
		alert++;
		break;
	default:
		break;
	}
	if (alert != 0) {
		avg = (vec_students.at(num_manage).math + vec_students.at(num_manage).oaip + vec_students.at(num_manage).physics + vec_students.at(num_manage).chemistry) / 4;
		cout << "New calculated average mark: " << avg << endl;
		vec_students.at(num_manage).AverageMark = avg;
	}
	cout << "Student managed" << endl;
}

void taskStuds(vector<Student>vec_students) {
	double avg_sum = 0, avg;
	for (int i = 0; i < vec_students.size(); i++)
		avg_sum += vec_students.at(i).AverageMark;
	avg = avg_sum / vec_students.size();
	cout << "Average mark : " << avg << endl;


	int group, counter = 0;
	cout << "Input group number";
	cin >> group;
	for (int i = 0; i < vec_students.size(); i++) {
		counter++;
		if (group == vec_students.at(i).group && vec_students.at(i).AverageMark > avg)
			cout << "Student " << i + 1 << endl
			<< "Name: " << vec_students.at(i).name << endl
			<< "Surname: " << vec_students.at(i).surname << endl
			<< "Birth date: " << vec_students.at(i).date << endl
			<< "Group: " << vec_students.at(i).group << endl
			<< "Marks: " << endl
			<< "	Math: " << vec_students.at(i).math << endl
			<< "	OAIP: " << vec_students.at(i).oaip << endl
			<< "	Physics: " << vec_students.at(i).physics << endl
			<< "	Chemistry: " << vec_students.at(i).chemistry << endl
			<< "	Average: " << vec_students.at(i).AverageMark << endl;
	};
	if (counter == 0) {
		cout << "No students found" << endl;
	};
}