import java.util.ArrayList;
import java.util.List;



public class Subject
{
    private List<Observer> observers = new ArrayList<>();
    private int value;



    public Subject()
    {
        this.value = 0;
    }

    public void attach(Observer observer)
    {
        observers.add(observer);
    }

    public void setValue(int value)
    {
        this.value = value;
        notifyObservers();
    }

    private void notifyObservers()
    {
        for (Observer observer : observers)
        {
            observer.update(value);
        }
    }
}
