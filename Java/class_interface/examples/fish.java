package class_interface.examples;

public class fish implements prey, predator{
    public void hunt()
    {
        System.out.println("Fish is hunting...");
    }
    public void flee()
    {
        System.out.println("Fish is fleeing...");
    }
    
}
