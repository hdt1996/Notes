package class_interface;

import class_interface.examples.hawk;
import class_interface.examples.mouse;

public class Main{
    public static void main(String[] args)
    {
        mouse mse = new mouse();
        mse.flee();
        hawk hwk = new hawk();
        hwk.hunt();
    }
}
