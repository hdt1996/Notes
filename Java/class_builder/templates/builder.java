
package class_builder.templates;
import class_builder.utils.constructor;

class Target
{
    String name;
    int age;
    String motto;

    public Target(String[] required, String _name, int _age, String _motto)
    {
        constructor par_mgr = new constructor(required);
        name = par_mgr.setProperty("name", _name);
        age = _age;
        motto = _motto;
        par_mgr.complyReqs();
        System.out.println(par_mgr.defaultMessage);
    }
}

class builder
{
    private String _name;
    private int _age = 14;   
    private String _motto = ""; 
    private String[] required = new String[]{"name"};

    public builder() {}

    public Target buildTarget()
    {
        return new Target(required, _name, _age, _motto);
    }

    public builder name(String _name)
    {
        this._name = _name;
        return this;
    }

    public builder age(int _age)
    {
        this._age = _age;
        return this;
    }

    public builder motto(String _motto)
    {
        this._motto = _motto;
        return this;
    }

    public static void main (String[] args)
    {
        Target builder = new builder()
            .name("Hungypoo")
            .age(15).buildTarget();
        System.out.println(builder);
    }
}