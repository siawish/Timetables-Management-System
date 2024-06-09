package Admin.Add;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class AddCourse {

    private JFrame frame;
    private JTextField courseIDField;
    private JTextField courseNameField;
    private JTextField courseCodeField;
    private JTextField descriptionField;
    private JTextField creditHoursField;
    private JFrame dash;

    public AddCourse(JFrame frm) {
        this.dash = frm;
        initialize();
    }

    /**
     * Initialize the contents of the frame.
     */
    private void initialize() {
        frame = new JFrame();
        frame.setBounds(100, 100, 600, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);

        JLabel lblAddCourse = new JLabel("ADD Course");
        lblAddCourse.setFont(new Font("Tahoma", Font.BOLD, 16));
        lblAddCourse.setBounds(240, 50, 181, 32);
        frame.getContentPane().add(lblAddCourse);

        JLabel lblCourseID = new JLabel("Course ID:");
        lblCourseID.setBounds(120, 120, 100, 16);
        frame.getContentPane().add(lblCourseID);

        courseIDField = new JTextField();
        courseIDField.setBounds(220, 120, 200, 22);
        frame.getContentPane().add(courseIDField);
        courseIDField.setColumns(10);

        JLabel lblCourseName = new JLabel("Course Name:");
        lblCourseName.setBounds(120, 160, 100, 16);
        frame.getContentPane().add(lblCourseName);

        courseNameField = new JTextField();
        courseNameField.setBounds(220, 160, 200, 22);
        frame.getContentPane().add(courseNameField);
        courseNameField.setColumns(10);

        JLabel lblCourseCode = new JLabel("Course Code:");
        lblCourseCode.setBounds(120, 200, 100, 16);
        frame.getContentPane().add(lblCourseCode);

        courseCodeField = new JTextField();
        courseCodeField.setBounds(220, 200, 200, 22);
        frame.getContentPane().add(courseCodeField);
        courseCodeField.setColumns(10);

        JLabel lblDescription = new JLabel("Description (if any):");
        lblDescription.setBounds(120, 240, 120, 16);
        frame.getContentPane().add(lblDescription);

        descriptionField = new JTextField();
        descriptionField.setBounds(220, 240, 200, 22);
        frame.getContentPane().add(descriptionField);
        descriptionField.setColumns(10);

        JLabel lblCreditHours = new JLabel("Credit Hours:");
        lblCreditHours.setBounds(120, 280, 100, 16);
        frame.getContentPane().add(lblCreditHours);

        creditHoursField = new JTextField();
        creditHoursField.setBounds(220, 280, 200, 22);
        frame.getContentPane().add(creditHoursField);
        creditHoursField.setColumns(10);

        JButton saveButton = new JButton("Save");
        saveButton.setBounds(220, 320, 100, 30);
        frame.getContentPane().add(saveButton);
        saveButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                saveCourse();
            }
        });

        JButton backButton = new JButton("Back");
        backButton.setBounds(340, 320, 80, 30);
        frame.getContentPane().add(backButton);
        backButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                frame.dispose();
                dash.setVisible(true);
            }
        });
    }

    private void saveCourse() {
        String url = "jdbc:mysql://localhost:3306/timetable";
        String user = "root"; // Add your MySQL username here
        String password = "malik"; // Add your MySQL password here

        try (Connection conn = DriverManager.getConnection(url, user, password)) {
            String query = "INSERT INTO course (CourseID, CourseName, CourseCode, Description, CreditHours) VALUES (?, ?, ?, ?, ?)";

            PreparedStatement pst = conn.prepareStatement(query);
            pst.setString(1, courseIDField.getText());
            pst.setString(2, courseNameField.getText());
            pst.setString(3, courseCodeField.getText());
            pst.setString(4, descriptionField.getText());
            pst.setString(5, creditHoursField.getText());

            pst.executeUpdate();
            JOptionPane.showMessageDialog(frame, "Course added successfully", "Success", JOptionPane.INFORMATION_MESSAGE);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "Failed to add course: " + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public JFrame getFrame() {
        return frame;
    }

    public void show() {
        frame.setVisible(true);
    }
}
