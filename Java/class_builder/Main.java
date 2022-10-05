package class_builder;
import java.io.File;  
import java.io.FileNotFoundException; 
import java.util.Scanner;
//import java.util.regex.Pattern;
//import java.util.regex.Matcher;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args)
    {
        String wd_abs_path = new File("").getAbsolutePath();
        System.out.println("\nWork Dir Path: "+wd_abs_path);

        File tmp_build_file = new File("./class_builder/templates/builder.java");
        String tmp_build_relpath = tmp_build_file.getPath();
        String tmp_build_abspath = tmp_build_file.getAbsolutePath();
        
        System.out.println("Builder Template Relative Path: "+tmp_build_relpath);
        System.out.println("Builder Template Absolute Path: "+tmp_build_abspath);

        if(tmp_build_file.exists() && !tmp_build_file.isDirectory()) 
        { 
            System.out.println("Search Success: Template -- " + tmp_build_file);
        }
        else
        {
            throw new java.lang.Error("Template file for builder does not exist");
        }
        Scanner reader;

        try
        {
            reader = new Scanner(tmp_build_file);
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
