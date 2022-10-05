package Serializer;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.ObjectStreamClass;
import java.io.Serializable;

class User implements Serializable{
    String name;
    String password;
}

public class Main {
    private static void serialize()
    {
        try
        {
            User user = new User();
            user.name = "Hung";
            user.password="HELLO";
            FileOutputStream fileout = new FileOutputStream("UserInfo.ser");
            ObjectOutputStream obj = new ObjectOutputStream(fileout);
            obj.writeObject(user);
            obj.close();
            fileout.close();
            System.out.println("\n\nObject saved\n\n");
            long ser_ver_id = ObjectStreamClass.lookup(user.getClass()).getSerialVersionUID();
            System.out.println("Serialization ID: "+ser_ver_id);
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

    private static void deserialize()
    {
        try
        {
            User user = null;
            FileInputStream filein = new FileInputStream("./UserInfo.ser");
            ObjectInputStream in = new ObjectInputStream(filein);
            user = (User) in.readObject();
            in.close();
            filein.close();
            System.out.println("Read Object Success: "+user.name+"----"+user.password);
        }
        catch( FileNotFoundException e)
        {
            e.printStackTrace();

        }
        catch( IOException e)
        {
            e.printStackTrace();

        }
        catch( ClassNotFoundException e)
        {
            e.printStackTrace();

        }

    } 
    public static void main(String[] args)
    {

        String wd_abs_path = new File("").getAbsolutePath();
        System.out.println("\nWork Dir Path: "+wd_abs_path);
        serialize();
        deserialize();
    }
    
}
