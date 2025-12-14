import java.util.ArrayList;
import java.util.List;



public abstract class Pizza
{
    protected String name;
    protected Cheese cheese;
    protected Clams clams;
    protected Dough dough;
    protected Pepperoni pepperoni;
    protected Sauce sauce;
    protected Veggies[] veggies;



    public abstract void prepare();

    public void bake()
    {
        System.out.println("焼いています: 25分間で180度");
    }

    public void cut()
    {
        System.out.println("ピザを四角くカットしています");
    }

    public void box()
    {
        System.out.println("ピザをオリジナルのボックスに詰めています");
    }



    public void setName(String name)
    {
        this.name = name;
    }

    public String getName()
    {
        return name;
    }

    public String toString()
    {
        StringBuilder result = new StringBuilder();



        result.append("---- " + name + " ----\n");

        if (cheese != null)
            result.append(cheese + "\n");
        if (clams != null)
            result.append(clams + "\n");
        if (dough != null)
            result.append(dough + "\n");
        if (pepperoni != null)
            result.append(pepperoni + "\n");
        if (sauce != null)
            result.append(sauce + "\n");
        if (veggies != null)
        {
            for (Veggies veggie : veggies)
                result.append(veggie + "\n");
        }
        
        

        return result.toString();
    }
}
