package Threads;


class newThread extends Thread{
    @Override
    public void run()
    {
        System.out.println("New Thread is running");
    }
}

public class Main {
    public static void main(String[] args) throws InterruptedException
    {
        Thread.currentThread().setName("HUNGY BOI");
        String th_name = Thread.currentThread().getName();
        System.out.println("\n"+th_name);
        Thread.currentThread().setPriority(10);
        int priority = Thread.currentThread().getPriority();
        //Priority from 1 lowest to 10 highest
        System.out.println("\n Priority: "+priority);
        boolean is_alive = Thread.currentThread().isAlive();
        System.out.println("\n Thread Alive: "+is_alive);

        for ( int i = 2; i > 0; i--)
        {
            System.out.print(i);
            Thread.sleep(1000);
        }
        System.out.println("DONE....\n");

        newThread thread2 = new newThread();
        thread2.setName("2nd Thread");
        thread2.setDaemon(true);
        thread2.start();
        System.out.println(thread2.isAlive());
        System.out.println(thread2.getName());
        System.out.println(thread2.getPriority());

        System.out.println("Thread2 is Daemon: "+thread2.isDaemon()); //Daemon threads are ran in background for tasks such as garbage collection
        System.out.println("ALL THREAD COUNT: "+Thread.activeCount());

    }
}
