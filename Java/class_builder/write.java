package class_builder;
import java.io.File;  
import java.io.FileNotFoundException; 
import java.util.Scanner;
//import java.util.regex.Pattern;
//import java.util.regex.Matcher;
import java.util.ArrayList;

public class write {
    public static void main(String[] args)
    {
        String currPath = new File("").getAbsolutePath();
        System.out.println("\nWork Dir Path: "+currPath);

        File temp_builder = new File("./class_builder/templates/builder.java");
        if(temp_builder.exists() && !temp_builder.isDirectory()) 
        { 
            System.out.println("Search Success: Template -- " + temp_builder);
        }
        else
        {
            throw new java.lang.Error("Template file for builder does not exist");
        }
        Scanner reader;

        try
        {
            reader = new Scanner(temp_builder);
        }
        catch (FileNotFoundException e)
        {
            throw new java.lang.Error(e);
        }

        

        ArrayList<String> lines = new ArrayList<String>();

        while (reader.hasNextLine())
        {
            String line = reader.nextLine();
            lines.add(line);
        }
        System.out.print("FINAL LINES:\n"+String.join("\n",lines));
        reader.close();

        
        
    }
    
}
