package gui;
import gui.components.Builder_Window;
import gui.components.Window;
//import gui.components.Icons;
//import gui.components.Label;
//import gui.components.Button;

public class Main {
    public static void main(String[] args)
    {
        Window window = new Builder_Window()
            .title("Enzyme")
            .background("./gui/static/enzyme_logo.jpg")
            .size(new int[]{500,500})
            .resize(true)
            .on_close("Nothing")
            .buildObject();
    }
}
