package Admin.Add;


import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class AddTeacher {

    private JFrame frame;
    private JTextField teacherIDField;
    private JTextField firstNameField;
    private JTextField lastNameField;
    private JTextField emailField;
    private JTextField usernameField;
    private JTextField passwordField;
    private JFrame previousFrame;

    /**
     * Create the application.
     */
    public AddTeacher(JFrame frm) {
        this.previousFrame = frm;
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

        JLabel lblAddTeacher = new JLabel("Add Teacher");
        lblAddTeacher.setBounds(150, 20, 150, 30);
        frame.getContentPane().add(lblAddTeacher);

        JLabel lblTeacherID = new JLabel("Teacher ID:");
        lblTeacherID.setBounds(50, 70, 100, 30);
        frame.getContentPane().add(lblTeacherID);

        teacherIDField = new JTextField();
        teacherIDField.setBounds(200, 70, 200, 30);
        frame.getContentPane().add(teacherIDField);
        teacherIDField.setColumns(10);

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
                String teacherID = teacherIDField.getText();
                String firstName = firstNameField.getText();
                String lastName = lastNameField.getText();
                String email = emailField.getText();
                String username = usernameField.getText();
                String password = passwordField.getText();
                addTeacher(teacherID, firstName, lastName, email, username, password);
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

    private void addTeacher(String teacherID, String firstName, String lastName, String email, String username, String password) {
        String dbUrl = "jdbc:mysql://127.0.0.1:3306/timetable";
        String dbUsername = "root";  // MySQL username
        String dbPassword = "malik";  // MySQL password

        try (Connection conn = DriverManager.getConnection(dbUrl, dbUsername, dbPassword)) {
            // Check if teacher already exists
            String checkQuery = "SELECT COUNT(*) FROM teacher WHERE TeacherID = ?";
            PreparedStatement checkStmt = conn.prepareStatement(checkQuery);
            checkStmt.setString(1, teacherID);
            ResultSet rs = checkStmt.executeQuery();
            rs.next();
            int count = rs.getInt(1);

            if (count > 0) {
                JOptionPane.showMessageDialog(frame, "Teacher ID already exists", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }

            // Insert into teacher table
            String insertTeacherQuery = "INSERT INTO teacher (TeacherID, FirstName, LastName, Email) VALUES (?, ?, ?, ?)";
            PreparedStatement insertTeacherStmt = conn.prepareStatement(insertTeacherQuery);
            insertTeacherStmt.setString(1, teacherID);
            insertTeacherStmt.setString(2, firstName);
            insertTeacherStmt.setString(3, lastName);
            insertTeacherStmt.setString(4, email);
            insertTeacherStmt.executeUpdate();

            // Insert into user table
            String insertUserQuery = "INSERT INTO user (Username, Password, UserType, ForeignID) VALUES (?, ?, ?, ?)";
            PreparedStatement insertUserStmt = conn.prepareStatement(insertUserQuery);
            insertUserStmt.setString(1, username);
            insertUserStmt.setString(2, password);
            insertUserStmt.setString(3, "Teacher");
            insertUserStmt.setString(4, teacherID);
            insertUserStmt.executeUpdate();

            JOptionPane.showMessageDialog(frame, "Teacher added successfully", "Success", JOptionPane.INFORMATION_MESSAGE);
        } catch (Exception ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Failed to add teacher: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public void show() {
        frame.setVisible(true);
    }
}
