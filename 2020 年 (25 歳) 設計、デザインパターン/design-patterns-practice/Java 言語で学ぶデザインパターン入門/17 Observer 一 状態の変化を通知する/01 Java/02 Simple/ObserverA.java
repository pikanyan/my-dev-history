public class ObserverA implements Observer
{
    @Override
    public void update(int value)
    {
        System.out.println("ObserverA : " + value);
    }
}
