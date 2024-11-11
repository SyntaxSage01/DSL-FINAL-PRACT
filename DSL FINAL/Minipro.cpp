/*
GROUP MEMBERS
Rutuja Bambale-07
Kashvi Goyal-15
Nirvahita Devkate-24
Shweta Korekar-25
Class- SE-2(P- Batch)
*/

//MINI PROJECT ON LIBRARY MANAGEMENT SYSTEM

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
// Constants
const int MAX_NAME_LENGTH = 50;
// Student structure
struct Student {
int roll;
char name[MAX_NAME_LENGTH];
double balance;
Student* next;
};
// Book structure
struct Book {
int isbn;
char title[MAX_NAME_LENGTH];
char author[MAX_NAME_LENGTH];
bool available;
Book* next;
};
// Global variables
Student* student_head = nullptr;
Book* book_head = nullptr;
// Function prototypes
void create_account();
void display(int roll);
void deposit_amount(int roll, double amount);
void issue_item(int roll);
void display_sorted();
Student* find_student(int roll);
Book* find_book(int isbn);
void add_book();
void edit_book();
void view_books();
int main() {
int option;
bool is_admin;
string password;
while (true) {
cout << "Login as:\n1. Admin\n2. Student\n0. Exit\n";
cin >> option;
if (option == 0) {
break;
}
is_admin = (option == 1);
cout << "Enter password(as password): ";
cin >> password;
if (password == "password") { // Simple password for demonstration
if (is_admin) {
cout << "Admin options:\n1. Add book\n2. Edit book\n3. View book
status\n4. View enrolled students\n5. View student balance\n";
cin >> option;
switch (option) {
case 1: add_book(); break;
case 2: edit_book(); break;
case 3: view_books(); break;
case 4: display_sorted(); break;
case 5: {
int roll;
cout << "Enter student roll number: ";
cin >> roll;
display(roll);
break;
}
}
} else {
int roll;
cout << "Enter your roll number: ";
cin >> roll;
Student* student = find_student(roll);
if (!student) {
cout << "Student not found. Create an account? (1. Yes / 2.
No): ";
cin >> option;
if (option == 1) {
create_account();
}
} else {
cout << "Student options:\n1. View balance\n2. Deposit
amount\n3. Issue item\n";
cin >> option;
switch (option) {
case 1: display(roll); break;
case 2: {
double amount;
cout << "Enter the amount to deposit: ";
cin >> amount;
deposit_amount(roll, amount);
break;
}
case 3: issue_item(roll); break;
}
}
}
} else {
cout << "Incorrect password.\n";
}
}
return 0;
}
void create_account() {
int roll;
cout << "Enter roll number : ";
cin >> roll;
if (find_student(roll)) {
cout << "Account already exists for this roll number.\n";
return;
}
Student* new_student = new Student;
new_student->roll = roll;
cout << "Enter student name: ";
cin.ignore();
cin.getline(new_student->name, MAX_NAME_LENGTH);
double initial_deposit;
cout << "Enter initial deposit amount ($50 minimum): ";
cin >> initial_deposit;
if (initial_deposit < 50) {
cout << "Initial deposit must be at least $50.\n";
delete new_student; // Avoid memory leak
return;
}
new_student->balance = initial_deposit - 20 - 30; // Account opening and
security deposit
new_student->next = student_head;
student_head = new_student;
}
void display(int roll) {
Student* student = find_student(roll);
if (!student) {
cout << "Student not found.\n";
return;
}
cout << "Roll No: " << student->roll << endl;
cout << "Name: " << student->name << endl;
cout << "Balance: $" << fixed << setprecision(2) << student->balance << endl;
}
void deposit_amount(int roll, double amount) {
Student* student = find_student(roll);
if (!student) {
cout << "Student not found.\n";
return;
}
student->balance += amount;
cout << "New balance: $" << fixed << setprecision(2) << student->balance <<
endl;
}
void issue_item(int roll) {
Student* student = find_student(roll);
if (!student) {
cout << "Student not found.\n";
return;
}
cout << "Available books:\n";
Book* current_book = book_head;
while (current_book) {
if (current_book->available) {
cout << current_book->isbn << ". " << current_book->title << " by " <<
current_book->author << endl;
}
current_book = current_book->next;
}
int choice;
cout << "Enter the ISBN of the book you want to issue (0 to cancel): ";
cin >> choice;
Book* book = find_book(choice);
if (choice == 0 || !book) {
return; // Cancel or book not found
}
if (book->available && student->balance >= 2) {
book->available = false;
student->balance -= 2;
cout << "Book issued successfully. New balance: $" << fixed <<
setprecision(2) << student->balance << endl;
} else {
cout << "Cannot issue the book. Insufficient balance or book is
unavailable.\n";
}
}
void display_sorted() {
Student* current = student_head;
// Collect students into an array for sorting
Student* students[MAX_NAME_LENGTH];
int count = 0;
while (current) {
students[count++] = current;
current = current->next;
}
// Simple bubble sort by roll number
for (int i = 0; i < count - 1; i++) {
for (int j = 0; j < count - i - 1; j++) {
if (students[j]->roll > students[j + 1]->roll) {
swap(students[j], students[j + 1]);
}
}
}
// Display sorted students
for (int i = 0; i < count; i++) {
cout << students[i]->roll << " - " << students[i]->name << " - Balance: $"
<< fixed << setprecision(2) << students[i]->balance << endl;
}
}
Student* find_student(int roll) {
Student* current = student_head;
while (current) {
if (current->roll == roll) {
return current;
}
current = current->next;
}
return nullptr;
}
Book* find_book(int isbn) {
Book* current = book_head;
while (current) {
if (current->isbn == isbn) {
return current;
}
current = current->next;
}
return nullptr;
}
void add_book() {
Book* new_book = new Book;
cout << "Enter book title: ";
cin.ignore();
cin.getline(new_book->title, MAX_NAME_LENGTH);
cout << "Enter book author: ";
cin.getline(new_book->author, MAX_NAME_LENGTH);
int isbn;
cout << "Enter book ISBN: ";
cin >> isbn;
if (find_book(isbn)) {
cout << "A book with this ISBN already exists.\n";
delete new_book; // Avoid memory leak
return;
}
new_book->isbn = isbn;
new_book->available = true;
new_book->next = book_head;
book_head = new_book;
}
void edit_book() {
int isbn;
cout << "Enter book ISBN to edit: ";
cin >> isbn;
Book* book = find_book(isbn);
if (!book) {
cout << "Book not found.\n";
return;
}
cout << "Current book title: " << book->title << endl;
cout << "Enter new book title: ";
cin.ignore();
cin.getline(book->title, MAX_NAME_LENGTH);
cout << "Current book author: " << book->author << endl;
cout << "Enter new book author: ";
cin.getline(book->author, MAX_NAME_LENGTH);
cout << "Book details updated.\n";
}
void view_books() {
Book* current = book_head;
if (!current) {
cout << "No books available.\n";
return;
}
while (current) {
cout << "Title: " << current->title << endl;
cout << "Author: " << current->author << endl;
cout << "ISBN: " << current->isbn << endl;
cout << "Available: " << (current->available ? "Yes" : "No") << endl <<
endl;
current = current->next;
}
}
/* 
OUTPUT
Login as:
1. Admin
2. Student
0. Exit
1
Enter password(as password): password
Admin options:
1. Add book
2. Edit book
3. View book status
4. View enrolled students
5. View student balance
1
Enter book title: Harry Potter
Enter book author: J.K Rowling
Enter book ISBN: 24
Login as:
1. Admin
2. Student
0. Exit
1
Enter password(as password): password
Admin options:
1. Add book
2. Edit book
3. View book status
4. View enrolled students
5. View student balance
1
Enter book title: verity
Enter book author: collen hoover
Enter book ISBN: 45
Login as:
1. Admin
2. Student
0. Exit
1
Enter password(as password): password
Admin options:
1. Add book
2. Edit book
3. View book status
4. View enrolled students
5. View student balance
4
Login as:
1. Admin
2. Student
0. Exit
2
Enter password(as password): password
Enter your roll number: 23
Student not found. Create an account? (1. Yes / 2. No): 1
Enter roll number (format): 23
Enter student name: Kashvi
Enter initial deposit amount ($50 minimum): 450
Login as:
1. Admin
2. Student
0. Exit
2
Enter password(as password): password
Enter your roll number: 23
Student options:
1. View balance
2. Deposit amount
3. Issue item
3
Available books:
45. verity by collen hoover
24. Harry Potter by J.K Rowling
Enter the ISBN of the book you want to issue (0 to cancel): 45
Book issued successfully. New balance: $398.00
Login as:
1. Admin
2. Student
0. Exit
1
Enter password(as password): password
Admin options:
1. Add book
2. Edit book
3. View book status
4. View enrolled students
5. View student balance
5
Enter student roll number: 23
Roll No: 23
Name: Kashvi
Balance: $398.00
Login as:
1. Admin
2. Student
0. Exit
*/