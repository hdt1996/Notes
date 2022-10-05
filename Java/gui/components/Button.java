package gui.components;

import javax.swing.JButton;

public class Button {
    public static JButton makeButton()
    {
        JButton button = new JButton();
        button.setBounds(200,100,100,50);
        return button;
    }
}
