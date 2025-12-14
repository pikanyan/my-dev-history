public class Main
{
    public static void main(String[] args)
    {
        Subject subject = new Subject();
        ObserverA observerA = new ObserverA();

        subject.attach(observerA);
        subject.setValue(123);
    }
}
