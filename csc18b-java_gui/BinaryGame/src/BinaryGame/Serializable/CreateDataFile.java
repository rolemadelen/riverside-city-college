/*
 * CSC 18B 42029 - Java Programming
 * Individual Project: Binary Game
 *
 * File name: CreateDataFile.java
 * Coded by : Jiwon Yoo
 */

package BinaryGame.Serializable;

import java.io.*;

/**
 *
 * @author astraea
 */
public class CreateDataFile {
    private ObjectOutputStream output; // outputs data to file
    private OptionSerializable option_record; // obj to be written to file
    private UsernameSerializable username_record; // obj to be written to file
   
    // open file for option data
    public void openFile(OptionSerializable option) {
        try // open file
        {
            output = new ObjectOutputStream(
                new FileOutputStream("option_data.txt"));
        } // end try
        catch (IOException ie){
            System.err.println("Error opening file.");
        } // end catch
    } // end method openFile
    
    // open file for username data
    public void openFile(UsernameSerializable user) {
        try // open file
        {
            output = new ObjectOutputStream(
                new FileOutputStream("username_data.txt"));
        } // end try
        catch (IOException ie){
            System.err.println("Error opening file.");
        } // end catch
    } // end method openFile
    
    // add records to file for option data
    public void addRecords(OptionSerializable _record) {        
        try // output values to file
        {            
            option_record = new OptionSerializable(_record.getVolume());
            output.writeObject(option_record);
        } // end try
        catch ( IOException ie ) {
            System.err.println("Error writing to file.");
            return;
        } // end catch
    } // end methd addRecords

    // add records to file for username data
    public void addRecords(UsernameSerializable _record) {        
        try // output values to file
        {            
            username_record = new UsernameSerializable(_record.getUsername());
            output.writeObject(username_record);
        } // end try
        catch ( IOException ie ) {
            System.err.println("Error writing to file.");
            return;
        } // end catch
    } // end methd addRecords

    // close file
    public void closeFile() {
        try // close file
        {
            if( output != null )
                output.close();
        } // end try
        catch (IOException ie) {
            System.err.println("Error closing file");
            System.exit(0);
        } // end catch
    } // end method closeFile
} // end class CreateDataFile
