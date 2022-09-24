import java.util.Scanner;
import javax.swing.JOptionPane;

abstract class ABS_PRINTER{
    abstract void print1();
    abstract void print2();
}


class Terminal{
    Scanner scanner;
    private void prompt(String category, Class<?> dtype)
    {
        System.out.print(String.format("What is your %s", category)+": ");
        if(dtype == String.class)
        {
            String response = scanner.nextLine();
            System.out.println(String.format("Your %s is %s ", category, response)+"\n");

        }
        else if(dtype == int.class)
        {
            int response = scanner.nextInt();
            scanner.nextLine();
            System.out.println(String.format("Your %s is %s ", category, response)+"\n");
        }
    }
    public void makePrompt(String[] categories, Class<?>[] dtypes)
    {
        scanner = new Scanner(System.in);
        if (categories.length >= 10 | dtypes.length >=10 )
        {
            throw new java.lang.Error("Too many categories. Please reduce");
        }
        for(int i = 0; i < categories.length; i++)
        {
            prompt(categories[i], dtypes[i]);
        }
        scanner.close();
    }
}

class GUI{
    Scanner scanner;
    void gui(String category, Class<?> dtype)
    {
        if(dtype == String.class)
        {
            String response = JOptionPane.showInputDialog(String.format("What is your %s", category));
            JOptionPane.showMessageDialog(null, String.format("Your %s is %s",category,response));

        }
        else if(dtype == int.class)
        {
            int response = Integer.parseInt(JOptionPane.showInputDialog(String.format("What is your %s", category)));
            JOptionPane.showMessageDialog(null, String.format("Your %s is %s",category,response));
        }
        else if(dtype == double.class)
        {
            double response = Double.parseDouble(JOptionPane.showInputDialog(String.format("What is your %s", category)));
            JOptionPane.showMessageDialog(null, String.format("Your %s is %s",category,response));
        }
    }

    public void makeGUI(String[] categories, Class<?>[] dtypes)
    {
        scanner = new Scanner(System.in);
        if (categories.length >= 10 | dtypes.length >=10 )
        {
            throw new java.lang.Error("Too many categories. Please reduce");
        }
        for(int i = 0; i < categories.length; i++)
        {
            gui(categories[i], dtypes[i]);
        }
        scanner.close();
    }
}


class Data_Math{
    double x = 3.14;
    double y = -10;

    double a = Math.max(x,y);
    double b = Math.abs(x);
    double c = Math.sqrt(x);
    double d = Math.floor(x);
    double e = Math.ceil(x);


    public void calculate()
    {
        System.out.println(a);
    }
}

public class Main {
    private class PRINTER extends ABS_PRINTER{
        void print1(){
            System.out.print("\nPrint1\n");
        }
        void print2(){
            System.out.print("\nPrint2\n");
        }
    }
    void caller(){
        System.out.print("\nCALLED CALLER\n");
    }
    public static void main(String[] args){
        Main util = new Main();
        Main.PRINTER printer = util.new PRINTER();
        printer.print1();
        util.caller();

        Terminal my_prompt = new Terminal();
        my_prompt.makePrompt(new String[]{"Name","Job","Age","Phone Number"},new Class<?>[]{String.class, String.class, int.class, String.class});

        GUI my_gui = new GUI();
        my_gui.makeGUI(new String[]{"Name","Job","Age","Phone Number"},new Class<?>[]{String.class, String.class, int.class, String.class});

    }
    
}
