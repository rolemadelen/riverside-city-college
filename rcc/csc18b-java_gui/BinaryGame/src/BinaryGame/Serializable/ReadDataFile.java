/*
 * CSC 18B 42029 - Java Programming
 * Individual Project: Binary Game
 *
 * File name: ReadDataFile.java
 * Coded by : Jiwon Yoo
 */

package BinaryGame.Serializable;

import java.io.*;

/**
 *
 * @author astraea
 */
public class ReadDataFile {
    private ObjectInputStream input;
    
    // open file for option data
    public void openFile(OptionSerializable option) {
        try // open file
        {
             input = new ObjectInputStream(new FileInputStream("option_data.txt"));
        } // end try
        catch (IOException ie) {
            System.err.println("Error opening file.");
        } // end catch
    } // end method openFile
    
    // open file for username data
    public void openFile(UsernameSerializable user) {
        try // open file
        {
             input = new ObjectInputStream(new FileInputStream("username_data.txt"));
        } // end try
        catch (IOException ie) {
            System.err.println("Error opening file.");
        } // end catch
    } // end method openFile
    
    
    // read record from option_data file
    public OptionSerializable readRecords(OptionSerializable option) {
        OptionSerializable record;
        
        try // input the values from the file
        {
            while(true) {
                record = (OptionSerializable) input.readObject();
                return record;
            }// end while
        } // end try
        catch ( EOFException eofe) {
            return null; // end of file was reached
        } // end catch
        catch (ClassNotFoundException ce) {
            System.err.println("Unable to create object.");
        } // end catch
        catch (IOException ie) {
            System.err.println("Error during read from file");
        } // end catch
        return null;
    } // end method readRecords()
    
     // read record from username_data file
    public UsernameSerializable readRecords(UsernameSerializable user) {
        UsernameSerializable record;
        
        try // input the values from the file
        {
            while(true) {
                record = (UsernameSerializable) input.readObject();
                return record;
            }// end while
        } // end try
        catch ( EOFException eofe) {
            return null; // end of file was reached
        } // end catch
        catch (ClassNotFoundException ce) {
            System.err.println("Unable to create object.");
        } // end catch
        catch (IOException ie) {
            System.err.println("Error during read from file");
        } // end catch
        return null;
    } // end method readRecords()
    
    // close file 
    public void closeFile() {
        try // close file and exit
        {
            if(input != null)
                input.close();
        } // end try
        catch (IOException ie) {
            System.err.println("Error closing file");
            System.exit(0);
        } // end catch
    } // end method closeFile
} // end class ReadDataFile
