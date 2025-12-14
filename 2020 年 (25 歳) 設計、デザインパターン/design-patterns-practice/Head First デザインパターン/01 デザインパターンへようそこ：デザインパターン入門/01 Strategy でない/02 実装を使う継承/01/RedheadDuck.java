public class RedheadDuck extends Duck implements Flyable, Quackable
{
    @Override
    public void display()
    {
        System.out.println("Displaying a redhead duck");
    }

    @Override
    public void fly()
    {
        System.out.println("Flying");
    }

    @Override
    public void quack()
    {
        System.out.println("Quack");
    }
}
