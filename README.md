Certainly! Here's the revised version of your project description with corrections and updates to use MySQL and Java Swing:

# TimeTableGenerator

TimeTableGenerator is a Java Swing application developed with Java and MySQL to manage and create timetables for educational institutions. It provides functionalities for administrators, teachers, and students.

## Features

- **Admins**: Add and manage teachers, students, rooms, and sections. Create and modify timetables.
- **Teachers**: View their own timetables and manage availability.
- **Students**: View personal timetables specific to their section.

## Installation

### Prerequisites
- JDK 8 or later
- MySQL Server
- An IDE like IntelliJ IDEA or Eclipse

### Steps
1. **Clone the Repository**
    ```sh
    git clone https://github.com/siawish/Timetables-Management-System-JAVA
    ```
2. **Open the Project**
    - Open the project in your preferred Java IDE.
3. **Configure the Database**
    - Ensure MySQL Server is running.
    - Update the connection string in the project.
    - Execute the provided SQL script in `database_setup.sql` to set up the database schema.
4. **Build and Run**
    - Build the project in your IDE.
    - Run the application from your IDE.

## Database Setup

1. **Create a Database**
    - Use MySQL Workbench or any SQL client to create a new database.
2. **Run the Database Script**
    - Execute the script provided in `database_setup.sql` to create the necessary tables.

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
