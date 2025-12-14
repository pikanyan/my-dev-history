public class DecoyDuck extends Duck
{
    @Override
    public void display()
    {
        System.out.println("Displaying a decoy duck");
    }

    @Override
    public void fly()
    {
        System.out.println("");
    }

    @Override
    public void quack()
    {
        System.out.println("");
    }
}
