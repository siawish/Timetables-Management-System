package Admin.Add;

import javax.swing.*;
import java.awt.*;
import java.sql.*;

public class AddSlot {

    private JFrame frame;
    private JComboBox<String> sectionIDcb, dayCb, startTimeCb, teacherIDcb, roomIDcb, courseCodecb;
    private JButton saveButton, backButton;
    private JFrame dash;

    public AddSlot(JFrame frm) {
        initialize();
        this.dash = frm;
        loadComboBoxData();
    }

    private void initialize() {
        frame = new JFrame();
        frame.setBounds(100, 100, 450, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);

        JLabel label1 = new JLabel("ADD SLOT");
        label1.setFont(new Font("Microsoft Sans Serif", Font.BOLD, 16));
        label1.setBounds(160, 10, 120, 30);
        frame.getContentPane().add(label1);

        JLabel label7 = new JLabel("Section ID:");
        label7.setBounds(50, 50, 80, 20);
        frame.getContentPane().add(label7);

        sectionIDcb = new JComboBox<>();
        sectionIDcb.setBounds(150, 50, 200, 20);
        frame.getContentPane().add(sectionIDcb);

        JLabel label6 = new JLabel("DAY:");
        label6.setBounds(50, 80, 80, 20);
        frame.getContentPane().add(label6);

        dayCb = new JComboBox<>(new String[]{"MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY"});
        dayCb.setBounds(150, 80, 200, 20);
        frame.getContentPane().add(dayCb);

        JLabel label5 = new JLabel("Start Time:");
        label5.setBounds(50, 110, 80, 20);
        frame.getContentPane().add(label5);

        startTimeCb = new JComboBox<>(new String[]{"8:00:00", "10:00:00", "12:00:00", "02:00:00", "04:00:00", "06:00:00"});
        startTimeCb.setBounds(150, 110, 200, 20);
        frame.getContentPane().add(startTimeCb);

        JLabel label4 = new JLabel("Teacher ID:");
        label4.setBounds(50, 140, 80, 20);
        frame.getContentPane().add(label4);

        teacherIDcb = new JComboBox<>();
        teacherIDcb.setBounds(150, 140, 200, 20);
        frame.getContentPane().add(teacherIDcb);

        JLabel label2 = new JLabel("Room ID:");
        label2.setBounds(50, 170, 80, 20);
        frame.getContentPane().add(label2);

        roomIDcb = new JComboBox<>();
        roomIDcb.setBounds(150, 170, 200, 20);
        frame.getContentPane().add(roomIDcb);

        JLabel label3 = new JLabel("Course Code:");
        label3.setBounds(50, 200, 80, 20);
        frame.getContentPane().add(label3);

        courseCodecb = new JComboBox<>();
        courseCodecb.setBounds(150, 200, 200, 20);
        frame.getContentPane().add(courseCodecb);

        saveButton = new JButton("Save");
        saveButton.setBounds(150, 230, 80, 30);
        frame.getContentPane().add(saveButton);
        saveButton.addActionListener(e -> saveSlot());

        backButton = new JButton("Back");
        backButton.setBounds(270, 230, 80, 30);
        frame.getContentPane().add(backButton);
        backButton.addActionListener(e -> {
            frame.setVisible(false);
            if (dash != null) {
                dash.setVisible(true);
            }
        });
    }

    private void loadComboBoxData() {
        // JDBC connection details
        String connectionString = "jdbc:mysql://localhost:3306/timetable";

        try (Connection conn = DriverManager.getConnection(connectionString, "root", "malik")) {
            loadComboBoxDataFromDB(conn, "SELECT TeacherID FROM Teacher", teacherIDcb);
            loadComboBoxDataFromDB(conn, "SELECT RoomID FROM Room", roomIDcb);
            loadComboBoxDataFromDB(conn, "SELECT CourseCode FROM Course", courseCodecb);
            loadComboBoxDataFromDB(conn, "SELECT SectionID FROM Sections", sectionIDcb);
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Failed to load data: " + e.getMessage());
        }
    }

    private void loadComboBoxDataFromDB(Connection conn, String query, JComboBox<String> comboBox) throws SQLException {
        try (Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery(query)) {
            while (rs.next()) {
                comboBox.addItem(rs.getString(1));
            }
        }
    }

    private void saveSlot() {
        if (teacherIDcb.getSelectedIndex() == -1 || roomIDcb.getSelectedIndex() == -1 ||
            courseCodecb.getSelectedIndex() == -1 || sectionIDcb.getSelectedIndex() == -1 ||
            dayCb.getSelectedIndex() == -1 || startTimeCb.getSelectedIndex() == -1) {
            JOptionPane.showMessageDialog(frame, "Please fill all the fields before saving.");
            return;
        }

        String teacherID = (String) teacherIDcb.getSelectedItem();
        String roomID = (String) roomIDcb.getSelectedItem();
        String courseCode = (String) courseCodecb.getSelectedItem();
        String sectionID = (String) sectionIDcb.getSelectedItem();
        String day = (String) dayCb.getSelectedItem();
        String startTime = (String) startTimeCb.getSelectedItem();

        String connectionString = "jdbc:mysql://localhost:3306/timetable";

        try (Connection conn = DriverManager.getConnection(connectionString, "root", "malik")) {
            String section = sectionID.equals("1") ? "bse_2a" : "bse_2b";
            String checkQuery = "SELECT COUNT(*) FROM " + section + " WHERE Day = ? AND StartTime = ?";
            try (PreparedStatement checkStmt = conn.prepareStatement(checkQuery)) {
                checkStmt.setString(1, day);
                checkStmt.setString(2, startTime);
                try (ResultSet rs = checkStmt.executeQuery()) {
                    if (rs.next() && rs.getInt(1) > 0) {
                        JOptionPane.showMessageDialog(frame, "This slot is already scheduled at this time and day.");
                        return;
                    }
                }
            }

            String insertQuery = "INSERT INTO " + section + " (CourseID, RoomID, TeacherID, StartTime, Day) VALUES (?, ?, ?, ?, ?)";
            try (PreparedStatement insertStmt = conn.prepareStatement(insertQuery)) {
                insertStmt.setString(1, courseCode);
                insertStmt.setString(2, roomID);
                insertStmt.setString(3, teacherID);
                insertStmt.setString(4, startTime);
                insertStmt.setString(5, day);
                insertStmt.executeUpdate();
                JOptionPane.showMessageDialog(frame, "Timetable slot saved successfully.");
            }
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "An error occurred while saving the timetable slot: " + e.getMessage());
        }
    }

    public void show() {
        frame.setVisible(true);
    }
}
