public class RubberDuck extends Duck implements Quackable
{
    @Override
    public void display()
    {
        System.out.println("Displaying a rubber duck");
    }

    @Override
    public void quack()
    {
        System.out.println("Squeak");
    }
}
