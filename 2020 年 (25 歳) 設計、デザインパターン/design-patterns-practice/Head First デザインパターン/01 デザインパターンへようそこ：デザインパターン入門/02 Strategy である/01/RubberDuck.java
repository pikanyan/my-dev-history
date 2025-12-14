public class RubberDuck extends Duck
{
    public RubberDuck()
    {
        flyBehavior = new FlyNoWay();
        quackBehavior = new Squeak();
    }

    @Override
    public void display()
    {
        System.out.println("Displaying a rubber duck");
    }
}
