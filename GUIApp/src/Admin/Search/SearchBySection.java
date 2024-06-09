package Admin.Search;

import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public class SearchBySection {

    private JFrame frame;
    private JComboBox<String> sectionComboBox;
    private JTable table;
    private JFrame previousFrame;  // Store the previous form

    // Database configuration
    private static final String DB_URL = "jdbc:mysql://127.0.0.1:3306/timetable";
    private static final String DB_USERNAME = "root";  // MySQL username
    private static final String DB_PASSWORD = "malik";  // MySQL password

    /**
     * Launch the application.
     */
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    SearchBySection window = new SearchBySection(null);  
                    window.show();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    /**
     * Create the application.
     */
    public SearchBySection(JFrame previousFrame) {
        this.previousFrame = previousFrame;
        initialize();
        loadSections();
    }

    /**
     * Show the frame.
     */
    public void show() {
        frame.setVisible(true);
    }

    /**
     * Initialize the contents of the frame.
     */
    private void initialize() {
        frame = new JFrame();
        frame.setBounds(100, 100, 700, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);

        JLabel lblTitle = new JLabel("Search By Section");
        lblTitle.setBounds(300, 20, 200, 30);
        frame.getContentPane().add(lblTitle);

        JLabel lblSection = new JLabel("Section ID:");
        lblSection.setBounds(50, 80, 100, 30);
        frame.getContentPane().add(lblSection);

        sectionComboBox = new JComboBox<>();
        sectionComboBox.setBounds(150, 80, 200, 30);
        frame.getContentPane().add(sectionComboBox);

        JButton btnSearch = new JButton("Search");
        btnSearch.setBounds(370, 80, 100, 30);
        frame.getContentPane().add(btnSearch);

        JScrollPane scrollPane = new JScrollPane();
        scrollPane.setBounds(50, 130, 600, 300);
        frame.getContentPane().add(scrollPane);

        table = new JTable();
        scrollPane.setViewportView(table);

        JButton btnBack = new JButton("Back");
        btnBack.setBounds(480, 80, 100, 30);
        frame.getContentPane().add(btnBack);

        btnSearch.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                searchBySection();
            }
        });

        btnBack.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                frame.dispose();  
                if (previousFrame != null) {
                    previousFrame.setVisible(true);  
                }
            }
        });
    }

    /**
     * Load sections into the combo box.
     */
    private void loadSections() {
        sectionComboBox.addItem("bse_2a");
        sectionComboBox.addItem("bse_2b");
    }

    /**
     * Search by section and populate the table.
     */
    private void searchBySection() {
        if (sectionComboBox.getSelectedItem() == null) {
            JOptionPane.showMessageDialog(frame, "Please select a section.");
            return;
        }

        String sectionTable = sectionComboBox.getSelectedItem().toString();

        try (Connection connection = DriverManager.getConnection(DB_URL, DB_USERNAME, DB_PASSWORD);
             PreparedStatement preparedStatement = connection.prepareStatement("SELECT * FROM " + sectionTable);
             ResultSet resultSet = preparedStatement.executeQuery()) {

            DefaultTableModel model = new DefaultTableModel();
            int columnCount = resultSet.getMetaData().getColumnCount();

            // Add column names
            for (int i = 1; i <= columnCount; i++) {
                model.addColumn(resultSet.getMetaData().getColumnName(i));
            }

            // Add rows
            while (resultSet.next()) {
                Object[] row = new Object[columnCount];
                for (int i = 1; i <= columnCount; i++) {
                    row[i - 1] = resultSet.getObject(i);
                }
                model.addRow(row);
            }

            table.setModel(model);

        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "An error occurred: " + e.getMessage());
        }
    }
}
