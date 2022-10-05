package MultiThread;

class newThread extends Thread{ //Initial way of creating Threads
    @Override
    public void run()
    {
        int iter = 30;
        int index = 0;
        while(iter>0)
        {
            System.out.println("Thread 1:------------"+index);
            index++;
            iter--;
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            int error = 5/0;
        }
        System.out.println("Finished");
    }
}

class MyRunnable implements Runnable ///Other way of creating Threads
{
    @Override
    public void run()
    {
        int iter = 30;
        int index = 0;
        while(iter>0)
        {
            System.out.println("Thread 2:------"+index);
            index++;
            iter--;
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        System.out.println("Finished");
    }

}

public class Main {
    public static void main(String[] args) throws InterruptedException
    {
        MyRunnable run_1 = new MyRunnable();
        Thread thread2 = new Thread(run_1);
        Thread thread3 = new newThread();
        thread2.start();
        thread2.join();
        thread3.start();
    }
}
