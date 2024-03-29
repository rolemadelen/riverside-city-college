/*
 * CSC 18B 42029 - Java Programming
 * Individual Project: Binary Game
 *
 * File name: GameModeFrame.java
 * Coded by : Jiwon Yoo
 */
package BinaryGame.Main;

import BinaryGame.Main.Game.*;
import java.awt.Color;

/**
 *
 * @author Jiwon
 */
public class GameModeFrame extends javax.swing.JFrame {

    private static BinaryGeneratorThread thread; 

    private int numberOfComputer = 1; /* 1, 2, or 3 */
    private int level = 1; /* 1 = easy, 2 = medium, 3 = hard */
    /**
     * Creates new form SelectPlayerFrame
     */
    public GameModeFrame() {
        initComponents();
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
        credit = new javax.swing.JLabel();
        selectMode = new javax.swing.JLabel();
        hardMode = new javax.swing.JLabel();
        easyMode = new javax.swing.JLabel();
        mediumMode = new javax.swing.JLabel();
        hardLimit = new javax.swing.JLabel();
        easyLimit = new javax.swing.JLabel();
        medLimit = new javax.swing.JLabel();
        selectNumOfComp = new javax.swing.JLabel();
        oneCompText = new javax.swing.JLabel();
        twoCompText = new javax.swing.JLabel();
        threeCompText = new javax.swing.JLabel();
        oneComp = new javax.swing.JLabel();
        twoComp = new javax.swing.JLabel();
        threeComp = new javax.swing.JLabel();
        playLabel = new javax.swing.JLabel();
        backLabel = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Binary Game");
        setAlwaysOnTop(true);
        setUndecorated(true);
        setResizable(false);

        panel.setBackground(new java.awt.Color(0, 0, 0));
        panel.setMaximumSize(new java.awt.Dimension(800, 700));
        panel.setMinimumSize(new java.awt.Dimension(800, 700));
        panel.setName("Binary Game"); // NOI18N
        panel.setPreferredSize(new java.awt.Dimension(800, 700));
        panel.setLayout(null);

        credit.setForeground(new java.awt.Color(51, 51, 51));
        credit.setText("Jiwon Yoo");
        panel.add(credit);
        credit.setBounds(10, 680, 90, 20);

        selectMode.setFont(new java.awt.Font("Tahoma", 0, 56)); // NOI18N
        selectMode.setForeground(new java.awt.Color(255, 255, 255));
        selectMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/selectMode.png"))); // NOI18N
        panel.add(selectMode);
        selectMode.setBounds(20, 30, 550, 70);

        hardMode.setFont(new java.awt.Font("Tahoma", 0, 48)); // NOI18N
        hardMode.setForeground(new java.awt.Color(255, 255, 255));
        hardMode.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        hardMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/hardMode.png"))); // NOI18N
        hardMode.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        hardMode.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                hardModeMouseClicked(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                hardModeMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                hardModeMouseExited(evt);
            }
        });
        panel.add(hardMode);
        hardMode.setBounds(550, 130, 180, 60);

        easyMode.setFont(new java.awt.Font("Tahoma", 0, 48)); // NOI18N
        easyMode.setForeground(new java.awt.Color(255, 255, 255));
        easyMode.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        easyMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/easyModeHover.gif"))); // NOI18N
        easyMode.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        easyMode.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                easyModeMouseClicked(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                easyModeMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                easyModeMouseExited(evt);
            }
        });
        panel.add(easyMode);
        easyMode.setBounds(50, 130, 190, 60);

        mediumMode.setFont(new java.awt.Font("Tahoma", 0, 48)); // NOI18N
        mediumMode.setForeground(new java.awt.Color(255, 255, 255));
        mediumMode.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        mediumMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/mediumMode.png"))); // NOI18N
        mediumMode.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        mediumMode.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                mediumModeMouseClicked(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                mediumModeMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                mediumModeMouseExited(evt);
            }
        });
        panel.add(mediumMode);
        mediumMode.setBounds(270, 130, 260, 60);

        hardLimit.setFont(new java.awt.Font("Ubuntu", 0, 12)); // NOI18N
        hardLimit.setForeground(java.awt.Color.gray);
        hardLimit.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        hardLimit.setText("0000 0000 - 1111 1111");
        panel.add(hardLimit);
        hardLimit.setBounds(570, 190, 130, 15);

        easyLimit.setFont(new java.awt.Font("Ubuntu", 0, 12)); // NOI18N
        easyLimit.setForeground(java.awt.Color.green);
        easyLimit.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        easyLimit.setText("0000 - 1111");
        panel.add(easyLimit);
        easyLimit.setBounds(100, 190, 80, 15);

        medLimit.setFont(new java.awt.Font("Ubuntu", 0, 12)); // NOI18N
        medLimit.setForeground(java.awt.Color.gray);
        medLimit.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        medLimit.setText("000000 - 111111");
        panel.add(medLimit);
        medLimit.setBounds(340, 190, 110, 15);

        selectNumOfComp.setFont(new java.awt.Font("Tahoma", 0, 56)); // NOI18N
        selectNumOfComp.setForeground(new java.awt.Color(255, 255, 255));
        selectNumOfComp.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/numOfComp.png"))); // NOI18N
        panel.add(selectNumOfComp);
        selectNumOfComp.setBounds(20, 330, 620, 70);

        oneCompText.setForeground(java.awt.Color.green);
        oneCompText.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        oneCompText.setText("1");
        panel.add(oneCompText);
        oneCompText.setBounds(90, 580, 80, 18);

        twoCompText.setForeground(java.awt.Color.gray);
        twoCompText.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        twoCompText.setText("10");
        panel.add(twoCompText);
        twoCompText.setBounds(330, 580, 80, 18);

        threeCompText.setForeground(java.awt.Color.gray);
        threeCompText.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        threeCompText.setText("11");
        panel.add(threeCompText);
        threeCompText.setBounds(600, 580, 80, 18);

        oneComp.setFont(new java.awt.Font("Tahoma", 0, 48)); // NOI18N
        oneComp.setForeground(new java.awt.Color(255, 255, 255));
        oneComp.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        oneComp.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/test.png"))); // NOI18N
        oneComp.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        oneComp.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                oneCompMouseClicked(evt);
            }
        });
        panel.add(oneComp);
        oneComp.setBounds(30, 420, 200, 170);

        twoComp.setFont(new java.awt.Font("Tahoma", 0, 48)); // NOI18N
        twoComp.setForeground(new java.awt.Color(255, 255, 255));
        twoComp.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        twoComp.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/test2.png"))); // NOI18N
        twoComp.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        twoComp.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                twoCompMouseClicked(evt);
            }
        });
        panel.add(twoComp);
        twoComp.setBounds(270, 420, 200, 170);

        threeComp.setFont(new java.awt.Font("Tahoma", 0, 48)); // NOI18N
        threeComp.setForeground(new java.awt.Color(255, 255, 255));
        threeComp.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        threeComp.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/test3.png"))); // NOI18N
        threeComp.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        threeComp.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                threeCompMouseClicked(evt);
            }
        });
        panel.add(threeComp);
        threeComp.setBounds(530, 420, 200, 170);

        playLabel.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/play45.png"))); // NOI18N
        playLabel.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        playLabel.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                playLabelMouseClicked(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                playLabelMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                playLabelMouseExited(evt);
            }
        });
        panel.add(playLabel);
        playLabel.setBounds(590, 630, 160, 50);

        backLabel.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/back45.png"))); // NOI18N
        backLabel.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        backLabel.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                backLabelMouseClicked(evt);
            }
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                backLabelMouseEntered(evt);
            }
            public void mouseExited(java.awt.event.MouseEvent evt) {
                backLabelMouseExited(evt);
            }
        });
        panel.add(backLabel);
        backLabel.setBounds(40, 630, 160, 50);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(panel, javax.swing.GroupLayout.PREFERRED_SIZE, 800, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(panel, javax.swing.GroupLayout.PREFERRED_SIZE, 700, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void mediumModeMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_mediumModeMouseClicked
        Option.soundEffect("src/sound/Right Channel Scramble.wav");
        easyMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/easyMode.png")));
        mediumMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/mediumModeHover.gif")));
        hardMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/hardMode.png")));
        
        easyLimit.setForeground(java.awt.Color.gray);
        medLimit.setForeground(java.awt.Color.blue);
        hardLimit.setForeground(java.awt.Color.gray);
        
        level = 2; // set level to medium
    }//GEN-LAST:event_mediumModeMouseClicked

    private void hardModeMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_hardModeMouseClicked
        Option.soundEffect("src/sound/Right Channel Scramble.wav");
        easyMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/easyMode.png")));
        mediumMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/mediumMode.png")));
        hardMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/hardModeHover.gif")));
        
        easyLimit.setForeground(java.awt.Color.gray);
        medLimit.setForeground(java.awt.Color.gray);
        hardLimit.setForeground(java.awt.Color.red);
        
        level = 3; // set level to hard
    }//GEN-LAST:event_hardModeMouseClicked

    private void easyModeMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_easyModeMouseClicked
        Option.soundEffect("src/sound/Right Channel Scramble.wav");
        easyMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/easyModeHover.gif")));
        mediumMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/mediumMode.png")));
        hardMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/hardMode.png")));
        
        easyLimit.setForeground(java.awt.Color.green);
        medLimit.setForeground(java.awt.Color.gray);
        hardLimit.setForeground(java.awt.Color.gray);
        
        level = 1; // set level to easy
    }//GEN-LAST:event_easyModeMouseClicked

    private void easyModeMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_easyModeMouseEntered
        easyMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/easyModeHover.gif")));
        Option.soundEffect("src/sound/robot blip.wav");
    }//GEN-LAST:event_easyModeMouseEntered

    private void mediumModeMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_mediumModeMouseEntered
        mediumMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/mediumModeHover.gif")));        
        Option.soundEffect("src/sound/robot blip.wav");
    }//GEN-LAST:event_mediumModeMouseEntered

    private void hardModeMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_hardModeMouseEntered
        hardMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/hardModeHover.gif")));
        Option.soundEffect("src/sound/robot blip.wav");
    }//GEN-LAST:event_hardModeMouseEntered

    private void easyModeMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_easyModeMouseExited
        if( level != 1) // if easy mode is not selected
            easyMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/easyMode.png")));
    }//GEN-LAST:event_easyModeMouseExited

    private void mediumModeMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_mediumModeMouseExited
        if( level != 2) // if medium mode is not selected
            mediumMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/mediumMode.png")));
    }//GEN-LAST:event_mediumModeMouseExited

    private void hardModeMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_hardModeMouseExited
        if( level != 3) // if hard mode is not selected
            hardMode.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/hardMode.png")));
    }//GEN-LAST:event_hardModeMouseExited

    private void oneCompMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_oneCompMouseClicked
        Option.soundEffect("src/sound/Right Channel Scramble.wav");
        oneCompText.setForeground(Color.green);
        twoCompText.setForeground(Color.gray);
        threeCompText.setForeground(Color.gray);
        numberOfComputer = 1;
    }//GEN-LAST:event_oneCompMouseClicked

    private void twoCompMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_twoCompMouseClicked
        Option.soundEffect("src/sound/Right Channel Scramble.wav");
        oneCompText.setForeground(Color.gray);
        twoCompText.setForeground(Color.green);
        threeCompText.setForeground(Color.gray);
        numberOfComputer = 2;
    }//GEN-LAST:event_twoCompMouseClicked

    private void threeCompMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_threeCompMouseClicked
        Option.soundEffect("src/sound/Right Channel Scramble.wav");
        oneCompText.setForeground(Color.gray);
        twoCompText.setForeground(Color.gray);
        threeCompText.setForeground(Color.green);
        numberOfComputer = 3;
    }//GEN-LAST:event_threeCompMouseClicked

    private void playLabelMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_playLabelMouseEntered
        Option.soundEffect("src/sound/robot blip.wav");
        playLabel.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/play45Hover.gif")));
    }//GEN-LAST:event_playLabelMouseEntered

    private void playLabelMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_playLabelMouseExited
        playLabel.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/play45.png")));
    }//GEN-LAST:event_playLabelMouseExited

    private void playLabelMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_playLabelMouseClicked
         Option.soundEffect("src/sound/Right Channel Scramble.wav");
         
         if( numberOfComputer == 1) {
             GameOneCompFrame game = new GameOneCompFrame();
             game.setVisible(true);
             this.setVisible(false);
             thread = new BinaryGeneratorThread(game);
             thread.setMode( level );
             thread.start();
         } else if( numberOfComputer == 2) {
             GameTwoCompFrame game = new GameTwoCompFrame();
             game.setVisible(true);
             this.setVisible(false);
             thread = new BinaryGeneratorThread(game);
             thread.setMode( level );
             thread.start();
        } else {
             GameThreeCompFrame game = new GameThreeCompFrame();
             game.setVisible(true);
             this.setVisible(false);
             thread = new BinaryGeneratorThread(game);
             thread.setMode( level );
             thread.start();
         }
    }//GEN-LAST:event_playLabelMouseClicked

    public boolean checkAnswer(String str) {
        return (thread.checkAnswer(str));
    }
 
    public void wrong() {
        thread.isWrong();
    }
    public void stopThread() {
        thread.interrupt();
        thread = null;
        //thread.stopTimer();
    }
    
    private void backLabelMouseEntered(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_backLabelMouseEntered
        Option.soundEffect("src/sound/robot blip.wav");
        backLabel.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/back45Hover.gif")));
    }//GEN-LAST:event_backLabelMouseEntered

    private void backLabelMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_backLabelMouseExited
        backLabel.setIcon(new javax.swing.ImageIcon(getClass().getResource("/image/main menu/back45.png")));
    }//GEN-LAST:event_backLabelMouseExited

    private void backLabelMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_backLabelMouseClicked
        Option.soundEffect("src/sound/Right Channel Scramble.wav");
        PlayMenuFrame screen = new PlayMenuFrame();
        this.setVisible(false);
        screen.setVisible(true);
    }//GEN-LAST:event_backLabelMouseClicked


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JLabel backLabel;
    private javax.swing.JLabel credit;
    private javax.swing.JLabel easyLimit;
    private javax.swing.JLabel easyMode;
    private javax.swing.JLabel hardLimit;
    private javax.swing.JLabel hardMode;
    private javax.swing.JLabel medLimit;
    private javax.swing.JLabel mediumMode;
    private javax.swing.JLabel oneComp;
    private javax.swing.JLabel oneCompText;
    private javax.swing.JPanel panel;
    private javax.swing.JLabel playLabel;
    private javax.swing.JLabel selectMode;
    private javax.swing.JLabel selectNumOfComp;
    private javax.swing.JLabel threeComp;
    private javax.swing.JLabel threeCompText;
    private javax.swing.JLabel twoComp;
    private javax.swing.JLabel twoCompText;
    // End of variables declaration//GEN-END:variables
}
