/*
 * CSC 18B 42029 - Java Programming
 * Individual Project: Binary Game
 *
 * File name: GameThread.java
 * Coded by : Jiwon Yoo
 */

package BinaryGame.Main.Game;

import java.util.Random;
//import java.util.Timer;
//import java.util.TimerTask;
/**
 *
 * @author Jiwon
 */
public class BinaryGeneratorThread extends Thread {

    private GameOneCompFrame game;
    private GameTwoCompFrame game2;
    private GameThreeCompFrame game3;
    
    private int numOfComp = 1;
    private int dec;
    private int previous_dec=0;
    private int mode;
    private boolean wrong = false;
    
    //private boolean running = false;
    //private boolean stopTime = false;
    
    private static final Random rand = new Random();
//    private static Timer timer = new Timer();
//    private static Timer timer2 = new Timer();
    public BinaryGeneratorThread( GameOneCompFrame game ) {
        this.game = game;
        numOfComp = 1;
    }
    public BinaryGeneratorThread( GameTwoCompFrame game ) {
        game2 = game;
        numOfComp = 2;
    }
    public BinaryGeneratorThread( GameThreeCompFrame game) {
        game3 = game;
        numOfComp = 3;
    }
    
    @Override
    public void run() {        
        super.run();
//        if(!running)
          random_binary(mode);
        while(!this.isInterrupted()) {
            try {
//                random_binary( mode );
                    // if wrong generate new binary
                    if(wrong) {
                        random_binary(mode);
                        wrong = false;
                    }
                    
//                if(mode == 1) {
//                    Thread.sleep(2000);
//                    changePlayer();
//                } else if(mode == 2) {
//                    Thread.sleep(2000);
//                    changePlayer();
//                } else {
//                    Thread.sleep(2000);
//                    changePlayer();
//                }
            } catch(Exception e) {
                System.out.println(e.getStackTrace());
            }
        }
        
        //after 15 second, game/round is over
//        timer2.schedule(new GameOver(), 15000, 1);
//        
//        if(mode == 1) // easy mode 2 sec delay
//           timer.schedule(new Test(), 2000, 2000);
//        else if(mode == 2) // medium mode 2 sec delay
//           timer.schedule(new Test(), 2000, 2000); 
//        else // hard mode 3 sec delay
//           timer.schedule(new Test(), 3000, 3000);
    }
   
    /* increase wrong by 1 to change the given binary digit */
    public void isWrong() {
        wrong = true;
    }
    /* generate random binary based on the mode*/
    public void random_binary(int mode) {
        //running = true;
        String binary;
        if(mode == 1) {
            dec = rand.nextInt(16); // 0 to 15 = 4 digit binary    
            while(dec == previous_dec)
                dec = rand.nextInt(16);
            binary = String.format("%4s",Integer.toBinaryString(dec).replace(' ','0'));
            if(numOfComp == 1)
                game.setBinaryText(String.format("%4s",binary.replace(' ','0')));
            else if(numOfComp == 2)
                game2.setBinaryText(String.format("%4s",binary.replace(' ','0')));
            else
                game3.setBinaryText(String.format("%4s",binary.replace(' ','0')));
        } else if(mode == 2) {
            dec = rand.nextInt(64); // 0 to 63 = 6 digit binary     
            while(dec == previous_dec)
                dec = rand.nextInt(64);
            binary = String.format("%6s",Integer.toBinaryString(dec).replace(' ','0'));
            if(numOfComp == 1)
                game.setBinaryText(String.format("%4s",binary.replace(' ','0')));
            else if(numOfComp == 2)
                game2.setBinaryText(String.format("%4s",binary.replace(' ','0')));
            else
                game3.setBinaryText(String.format("%4s",binary.replace(' ','0')));
        } else {
            dec = rand.nextInt(256); // 0 to 255 = 8 digit binary   
            while(dec == previous_dec)
                dec = rand.nextInt(256);
            binary = String.format("%8s",Integer.toBinaryString(dec).replace(' ','0'));
            if(numOfComp == 1)
                game.setBinaryText(String.format("%4s",binary.replace(' ','0')));
            else if(numOfComp == 2)
                game2.setBinaryText(String.format("%4s",binary.replace(' ','0')));
            else
                game3.setBinaryText(String.format("%4s",binary.replace(' ','0')));
        }
        previous_dec = dec;
    }
    
    /* check player answer and return true if right, else false */
    public boolean checkAnswer(String text) {
        int player_answer = Integer.parseInt(text);
        if(player_answer == dec) {
            random_binary(mode);
           return true;   
        } else {
            return false;
        }
    }

    /* set mode of the game to easy, medium, or hard */
    public void setMode(int level) {
        mode = level;
    }

//    /* move over to the next player after a certain time period.*/
//    public void changePlayer() {
//        switch(numOfComp) {
//            case 1:
//                if(game.getTurn()==1)
//                    game.setTurn(2);
//                else
//                    game.setTurn(1);
//                break;
//            case 2:
//                if(game2.getTurn()==1)
//                    game2.setTurn(2);
//                else if(game2.getTurn()==2)
//                    game2.setTurn(3);
//                else
//                    game2.setTurn(1);
//                break;
//            case 3:
//                if(game3.getTurn()==1)
//                    game3.setTurn(2);
//                else if(game3.getTurn()==2)
//                    game3.setTurn(3);
//                else if(game3.getTurn()==3)
//                    game3.setTurn(4);
//                else
//                    game3.setTurn(1);
//                break;
//        }
//    }

//    public void stopTimer() {
//        stopTime = true;
//    }
//    
//    public class Test extends TimerTask {
//        @Override
//        public void run() {
//            random_binary(mode);
//            changePlayer();
//        }
//    }
//    
//    public class GameOver extends TimerTask {
//        @Override
//        public void run() {
//
//            System.exit(0);
//        }
//    }
}