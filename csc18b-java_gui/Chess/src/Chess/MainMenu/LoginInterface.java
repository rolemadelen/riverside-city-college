/*
 * Name: Alec Farfan, Jiwon Yoo, Luis Pena, Wenbo Yang
 * Date: 03/20/15
 * Purpose: Chess LoginUI Class
 */

package Chess.MainMenu;

// Import libraries
import Chess.Game.*;
import java.awt.Color;
import java.awt.HeadlessException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import javax.swing.JOptionPane;

public class LoginInterface extends javax.swing.JFrame {

    // Member variables
    private static boolean onePlayer;
    private Pattern r,r2;
    private Matcher m,m2;
    public Player_Info player1;
    public Player_Info player2;
    public int game_choice;
    
    
    
    //Mysql variables 
  
    Connection connect = null;
    PreparedStatement  states  = null;
    ResultSet  results = null;
    
    /**
     * Creates new form LoginUI
     */
    public LoginInterface(int game_choice) {
        initComponents();
        player1 = new Player_Info();
        player2 = new Player_Info();
        this.game_choice = game_choice;
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        registerDialog = new javax.swing.JDialog();
        registerUsernameLabel = new javax.swing.JLabel();
        registerUnameTextField = new javax.swing.JTextField();
        registerPWField = new javax.swing.JPasswordField();
        registerConfirmPWField = new javax.swing.JPasswordField();
        registerPWLabel = new javax.swing.JLabel();
        registerConfirmPWLabel = new javax.swing.JLabel();
        registerButton2 = new javax.swing.JButton();
        registerCancelButton = new javax.swing.JButton();
        registerCheckIDButton = new javax.swing.JButton();
        jPanel1 = new javax.swing.JPanel();
        selectPlayerLabel = new javax.swing.JLabel();
        choice1 = new java.awt.Choice();
        startGameButton = new javax.swing.JButton();
        userNameLabel = new javax.swing.JLabel();
        usernameTextField = new javax.swing.JTextField();
        pwLabel = new javax.swing.JLabel();
        userPasswordField = new javax.swing.JPasswordField();
        loginGuestButtton = new javax.swing.JButton();
        registerButton = new javax.swing.JButton();
        returnLabel = new javax.swing.JLabel();
        player1ID = new javax.swing.JLabel();
        p1UserName = new javax.swing.JTextField();
        p2UserName = new javax.swing.JTextField();
        player2ID = new javax.swing.JLabel();
        loginButton = new javax.swing.JButton();

        registerDialog.setTitle("Chess - Registor new user");
        registerDialog.setAlwaysOnTop(true);

        registerUsernameLabel.setText("User Name:");

        registerUnameTextField.setForeground(new java.awt.Color(203, 203, 203));
        registerUnameTextField.setText("enter username");
        registerUnameTextField.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                registerUnameTextFieldMouseClicked(evt);
            }
        });

        registerPWField.setText("root");

        registerConfirmPWField.setText("toor");

        registerPWLabel.setText("Password:");

        registerConfirmPWLabel.setText("Confirm Password:");

        registerButton2.setText("Register");
        registerButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                registerButton2ActionPerformed(evt);
            }
        });

        registerCancelButton.setText("Cancel");
        registerCancelButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                registerCancelButtonActionPerformed(evt);
            }
        });

        registerCheckIDButton.setText("Check");

        javax.swing.GroupLayout registerDialogLayout = new javax.swing.GroupLayout(registerDialog.getContentPane());
        registerDialog.getContentPane().setLayout(registerDialogLayout);
        registerDialogLayout.setHorizontalGroup(
            registerDialogLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(registerDialogLayout.createSequentialGroup()
                .addGap(37, 37, 37)
                .addGroup(registerDialogLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(registerUsernameLabel)
                    .addComponent(registerPWLabel)
                    .addComponent(registerConfirmPWLabel)
                    .addComponent(registerButton2))
                .addGap(138, 138, 138)
                .addGroup(registerDialogLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, registerDialogLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                        .addComponent(registerPWField)
                        .addComponent(registerUnameTextField)
                        .addComponent(registerConfirmPWField, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 180, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(registerCancelButton, javax.swing.GroupLayout.Alignment.TRAILING))
                .addGap(34, 34, 34)
                .addComponent(registerCheckIDButton)
                .addContainerGap())
        );
        registerDialogLayout.setVerticalGroup(
            registerDialogLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(registerDialogLayout.createSequentialGroup()
                .addGap(24, 24, 24)
                .addGroup(registerDialogLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(registerUsernameLabel)
                    .addComponent(registerUnameTextField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(registerCheckIDButton))
                .addGap(18, 18, 18)
                .addGroup(registerDialogLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(registerPWField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(registerPWLabel))
                .addGap(18, 18, 18)
                .addGroup(registerDialogLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(registerConfirmPWField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(registerConfirmPWLabel))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 95, Short.MAX_VALUE)
                .addGroup(registerDialogLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(registerButton2)
                    .addComponent(registerCancelButton))
                .addGap(29, 29, 29))
        );

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Chess - Login");
        setMinimumSize(new java.awt.Dimension(465, 300));
        setUndecorated(true);
        setPreferredSize(new java.awt.Dimension(465, 451));
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowActivated(java.awt.event.WindowEvent evt) {
                formWindowActivated(evt);
            }
            public void windowDeactivated(java.awt.event.WindowEvent evt) {
                formWindowDeactivated(evt);
            }
        });

        jPanel1.setBackground(new java.awt.Color(0, 0, 0));
        jPanel1.setMinimumSize(new java.awt.Dimension(465, 400));
        jPanel1.setPreferredSize(new java.awt.Dimension(465, 451));

        selectPlayerLabel.setForeground(new java.awt.Color(255, 255, 255));
        selectPlayerLabel.setText("Select Player to Login:");

        choice1.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        choice1.setName(""); // NOI18N

        startGameButton.setText("Start Game");
        startGameButton.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        startGameButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                startGameButtonActionPerformed(evt);
            }
        });

        userNameLabel.setForeground(new java.awt.Color(255, 255, 255));
        userNameLabel.setText("User Name:");

        usernameTextField.setForeground(new java.awt.Color(209, 209, 209));
        usernameTextField.setText("user name");
        usernameTextField.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                usernameTextFieldMouseClicked(evt);
            }
        });

        pwLabel.setForeground(new java.awt.Color(255, 255, 255));
        pwLabel.setText("Password:");

        userPasswordField.setText("root");

        loginGuestButtton.setText("Login as Guest");
        loginGuestButtton.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        loginGuestButtton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                loginGuestButttonActionPerformed(evt);
            }
        });

        registerButton.setText("Register");
        registerButton.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        registerButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                registerButtonActionPerformed(evt);
            }
        });

        returnLabel.setForeground(new java.awt.Color(255, 255, 255));
        returnLabel.setText("Return");
        returnLabel.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                returnLabelMouseClicked(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                returnLabelMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                returnLabelMouseExited(evt);
            }
        });

        player1ID.setForeground(new java.awt.Color(255, 255, 255));
        player1ID.setText("Player 1:");

        p1UserName.setEnabled(false);

        p2UserName.setEnabled(false);

        player2ID.setForeground(new java.awt.Color(255, 255, 255));
        player2ID.setText("Player 2:");

        loginButton.setText("Login");
        loginButton.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        loginButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                loginButtonActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addGap(52, 52, 52)
                .addComponent(returnLabel)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(startGameButton, javax.swing.GroupLayout.PREFERRED_SIZE, 189, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(135, 135, 135))
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(82, 82, 82)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(p1UserName, javax.swing.GroupLayout.PREFERRED_SIZE, 123, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(loginGuestButtton, javax.swing.GroupLayout.PREFERRED_SIZE, 131, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGap(2, 2, 2)
                        .addComponent(userNameLabel))
                    .addComponent(pwLabel)
                    .addComponent(selectPlayerLabel)
                    .addComponent(player1ID))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 47, Short.MAX_VALUE)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(choice1, javax.swing.GroupLayout.PREFERRED_SIZE, 132, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(usernameTextField, javax.swing.GroupLayout.PREFERRED_SIZE, 132, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(userPasswordField, javax.swing.GroupLayout.PREFERRED_SIZE, 132, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(loginButton, javax.swing.GroupLayout.PREFERRED_SIZE, 132, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(registerButton, javax.swing.GroupLayout.PREFERRED_SIZE, 132, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(player2ID)
                    .addComponent(p2UserName, javax.swing.GroupLayout.PREFERRED_SIZE, 127, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(78, 78, 78))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(selectPlayerLabel)
                        .addGap(38, 38, 38)
                        .addComponent(userNameLabel)
                        .addGap(19, 19, 19)
                        .addComponent(pwLabel)
                        .addGap(46, 46, 46)
                        .addComponent(loginGuestButtton))
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(choice1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(32, 32, 32)
                        .addComponent(usernameTextField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(14, 14, 14)
                        .addComponent(userPasswordField, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(12, 12, 12)
                        .addComponent(loginButton)
                        .addGap(8, 8, 8)
                        .addComponent(registerButton)))
                .addGap(47, 47, 47)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(player1ID)
                    .addComponent(player2ID))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(p1UserName, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(p2UserName, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(50, 50, 50)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(startGameButton, javax.swing.GroupLayout.PREFERRED_SIZE, 55, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(returnLabel))
                .addContainerGap(40, Short.MAX_VALUE))
        );

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, 470, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, 420, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void returnLabelMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_returnLabelMouseClicked
        // TODO add your handling code here:
        this.setVisible(false);
        //System.exit(0);
        StartInterface mainMenu = new StartInterface();
        mainMenu.setLocationRelativeTo(null);
        mainMenu.setVisible(true);
    }//GEN-LAST:event_returnLabelMouseClicked

    private void returnLabelMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_returnLabelMouseEntered
        // TODO add your handling code here:
        returnLabel.setText("RETURN");
        returnLabel.setForeground(Color.MAGENTA);
    }//GEN-LAST:event_returnLabelMouseEntered

    private void returnLabelMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_returnLabelMouseExited
        // TODO add your handling code here:
        returnLabel.setText("Return");
        returnLabel.setForeground(Color.WHITE);
    }//GEN-LAST:event_returnLabelMouseExited

    private void registerButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_registerButtonActionPerformed
        // TODO add your handling code here:
        registerDialog.setLocationRelativeTo(null);
        registerDialog.setSize(600,250);
        registerDialog.setVisible(true);
        if( registerDialog.isEnabled() );
            reset();
    }//GEN-LAST:event_registerButtonActionPerformed

    private void registerCancelButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_registerCancelButtonActionPerformed
        // TODO add your handling code here:
        registerDialog.setVisible(false);
    }//GEN-LAST:event_registerCancelButtonActionPerformed

    private void registerButton2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_registerButton2ActionPerformed
      // String to be scanned to find the pattern.
      String username = registerUnameTextField.getText();
      String pw = "",
              pwConfirm = "";
      
      // getPassword() returns char[]
      char[] ch = registerPWField.getPassword(),
              ch2 = registerConfirmPWField.getPassword();
      
      // append each char in char[] to string
      for(int i = 0; i < ch.length; ++i) 
           pw += ("" + ch[i]);
      
       for(int i = 0; i < ch2.length; ++i) 
           pwConfirm += ("" + ch2[i]);
      
       // patterns
      String pattern = "^[a-zA-Z0-9]{3,35}$"; // username
      String pattern2 = "^[a-zA-Z0-9!@#$%^&*]{8,35}$"; // password

      // Create a Pattern object
      r = Pattern.compile(pattern);
      r2 = Pattern.compile(pattern2);
      // Now create matcher object.
      m = r.matcher(username);
      m2 = r2.matcher(pw);
      
      if(m.find() && m2.find() && (pw.equals(pwConfirm))){
          System.out.println("true");       
          
      String regusername = registerUnameTextField.getText();
      String regpassword = String.valueOf(registerConfirmPWField.getPassword());
        
        try{
            String mysqlQuery = "INSERT INTO users(username,password)" + "values(?,?)";
            states = connect.prepareStatement(mysqlQuery);
            states.setString(1,regusername);
            states.setString(2,regpassword);
            int i = states.executeUpdate();
            
            
            if(i>0){
            JOptionPane.showMessageDialog(null, "Sign Up Success! ");
            
            
            } else{
                JOptionPane.showMessageDialog(null, "Oops! There was a problem with the Registration");
            }
            
        }catch(SQLException | HeadlessException e){
            
            JOptionPane.showMessageDialog(null, e);
        }
          
          registerDialog.setVisible(false);
      } else {
          System.out.println("false"); 
          //if username field is empty
          if(registerUnameTextField.getText().equals("enter username") ||
                  registerUnameTextField.getText().length() == 0) {
              JOptionPane.showMessageDialog(null, "Enter username!");
          }
          // if pw and pwConfirm is not matched
          else if(!pw.equals(pwConfirm)) {
              JOptionPane.showMessageDialog(null, "Password not matched!");
          }
          // if username or pw failed passing regex test
          else {
              JOptionPane.showMessageDialog(null, "Username: 3-35 characters.\n"
                      + "Password: 8-35 characters.");
          }     
      }
    }//GEN-LAST:event_registerButton2ActionPerformed

    private void loginGuestButttonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_loginGuestButttonActionPerformed
        if(choice1.getSelectedItem().equals("Player 1")) {
            p1UserName.setText(("Guset 1"));
        } else {
            p2UserName.setText("Guest 2");
        }
    }//GEN-LAST:event_loginGuestButttonActionPerformed

    private void loginButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_loginButtonActionPerformed
        // perform regex test on username and pw
        String username = usernameTextField.getText();
        String pw = "";

        // getPassword() returns char[]
        char[] ch = userPasswordField.getPassword();
        
        // append each char in char[] to string
        for(int i = 0; i < ch.length; ++i) 
           pw += ("" + ch[i]);

        // patterns
        String pattern = "^[a-zA-Z0-9]{3,35}$"; // username
        String pattern2 = "^[a-zA-Z0-9!@#$%^&*]{8,35}$"; // password

        // Create a Pattern object
        r = Pattern.compile(pattern);
        r2 = Pattern.compile(pattern2);
        
        // Now create matcher object.  
        m = r.matcher(username);
        m2 = r2.matcher(pw);
        String getusername = usernameTextField.getText();
        String getpassword = String.valueOf(userPasswordField.getPassword());
        //int getid = 0;
        try{
            String mysqlQuery = "SELECT * FROM users WHERE username = ? AND password = ?";
            //String mysqlQuery = "SELECT * FROM users WHERE username = ? AND password = ? AND id =?;";
            states = connect.prepareStatement(mysqlQuery);
            states.setString(1,getusername);
            states.setString(2,getpassword);
            //states.setInt(3, getid);
            results = states.executeQuery();
          
            
            if (results.next()){
       
                 String getid = results.getString("id");
                 if(choice1.getSelectedItem().equals("Player 1")){
                  p1UserName.setText(getusername);
                  player1.set_username(getusername);
                  player1.set_password(getpassword);
                  int getID = Integer.parseInt(getid);
                  player1.set_id(getID);
                 //JOptionPane.showMessageDialog(null, getUsernameStored);
                  JOptionPane.showMessageDialog(null, "Login Successful!");
                 
                 //JOptionPane.showMessageDialog(null, getID);
                 }else if(choice1.getSelectedItem().equals("Player 2")){
                     int getID = Integer.parseInt(getid);
                     player2.set_id(getID);
                     player2.set_username(getusername);
                     player2.set_password(getpassword);
                  
                     //JOptionPane.showMessageDialog(null, getID);
                     
                    // JOptionPane.showMessageDialog(null, getUsernameStored2);
                   p2UserName.setText(getusername);
                    JOptionPane.showMessageDialog(null, "Login Successful!");
         }
            }
       
            else{  JOptionPane.showMessageDialog(null, "Login Failed, Please Try Again");}
   
        }catch(SQLException | HeadlessException e){    
            JOptionPane.showMessageDialog(null, e);
        }
        
        // if username and pw failed to pass regex test
        // show error (chekc database later on)
         if(m.find() && m2.find()) {
              if(choice1.getSelectedItem().equals("Player 1"))
                  p1UserName.setText(getusername);
              else if(choice1.getSelectedItem().equals("Player 2"))
                  p2UserName.setText(getusername);
         } else {
             
         }
    }//GEN-LAST:event_loginButtonActionPerformed

    private void usernameTextFieldMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_usernameTextFieldMouseClicked
        usernameTextField.setText("");
        usernameTextField.setForeground(Color.BLACK);
    }//GEN-LAST:event_usernameTextFieldMouseClicked

    private void registerUnameTextFieldMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_registerUnameTextFieldMouseClicked
        registerUnameTextField.setText("");
        registerUnameTextField.setForeground(Color.BLACK);
    }//GEN-LAST:event_registerUnameTextFieldMouseClicked

    private void startGameButtonActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_startGameButtonActionPerformed
        if(p1UserName.getText().length() == 0 || 
                p2UserName.getText().length() == 0) {
            JOptionPane.showMessageDialog(null, "Login please..");
        } else {
            PlayInterface screen = new PlayInterface(player1,player2,game_choice);
            screen.setLocationRelativeTo(null);
            screen.setVisible(true);
            this.setVisible(false);
        }
    }//GEN-LAST:event_startGameButtonActionPerformed

    private void formWindowActivated(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowActivated
        // Connect to Database as soon as its opened. 
        connect = MysqlConnection.connectMysql();
        if(onePlayer == true) {
             choice1.add("Player 1");
             p2UserName.setText("Computer");
        }
        else{
             choice1.add("Player 1");
             choice1.add("Player 2");
             
        }
    }//GEN-LAST:event_formWindowActivated

    private void formWindowDeactivated(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowDeactivated
        choice1.removeAll();
    }//GEN-LAST:event_formWindowDeactivated

    // reset register field
    private void reset() {
        registerUnameTextField.setText("enter username");
        registerUnameTextField.setForeground(new Color(203,203,203));
        registerPWField.setText("root");
        registerConfirmPWField.setText("toor");
    }
    
    // check if 1P or 2P login
    public static void isOnePlayer(boolean b) {
        onePlayer = b;
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private java.awt.Choice choice1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JButton loginButton;
    private javax.swing.JButton loginGuestButtton;
    private javax.swing.JTextField p1UserName;
    private javax.swing.JTextField p2UserName;
    private javax.swing.JLabel player1ID;
    private javax.swing.JLabel player2ID;
    private javax.swing.JLabel pwLabel;
    private javax.swing.JButton registerButton;
    private javax.swing.JButton registerButton2;
    private javax.swing.JButton registerCancelButton;
    private javax.swing.JButton registerCheckIDButton;
    private javax.swing.JPasswordField registerConfirmPWField;
    private javax.swing.JLabel registerConfirmPWLabel;
    private javax.swing.JDialog registerDialog;
    private javax.swing.JPasswordField registerPWField;
    private javax.swing.JLabel registerPWLabel;
    private javax.swing.JTextField registerUnameTextField;
    private javax.swing.JLabel registerUsernameLabel;
    private javax.swing.JLabel returnLabel;
    private javax.swing.JLabel selectPlayerLabel;
    private javax.swing.JButton startGameButton;
    private javax.swing.JLabel userNameLabel;
    private javax.swing.JPasswordField userPasswordField;
    private javax.swing.JTextField usernameTextField;
    // End of variables declaration//GEN-END:variables
}
