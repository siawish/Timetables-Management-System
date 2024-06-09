import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JComboBox;
import javax.swing.JButton;
import javax.swing.JOptionPane;

import Admin.Add.AddCourse;
import Admin.Add.AddRoom;
import Admin.Add.AddSlot;
import Admin.Add.AddStudent;
import Admin.Add.AddTeacher;
import Admin.Search.SearchByCourse;
import Admin.Search.SearchByRoom;
import Admin.Search.SearchBySection;
import Admin.Search.SearchByTeacher;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Font;

public class AdminDash {

    private JFrame frame;
    private JComboBox<String> addComboBox;
    private JComboBox<String> viewComboBox;

    /**
     * Create the application.
     */
    public AdminDash() {
        initialize();
    }

    /**
     * Initialize the contents of the frame.
     */
    private void initialize() {
        frame = new JFrame();
        frame.setBounds(100, 100, 600, 400); 
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);

        JLabel lblAdminDashboard = new JLabel("Admin Dashboard");
        lblAdminDashboard.setFont(new Font("Tahoma", Font.PLAIN, 20));
        lblAdminDashboard.setBounds(223, 21, 158, 30);
        frame.getContentPane().add(lblAdminDashboard);

        JLabel lblAdd = new JLabel("Add:");
        lblAdd.setBounds(21, 105, 80, 25);
        frame.getContentPane().add(lblAdd);

        String[] addOptions = {"", "Add Slot", "Add Teacher", "Add Course", "Add Room", "Add Student"};
        addComboBox = new JComboBox<>(addOptions);
        addComboBox.setBounds(71, 105, 200, 25);
        frame.getContentPane().add(addComboBox);

        JLabel lblView = new JLabel("View:");
        lblView.setBounds(302, 105, 80, 25);
        frame.getContentPane().add(lblView);

        String[] viewOptions = {"", "Search By Day", "Search By Course", "Search By Room", "Search As Teacher", "Search As Student", "Search By Section"};
        viewComboBox = new JComboBox<>(viewOptions);
        viewComboBox.setBounds(352, 105, 200, 25);
        frame.getContentPane().add(viewComboBox);

        JButton btnSelect = new JButton("Select");
        btnSelect.setBounds(71, 210, 395, 30);
        frame.getContentPane().add(btnSelect);

        JButton btnBack = new JButton("Back");
        btnBack.setBounds(476, 210, 100, 30);
        frame.getContentPane().add(btnBack);

        btnSelect.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                handleSelection();
            }
        });

        btnBack.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                handleBack();
            }
        });
    }

    private void handleSelection() {
        String addOption = (String) addComboBox.getSelectedItem();
        String viewOption = (String) viewComboBox.getSelectedItem();

        if (!addOption.isEmpty()) {
            switch (addOption) {
                case "Add Slot":
                	AddSlot AddSlot=new AddSlot(frame);
                	frame.setVisible(false);
                	AddSlot.show();
                    
                    break;
                case "Add Teacher":
                	AddTeacher AddTeacher= new AddTeacher(frame);
                    frame.setVisible(false);  
                    AddTeacher.show();
                    
                    break;
                case "Add Course":
                	AddCourse AddCourse= new AddCourse(frame);
                    frame.setVisible(false);  
                    AddCourse.show();
                   
                    break;
                case "Add Room":
                	AddRoom AddRoom = new AddRoom(frame);
                	frame.setVisible(false);
                	AddRoom.show();
                    JOptionPane.showMessageDialog(frame, "Add Room Form");
                    break;
                case "Add Student":
                	AddStudent AddStudent=new AddStudent(frame);
                	frame.setVisible(false);
                	AddStudent.show();
                	
                    
                    break;
                default:
                    JOptionPane.showMessageDialog(frame, "Please select a valid option", "Error", JOptionPane.ERROR_MESSAGE);
                    break;
            }
        } else if (!viewOption.isEmpty()) {
            switch (viewOption) {
                case "Search By Day":
                	
                    JOptionPane.showMessageDialog(frame, "Search By Day Form");
                    break;
                case "Search By Course":
                	SearchByCourse SearchByCourse = new SearchByCourse(frame);
                	frame.setVisible(false);
                	SearchByCourse.show();
                   
                    break;
                case "Search By Room":
                	
                	SearchByRoom SearchByRoom = new SearchByRoom(frame);
                	frame.setVisible(false);
                	SearchByRoom.show();
                    
                    break;
                case "Search As Teacher":
                	SearchByTeacher SearchByteacher = new SearchByTeacher(frame);
                	frame.setVisible(false);
                	SearchByteacher.show();
                    
                    break;
                case "Search As Student":
                	SearchBySection SearchBySection = new SearchBySection(frame);
                	frame.setVisible(false);
                	SearchBySection.show();
                    JOptionPane.showMessageDialog(frame, "Search As Student Form");
                    break;
                case "Search By Section":
                	SearchBySection SearchySection = new SearchBySection(frame);
                	frame.setVisible(false);
                	SearchySection.show();
                	break;
                default:
                    
                    break;
            }
        } else {
            JOptionPane.showMessageDialog(frame, "Please select an option", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private void handleBack() {
        LoginPage loginPage = new LoginPage();
        loginPage.setVisible(true);
        frame.dispose();
    }

    public void setVisible(boolean isVisible) {
        frame.setVisible(isVisible);
    }
}
