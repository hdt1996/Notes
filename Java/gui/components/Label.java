package gui.components;

import java.awt.Font;
import java.awt.Color;
import javax.swing.JLabel;

public class Label {
    public JLabel makeLabel()
    {
        JLabel label = new JLabel();
        label.setText("About this Application");
        //label.setIcon(resized_icon);
        label.setHorizontalTextPosition(JLabel.CENTER);
        label.setVerticalTextPosition(JLabel.BOTTOM);
        label.setForeground(Color.RED);
        label.setFont(new Font("Times New Roman", Font.PLAIN,50));
        label.setIconTextGap(-5);
        label.setBackground(Color.black);
        label.setOpaque(true);
        //label.setBorder(border);
        label.setVerticalAlignment(JLabel.CENTER);
        label.setHorizontalAlignment(JLabel.CENTER);
        //label.setBounds(0,0,400,200);
        return label;
    }
}
