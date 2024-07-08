 University Management System

Welcome to the **University Management System** project, a C++ console application designed to manage student records for a fictional university. This application allows administrators, teachers, and students to interact with the system to manage and view student information.

 Table of Contents

- [Features](#features)
- [Prerequisites](#prerequisites)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Code Overview](#code-overview)
- [Contributing](#contributing)
- [License](#license)

 Features

- Admin Panel:
  - Add, remove, and update student records.
  - View all student records.
  
- Teacher Panel:
  - Add student marks.

- Student Panel:
  - Check personal information.
  - Check results.
  - Check assigned courses.

 Prerequisites

- A C++ compiler (such as GCC or Visual Studio)
- Basic knowledge of C++ and command-line operations

 Getting Started

1. Clone the Repository:

   git clone https://github.com/Maryam-Amir00/PF_PROJECT_University_Management_System.git
   

2. Navigate to the Project Directory:
   
   cd university-management-system
  

3. Compile the Program:
   
   g++ -o university_management_system main.cpp
   

4. Run the Executable:
   
   ./university_management_system
  

Usage

Upon running the program, you will be presented with a main menu:

!-------------- University Management System --------------!

     **** Superior University ****

  1- Admin

  2- Student

  3- Teacher

  4- Exit

 Enter your choice (1 to 4):

- **Admin**: Login with username `admin` and password `1234`. Admins can manage student records.
- **Student**: Login with username `student` and password `1234`. Students can view their information and results.
- **Teacher**: Login with username `teacher` and password `1234`. Teachers can add marks for students.

 Admin Panel
Admins have access to options for adding, removing, updating, and viewing student records.

 Teacher Panel
Teachers can add marks for students.

 Student Panel
Students can check their information, results, and courses.

 File Structure

The project consists of the following main files:

- `main.cpp`: The primary C++ file containing the program's logic.
- `project.txt`: A text file used to store student records.
- `temp.txt`: A temporary file used during record updates and deletions.

 Code Overview

 Key Functions

- **`mainpanel()`**: Displays the main menu and handles user selection.
- **`admin()`**: Admin panel for managing student records.
- **`add()`**: Adds a new student record.
- **`removerec()`**: Removes a student record.
- **`update()`**: Updates a student record.
- **`check()`**: Checks and displays a specific student's record.
- **`displayAllRecords()`**: Displays all student records.
- **`addmarks()`**: Adds marks for a student.
- **`student()`**: Student panel for viewing information and results.
- **`checkinfo()`**: Displays student's information.
- **`checkresult()`**: Displays student's results.
- **`checkcourse()`**: Displays assigned courses based on the department.
- **`teacher()`**: Teacher panel for managing marks.
- **`containsOnlyLetters()`**: Helper function to validate input strings.

 Error Handling

The program includes basic error handling to ensure valid inputs, including checks for valid student IDs, names, and departments.

 Contributing

We welcome contributions to enhance this project! Feel free to fork the repository, make improvements, and submit a pull request. Please ensure that your changes are well-documented.
