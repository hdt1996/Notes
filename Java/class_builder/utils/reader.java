package class_builder.utils;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.File;  
public class reader {
    public static void main(String[] args)
    {
        try
        {
            String wd_abs_path = new File("").getAbsolutePath();
            System.out.println("\nWork Dir Path: "+wd_abs_path);
            FileReader reader = new FileReader("./class_builder/templates/builder.java");
            int data = reader.read();
            while(data != -1)
            {
                System.out.print((char)data);
                data = reader.read();
            }
            reader.close();
        }
        catch (FileNotFoundException e)
        {
            e.printStackTrace();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
    
}
