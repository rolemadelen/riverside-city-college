/*
 * CSC 18B 42029 - Java Programming
 * Individual Project: Binary Game
 *
 * File name: Option.java
 * Coded by : Jiwon Yoo
 */

package BinaryGame.Main;

import BinaryGame.Serializable.*;
import java.io.*;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.sound.sampled.*;
import javax.swing.JOptionPane;
import sun.audio.*;

/**
 * class Option contains following methods:
 *      void playBGM();
 *      void applyChanges();
 *      String changeKeySetting();
 *      void soundEffect();
 * 
 * @author astraea
 */
public class Option {    
    /*
     * playBGM method reads an audio file and
     * plays the audio continuously.
     */
    protected static void playBGM( String path ) {
         // add bgm and loop continuously
        File audioFile = new File(path);
        try {
            AudioInputStream audioStream = AudioSystem.getAudioInputStream(audioFile);
            AudioFormat format = audioStream.getFormat();
            DataLine.Info info = new DataLine.Info(Clip.class, format);
            Clip audioClip = null;
            try {
                audioClip = (Clip) AudioSystem.getLine(info);
            } catch (LineUnavailableException ex) {
                Logger.getLogger(Option.class.getName()).log(Level.SEVERE, null, ex);
            }
            try {
                audioClip.open(audioStream);
            } catch (LineUnavailableException ex) {
                Logger.getLogger(Option.class.getName()).log(Level.SEVERE, null, ex);
            }
            
            audioClip.loop(Clip.LOOP_CONTINUOUSLY);
            //audioClip.close();
            audioStream.close();
            
//            FloatControl gainControl = (FloatControl) audioClip.getControl(FloatControl.Type.MASTER_GAIN);
//            gainControl.setValue(-10.0f);
        } catch (UnsupportedAudioFileException ex) {
            Logger.getLogger(MainFrame.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(MainFrame.class.getName()).log(Level.SEVERE, null, ex);
        }
       
    }
    
    /* stopBGM method closes audioStream */
    protected static void stopBGM() {
        ;
    }
    
    /*
     * changeVolume method changes the
     * current audio volume.
     */
    protected static void applyChanges(int changeVolume) {
        // serialze option frame
        OptionSerializable record = new OptionSerializable();
        CreateDataFile data = new CreateDataFile();
        
        record.setVolume(changeVolume);
        
        data.openFile(record);
        data.addRecords(record);
        data.closeFile();
    } // end method applayChanges
    
    /*
    * Get a sound flie path as a parameter,
    * open the file as a FileInputStream and play the audio.
    * Mainly used for buttons' audio effect
    */
    public static void soundEffect(String dest) {
        try {
            InputStream in;
            in = new FileInputStream(new File(dest));
            AudioStream audio = new AudioStream(in);
            AudioPlayer.player.start(audio);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(null, e);
        } // end catch
    } // end method soundEffect
} // end class Option
