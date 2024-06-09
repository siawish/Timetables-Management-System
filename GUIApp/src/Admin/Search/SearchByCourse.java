package Admin.Search;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.sql.*;

public class SearchByCourse {

    private JFrame frame;
    private JTable dataTable;
    private JComboBox<String> courseComboBox;
    private JButton searchButton, backButton;
    private JFrame dash;

    public SearchByCourse() {
        initialize();
    }

    public SearchByCourse(JFrame obj) {
        dash = obj;
        initialize();
    }

    private void initialize() {
        frame = new JFrame();
        frame.setBounds(100, 100, 1123, 534);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);

        JLabel label1 = new JLabel("Search By Course");
        label1.setFont(new Font("Microsoft Sans Serif", Font.BOLD, 16));
        label1.setBounds(438, 35, 247, 32);
        frame.getContentPane().add(label1);

        JLabel label2 = new JLabel("Course ID :");
        label2.setBounds(91, 95, 73, 16);
        frame.getContentPane().add(label2);

        courseComboBox = new JComboBox<>();
        courseComboBox.setBounds(91, 125, 400, 24);
        frame.getContentPane().add(courseComboBox);

        searchButton = new JButton("Search");
        searchButton.setBounds(535, 122, 122, 27);
        searchButton.addActionListener(e -> searchByCourse());
        frame.getContentPane().add(searchButton);

        backButton = new JButton("Back");
        backButton.setBounds(676, 121, 122, 27);
        backButton.addActionListener(e -> {
            frame.setVisible(false);
            if (dash != null) {
                dash.setVisible(true);
            }
        });
        frame.getContentPane().add(backButton);

        JScrollPane scrollPane = new JScrollPane();
        scrollPane.setBounds(38, 164, 996, 367);
        frame.getContentPane().add(scrollPane);

        dataTable = new JTable();
        scrollPane.setViewportView(dataTable);

        populateCourseComboBox();
    }

    private void populateCourseComboBox() {
        String url = "jdbc:mysql://localhost:3306/timetable";
        String user = "root";
        String password = "malik";

        try (Connection conn = DriverManager.getConnection(url, user, password)) {
            String query = "SELECT CourseID, CourseName FROM course";
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(query);

            while (rs.next()) {
                String courseID = rs.getString("CourseID");
                String courseName = rs.getString("CourseName");
                courseComboBox.addItem(courseID + " - " + courseName);
            }
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(frame, "Error occurred: " + ex.getMessage());
        }
    }

    private void searchByCourse() {
        String selectedItem = (String) courseComboBox.getSelectedItem();
        if (selectedItem == null) {
            JOptionPane.showMessageDialog(frame, "Please select a Course ID.");
            return;
        }

        String courseID = selectedItem.split("-")[0].trim();

        String url = "jdbc:mysql://localhost:3306/timetable";
        String user = "root";
        String password = "malik";

        try (Connection conn = DriverManager.getConnection(url, user, password)) {
            String query = "SELECT * FROM `bse_2a` WHERE CourseID = ? UNION SELECT * FROM `bse_2b` WHERE CourseID = ?";
            PreparedStatement pstmt = conn.prepareStatement(query);
            pstmt.setString(1, courseID);
            pstmt.setString(2, courseID);

            ResultSet rs = pstmt.executeQuery();
            ResultSetMetaData metaData = rs.getMetaData();

            DefaultTableModel model = new DefaultTableModel();
            int columnCount = metaData.getColumnCount();
            for (int i = 1; i <= columnCount; i++) {
                model.addColumn(metaData.getColumnName(i));
            }

            while (rs.next()) {
                Object[] row = new Object[columnCount];
                for (int i = 1; i <= columnCount; i++) {
                    row[i - 1] = rs.getObject(i);
                }
                model.addRow(row);
            }

            dataTable.setModel(model);
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(frame, "Error occurred: " + ex.getMessage());
        }
    }

    public void show() {
        frame.setVisible(true);
    }
}
