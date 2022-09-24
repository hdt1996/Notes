package class_builder.utils;

import java.util.HashMap;

public class constructor
{
    public String defaultMessage = "This is default";
    HashMap<String, Object> required_params = new HashMap<String, Object>();

    private final void add(String key)
    {
        required_params.put(key, null);
        System.out.println(required_params);
    }
    public constructor(String[] req_args){
        for(int a = 0; a < req_args.length; a++)
        {
            add(req_args[a]);
        }
    }
    public final String setProperty(String key, String val)
    {
        if(required_params.containsKey(key))
        {
            required_params.put(key, val);
        }
        return val;
    }    
    final int setProperty(String key, int val)
    {
        if(required_params.containsKey(key))
        {
            required_params.put(key, val);
        }
        return val;
    }

    public final void complyReqs()
    {
        for (HashMap.Entry<String, Object> kv : required_params.entrySet())
        {
            String k = kv.getKey();
            Object value = kv.getValue();
            if (value == null)
            {
                throw new java.lang.Error(String.format("Missing value for required argument - '%s'", k));
            }
        }
    }

}