#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <thread>
#include <chrono>
#include <cmath>


using namespace std;


struct Node
{
	string code, data;
	Node *next;
};
struct NodeL
{
	string FName;
	string Reg;
	string Uname;
	string Pass;

	NodeL *next;
};


class List
{
private:
	string str4, str5;
	Node *cur = NULL, *pev = NULL;
	Node *head, *tail;
	Node *del = NULL;
public:

	void AddNode()
	{
		char n[100];
		string str1, str2;

		ifstream file;
		file.open("Data1.txt");
		if (file.is_open())
		{
			while (!file.eof())
			{
				Node *temp = new Node;
				file >> str1;
				file.getline(n, 100);
				str2 = n;
				temp->code = str1;
				temp->data = str2;
				temp->next = NULL;
				if (head == NULL)
				{
					head = temp;
					tail = temp;
					temp = NULL;
				}
				else
				{
					tail->next = temp;
					tail = temp;
				}
			}
		}
		else
		{
			cout << "File not open\n";
		}
	}
	void Display()
	{
		Node *cur = NULL;
		cur = head;
		while (cur != NULL)
		{
			cout << cur->code << cur->data << endl;
			cur = cur->next;
		}
		//Sleep(5000);
	}
	void SearchCourse()
	{
		string str1, str2, str3;
		Node *temp = NULL;
		AddNode();
		temp = head;

		cout << "Enter Course Code to search:\n";
		cin >> str1;
		for_each(str1.begin(), str1.end(), [](char & c)
		{
			c = toupper(c);
		});

		while (temp != NULL)
		{
			str2 = temp->code;

			if (str1 == str2)
			{
				del = temp;
				cout << "Result:\t" << temp->code << " " << temp->data << endl;
				break;
			}
			temp = temp->next;
		}

		Sleep(1000);
	}
	void Addnewcourse()
	{
		int n;
		string str1, str2;
		char str3[100];
		Node *temp = new Node;
		AddNode();
		cur = head;
		cout << "Select Semester:\n";
		cout << "1. 1stSemester\n2. 2ndSemester\n3. 3rdSemester\n4. 4thSemester\n5. 5thSemester\n6. 6thSemester\n\n";
		cin >> str1;

		while (cur != NULL)
		{
			if (str1 == "1")
			{
				while (cur->code != "2nd")
				{
					pev = cur;
					cout << cur->code << " " << cur->data << endl;
					cur = cur->next;
				}
				AddCourse();
				break;
			}
			else if (str1 == "2")
			{
				while (cur->code != "2nd")
				{
					cur = cur->next;
					if (cur->code == "2nd")
					{
						while (cur->code != "3rd")
						{
							cout << cur->code << " " << cur->data << endl;
							cur = cur->next;
						}
						AddCourse();
						break;
					}
				}
			}
			else if (str1 == "3")
			{
				while (cur->code != "3rd")
				{
					cur = cur->next;
					if (cur->code == "3rd")
					{
						while (cur->code != "4th")
						{
							cout << cur->code << " " << cur->data << endl;
							cur = cur->next;
						}
						AddCourse();
						break;
					}
				}
			}
			else if (str1 == "4")
			{
				while (cur->code != "4th")
				{
					cur = cur->next;
					if (cur->code == "4th")
					{
						while (cur->code != "5th")
						{
							cout << cur->code << " " << cur->data << endl;
							cur = cur->next;
						}
						AddCourse();
						break;
					}
				}
			}
			else if (str1 == "5")
			{
				while (cur->code != "5th")
				{
					cur = cur->next;
					if (cur->code == "5th")
					{
						while (cur->code != "6th")
						{
							cout << cur->code << " " << cur->data << endl;
							cur = cur->next;
						}
						AddCourse();
						break;
					}
				}
			}
			else if (str1 == "6")
			{
				while (cur->code != "6th")
				{
					cur = cur->next;
					if (cur->code == "6th")
					{
						while (cur != NULL)
						{
							cout << cur->code << " " << cur->data << endl;
							cur = cur->next;
						}
						AddCourse();
						break;
					}
				}
			}
		}

	};
	void AddCourseTofile()
	{
		string str1;
		Node *temp = NULL;
		fstream file;

		temp = head;
		remove("Data1.txt");
		file.open("Data1.txt", ios::app);
		while (temp != NULL)
		{
			file << temp->code << " " << temp->data << endl;
			temp = temp->next;
		}
		file.close();
	}
	void AddCourse()
	{
		char n;
		Node *temp = new Node;
		cout << "Want to Enter New Couse(Yes or No):\n";
		cin >> n;
		if (n == 'Y' || n == 'y')
		{
			cout << "Enter new Course Code:\n";
			cin >> str4;
			for_each(str4.begin(), str4.end(), [](char & c)
			{
				c = toupper(c);
			});
			cout << "Enter Course name:\n";
			cin >> str5;
			temp->code = str4;
			temp->data = str5;
			pev->next = temp;
			temp->next = cur;
			AddCourseTofile();
			system("cls");
		}
		else
		{
			system("cls");
		}
	}
	void DeleteCourse()
	{
		Node *search = NULL, *searchpev = NULL, *newNode = NULL;
		SearchCourse();
		search = head;

		while (search != NULL)
		{

			if (del->code == search->code)
			{
				break;
			}
			searchpev = search;
			search = search->next;
		}
		newNode = search;
		search = search->next;
		searchpev->next = search;

		delete newNode;
		DeleteFromFile();

		system("cls");
	}
	void DeleteFromFile()
	{
		string str1;
		Node *temp = NULL;
		fstream file;
		temp = head;

		remove("Data1.txt");
		file.open("Data1.txt", ios::app);
		while (temp != NULL)
		{
			file << temp->code << " " << temp->data << endl;
			temp = temp->next;
		}
		file.close();
	}
};

