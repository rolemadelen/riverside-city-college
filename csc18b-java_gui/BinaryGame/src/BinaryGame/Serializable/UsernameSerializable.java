/*
 * CSC 18B 42029 - Java Programming
 * Individual Project: Binary Game
 *
 * File name: UsernameSerializable.java
 * Coded by : Jiwon Yoo
 */

package BinaryGame.Serializable;

import java.io.Serializable;

/**
 * 
 * @author astraea
 */
public class UsernameSerializable implements Serializable {
    private String username;

    // no-argument constructor
    public UsernameSerializable() {
        this("username");
    } // end no-argument constructor
    
    // one-argument constructor
    public UsernameSerializable(String _username) {
        username = _username;
    } // end one-argument constructor

    // get username
    public String getUsername() {
        return username;
    } // end method getUsername

    // set username
    public void setUsername(String username) {
        this.username = username;
    } // end method setUsername
} // end class UsernameSerializable
