package Admin.Search;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.*;
import java.util.Vector;

public class SearchByTeacher {

    private JFrame frame;
    private JComboBox<String> teacherComboBox;
    private JComboBox<String> sectionComboBox;
    private JButton searchButton;
    private JTable dataTable;
    private JButton closeButton;
    private JFrame previousFrame;

    // Database connection details
    private static final String DB_URL = "jdbc:mysql://127.0.0.1:3306/timetable";
    private static final String DB_USERNAME = "root";  // MySQL username
    private static final String DB_PASSWORD = "malik";  // MySQL password

    /**
     * Launch the application.
     */
    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            try {
                SearchByTeacher window = new SearchByTeacher(new JFrame());
                window.frame.setVisible(true);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    /**
     * Create the application.
     */
    public SearchByTeacher(JFrame previousFrame) {
        this.previousFrame = previousFrame;
        initialize();
        populateTeacherComboBox();
        populateSectionComboBox();
    }

    /**
     * Initialize the contents of the frame.
     */
    private void initialize() {
        frame = new JFrame();
        frame.setBounds(100, 100, 1068, 556);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);

        teacherComboBox = new JComboBox<>();
        teacherComboBox.setBounds(36, 116, 200, 24);
        frame.getContentPane().add(teacherComboBox);

        sectionComboBox = new JComboBox<>();
        sectionComboBox.setBounds(264, 116, 200, 24);
        frame.getContentPane().add(sectionComboBox);

        searchButton = new JButton("Search");
        searchButton.setBounds(505, 116, 122, 27);
        frame.getContentPane().add(searchButton);
        searchButton.addActionListener(this::searchByTeacherButtonActionPerformed);

        dataTable = new JTable();
        JScrollPane scrollPane = new JScrollPane(dataTable);
        scrollPane.setBounds(36, 165, 996, 367);
        frame.getContentPane().add(scrollPane);

        JLabel titleLabel = new JLabel("Search By Teacher");
        titleLabel.setFont(new Font("Microsoft Sans Serif", Font.BOLD, 16));
        titleLabel.setBounds(406, 38, 272, 32);
        frame.getContentPane().add(titleLabel);

        JLabel teacherLabel = new JLabel("Teacher ID:");
        teacherLabel.setBounds(94, 87, 77, 16);
        frame.getContentPane().add(teacherLabel);

        JLabel sectionLabel = new JLabel("Section ID:");
        sectionLabel.setBounds(327, 87, 71, 16);
        frame.getContentPane().add(sectionLabel);

        closeButton = new JButton("Close");
        closeButton.setBounds(658, 116, 122, 27);
        frame.getContentPane().add(closeButton);
        closeButton.addActionListener(this::closeButtonActionPerformed);
    }

    private void populateTeacherComboBox() {
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USERNAME, DB_PASSWORD);
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery("SELECT TeacherID FROM teacher")) {

            while (rs.next()) {
                teacherComboBox.addItem(rs.getString("TeacherID"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Error loading teachers: " + e.getMessage());
        }
    }

    private void populateSectionComboBox() {
        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USERNAME, DB_PASSWORD);
             Statement stmt = conn.createStatement();
             ResultSet rs = stmt.executeQuery("SELECT SectionName FROM sections")) {

            while (rs.next()) {
                sectionComboBox.addItem(rs.getString("SectionName"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Error loading sections: " + e.getMessage());
        }
    }

    private void searchByTeacherButtonActionPerformed(ActionEvent e) {
        String selectedTeacherID = (String) teacherComboBox.getSelectedItem();
        String selectedSectionName = (String) sectionComboBox.getSelectedItem();
        String sectionTable = "";

        if ("BSE-2A".equals(selectedSectionName)) {
            sectionTable = "BSE_2A";
        } else if ("BSE-2B".equals(selectedSectionName)) {
            sectionTable = "BSE_2B";
        }

        try (Connection conn = DriverManager.getConnection(DB_URL, DB_USERNAME, DB_PASSWORD);
             PreparedStatement ps = conn.prepareStatement("SELECT * FROM " + sectionTable + " WHERE TeacherID = ?")) {

            ps.setString(1, selectedTeacherID);
            ResultSet rs = ps.executeQuery();

            dataTable.setModel(buildTableModel(rs));
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(frame, "Error occurred: " + ex.getMessage());
            ex.printStackTrace();
        }
    }

    private void closeButtonActionPerformed(ActionEvent e) {
        previousFrame.setVisible(true);
        frame.dispose();
    }

    private static DefaultTableModel buildTableModel(ResultSet rs) throws SQLException {
        ResultSetMetaData metaData = rs.getMetaData();

        // Names of columns
        Vector<String> columnNames = new Vector<>();
        int columnCount = metaData.getColumnCount();
        for (int column = 1; column <= columnCount; column++) {
            columnNames.add(metaData.getColumnName(column));
        }

        // Data of the table
        Vector<Vector<Object>> data = new Vector<>();
        while (rs.next()) {
            Vector<Object> vector = new Vector<>();
            for (int columnIndex = 1; columnIndex <= columnCount; columnIndex++) {
                vector.add(rs.getObject(columnIndex));
            }
            data.add(vector);
        }

        return new DefaultTableModel(data, columnNames);
    }

    public void show() {
        frame.setVisible(true);
    }
}
