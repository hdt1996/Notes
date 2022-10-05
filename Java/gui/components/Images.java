package gui.components;
import java.awt.Image;
import javax.swing.ImageIcon;

public class Images {
    public ImageIcon makeIcon()
    {
        ImageIcon logo = new ImageIcon("./gui/static/enzyme_logo.jpg");
        Image resized_logo = logo.getImage();
        ImageIcon resized_icon = new ImageIcon(resized_logo.getScaledInstance(120,120, java.awt.Image.SCALE_SMOOTH));
        return resized_icon;
    }
    public Image makeImage()
    {
        ImageIcon logo = new ImageIcon("./gui/static/enzyme_logo.jpg");
        Image resized_logo = logo.getImage();
        ImageIcon resized_icon = new ImageIcon(resized_logo.getScaledInstance(120,120, java.awt.Image.SCALE_SMOOTH));
        resized_logo = resized_icon.getImage();
        return resized_logo;
    }
    
}
