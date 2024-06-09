# TimeTableGenerator

TimeTableGenerator is a Windows Forms application developed with C++ and SQL to manage and create timetables for educational institutions. It provides functionalities for administrators, teachers, and students.

## Features

- **Admins**: Add and manage teachers, students, rooms, and sections. Create and modify timetables.
- **Teachers**: View their own timetables and manage availability.
- **Students**: View personal timetables specific to their section.

## Installation

### Prerequisites
- Visual Studio 2017 or later
- SQL Server

### Steps
1. **Clone the Repository**
    ```sh
    git clone https://github.com/siawish/TimeTableGenerator.git
    ```
2. **Open the Solution**
    - Open `TimeTableGenerator.sln` in Visual Studio.
3. **Configure the Database**
    - Ensure SQL Server is running.
    - Update the connection string in the project.
    - Execute the provided SQL script in `database_setup.txt` to set up the database schema.
4. **Build and Run**
    - Build the project in Visual Studio.
    - Run the application from Visual Studio.

## Database Setup

1. **Create a Database**
    - Use SQL Server Management Studio (SSMS) or any SQL client to create a new database.
2. **Run the Database Script**
    - Execute the script provided in `database_setup.txt` to create the necessary tables.

## Usage

### Login
- Users login with a username and password.
- The application queries the `Users` table to check credentials.
- Based on the `Role` (Admin, Teacher, or Student), the user is redirected to their respective dashboard.

### Admin Interface
- **Add/Manage Records**: Add or manage teachers, students, rooms, and sections.
- **Create Timetables**: Generate timetables for different sections.

### Teacher Interface
- **View Timetable**: View only your own timetable.
- **Manage Availability**: Update your availability.

### Student Interface
- **View Timetable**: View your section-specific timetable.

### Combo Boxes
- Combo boxes in the application are populated dynamically from the database to ensure they are always up-to-date.

## Database Structure

- **Users**: Stores admin, teacher, and student information.
- **Sections**: Stores information about different sections.
- **Rooms**: Stores room details.
- **Timetables**: Stores generated timetables for each section.



