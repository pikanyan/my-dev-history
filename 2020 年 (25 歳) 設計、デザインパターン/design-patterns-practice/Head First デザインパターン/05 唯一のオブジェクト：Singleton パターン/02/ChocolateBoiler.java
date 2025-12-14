public class ChocolateBoiler
{
    private static ChocolateBoiler uniqueInstance;

    private boolean empty;
    private boolean boiled;
    


    private ChocolateBoiler()
    {
        empty = true;
        boiled = false;
    }

    public static synchronized ChocolateBoiler getInstance()
    {
        if (uniqueInstance == null)
            uniqueInstance = new ChocolateBoiler();
        return uniqueInstance;
    }

    public void fill()
    {
        if (isEmpty())
        {
            empty = false;
            boiled = false;

            System.out.println("ボイラーにチョコレートとミルクを追加しました。");
        }
    }

    public void drain()
    {
        if (!isEmpty() && isBoiled())
        {
            empty = true;

            System.out.println("ボイラーを空にしました。");
        }
    }

    public void boil()
    {
        if (!isEmpty() && !isBoiled())
        {
            boiled = true;

            System.out.println("チョコレートとミルクを沸騰させました。");
        }
    }

    public boolean isEmpty()
    {
        return empty;
    }

    public boolean isBoiled()
    {
        return boiled;
    }
}
