import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import Admin.Search.SearchByRoom;
import Admin.Search.SearchBySection;

public class TeacherDash {

    private JFrame frame;
    private String foreignID;

   

    /**
     * Create the application.
     */
    public TeacherDash(String foreignID) {
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

        JLabel lblTitle = new JLabel("Teacher Dashboard");
        lblTitle.setFont(new Font("Microsoft Sans Serif", Font.PLAIN, 24));
        lblTitle.setBounds(250, 30, 300, 50);
        frame.getContentPane().add(lblTitle);

        JButton btnBySection = new JButton("By Section");
        btnBySection.setBounds(270, 150, 200, 30);
        frame.getContentPane().add(btnBySection);

        JLabel lblViewTimetable = new JLabel("View Timetable");
        lblViewTimetable.setFont(new Font("Microsoft Sans Serif", Font.BOLD, 16));
        lblViewTimetable.setBounds(310, 100, 150, 30);
        frame.getContentPane().add(lblViewTimetable);

        JButton btnByRoom = new JButton("By Room");
        btnByRoom.setBounds(270, 200, 200, 30);
        frame.getContentPane().add(btnByRoom);

        JButton btnBack = new JButton("Back");
        btnBack.setBounds(270, 250, 200, 30);
        frame.getContentPane().add(btnBack);

        btnBySection.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	SearchBySection SearchySection = new SearchBySection(frame);
            	frame.setVisible(false);
            	SearchySection.show();
            }
        });

        btnByRoom.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	SearchByRoom SearchByRoom = new SearchByRoom(frame);
            	frame.setVisible(false);
            	SearchByRoom.show();       }
        });

        btnBack.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                
                frame.setVisible(false);
                
            }
        });
    }

    public void setVisible(boolean visible) {
        frame.setVisible(visible);
    }
}
