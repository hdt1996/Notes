package gui.components;
//import javax.swing.JButton;
import javax.swing.JFrame;
//import javax.swing.border.Border;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
//import java.util.HashMap;
import class_builder.utils.constructor;

public class Window extends JFrame implements ActionListener 
{
    public Window(String[] required, String title, boolean border, int[] size, boolean resize, String background, String on_close)
    {
        constructor par_mgr = new constructor(required);
        par_mgr.setProperty("title", title);
        par_mgr.setProperty("border", border);
        par_mgr.setProperty("size", size);
        par_mgr.setProperty("resize", resize);
        par_mgr.setProperty("background", background);
        par_mgr.complyReqs();
        Background.processBackground(background, this);
        setVisible(true);
        setTitle(title); 
        //setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        setSize(size[0], size[1]);
        setResizable(resize);
        processOnClose(on_close);

        //Background.processBackground(background, this);

        //frame.setIconImage(logo.getImage());
        //getContentPane().setBackground(new Color(10,100,200));       
    }

    private void processOnClose(String on_close)
    {
        if (!on_close.equals(null))
        {
            switch (on_close)
            {
                case "Hide": this.setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE); break;
                case "Nothing": this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE); break;
                default: break;
            }
        }
    }

    @Override
    public void actionPerformed(ActionEvent e)
    {
        //if(e.getSource()==my_button)
        //{
         //   System.out.println("FOUND\n\n...");
        //}
    }
}