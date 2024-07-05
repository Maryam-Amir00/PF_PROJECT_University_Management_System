#include <iostream>
#include <fstream> // for file handling
#include <iomanip> // for setw function
#include <cctype> // For isalpha() function
using namespace std;

const int maxstudent = 30;
int i = 0;

int id[maxstudent];
string firstname[maxstudent];
string lastname[maxstudent];
string department[maxstudent];
double marks[maxstudent];

void mainpanel();
void admin();
void add();
void removerec();
void update();
void check();
void student();
void checkinfo();
void checkresult();
void checkcourse();
void teacher();
void addmarks();
void displayAllRecords(); 
bool containsOnlyLetters(const string& str);

int main() {
    mainpanel();
    return 0;
}

void mainpanel()
 {
    int choice;
    cout << "!-------------- University Management System --------------!\n\n";
    cout << "\t **** Superior University ****\n\n";
    cout << " 1- Admin\n\n";
    cout << " 2- Student\n\n";
    cout << " 3- Teacher\n\n";
    cout << " 4- Exit\n\n";
    cout << " Enter your choice (1 to 4): ";
    cin>>choice;
    cin.ignore(1000,'\n');
    while (1)
	 {
        if (cin.fail())
		 {
            cout << "\nInvalid Input\n\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"Enter Your input in Alphabets";
            cout << "Press Enter to go back\n\n";
            system("pause");
            system("cls");
            mainpanel();
        }
        if (!cin.fail()) 
		{
            break;
        }
    }
    switch (choice) 
	{
    case 1:
        system("cls");
        admin();
        break;
    case 2:
        system("cls");
        student();
        break;
    case 3:
        system("cls");
        teacher();
        break;
    case 4:
        exit(0);
        break;
    default:
        cout << "\nInvalid Input\n\n";
        cout << "Press Enter to input Again\n\n";
        system("pause");
        system("cls");
        mainpanel();
    }
}

void admin()
 {
    string username = "admin";
    string password = "1234";
    string admin, pass;
    bool found = false;
    cout << "Enter Admin Username: ";
    cin >> admin;
    cout << "Enter Password:";
    cin >> pass;
    if (username == admin && password == pass) 
	{
        found = true;
    } 
	else
	 {
        cout << "\nInvalid Input\n";
        cout << "Press Enter to go back to mainpanel\n\n";
        system("pause");
        system("cls");
        mainpanel();
    }
    while (found)
	 {
        system("cls");
        cout << "\n\t *** Welcome to Admin Section ****\n\n";
        int choice;
        cout << " 1- Add Student\n\n";
        cout << " 2- Remove Student\n\n";
        cout << " 3- Update Information\n\n";
        cout << " 4- Check Records\n\n";
        cout << " 5- Logout\n\n";
        cout << " 6- Exit\n\n";
        cout << " 7- Display All Records\n\n";
        cout << " Enter your choice (1 to 7): ";
        cin >> choice;
        cin.ignore(1000,'\n');
        while (1) 
		{
            if (cin.fail())
			 {
                cout << "\nInvalid Input\n\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter your choice again: ";
            cin>>choice;
            
            }
            if (!cin.fail())
		    {
                break;
            }
        }
        switch(choice)
		 {
        case 1:
            system("cls");
            add();
            break;
        case 2:
            system("cls");
            removerec();
            break;
        case 3:
            system("cls");
            update();
            break;
        case 4:
            system("cls");
            check();
            break;
        case 5:
            system("cls");
            mainpanel();
            break;
        case 6:
            system("cls");
            exit(0);
            break;
        case 7:
            system("cls");
            displayAllRecords();
            break;
        default:
            cout << "Invalid Input\n\n";
            system("pause");
        }
    }
}

