public class DecoyDuck extends Duck
{
    public DecoyDuck()
    {
        flyBehavior = new FlyNoWay();
        quackBehavior = new MuteQuack();
    }

    @Override
    public void display()
    {
        System.out.println("Displaying a decoy duck");
    }
}
