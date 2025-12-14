import java.util.ArrayList;
import java.util.List;



public abstract class Pizza
{
    protected String name;
    protected String dough;
    protected String sauce;
    protected List<String> toppings = new ArrayList<String>();



    public void prepare()
    {
        System.out.println("準備中: " + name);
        System.out.println("生地をこねています...");
        System.out.println("ソースを追加しています...");
        System.out.println("トッピングを追加しています:");

        for (String topping : toppings)
            System.out.println("  " + topping);
    }

    public void bake()
    {
        System.out.println("焼いています: 25分間で180度");
    }

    public void cut()
    {
        System.out.println("ピザを扇形にカットしています");
    }

    public void box()
    {
        System.out.println("ピザをオリジナルのボックスに詰めています");
    }

    public String getName()
    {
        return name;
    }
}
