//including header files
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

//function declaration
void project();
void add_data();
void display_data();
void delete_data();
void get_trash();


//defining student class
class student
{
    //initiating member variables
    int addmission_no;
    char student_name[20];
    char student_gender;
    int std;
    float student_marks;
    double student_percentage;

    public:

        //initiating members of the class
        void get_data();
        void show_data();
        int get_admission_no()
        {
            return addmission_no;
        }

}s; //s is a object of student class

//initiating main function
int main()
{
    project();

    return 0;

}

//decleration of project function
void project()
{
    int ch;

    do
    {   
        //outputing the user base interface for this systerm
        system("cls"); //clearing the terminal

        cout << "********************STUDENT MANAGEMENT SYSTERM********************" << endl;

        cout << "1. Write Student Record" << endl;

		cout << "2. Read Student Record" << endl;

		cout << "3. Delete Student Record" << endl;

		cout << "4. Get Deleted Records" << endl;

		cout << "0. Exit" << endl;

		cout << "Enter your choice: ";

        system("cls");
    
    switch (ch)

		{
		case 1: add_data(); // add student data to file - stu.txt
			    break;

		case 2: display_data();  // read data from file - stu.txt
			    break;

		case 3: delete_data(); // remove data from - stu.txt and store in Trash.txt  
			    break;

		case 4: get_trash();  // add data from Trash.txt to stu.txt
   			  break;
		}

    //pause system untill user enter anything    
    system("pause");
    }while (ch);
}

//to get data from the user
void student::get_data()
{
    cout << endl << endl << "**********ENTER STUDENT DATA**********" << endl;

    //getting user inputs for details of the student
    cout << "Addmission no : " ; cin >> addmission_no;

    cout << "Full Name: "; cin.getline(student_name, 20);

	cout << "Gender (M/F): "; cin >> student_gender;

	cout << "Class: "; cin >> std;

	cout << "Total Marks (/500): "; cin >> student_marks;

    cout << endl;

    student_percentage = student_marks /5 ; 

}

//to show data for the user
void student::show_data()
{
    cout << endl << endl << "**********STUDENT DATA**********" << endl;

    //display the details of the student
    cout << "Addmission no : " << addmission_no << endl;

    cout << "Full Name: " << student_name << endl;

	cout << "Gender (M/F): " << student_gender << endl;

	cout << "Class: " <<  std << endl;

	cout << "Total Marks (/500): " <<  student_marks << endl;

    cout << "Average: " << student_percentage << endl;

}

//add data to a file 
void add_data()
{   
    //calling inpput stream
    ofstream output_file;

    //operning the file in input mode and write data in binary mode
    output_file.open("detail.txt",ios :: out | ios :: binary);

    //get data from get data function
    s.get_data();

    //write student details in student class to output file
    output_file.write((char*)&s, sizeof(s));

    //close the output file
    output_file.close();

    cout << "\n\n*******Data Successfully Saved to File*******\n";

}

void display_data()
{
    //calling imput stream
    ifstream data_file;

    //opening the data dile in input mode
    data_file.open("detail.txt" , ios :: in | ios :: binary );

    //read the data from the data file
    while (data_file.read((char*)&s , sizeof(s)))
    {
        //calling from data method in student class
        s.show_data();
    }

    //close the data file
    data_file.close();

    cout <<  "\n\n******Data Reading from File Successfully Done*****\n";

}

void delete_data()
{
    ifstream data_file;
    ofstream temp_file , trash_file;

    data_file.open("detail.txt" , ios :: in | ios :: binary);
    temp_file.open("temp.txt" , ios :: out | ios :: binary);
    trash_file.open("trash.txt" , ios :: out | ios :: binary);

    
}