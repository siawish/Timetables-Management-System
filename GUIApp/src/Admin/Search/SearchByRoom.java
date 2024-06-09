package Admin.Search;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;

import java.sql.*;

public class SearchByRoom {

    private JFrame frame;
    private JTable dataTable;
    private JComboBox<String> roomComboBox;
    private JComboBox<String> sectionComboBox;
    private JButton searchButton, backButton;
    private JFrame dash;

    public SearchByRoom() {
        initialize();
    }

    public SearchByRoom(JFrame obj) {
        dash = obj;
        initialize();
    }

    private void initialize() {
        frame = new JFrame();
        frame.setBounds(100, 100, 1123, 534);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);

        JLabel label1 = new JLabel("Search By Room");
        label1.setFont(new Font("Microsoft Sans Serif", Font.BOLD, 16));
        label1.setBounds(438, 35, 247, 32);
        frame.getContentPane().add(label1);

        JLabel label2 = new JLabel("Room ID :");
        label2.setBounds(91, 95, 66, 16);
        frame.getContentPane().add(label2);

        JLabel label3 = new JLabel("Section :");
        label3.setBounds(369, 95, 58, 16);
        frame.getContentPane().add(label3);

        roomComboBox = new JComboBox<>();
        roomComboBox.setBounds(91, 125, 200, 24);
        frame.getContentPane().add(roomComboBox);

        sectionComboBox = new JComboBox<>();
        sectionComboBox.setBounds(317, 125, 200, 24);
        frame.getContentPane().add(sectionComboBox);

        searchButton = new JButton("Search");
        searchButton.setBounds(535, 122, 122, 27);
        searchButton.addActionListener(e -> searchByRoomAndSection());
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

        populateRoomComboBox();
        populateSectionComboBox();
    }

    private void populateRoomComboBox() {
        String url = "jdbc:mysql://localhost:3306/timetable";
        String user = "root";
        String password = "malik";

        try (Connection conn = DriverManager.getConnection(url, user, password)) {
            String query = "SELECT RoomID FROM Room";
            Statement stmt = conn.createStatement();
            ResultSet rs = stmt.executeQuery(query);

            while (rs.next()) {
                roomComboBox.addItem(rs.getString("RoomID"));
            }
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(frame, "Error occurred: " + ex.getMessage());
        }
    }

    private void populateSectionComboBox() {
        sectionComboBox.addItem("BSE_2A");
        sectionComboBox.addItem("BSE_2B");
    }

    private void searchByRoomAndSection() {
        String selectedRoom = (String) roomComboBox.getSelectedItem();
        String selectedSection = (String) sectionComboBox.getSelectedItem();

        if (selectedRoom == null || selectedSection == null) {
            JOptionPane.showMessageDialog(frame, "Please select both Room ID and Section.");
            return;
        }

        String url = "jdbc:mysql://localhost:3306/timetable";
        String user = "root";
        String password = "malik";

        try (Connection conn = DriverManager.getConnection(url, user, password)) {
            String query = "SELECT * FROM `" + selectedSection + "` WHERE RoomID = ?";
            PreparedStatement pstmt = conn.prepareStatement(query);
            pstmt.setString(1, selectedRoom);

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