class Login{
private:
	NodeL *head, *tail;
	string cur;
	string Usern, Password, check;
	string fullname, regist, usern, passn;
	string arr1[6], arr2[6];
public:
	void AddUser()
	{
		char fname[100];
		string Fname, Reg, Uname, Pass, str1;
		cin.get();
		cout << "Enter Fullname:\n";

		gets_s(fname);
		Fname = fname;
		fullname = Fname;
		//cin >> Fname;
		cout << "Enter Registration Number:\n";
		cin >> Reg;
		regist = Reg;
		cout << "Enter Username:\n";
		cin >> Uname;
		usern = Uname;
		ifstream read;
		read.open("Login.txt", ios::app);

		while (!read.eof())
		{
			read >> str1;
			if (str1 == Uname)
			{
				cout << "Username already exist\n";
				cin >> Uname;
				usern = Uname;
			}

		}
		read.close();
		cout << "Enter Password:\n";
		cin >> Pass;
		passn = Pass;

		//AddUsertoFile();

		ofstream file;
		file.open("Login.txt", ios::app);
		file << Fname << endl;
		file << Reg << endl;
		file << Uname << endl;
		file << Pass << endl;
		file.close();

	}
	/*void Get_user()
	{
	Login l;
	ofstream file;
	file.open("Login.txt", ios::app);

	l.AddUser();
	file.write(reinterpret_cast<char *> (&l), sizeof(Login));

	file.close();
	}*/
	void ReadLinklist()
	{
		NodeL *temp = NULL;

		fstream file;
		file.open("Login.txt");

		temp = head;

		while (temp != NULL)
		{
			file << temp->FName << endl;
			file << temp->Reg << endl;
			file << temp->Uname << endl;
			file << temp->Pass << endl;

			temp = temp->next;

		}
		file.close();
	}
	void AddLinkedList()
	{
		string str1, str2;

		char n[100], r[100];
		ifstream file;
		file.open("Login.txt", ios::app);
		if (file.is_open())
		{
			while (!file.eof())
			{
				NodeL *temp = new NodeL;
				file.getline(n, 100);
				str1 = n;
				temp->FName = str1;
				file >> str1;
				temp->Reg = str1;
				file >> str1;
				temp->Uname = str1;
				file >> str1;
				temp->Pass = str1;
				file.getline(r, 100);
				temp->next = NULL;
				if (head == NULL)
				{
					head = temp;
					tail = temp;
					temp = NULL;
				}
				else
				{
					tail->next = temp;
					tail = temp;
				}
			}
		}
		else
		{
			cout << "File is not open\n";
		}
	};
	bool SignIn()
	{
		string Uname, Pas, str1, str2;
		AddLinkedList();
		cout << "Enter Username:\n";
		cin >> Uname;
		cout << "Enter Password:\n";
		cin >> Pas;
		Usern = Uname;
		NodeL *cur = NULL;
		NodeL *pev = NULL;
		cur = head;
		while (cur != NULL)
		{
			str1 = cur->Uname;
			str2 = cur->Pass;
			pev = cur;
			if (Uname == str1 && Pas == str2)
			{
				cout << "Name:\t" << cur->FName << endl;
				cout << "Registration No.:\t" << cur->Reg << endl;
				cout << "Username:\t" << cur->Uname << endl;
				return true;
				break;
			}
			else
			{
				cur = cur->next;
			}
			/*else
			{
			cout << "Username and Password not found\n";
			Sleep(1000);
			return false;
			break;
			}*/
		}
		if (Uname != str1 && Pas != str2)
		{
			cout << "Username and Password not found\n";
			Sleep(1000);
			return false;
		}
	}
	/*void changePassword()
	{
	string Uname, Pass, find, replace, str1;

	fstream file;

	file.open("Login.txt");
	cout << "Enter Username:\n";
	cin >> Uname;

	cout << "Enter Password:\n";
	cin >> Pass;

	while (file >> str1)
	{
	if (str1 == Uname)
	{
	file >> find;

	if (find == Pass)
	{
	cout << "Enter new Password:\n";
	cin >> replace;
	}

	replace += "\n";
	file << replace;

	break;
	}
	}

	}*/
	/*void ChangePassword()
	{
	string str1,str2,str3,str4,str5;
	AddLinkedList();
	cout << "Enter Username:\n";
	cin >> str1;

	ifstream file;
	file.open("Login.txt", ios::app);
	while (!file.eof())
	{
	file >> str2;
	if (str1 == str2)
	{
	cout << "Enter you old password:\n";
	cin >> str1;
	file >> str2;
	if (str1 == str2)
	{
	cout << "Enter new password:\n";
	cin >> str3;
	cout << "Re-Enter password:\n";
	cin >> str4;
	if (str3 == str4)
	{
	ifstream read;
	ofstream write;
	read.open("Login.txt");
	write.open("Login.txt");
	while (!read.eof())
	{

	if (str1 == str2)
	{
	str5 = str3;
	}
	write << str5;
	}
	}

	}
	break;
	}
	}
	}*/
	void PreCourse()
	{
		int count = 0;
		string course, str1;
		List l;

		l.AddNode();
		l.Display();
		cout << "\n\n";
		cout << "Please enter Course Code from the follow which you have Passed:\n";

		ofstream write;
		write.open("CourseStudied.txt");
		for (int i = 0; i <= 1; i++)
		{
			cin >> course;
			for_each(course.begin(), course.end(), [](char & c)
			{
				c = toupper(c);
			});

			//course store in file

			arr1[i] = course;

		}
		write.close();

	}
	void CourseStudy()
	{
		int count = 0;
		string data, str1;
		List l;
		string arr[10];

		cout << "\nPlease enter Course Code from the follow which you have to Study:\n";

		ofstream file;
		file.open("Studycourse.txt");
		for (int i = 0; i <= 1; i++)
		{
			cin >> data;
			for_each(data.begin(), data.end(), [](char & c)
			{
				c = toupper(c);
			});
			arr2[i] = data;
		}
		file.close();

	}
	void CheckingCourse()
	{
		string str1, str2, str3, str4, str5;
		List l;
		ifstream read;
		read.open("Studycourse.txt", ios::app);
		ifstream file;
		file.open("CourseChecker.txt");
		ifstream write;
		write.open("CourseStudied.txt", ios::app);



		/*write >> str1;
		read >> str2;
		file >> str3;*/

		/*Node *temp = NULL;
		l.AddNode();
		temp = l.head;

		while (temp != NULL)
		{
		if (temp->data == str1)
		{
		temp->data = str4;
		}
		if (temp->data == str2)
		{
		temp->data = str5;
		}
		temp = temp->next;
		}*/

		for (int i = 0; i < 2; i++)
		{
			str1 = arr1[i];
			str2 = arr2[i];

			file >> str3;
			if (str1 == " " || str3 == " ")
			{
				break;
				system("CLS");
				Menu();
			}

			else if (str1 == "MA1001" && str2 == "MA1005")
			{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou can study this subject\n";
				/*else
				{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou can't study this subject\n";
				}*/
			}
			else if (str1 == "PH100X" && str2 == "CSC1074")
			{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou study that course\n";
				/*else
				{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou can't study that course\n";
				}*/
			}
			else if (str1 == "ENG1092" && str2 == "ENG1091")
			{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou study that course\n";
				/*else
				{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou can't study that course\n";
				}*/
			}
			else if (str1 == "CSC1072" && str2 == "CSC2075")
			{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou study that course\n";
				/*else
				{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou can't study that course\n";
				}*/
			}
			else if (str1 == "MA-1005" && str2 == "MA2002")
			{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou study that course\n";
				/*else
				{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou can't study that course\n";
				}*/
			}
			else if (str1 == "ENG1092" && str2 == "ENG3091")
			{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou study that course\n";
				/*else
				{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou can't study that course\n";
				}*/
			}
			else if (str1 == "CSC1071" && str2 == "CSC2071")
			{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou study that course\n";
				/*else
				{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou can't study that course\n";
				}*/
			}
			else if (str1 == "CSC2078" && str2 == "CSC2077")
			{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou study that course\n";
				/*else
				{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou can't study that course\n";
				}*/
			}
			else if (str1 == "CSC2075" && str2 == "CSC3073")
			{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou study that course\n";
				/*else
				{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou can't study that course\n";
				}*/
			}
			else if (str1 == "MA2002" && str2 == "MA4001")
			{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou study that course\n";
				/*else
				{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "\nYou can't study that course\n";
				}*/
			}
			else if (str1 != "MA1001" || str1 != "PH100X" || str1 != "ENG1091" || str1 != "CSC1072" || str1 != "MA - 1005" || str1 != "ENG1092" || str1 != "CSC1071" || str1 != "CSC2078" || str1 != "CSC2075" || str1 != "MA2002" && str2 != "MA1005" || str2 != "CSC1074" || str2 != "ENG1092" || str2 != "CSC2075" || str2 != "MA2002" || str2 != "ENG3091" || str2 != "CSC2071" || str2 != "CSC2077" || str2 != "CSC3073" || str2 != "MA4001")
			{
				show_progress_bar(100, "\nChecking", '\xB2');
				cout << "These subject have no Prerequisite subject\n";
			}
			Sleep(1000);

		}
		system("CLS");
		Menu();
	}
	void Display()
	{
		NodeL *cur = NULL;
		string n, opass, npass, str1;
		int key;
		n = Usern;
		cur = head;
		while (cur->Uname != n)
		{
			cur = cur->next;
		}
		if (cur->Uname == n)
		{
			cout << "Fullname:\t\t" << cur->FName << endl;
			cout << "Registration no. : \t" << cur->Reg << endl;
			cout << "Username:\t\t" << cur->Uname << endl;
			cout << "Password:\t\t" << cur->Pass << endl;
		}

		cout << "\n\n1. Change Password\n";
		cout << "2. Change Name\n";
		cout << "3. Change registration no. \n";
		cout << "4. Delete Account\n";
		cout << "0. Exit\n";
		cin >> key;
		bool check = false;
		while (check != true)
		{
			if (key == 1)
			{
				ChangePassword();
				/*fstream file;
				file.open("Login.txt", ios::app);
				while (!file.eof())
				{
				file >> str1;
				if (n == str1)
				{
				cout << "Enter old Password:\n";
				cin >> opass;
				file >> str1;
				if (opass == str1)
				{
				cout << "Enter new Password:\n";
				cin >> npass;
				file << npass;

				}
				}

				}
				file.close();
				fstream read;
				read.open("Login.txt");
				while (!read.eof())
				{
				read >> str1;
				if (str1 == npass)
				{
				cout << "Password is changed\n";
				}

				}*/
				check = true;
			}
			else if (key == 2)
			{
				ChangeName();
				check = true;
			}
			else if (key == 3)
			{
				ChangeReg();
				check = true;
			}
			else if (key == 4)
			{
				DeleteUser();
				check = true;
				system("cls");
				LoginPanel();
			}
			else if (key == 0)
			{
				system("cls");
				Menu();
			}
			else
			{
				cerr << "Error\n";
				system("CLS");
				Menu();
			}
		}

	}
	void ChangePassword()
	{
		string n, npass;
		n = Usern;
		NodeL *temp = NULL;
		fstream file;
		temp = head;

		while (temp != NULL)
		{
			if (temp->Uname == n)
			{
				cout << "Enter new Password:\n";
				cin >> npass;


				temp->Pass = npass;
				//system("cls");
				//LoginPanel();
				break;
			}
			temp = temp->next;
		}
		remove("Login.txt");
		file.open("Login.txt", ios::app);
		while (temp != NULL)
		{
			file << temp->FName << endl;
			file << temp->Reg << endl;
			file << temp->Uname << endl;
			file << temp->Pass << endl;
			temp = temp->next;
		}
		file.close();
	}
	void ChangeName()
	{
		string n, Fname;
		char fname[100];
		n = Usern;
		NodeL *temp = NULL;
		fstream file;
		temp = head;

		while (temp != NULL)
		{
			if (temp->Uname == n)
			{
				cin.get();
				cout << "Enter Fullname:\n";
				gets_s(fname);
				Fname = fname;

				temp->FName = Fname;
				break;
			}
			temp = temp->next;
		}
		remove("Login.txt");
		file.open("Login.txt", ios::app);
		while (temp != NULL)
		{
			file << temp->FName << endl;
			file << temp->Reg << endl;
			file << temp->Uname << endl;
			file << temp->Pass << endl;
			temp = temp->next;
		}
		file.close();
	}
	void ChangeReg()
	{
		string n, reg;
		n = Usern;
		NodeL *temp = NULL;
		fstream file;
		temp = head;

		while (temp != NULL)
		{
			if (temp->Uname == n)
			{
				cout << "Enter Fullname:\n";
				cin >> reg;

				temp->Reg = reg;
				break;
			}
			temp = temp->next;
		}
		remove("Login.txt");
		file.open("Login.txt", ios::app);
		while (temp != NULL)
		{
			file << temp->FName << endl;
			file << temp->Reg << endl;
			file << temp->Uname << endl;
			file << temp->Pass << endl;
			temp = temp->next;
		}
		file.close();
	}
	void DisplayAllUser()
	{
		NodeL *temp = NULL;
		temp = head;
		while (temp != NULL)
		{
			cout << endl;
			cout << "FullName:\t" << temp->FName << endl;
			cout << "Registration NO. :\t" << temp->Reg << endl;
			cout << "UserName:\t" << temp->Pass << endl;
			cout << "--------------------------------------------------------------------------------------" << endl;
		}
	}
	void LoginPanel()
	{
		int key;
		bool check = false;
		string menu[3] = { "Add New User", "Login", "Exit" };
		int pointer = 0;

		system("Color 2F");
		cout << "-----------------------------------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		cout << "\nMembers:\n\t***Muhammad Aamir Asif***\t***16-NTU-1051***\n\t***Hamza Ahmed***\t***16-NTU-1047***\n\t***Muhammad Jawad Khalil***\t***16-NTU-1060***\n\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		cout << "\nPlatform:\nVisual Studio C++\n\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		cout << "-----------------------------------------------------------------------------------------------\n";
		cout << "\n\n\n\t\t\tStudent Prerequisite Subjects ManagementSystem\n\n\n";
		cout << "1. Create Account\n";
		cout << "2. Login\n";
		cout << "3. Search User\n";
		cin >> key;
		while (check != true)
		{
			if (key == 1)
			{
				system("CLS");
				//Get_user();
				AddUser();
				system("cls");
				LoginPanel();
				true;
			}
			else if (key == 2)
			{
				if (SignIn() == true)
				{
					system("CLS");
					Menu();
				}
				else
				{
					system("CLS");
					LoginPanel();
				}
				true;
			}
			else if (key == 3)
			{
				system("cls");
				SearchUser();
				system("cls");
				LoginPanel();
			}
			else if (key != 1 || key != 2 || key != 3)
			{
				cerr << "try Again";
				false;
				LoginPanel();
			}
			/*switch (key)
			{
			case '1':
			Get_user();
			break;
			true;
			case '2':
			SignIn();
			break;
			true;
			default:
			cout << "Hello";
			}*/
		}


		//while (true)
		//{
		//	system("cls");
		//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		//	//cout << "Main Menu\n\n";
		//	cout << "-----------------------------------------------------------------------------------------------\n";
		//	cout << "-----------------------------------------------------------------------------------------------\n";
		//	cout << "\nMembers:\nMuhammad Aamir Asif\nHamza Ahmed\nJawad Khalil\n\n";
		//	cout << "-----------------------------------------------------------------------------------------------\n";
		//	cout << "-----------------------------------------------------------------------------------------------\n";
		//	cout << "\nPlatform:\nVisual Studio C++\n\n";
		//	cout << "-----------------------------------------------------------------------------------------------\n";
		//	cout << "-----------------------------------------------------------------------------------------------\n";
		//	cout << "\n\n\n\t\t\tStudent Prerequisite Subjects ManagementSystem\n\n\n";
		//	for (int i = 0; i < 3; ++i)
		//	{
		//		if (i == pointer)
		//		{
		//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		//			cout << menu[i] << endl;
		//		}
		//		else
		//		{
		//			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		//			cout << menu[i] << endl;
		//		}
		//	}
		//	while (true)
		//	{
		//		if (GetAsyncKeyState(VK_UP) != 0)
		//		{
		//			pointer -= 1;
		//			if (pointer == -1)
		//			{
		//				pointer = 2;
		//			}
		//			break;
		//		}
		//		else if (GetAsyncKeyState(VK_DOWN) != 0)
		//		{
		//			pointer += 1;
		//			if (pointer == 3)
		//			{
		//				pointer = 0;
		//			}
		//			break;
		//		}
		//		else if (GetAsyncKeyState(VK_RETURN) != 0)
		//		{
		//			switch (pointer)
		//			{
		//			case 0:
		//			{
		//				system("CLS");
		//				AddUser();
		//				LoginPanel();
		//			} break;
		//			case 1:
		//			{
		//				if (SignIn() == true)
		//				{
		//					system("CLS");
		//					Menu();
		//				}
		//				else
		//				{
		//					system("CLS");
		//					LoginPanel();
		//				}
		//			} break;
		//			case 2:
		//			{
		//				system("END");
		//			} break;
		//			}
		//				//if (pointer == 0)
		//				//	{
		//				//		system("CLS");
		//				//		//Get_user();
		//				//		AddUser();
		//				//		LoginPanel();
		//				//		
		//				//	}
		//				//	else if (pointer == 1)
		//				//	{
		//				//		if (SignIn() == true)
		//				//		{
		//				//			system("CLS");
		//				//			Menu();
		//				//		}
		//				//		else
		//				//		{
		//				//			system("CLS");
		//				//			LoginPanel();
		//				//		}
		//				//		true;
		//				//	}
		//				//	else if (key != 1 || key != 2)
		//				//	{
		//				//		cerr << "try Again";
		//				//		
		//				//		LoginPanel();
		//				//	}
		//			break;
		//		}
		//	}
		//	Sleep(150);
		//}
	}
	void Menu()
	{
		List s;
		int choice;


		cout << "Menu\n\n";
		cout << "1. Check Course\n";
		cout << "2. Search Courses\n";
		cout << "3. Select Course for next semester & Check courses aviable or not\n";
		cout << "4. Account Information\n";
		cout << "5. Add New Course\n";
		cout << "6. Delete Course\n";
		cout << "7. Search Course\n";
		cout << "8. Logout\n";

		cin >> choice;

		while (choice != 9)
		{
			if (choice == 1)
			{
				system("CLS");
				s.AddNode();
				s.Display();
				Sleep(5000);
				system("CLS");
				Menu();
			}
			else if (choice == 2)
			{
				system("CLS");
				s.AddNode();
				s.SearchCourse();
				system("CLS");
				Menu();
			}
			else if (choice == 3)
			{
				system("CLS");
				PreCourse();
				CourseStudy();
				CheckingCourse();
				system("CLS");
				Menu();
			}
			else if (choice == 4)
			{
				system("CLS");

				Display();
				system("CLS");
				Menu();
			}
			else if (choice == 5)
			{
				system("cls");
				s.Addnewcourse();
				system("cls");
				Menu();
			}
			else if (choice == 6)
			{
				system("cls");
				s.DeleteCourse();
				system("cls");
				Menu();
			}
			else if (choice == 7)
			{
				system("cls");
				s.SearchCourse();
				system("cls");
				Menu();
			}
			else if (choice == 8)
			{
				system("cls");
				LoginPanel();
			}

		}


		/*string arr[4] = { "Check Course", "Search Course", "Select Course for next semester & Check courses aviable or not", "Account Information" };
		int pointer = 0;

		while (true)
		{
		system("cls");

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Main Menu\n\n";

		for (int i = 0; i < 4; ++i)
		{
		if (i == pointer)
		{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << arr[i] << endl;
		}
		else
		{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << arr[i] << endl;
		}
		}

		while (true)
		{
		if (GetAsyncKeyState(VK_UP) != 0)
		{
		pointer -= 1;
		if (pointer == -1)
		{
		pointer = 2;
		}
		break;
		}
		else if (GetAsyncKeyState(VK_DOWN) != 0)
		{
		pointer += 1;
		if (pointer == 3)
		{
		pointer = 1;
		}
		break;
		}
		else if (GetAsyncKeyState(VK_RETURN) != 0)
		{
		switch (pointer)
		{
		case 0:
		{
		system("CLS");
		s.AddNode();
		s.Display();
		Sleep(1000);
		system("CLS");
		Menu();
		} break;
		case 1:
		{
		system("CLS");
		s.AddNode();
		s.SearchCourse();
		Sleep(1000);
		system("CLS");
		Menu();
		} break;
		case 2:
		{
		system("CLS");
		PreCourse();
		CourseStudy();
		CheckingCourse();
		system("CLS");
		Menu();
		} break;
		case 3:
		{
		system("CLS");

		Display();
		system("CLS");
		Menu();
		}break;
		case 4:
		{
		return;
		} break;
		}
		break;
		}
		}

		Sleep(2000);
		}*/
	}
	void show_progress_bar(int time, const std::string &message, char symbol)
	{
		std::string progress_bar;
		const double progress_level = 1.42;

		std::cout << message << "\n\n";

		for (double percentage = 0; percentage <= 100; percentage += progress_level)
		{
			progress_bar.insert(0, 1, symbol);
			std::cout << "\r [" << std::ceil(percentage) << '%' << "] " << progress_bar;
			std::this_thread::sleep_for(std::chrono::milliseconds(time));
		}
		std::cout << "\n\n";
	}
	void SearchUser()
	{
		string str1, str2;
		NodeL *temp = NULL;
		AddLinkedList();
		temp = head;
		cout << "Enter Username to Search:\n";
		cin >> str1;

		while (temp != NULL)
		{
			str2 = temp->Uname;
			if (str2 == str1)
			{
				break;
			}
			temp = temp->next;
		}

		if (str2 != str1)
		{
			cout << "User not found\n";
		}
		else
		{
			cout << "Fullname:\t" << temp->FName << endl;
			cout << "Registration:\t" << temp->Reg << endl;
			cout << "Username:\t" << temp->Uname << endl;

		}

		Sleep(1000);
		system("cls");
	}
	void DeleteUser()
	{
		string n;
		NodeL *cun, *pev;
		NodeL *temp = new NodeL;
		cun = head;
		n = Usern;
		while (cun != NULL)
		{
			if (cun->Uname == n)
			{
				break;
			}
			pev = cun;
			cun = cun->next;
		}
		temp = cun;
		cun = cun->next;
		delete temp;
		if (pev == NULL)
		{
			pev = NULL;
		}
		else
		{
			pev->next = cun;
		}
		ReEnterUsertofile();
	}
	void ReEnterUsertofile()
	{
		NodeL *temp = NULL;
		fstream file;

		temp = head;
		remove("Login.txt");
		file.open("Login.txt", ios::app);
		while (temp != NULL)
		{
			file << temp->FName << endl;
			file << temp->Reg << endl;
			file << temp->Uname << endl;
			file << temp->Pass;
			temp = temp->next;
		}
		file.close();
	}
};


int main()
{
	Login l;
	List s;
	int choice = 0;
	int key = 0;
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);

	MoveWindow(console, r.left, r.top, 800, 700, true);

	l.LoginPanel();
	//s.DeleteCourse();

	return 0;
}