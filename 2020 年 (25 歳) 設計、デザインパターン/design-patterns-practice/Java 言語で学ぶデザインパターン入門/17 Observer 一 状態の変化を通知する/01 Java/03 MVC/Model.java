import java.util.ArrayList;
import java.util.List;



public class Model
{
    private List<Observer> observers = new ArrayList<>();
    private int value;



    public void addObserver(Observer observer)
    {
        observers.add(observer);
    }

    public void setValue(int value)
    {
        this.value = value;
        
        notifyObservers();
    }

    public int getValue()
    {
        return value;
    }

    private void notifyObservers()
    {
        for (Observer observer : observers)
        {
            observer.update();
        }
    }
}
