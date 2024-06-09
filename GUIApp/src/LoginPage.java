import java.awt.EventQueue;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.awt.Font;

public class LoginPage {

    private JFrame frame;
    private JTextField usernameField;
    private JPasswordField passwordField;

    /**
     * Launch the application.
     */
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    LoginPage window = new LoginPage();
                    window.frame.setVisible(true);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    /**
     * Create the application.
     */
    public LoginPage() {
        initialize();
    }

    /**
     * Initialize the contents of the frame.
     */
    private void initialize() {
        frame = new JFrame();
        frame.setBounds(100, 100, 450, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);

        JLabel lblTitle = new JLabel("Login");
        lblTitle.setFont(new Font("Tahoma", Font.BOLD, 20));
        lblTitle.setBounds(202, 20, 65, 35);
        frame.getContentPane().add(lblTitle);

        JLabel lblUsername = new JLabel("Username:");
        lblUsername.setBounds(58, 70, 80, 16);
        frame.getContentPane().add(lblUsername);

        usernameField = new JTextField();
        usernameField.setBounds(150, 65, 200, 26);
        frame.getContentPane().add(usernameField);
        usernameField.setColumns(10);

        JLabel lblPassword = new JLabel("Password:");
        lblPassword.setBounds(58, 120, 80, 16);
        frame.getContentPane().add(lblPassword);

        passwordField = new JPasswordField();
        passwordField.setBounds(150, 115, 200, 26);
        frame.getContentPane().add(passwordField);

        JButton btnLogin = new JButton("Login");
        btnLogin.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String username = usernameField.getText();
                String password = new String(passwordField.getPassword());
                String[] userData = authenticateUser(username, password);
                if (userData != null) {
                    String userType = userData[0];
                    String foreignID = userData[1];
                    JOptionPane.showMessageDialog(frame, "Login successful as " + userType);
                    switch (userType) {
                        case "Admin":
                            openAdminPage(foreignID);
                            break;
                        case "Teacher":
                            openTeacherPage(foreignID);
                            break;
                        case "Student":
                            openStudentPage(foreignID);
                            break;
                        default:
                            JOptionPane.showMessageDialog(frame, "Unknown user type");
                    }
                } else {
                    JOptionPane.showMessageDialog(frame, "Invalid username or password");
                }
            }
        });
        btnLogin.setBounds(150, 180, 117, 29);
        frame.getContentPane().add(btnLogin);
    }

    private String[] authenticateUser(String username, String password) {
        String dbUrl = "jdbc:mysql://127.0.0.1:3306/timetable";
        String dbUsername = "root";  // MySQL username
        String dbPassword = "malik";  // MySQL password

        try (Connection conn = DriverManager.getConnection(dbUrl, dbUsername, dbPassword)) {
            
            

            String sql = "SELECT UserType, ForeignID FROM User WHERE LOWER(Username) = LOWER(?) AND LOWER(Password) = LOWER(?)";
            PreparedStatement statement = conn.prepareStatement(sql);
            statement.setString(1, username);
            statement.setString(2, password);

            ResultSet resultSet = statement.executeQuery();

            if (resultSet.next()) {
                return new String[]{resultSet.getString("UserType"), resultSet.getString("ForeignID")};
            }
        } catch (Exception ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(frame, "Error: " + ex.getMessage());
        }
        return null;
    }

    private void openAdminPage(String foreignID) {
       
        JOptionPane.showMessageDialog(frame, "Opening Admin Page for user with ForeignID: " + foreignID);
        AdminDash dash = new AdminDash();
        dash.setVisible(true);
        frame.dispose();
    }

    private void openTeacherPage(String foreignID) {
        
        TeacherDash teacherPage = new TeacherDash(foreignID);
         teacherPage.setVisible(true);
    }

    private void openStudentPage(String foreignID) {
      
        StudentDash studentPage = new StudentDash(foreignID);
        studentPage.setVisible(true);
    }

    public void setVisible(boolean isVisible) {
        frame.setVisible(isVisible);
    }
}
