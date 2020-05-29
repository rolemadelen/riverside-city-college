/*
 * CSC 18B 42029 - Java Programming
 * Individual Project: Binary Game
 *
 * File name: OptionSerializable.java
 * Coded by : Jiwon Yoo
 */

package BinaryGame.Serializable;

import java.io.Serializable;

/**
 *
 * @author astraea
 */
public class OptionSerializable implements Serializable{
    private int volume;
    
    // no-argument contructor calls other contstructor w/ default values
    public OptionSerializable() {
        this(90);
    } // end no-argument constructor
   
    // four-argument constructor initializes a record
    public OptionSerializable(int _volume) {
        setVolume(_volume);
    } // end four-argument constructor

    // set volume
    public void setVolume(int _volume) {
        volume = _volume;
    } // end method  setVolume
    
    // get volume
    public int getVolume() {
        return volume;
    } // end method getVolume
} // end class BinaryGameSerializable
