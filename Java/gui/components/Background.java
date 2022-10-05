package gui.components;
import java.awt.Color;
import java.io.File;

import javax.swing.JComponent;
import javax.swing.JFrame;
import java.awt.Image;
import java.awt.Graphics;

class Component_IMG extends JComponent
{
    private Image image;
    public Component_IMG(Image image)
    {
        this.image = image;
    }
    @Override
    protected void paintComponent(Graphics g)
    {
        super.paintComponent(g);
        g.drawImage(image, 0, 0, this);
    }
}




public class Background
{
    static private int[] parseRGBStr(String[] str_arr)
    {
        int[] int_arr = new int[3];
        for (int index = 0; index < str_arr.length; index++)
        {
            String phr = str_arr[index];
            phr = phr.trim();
            try
            {
                int_arr[index]=Integer.parseInt(phr);
            }
            catch (NumberFormatException e)
            {
                throw new java.lang.Error(e);
            }
        }
        return int_arr;
    }

    static JComponent parseIMGFile()
    {
        Images test = new Images();
        Image test_img = test.makeImage();
        JComponent img_comp = new Component_IMG(test_img);
        return img_comp;
    }

    static public void processBackground(String background, JFrame window)
    {
        if(background == null){ return; }
        String[] str_arr = background.split("\\,");

        if (str_arr.length == 3)
        {
            int[] int_arr=parseRGBStr(str_arr);
            window.getContentPane().setBackground(new Color(int_arr[0],int_arr[1],int_arr[2]));
            return ;  
        }
        
        File file = new File(background);
        if (file.exists())
        {
            JComponent comp_img = parseIMGFile();
            window.setContentPane(comp_img);
            System.out.println("Background Input: "+file.getAbsolutePath());
            System.out.println("Input File Exists: "+file.exists());
        }
    }
}
