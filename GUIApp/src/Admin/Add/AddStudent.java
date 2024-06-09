package Admin.Add;

import javax.swing.*;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;

public class AddStudent {

    private JFrame frame;
    private JTextField studentIDField;
    private JTextField usernameField;
    private JTextField passwordField;
    private JTextField firstNameField;
    private JTextField lastNameField;
    private JTextField emailField;
    private JFrame previousFrame;

    /**
     * Create the application.
     */
    public AddStudent(JFrame previousFrame) {
        this.previousFrame = previousFrame;
        initialize();
    }

    /**
     * Initialize the contents of the frame.
     */
    private void initialize() {
        frame = new JFrame();
        frame.setBounds(100, 100, 450, 400);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);

        JLabel lblAddStudent = new JLabel("Add Student");
        lblAddStudent.setBounds(150, 20, 150, 30);
        frame.getContentPane().add(lblAddStudent);

        JLabel lblStudentID = new JLabel("Student ID:");
        lblStudentID.setBounds(50, 70, 100, 30);
        frame.getContentPane().add(lblStudentID);

        studentIDField = new JTextField();
        studentIDField.setBounds(200, 70, 200, 30);
        frame.getContentPane().add(studentIDField);
        studentIDField.setColumns(10);

        JLabel lblFirstName = new JLabel("First Name:");
        lblFirstName.setBounds(50, 110, 100, 30);
        frame.getContentPane().add(lblFirstName);

        firstNameField = new JTextField();
        firstNameField.setBounds(200, 110, 200, 30);
        frame.getContentPane().add(firstNameField);
        firstNameField.setColumns(10);

        JLabel lblLastName = new JLabel("Last Name:");
        lblLastName.setBounds(50, 150, 100, 30);
        frame.getContentPane().add(lblLastName);

        lastNameField = new JTextField();
        lastNameField.setBounds(200, 150, 200, 30);
        frame.getContentPane().add(lastNameField);
        lastNameField.setColumns(10);

        JLabel lblEmail = new JLabel("Email:");
        lblEmail.setBounds(50, 190, 100, 30);
        frame.getContentPane().add(lblEmail);

        emailField = new JTextField();
        emailField.setBounds(200, 190, 200, 30);
        frame.getContentPane().add(emailField);
        emailField.setColumns(10);

        JLabel lblUsername = new JLabel("Username:");
        lblUsername.setBounds(50, 230, 100, 30);
        frame.getContentPane().add(lblUsername);

        usernameField = new JTextField();
        usernameField.setBounds(200, 230, 200, 30);
        frame.getContentPane().add(usernameField);
        usernameField.setColumns(10);

        JLabel lblPassword = new JLabel("Password:");
        lblPassword.setBounds(50, 270, 100, 30);
        frame.getContentPane().add(lblPassword);

        passwordField = new JTextField();
        passwordField.setBounds(200, 270, 200, 30);
        frame.getContentPane().add(passwordField);
        passwordField.setColumns(10);

        JButton btnSave = new JButton("Save");
        btnSave.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String studentID = studentIDField.getText();
                String firstName = firstNameField.getText();
                String lastName = lastNameField.getText();
                String email = emailField.getText();
                String username = usernameField.getText();
                String password = passwordField.getText();
                addStudent(studentID, firstName, lastName, email, username, password);
            }
        });
        btnSave.setBounds(50, 320, 150, 30);
        frame.getContentPane().add(btnSave);

        JButton btnBack = new JButton("Back");
        btnBack.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                frame.dispose();
                previousFrame.setVisible(true);
            }
        });
        btnBack.setBounds(250, 320, 150, 30);
        frame.getContentPane().add(btnBack);
    }

    private void addStudent(String studentID, String firstName, String lastName, String email, String username, String password) {
        String dbUrl = "jdbc:mysql://127.0.0.1:3306/timetable";
        String dbUsername = "root";  // MySQL username
        String dbPassword = "malik";  // MySQL password

        try (Connection conn = DriverManager.getConnection(dbUrl, dbUsername, dbPassword)) {
            // Check if student already exists
            String checkQuery = "SELECT COUNT(*) FROM student WHERE StudentID = ?";
            PreparedStatement checkStmt = conn.prepareStatement(checkQuery);
            checkStmt.setString(1, studentID);
            ResultSet rs = checkStmt.executeQuery();
            rs.next();
            int count = rs.getInt(1);

            if (count > 0) {
                JOptionPane.showMessageDialog(frame, "Student ID already exists", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }

            // Insert into student table
            String insertStudentQuery = "INSERT INTO student (StudentID, FirstName, LastName, Email) VALUES (?, ?, ?, ?)";
            PreparedStatement insertStudentStmt = conn.prepareStatement(insertStudentQuery);
            insertStudentStmt.setString(1, studentID);
            insertStudentStmt.setString(2, firstName);
            insertStudentStmt.setString(3, lastName);
            insertStudentStmt.setString(4, email);
            insertStudentStmt.executeUpdate();

            // Insert into user table
            String insertUserQuery = "INSERT INTO user (Username, Password, UserType, ForeignID) VALUES (?, ?, ?, ?)";
            PreparedStatement insertUserStmt = conn.prepareStatement(insertUserQuery);
            insertUserStmt.setString(1, username);
            insertUserStmt.setString(2, password);
            insertUserStmt.setString(3, "Student");
            insertUserStmt.setString(4, studentID);
            insertUserStmt.executeUpdate();

            JOptionPane.showMessageDialog(frame, "Student added successfully", "Success", JOptionPane.INFORMATION_MESSAGE);
        } catch (Exception ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Failed to add student: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public void show() {
        frame.setVisible(true);
    }
}
