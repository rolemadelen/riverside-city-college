/*
 * CSC 18B 42029 - Java Programming
 * Individual Project: Binary Game
 *
 * File name: LoginFrame.java
 * Coded by : Jiwon Yoo
 */

package BinaryGame.Main;

import BinaryGame.Database.MySQLConnect;
import BinaryGame.Main.Game.GameOneCompFrame;
import BinaryGame.Serializable.*;
/**
 *
 * @author astraea
 */
public class LoginFrame extends javax.swing.JFrame {
    private static UsernameSerializable record = new UsernameSerializable();
    
    /**
     * Creates new form Login
     */
    public LoginFrame() {
        initComponents();
        
        // read data from a file
        ReadDataFile app = new ReadDataFile();
        app.openFile(record);
        record = app.readRecords(record);
        app.closeFile();
        
        username.setText(record.getUsername());
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        panel = new javax.swing.JPanel();
        username = new javax.swing.JTextField();
        password = new javax.swing.JPasswordField();
        signinButton = new javax.swing.JButton();
        optionButton = new javax.swing.JButton();
        quitButton = new javax.swing.JButton();
        rememberCheckBox = new javax.swing.JCheckBox();
        errorLabel = new javax.swing.JLabel();
        register = new javax.swing.JLabel();
        loginFormLabel = new javax.swing.JLabel();
        credit = new javax.swing.JLabel();
        title = new javax.swing.JLabel();
        bg1 = new javax.swing.JLabel();
        bg2 = new javax.swing.JLabel();
        bg3 = new javax.swing.JLabel();
        bg4 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Binary Game");
        setAlwaysOnTop(true);
        setMinimumSize(new java.awt.Dimension(800, 700));
        setName(""); // NOI18N
        setUndecorated(true);
        setResizable(false);

        panel.setBackground(new java.awt.Color(0, 0, 0));
        panel.setMinimumSize(new java.awt.Dimension(800, 700));
        panel.setLayout(null);

        username.setBackground(new java.awt.Color(23, 23, 23));
        username.setForeground(new java.awt.Color(2, 151, 2));
        username.setText("username");
        username.setBorder(null);
        username.setCursor(new java.awt.Cursor(java.awt.Cursor.TEXT_CURSOR));
        username.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                usernameMouseClicked(evt);
            }
        });
        panel.add(username);
        username.setBounds(340, 300, 170, 28);

        password.setBackground(new java.awt.Color(23, 23, 23));
        password.setForeground(new java.awt.Color(2, 151, 2));
        password.setText("!@#$");
        password.setBorder(null);
        password.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                passwordMouseClicked(evt);
            }
        });
        panel.add(password);
        password.setBounds(340, 350, 170, 30);

        signinButton.setBackground(new java.awt.Color(21, 21, 21));
        signinButton.setFont(new java.awt.Font("Ubuntu Medium", 0, 18)); // NOI18N
        signinButton.setForeground(java.awt.Color.white);
        signinButton.setText("Sign in");
        signinButton.setBorder(null);
        signinButton.setFocusPainted(false);
        signinButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                signinButtonActionPerformed(evt);
            }
        });
        panel.add(signinButton);
        signinButton.setBounds(280, 430, 240, 50);

        optionButton.setBackground(new java.awt.Color(21, 21, 21));
        optionButton.setFont(new java.awt.Font("Ubuntu Medium", 0, 14)); // NOI18N
        optionButton.setForeground(java.awt.Color.white);
        optionButton.setText("Option");
        optionButton.setBorder(null);
        optionButton.setFocusPainted(false);
        optionButton.setFocusable(false);
        optionButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                optionButtonActionPerformed(evt);
            }
        });
        panel.add(optionButton);
        optionButton.setBounds(660, 610, 110, 30);

        quitButton.setBackground(new java.awt.Color(21, 21, 21));
        quitButton.setFont(new java.awt.Font("Ubuntu Medium", 0, 14)); // NOI18N
        quitButton.setForeground(java.awt.Color.white);
        quitButton.setText("Quit");
        quitButton.setBorder(null);
        quitButton.setFocusPainted(false);
        quitButton.setFocusable(false);
        quitButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                quitButtonActionPerformed(evt);
            }
        });
        panel.add(quitButton);
        quitButton.setBounds(660, 650, 110, 30);

        rememberCheckBox.setFont(new java.awt.Font("Ubuntu", 0, 14)); // NOI18N
        rememberCheckBox.setForeground(new java.awt.Color(89, 89, 89));
        rememberCheckBox.setText("Remember Me");
        rememberCheckBox.setBorder(null);
        rememberCheckBox.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        rememberCheckBox.setFocusPainted(false);
        rememberCheckBox.setFocusable(false);
        rememberCheckBox.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                rememberCheckBoxActionPerformed(evt);
            }
        });
        panel.add(rememberCheckBox);
        rememberCheckBox.setBounds(280, 400, 140, 20);

        errorLabel.setFont(new java.awt.Font("Ubuntu", 0, 12)); // NOI18N
        errorLabel.setForeground(new java.awt.Color(205, 21, 21));
        errorLabel.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        panel.add(errorLabel);
        errorLabel.setBounds(290, 270, 220, 20);

        register.setFont(new java.awt.Font("Ubuntu", 0, 14)); // NOI18N
        register.setForeground(new java.awt.Color(89, 89, 89));
        register.setHorizontalAlignment(javax.swing.SwingConstants.RIGHT);
        register.setText("Register");
        register.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        register.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                registerMouseClicked(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                registerMouseExited(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                registerMouseEntered(evt);
            }
        });
        panel.add(register);
        register.setBounds(440, 400, 70, 20);

        loginFormLabel.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/loginForm.png"))); // NOI18N
        loginFormLabel.setBorder(javax.swing.BorderFactory.createLineBorder(new java.awt.Color(50, 50, 50)));
        panel.add(loginFormLabel);
        loginFormLabel.setBounds(250, 210, 290, 292);

        credit.setForeground(new java.awt.Color(51, 51, 51));
        credit.setText("Jiwon Yoo");
        panel.add(credit);
        credit.setBounds(10, 680, 90, 20);

        title.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/title.png"))); // NOI18N
        panel.add(title);
        title.setBounds(100, 40, 593, 113);

        bg1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/matrix.gif"))); // NOI18N
        panel.add(bg1);
        bg1.setBounds(410, -10, 400, 440);

        bg2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/matrix.gif"))); // NOI18N
        panel.add(bg2);
        bg2.setBounds(0, -10, 400, 440);

        bg3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/matrix.gif"))); // NOI18N
        panel.add(bg3);
        bg3.setBounds(0, 290, 400, 440);

        bg4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/matrix.gif"))); // NOI18N
        panel.add(bg4);
        bg4.setBounds(410, 290, 400, 440);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(panel, javax.swing.GroupLayout.DEFAULT_SIZE, 800, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(panel, javax.swing.GroupLayout.DEFAULT_SIZE, 700, Short.MAX_VALUE)
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    /*
     * if sign in button is clicked,
     * check for the valid username and pswd, then
     * login and continue to the main menu;
     **/
    private void signinButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_signinButtonActionPerformed
        Option.soundEffect("src/sound/Short Circuit.wav");
        
        String id = username.getText();
        String pw = ""; // password
        
        // since getPassword() returns char[] not String,
        char[] ch = password.getPassword();
                
        // append each character to string
        for(int i = 0; i < ch.length; ++i) 
            pw += ("" + ch[i]);
        
        // check if username is valid
        MySQLConnect db = new MySQLConnect();
        
        // if valid, move on to the next screen
        if( db.isLoginValid(id, pw) ) {
            PlayMenuFrame screen = new PlayMenuFrame();
            this.setVisible(false);
            screen.setVisible(true);
        }
        // else, alert the user that either id or pswd is incorrect
        else {
            errorLabel.setText("* Incorrect Username or Password");
        }
    }//GEN-LAST:event_signinButtonActionPerformed

    /*
     * show register screen when
     * register button is clicked.
     */
    private void registerMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_registerMouseClicked
        RegisterFrame reg = new RegisterFrame();
        this.setVisible(false);
        reg.setVisible(true);
    }//GEN-LAST:event_registerMouseClicked

    private void registerMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_registerMouseEntered
       register.setForeground(new java.awt.Color(2, 151, 2));
       register.setFont(new java.awt.Font("Ubuntu", java.awt.Font.BOLD, 14));
    }//GEN-LAST:event_registerMouseEntered

    private void registerMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_registerMouseExited
       register.setForeground(new java.awt.Color(89, 89, 89));
       register.setFont(new java.awt.Font("Ubuntu", java.awt.Font.PLAIN, 14));
    }//GEN-LAST:event_registerMouseExited

    /* 
     * terminate the programe when 
     * quit button is pressed.
     */
    private void quitButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_quitButtonActionPerformed
        System.exit(0);
    }//GEN-LAST:event_quitButtonActionPerformed

    private void usernameMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_usernameMouseClicked
        username.setText("");
        errorLabel.setText("");
    }//GEN-LAST:event_usernameMouseClicked

    /*
     * show option screen when
     * option button is clicked.
     */
    private void optionButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_optionButtonActionPerformed
        Option.soundEffect("src/sound/Short Circuit.wav");
        OptionFrame option = new OptionFrame();
        this.setVisible(false);
        option.setVisible(true);
    }//GEN-LAST:event_optionButtonActionPerformed

    private void rememberCheckBoxActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_rememberCheckBoxActionPerformed
         CreateDataFile data = new CreateDataFile();
         
        if(rememberCheckBox.isSelected()) {
           record.setUsername(username.getText());
           data.openFile(record);
           data.addRecords(record);
           data.closeFile();
        }
    }//GEN-LAST:event_rememberCheckBoxActionPerformed

    private void passwordMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_passwordMouseClicked
        // TODO add your handling code here:
        password.setText("");
        errorLabel.setText("");
    }//GEN-LAST:event_passwordMouseClicked

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel bg1;
    private javax.swing.JLabel bg2;
    private javax.swing.JLabel bg3;
    private javax.swing.JLabel bg4;
    private javax.swing.JLabel credit;
    private javax.swing.JLabel errorLabel;
    private javax.swing.JLabel loginFormLabel;
    private javax.swing.JButton optionButton;
    private javax.swing.JPanel panel;
    private javax.swing.JPasswordField password;
    private javax.swing.JButton quitButton;
    private javax.swing.JLabel register;
    private javax.swing.JCheckBox rememberCheckBox;
    private javax.swing.JButton signinButton;
    private javax.swing.JLabel title;
    private javax.swing.JTextField username;
    // End of variables declaration//GEN-END:variables
}