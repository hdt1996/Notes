package audio;
import java.io.File;
import java.io.IOException;
import java.util.Scanner;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;

public class Main{
    public static void main(String[] args) throws UnsupportedAudioFileException, IOException, LineUnavailableException
    {
        File audio_file = new File("./audio/music.wav");
        AudioInputStream audioStream = AudioSystem.getAudioInputStream(audio_file);
        Clip clip = AudioSystem.getClip();
        clip.open(audioStream);
        Scanner scanner = new Scanner(System.in);
        String response = "";

        while(!response.equals("4"))
        {
            System.out.println("Audio Manager Options\n....................\n1)Start\n2)Pause\n3)Reset\n4)Quit");
            System.out.println("....................");
            response = scanner.next();
            switch(response)
            {
                case "1":
                    clip.start();
                    break;
                case "2":
                    clip.stop();
                    break;
                case "3":
                    clip.setMicrosecondPosition(0);
                    break;
                case "4":
                    clip.stop();
                    break;
                default:
                    System.out.println("Not a valid response!");
            }
            System.out.println("\n");
        }
        scanner.close();


    }
}

