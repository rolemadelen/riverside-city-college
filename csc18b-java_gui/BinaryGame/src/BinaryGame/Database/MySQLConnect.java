/*
 * CSC 18B 42029 - Java Programming
 * Individual Project: Binary Game
 *
 * File name: MySQLConnect.java
 * Coded by : Jiwon Yoo
 */
package BinaryGame.Database;

import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.HashMap;
/**
 *
 * @author astraea
 */
public class MySQLConnect {
    private Connection connect;
    private Statement states;
    private ResultSet results;
    private HashMap<String, String> usernameAndPswd;
    
    private final String query = "select * from binarygame_entity_user_Jiwon";
    
    public MySQLConnect() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            
            // Variable that will connect to the database containing all the tables
            // getConnection(location of DB, username for Admin, password for Admin);
           connect = DriverManager.getConnection("jdbc:mysql://localhost:3306/binarygame","admin","admin1234");
             //connect = DriverManager.getConnection("jdbc:mysql://209.129.8.4:3306/42029","42029","42029csc18b");

           /*
           CREATE DATABASE binarygame;
           use binarygame;
           CREATE TABLE binarygame_entity_user_Jiwon (name varchar(20), password varchar(20));
           
           CREATE USER 'admin'@'%' IDENTIFIED BY 'admin1234';
           GRANT ALL PRIVILEGES ON binarygame.* TO 'admin'@'localhost';
           */
            states = connect.createStatement();
            
        } // end try
        catch (Exception e) {
            System.err.println("Error: " + e);
        } // end catch
    } // end constructor MySQLConnect
    
    /*
     * used for registering a new user
     *
     * get all usernames from the database.
     * compare the exist usernames with the new username
     * and see if it alerady exists or not.
     * if it exists, not valid.
     * else, add it to the database and register new user
     */
    public boolean isUsernameValid(String newUsername, String newPassword) {
        usernameAndPswd = new HashMap<>();
        
        // get all the usernames from the db
        try {            
            results = states.executeQuery(query);
            
            while(results.next()) {
                String username = results.getString("name");
                //String username = results.getString("username");
                String password = results.getString("password");
                usernameAndPswd.put(username, password);
            } // end while

        } // end try
        catch(Exception e) {
            System.err.println(e);
        } // end catch
        
        // check if new username alerady exists in the db.
        // if it exists, return false
        if(usernameAndPswd.containsKey(newUsername)) {
            return false; 
        } 
        // else return true and add it to the database
        else {
            // create the mysql insert preparedstatement
            try {
                //String query = " insert into binarygame_entity_user_Jiwon (username, password) values (?, ?)";
                String query = " insert into binarygame_entity_user_Jiwon (name, password) values (?, ?)";
                
                PreparedStatement preparedStmt = connect.prepareStatement(query);
                preparedStmt.setString (1, newUsername);
                preparedStmt.setString (2, newPassword);
                
                // execute the preparedstatement
                preparedStmt.execute();
                
            } catch (SQLException ex) {
                Logger.getLogger(MySQLConnect.class.getName()).log(Level.SEVERE, null, ex);
            }
            
            return true;
        }
    }

     /*
     * used for loging in
     *
     * get all usernames from the db and put into the hashmap.
     * if username exists and password is correct, log in the user.
     * else, alert the user that either the username or password is incorrect.
     */
    public boolean isLoginValid(String user_id, String pw) {
        usernameAndPswd = new HashMap<>();
        
        // put username and password into hashmap
         try {            
            results = states.executeQuery(query);

            while(results.next()) {
                //String username = results.getString("username");
                String username = results.getString("name");
                String password = results.getString("password");
                usernameAndPswd.put(username, password);
            } // end while
            
        } // end try
        catch(Exception e) {
            System.err.println(e);
        } // end catch

         // if username exists and password is correct, return true
         if(usernameAndPswd.containsKey(user_id) &&
                 ( pw.equals(usernameAndPswd.get(user_id) ))) {
             return true;
         } 
         // else return false
         else {
             return false;
         }
    }
    
     public void getTableData() {
        try {    
            results = states.executeQuery(query);
            
            System.out.println("Results from Database");
            
            while(results.next()) {
                String uniqueID = results.getString("user_id");
                String username = results.getString("username");
                String password = results.getString("password");
                System.out.printf("#%2s\tUsername: %s\tPassword: %s\n", uniqueID,username, password);
            } // end while
            
        } // end try
        catch(Exception e) {
            System.err.println(e);
        } // end catch
    } // end method getTableData
} // end class MySQLConnect