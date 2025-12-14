public class MallardDuck extends Duck implements Flyable, Quackable
{
    @Override
    public void display()
    {
        System.out.println("Displaying a mallard duck");
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
