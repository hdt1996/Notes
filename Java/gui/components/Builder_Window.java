package gui.components;
//import java.awt.Color;
//import java.io.File;
//import javax.swing.BorderFactory;



public class Builder_Window
{
    String title;
    boolean border;
    int age;
    int[] size;
    boolean resize;
    String motto;
    String background;
    String on_close;
    private String[] required = new String[]{"title"};

    public Builder_Window() {}

    public Window buildObject()
    {
        return new Window(required, title, border, size, resize, background, on_close);
    }

    public Builder_Window title(String title)
    {
        this.title = title; return this;
    }

    public Builder_Window border(boolean border)
    {
        this.border = border; return this;
    }
    public Builder_Window size(int[] size)
    {
        this.size = size; return this;
    }
    public Builder_Window resize(boolean resize)
    {
        this.resize = resize; return this;
    }
    public Builder_Window background(String background)
    {
        this.background = background; return this;
    }
    public Builder_Window on_close(String on_close)
    {
        this.on_close = on_close; return this;
    }
}