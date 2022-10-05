package Timing;

import java.util.Calendar;
import java.util.Timer;
import java.util.TimerTask;

public class Main {
    public static void main(String[] args)
    {
        Timer timer = new Timer();
        TimerTask task = new TimerTask() {
            int counter = 0;
            @Override
            public void run()
            {
                System.out.println("\nTask Complete: "+counter);
                counter++;
            }
        };
        
        TimerTask task2 = new TimerTask() {
            int counter = 0;
            @Override
            public void run()
            {
                System.out.println("\nTask2 Complete: "+counter);
                counter++;
            }
        
        };
        Calendar date = Calendar.getInstance();
        date.set(Calendar.YEAR,2022);
        date.set(Calendar.MONTH,Calendar.SEPTEMBER);
        date.set(Calendar.DAY_OF_MONTH,24);
        date.set(Calendar.HOUR_OF_DAY, 13);
        date.set(Calendar.MINUTE, 14);
        date.set(Calendar.SECOND, 45);
        date.set(Calendar.MILLISECOND, 0);

        //timer.schedule(task, 0);
        //timer.schedule(task, date.getTime()); //Schedule one time based on date
        //timer.scheduleAtFixedRate(task, 0, 1000); //Perform every 1 second
        timer.scheduleAtFixedRate(task, date.getTime(), 1000); 
        timer.scheduleAtFixedRate(task2, date.getTime(), 1000); 
    }
    
}
