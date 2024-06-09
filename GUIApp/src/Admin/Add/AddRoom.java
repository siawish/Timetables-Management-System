package Admin.Add;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class AddRoom {

    private JFrame frame;
    private JTextField roomIDField;
    private JTextField roomNumberField;
    private JTextField capacityField;
    private JComboBox<String> typeComboBox;
    private JFrame dash;

    public AddRoom(JFrame frm) {
        this.dash = frm;
        initialize();
    }

    public AddRoom() {
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

        JLabel lblAddRoom = new JLabel("ADD ROOM");
        lblAddRoom.setFont(new Font("Tahoma", Font.BOLD, 16));
        lblAddRoom.setBounds(240, 50, 175, 32);
        frame.getContentPane().add(lblAddRoom);

        JLabel lblRoomID = new JLabel("Room ID:");
        lblRoomID.setBounds(120, 120, 100, 16);
        frame.getContentPane().add(lblRoomID);

        roomIDField = new JTextField();
        roomIDField.setBounds(240, 120, 200, 22);
        frame.getContentPane().add(roomIDField);
        roomIDField.setColumns(10);

        JLabel lblRoomNumber = new JLabel("Room Number:");
        lblRoomNumber.setBounds(120, 160, 100, 16);
        frame.getContentPane().add(lblRoomNumber);

        roomNumberField = new JTextField();
        roomNumberField.setBounds(240, 160, 200, 22);
        frame.getContentPane().add(roomNumberField);
        roomNumberField.setColumns(10);

        JLabel lblCapacity = new JLabel("Capacity:");
        lblCapacity.setBounds(120, 200, 100, 16);
        frame.getContentPane().add(lblCapacity);

        capacityField = new JTextField();
        capacityField.setBounds(240, 200, 200, 22);
        frame.getContentPane().add(capacityField);
        capacityField.setColumns(10);

        JLabel lblType = new JLabel("TYPE:");
        lblType.setBounds(120, 240, 100, 16);
        frame.getContentPane().add(lblType);

        typeComboBox = new JComboBox<>(new String[]{"LAB", "CLASS/ROOM"});
        typeComboBox.setBounds(240, 240, 200, 22);
        frame.getContentPane().add(typeComboBox);

        JButton saveButton = new JButton("Save");
        saveButton.setBounds(240, 320, 100, 30);
        frame.getContentPane().add(saveButton);
        saveButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                saveRoom();
            }
        });

        JButton backButton = new JButton("Back");
        backButton.setBounds(350, 320, 100, 30);
        frame.getContentPane().add(backButton);
        backButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                frame.dispose();
                dash.setVisible(true);
            }
        });
    }

    private void saveRoom() {
        String url = "jdbc:mysql://localhost:3306/timetable";
        String user = "root"; // Add your MySQL username here
        String password = "malik"; // Add your MySQL password here

        try (Connection conn = DriverManager.getConnection(url, user, password)) {
            String checkQuery = "SELECT COUNT(*) FROM room WHERE RoomID = ?";
            PreparedStatement checkPst = conn.prepareStatement(checkQuery);
            checkPst.setString(1, roomIDField.getText());
            ResultSet rs = checkPst.executeQuery();
            if (rs.next() && rs.getInt(1) > 0) {
                JOptionPane.showMessageDialog(frame, "Room ID already exists", "Error", JOptionPane.WARNING_MESSAGE);
                return;
            }

            if (roomIDField.getText().isEmpty()) {
                JOptionPane.showMessageDialog(frame, "Room ID is required", "Error", JOptionPane.WARNING_MESSAGE);
                return;
            }

            String query = "INSERT INTO room (RoomID, RoomNumber, Capacity, Type) VALUES (?, ?, ?, ?)";
            PreparedStatement pst = conn.prepareStatement(query);
            pst.setString(1, roomIDField.getText());
            pst.setString(2, roomNumberField.getText());
            pst.setString(3, capacityField.getText());
            pst.setString(4, (String) typeComboBox.getSelectedItem());

            pst.executeUpdate();
            JOptionPane.showMessageDialog(frame, "Room added successfully", "Success", JOptionPane.INFORMATION_MESSAGE);
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(frame, "Failed to add room: " + e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public JFrame getFrame() {
        return frame;
    }

    public void show() {
        frame.setVisible(true);
    }
}
