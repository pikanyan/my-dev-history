public abstract class Duck
{
    protected FlyBehavior flyBehavior;
    protected QuackBehavior quackBehavior;

    

    public abstract void display();

    public void fly()
    {
        flyBehavior.fly();
    }

    public void quack()
    {
        quackBehavior.quack();
    }

    public void swim()
    {
        System.out.println("All ducks float, even decoys!");
    }



    public void setFlyBehavior(FlyBehavior fb)
    {
        flyBehavior = fb;
    }

    public void setQuackBehavior(QuackBehavior qb)
    {
        quackBehavior = qb;
    }
}