void add()
 {
    system("cls");
    ofstream outdata;
    outdata.open("project.txt", ios::app);
    if (!outdata) 
	{
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    cout << "Add student ID: ";
    cin >> id[i];
    while (!cin || id[i] < 0)
	 {
        cout << "Invalid input! Please enter a valid student ID: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> id[i];
    }

    cout << "Add Student First Name: ";
    cin >> firstname[i];
    while (!containsOnlyLetters(firstname[i]))
	 {
        cout << "Invalid input! Please enter a valid first name: ";
        cin >> firstname[i];
    }

    cout << "Add Student Last Name: ";
    cin >> lastname[i];
    while (!containsOnlyLetters(lastname[i]))
	 {
        cout << "Invalid input! Please enter a valid last name: ";
        cin >> lastname[i];
    }

    cout << "Add Department: ";
    cin >> department[i];
    while (!containsOnlyLetters(department[i]))
	 {
        cout << "Invalid input! Please enter a valid department: ";
        cin >> department[i];
    }

    outdata << setw(5) << left << id[i] << setw(15) << left << firstname[i] << setw(15) << left << lastname[i]
            << setw(15) << left << department[i] << setw(10) << left << "0" << endl;

    cout << "\n\t Add Student Record Successfully!! " << endl;
    system("pause");
    ++i; // Increment for the next student ...
    outdata.close();
}

void removerec() {
    ifstream indata;
    ofstream outdata;
    indata.open("project.txt");
    outdata.open("temp.txt");
    if (!indata || !outdata) 
	{
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    int idfind;
    cout << "Enter ID to Remove Student: ";
    cin >> idfind;

    bool found = false;
    while (indata >> id[i] >> firstname[i] >> lastname[i] >> department[i]>>marks[i]) 
	{
        if (idfind == id[i]) 
		{
            found = true;
            continue;
        }
        outdata << setw(5) << left << id[i] << setw(15) << left << firstname[i] << setw(15) << left << lastname[i]
                << setw(15) << left << department[i] << setw(10) << left << "0" << endl;
    }
    if (!found)
	 {
        cout << "No Record Found\n";
    } 
	else 
	{
        cout << "Student Removed Successfully\n";
    }
    system("pause");
    indata.close();
    outdata.close();

    remove("project.txt");
    rename("temp.txt", "project.txt");
}

void update() 
{
    ifstream indata;
    ofstream outdata;
    indata.open("project.txt");
    outdata.open("temp.txt");
    if (!indata || !outdata)
	 {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    int idfind;
    string first_name, last_name, depart;
    cout << "Enter ID to update record: ";
    cin >> idfind;
    cout << "Enter first name to update record: ";
    cin >> first_name;
    cout << "Enter Last name to update record: ";
    cin >> last_name;
    cout << "Enter Department to update record: ";
    cin >> depart;

    while (indata >> id[i] >> firstname[i] >> lastname[i] >> department[i]>>marks[i])
	 {
        if (idfind == id[i]) {
            firstname[i] = first_name;
            lastname[i] = last_name;
            department[i] = depart;
        }
        outdata << setw(5) << left << id[i] << setw(15) << left << firstname[i] << setw(15) << left << lastname[i]
                << setw(15) << left << department[i] << setw(10) << left << "0" << endl;
    }
    cout << "Record Updated Successfully\n";
    system("pause");
    indata.close();
    outdata.close();

    remove("project.txt");
    rename("temp.txt", "project.txt");
}

void check() 
{
    ifstream indata("project.txt");
    if (!indata)
	 {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    int idfind;
    cout << "Enter ID to check: ";
    cin >> idfind;

    bool found = false;
    cout << "Records found:\n\n";
    while (indata >> id[i] >> firstname[i] >> lastname[i] >> department[i]>>marks[i]) {
        if (idfind == id[i]) {
            cout << setw(5) << left << id[i] << setw(15) << left << firstname[i] << setw(15) << left << lastname[i]
			 << setw(15) << left << department[i] << endl << endl;
            found = true;
            system("pause");
        }
    }
    if (!found) {
        cout << "Record not found" << endl;
    }
    indata.close();
}

void displayAllRecords() {
    ifstream indata("project.txt");
    if (!indata) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    cout << "\n\n**** All Records ****\n\n";
    cout << setw(5) << left << "ID" << setw(15) << left << "First Name" << setw(15) << left << "Last Name" 
	<< setw(15) << left << "Department" << setw(10) << left << "Marks" << endl;
    cout << "----------------------------------------------------------" << endl;

    int id, marks;
    string firstName, lastName, department;
    while (indata >> id >> firstName >> lastName >> department>>marks) {
        bool found = false;
        for (int j = 0; j < maxstudent; ++j) {
            if (id == ::id[j]) {
                marks = ::marks[j];
                found = true;
                break;
            }
        }
        cout << setw(5) << left << id << setw(15) << left << firstName << setw(15) << left << lastName
	 << setw(15) << left << department << setw(10) << left <<  marks << endl;
    }
    system("pause");
    indata.close();
    cout << endl;
}

void addmarks() {
    system("cls");
    ifstream indata;
    ofstream outdata;
    indata.open("project.txt");
    outdata.open("temp.txt", ios::app);
    if (!indata || !outdata) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    int idfind;
    cout << "Enter student ID: ";
    cin >> idfind;

    bool found = false;
    while (indata >> id[i] >> firstname[i] >> lastname[i] >> department[i]>>marks[i]) {
        if (idfind == id[i]) {
            cout << "Enter Marks to Add (out of 400): ";
            cin >> marks[i];
            if (marks[i] < 0 || marks[i] > 400)
            {
            	cout<<"Enter Valid marks (out of 400): ";
            	cin>>marks[i];
			}
            found = true;
        }
        outdata << setw(5) << left << id[i] << setw(15) << left << firstname[i] << setw(15) << left << lastname[i] 
		<< setw(15) << left << department[i] << setw(10) << left << marks[i] << endl;
    }
    if (!found) {
        cout << "Record Not Found\n";
    }
    outdata.close();
    indata.close();

    remove("project.txt");
    rename("temp.txt", "project.txt");
    system("pause");
}

void student() {
    string username = "student";
    string password = "1234";
    string student, pass;
    bool found = false;
    cout << "Enter Student Username: ";
    cin >> student;
    cout << "Enter Password:";
    cin >> pass;
    if (username == student && password == pass) {
        found = true;
    } else {
        cout << "\nInvalid Input\n";
        cout << "Press Enter to go back to mainpanel\n\n";
        system("pause");
        system("cls");
        mainpanel();
    }
    while (found) {
        system("cls");
        cout << "\n\t *** Welcome to Student Section ****\n\n";
        int choice;
        cout << " 1- Check Information\n\n";
        cout << " 2- Check Result\n\n";
        cout << " 3- Check Course\n\n";
        cout << " 4- Logout\n\n";
        cout << " 5- Exit\n\n";
        cout << " Enter your choice (1 to 5): ";
        cin >> choice;
        cin.ignore(1000,'\n');
        while (1) {
            if (cin.fail()) {
                cout << "\nInvalid Input\n\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter your choice again: ";
            cin>>choice;  
            }
            if (!cin.fail()) {
                break;
            }
        }
        switch(choice) {
        case 1:
            system("cls");
            checkinfo();
            break;
        case 2:
            system("cls");
            checkresult();
            break;
        case 3:
            system("cls");
            checkcourse();
            break;
        case 4:
            system("cls");
            mainpanel();
            break;
        case 5:
            system("cls");
            exit(0);
            break;
        default:
            cout << "Invalid Input\n\n";
            cout << "Press Enter to input Again\n\n";
        }
    }
}

void checkinfo() {
    system("cls");
    ifstream indata;
    indata.open("project.txt");
    if (!indata) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    int idinfo;
    bool found = false;
    cout << "Enter student id : ";
    cin >> idinfo;
    while(indata >> id[i] >> firstname[i] >> lastname[i] >> department[i]) {
        if (idinfo == id[i]) {
            cout << "\n\n Your ID : " << id[i];
            cout << "\n\n Your first Name : " << firstname[i];
            cout << "\n\n Your Last Name : " << lastname[i];
            cout << "\n\n Your Department : " << department[i] << endl << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "\nInvalid Id: \n ";
    }
    system("pause");
    indata.close();
}

void checkresult() {
    system("cls");
    ifstream indata;
    indata.open("project.txt");
    if (!indata) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    int idinfo;
    bool found = false;
    cout << "Enter student id : ";
    cin >> idinfo;
    while(indata >> id[i] >> firstname[i] >> lastname[i] >> department[i])
	 {
        if (idinfo == id[i])
		 {
            cout << "Your Marks: " << marks[i] << endl;
            found = true;
        }
    }
    if (!found) 
	{
        cout << "\nInvalid Id: \n ";
    }
    system("pause");
    indata.close();
}



void checkcourse()
 {
    system("cls");
    ifstream indata;
    indata.open("project.txt");
    if (!indata) 
	{
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    bool found = false;
    string dep;
            cout << "Enter Your Department : ";
            cin >> dep;
            if (dep == "CS" || dep == "cs")
			 {
                system("cls");
                cout << "Your Assigned Courses are : " << endl;
                cout << "1. Programming Fundamentals " << endl;
                cout << "2. English " << endl;
                cout << "3. Logics " << endl;
                cout << "4. Computer Architecture " << endl;
                found = true;
            } 
			else if (dep == "IT" || dep == "it")
			 {
                system("cls");
                cout << "Your Assigned Courses are : " << endl;
                cout << "1. Introduction to IT " << endl;
                cout << "2. Database " << endl;
                cout << "3. Web Designing " << endl;
                cout << "4. Networking " << endl;
                found = true;
            }
			 else 
			{
                system("cls");
                cout << "No Course Found " << endl;
                found = true;
            }
    if (!found)
	 {
        cout << "\nInvalid Id: \n ";
    }
    system("pause");
    indata.close();
}



void teacher() 
{
    string username = "teacher";
    string password = "1234";
    string teacher, pass;
    bool found = false;
    cout << "Enter Teacher Username: ";
    cin >> teacher;
    cout << "Enter Password:";
    cin >> pass;
    if (username == teacher && password == pass) 
	{
        found = true;
    } 
	else 
	{
        cout << "\nInvalid Input\n";
        cout << "Press Enter to go back to mainpanel\n\n";
        system("pause");
        system("cls");
        mainpanel();
    }
    while (found)
	 {
        system("cls");
        cout << "\n\t *** Welcome to Teacher Section ****\n\n";
        int choice;
        cout << " 1- Add Marks\n\n";
        cout << " 2- Logout\n\n";
        cout << " 3- Exit\n\n";
        cout << " Enter your choice (1 to 3): ";
        cin >> choice;
        cin.ignore(1000,'\n');
        while (1)
		 {
            if (cin.fail())
			 {
                cout << "\nInvalid Input\n\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter your choice again: ";
            cin>>choice;
			}         
            if (!cin.fail()) 
			{
            break;
            }
        }
        switch(choice) 
		{
        case 1:
            system("cls");
            addmarks();
            break;
        case 2:
            system("cls");
            mainpanel();
            break;
        case 3:
            system("cls");
            exit(0);
            break;
        default:
            cout << "Invalid Input\n\n";
            cout << "Press Enter to input Again\n\n";
        }
    }
}



bool containsOnlyLetters(const string& str) {
    for (int i = 0; i < str.length(); ++i) {
        if (!isalpha(str[i])) {
            return false;
        }
    }
    return true;
}




