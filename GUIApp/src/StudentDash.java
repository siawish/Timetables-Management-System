import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import Admin.Search.SearchByCourse;
import Admin.Search.SearchByRoom;

public class StudentDash {

    private JFrame frame;
    private String foreignID;

    /**
     * Launch the application.
     */
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    StudentDash window = new StudentDash("12345"); 
                    window.frame.setVisible(true);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    /**
     * Create the application with foreignID.
     */
    public StudentDash(String foreignID) {
        this.foreignID = foreignID;
        initialize();
    }

    /**
     * Initialize the contents of the frame.
     */
    private void initialize() {
        frame = new JFrame();
        frame.setBounds(100, 100, 800, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().setLayout(null);

        JLabel lblTitle = new JLabel("Student Dashboard");
        lblTitle.setFont(new Font("Microsoft Sans Serif", Font.PLAIN, 24));
        lblTitle.setBounds(250, 30, 300, 50);
        frame.getContentPane().add(lblTitle);

        JLabel lblViewTimetable = new JLabel("View Timetable");
        lblViewTimetable.setFont(new Font("Microsoft Sans Serif", Font.BOLD, 16));
        lblViewTimetable.setBounds(325, 100, 150, 30);
        frame.getContentPane().add(lblViewTimetable);

        JButton btnByDay = new JButton("By Day");
        btnByDay.setBounds(270, 200, 255, 28);
        frame.getContentPane().add(btnByDay);

        JButton btnByRoom = new JButton("By Room");
        btnByRoom.setBounds(270, 250, 255, 28);
        frame.getContentPane().add(btnByRoom);

        JButton btnByCourse = new JButton("By Course");
        btnByCourse.setBounds(270, 300, 255, 28);
        frame.getContentPane().add(btnByCourse);

        btnByDay.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JOptionPane.showMessageDialog(frame, "Viewing timetable by Day for user with ForeignID: " + foreignID);
            }
        });

        btnByRoom.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
//              
            	SearchByRoom SearchByRoom = new SearchByRoom(frame);
            	frame.setVisible(false);
            	SearchByRoom.show();}
        });

        btnByCourse.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
//               
            	SearchByCourse SearchByCourse = new SearchByCourse(frame);
            	frame.setVisible(false);
            	SearchByCourse.show();
            }
        });
    }

    public void setVisible(boolean visible) {
        frame.setVisible(visible);
    }
}
