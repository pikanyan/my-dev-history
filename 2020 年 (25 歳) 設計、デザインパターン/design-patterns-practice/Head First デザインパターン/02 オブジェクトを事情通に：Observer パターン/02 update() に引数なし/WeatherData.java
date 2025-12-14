import java.util.List;
import java.util.ArrayList;



public class WeatherData implements Subject
{
    private List<Observer> observers;

    private float temp;
    private float humidity;
    private float pressure;



    public WeatherData()
    {
        observers = new ArrayList<>();
    }

    @Override
    public void registerObserver(Observer o)
    {
        observers.add(o);
    }

    @Override
    public void removeObserver(Observer o)
    {
        observers.remove(o);
    }

    @Override
    public void notifyObservers()
    {
        for (Observer observer : observers)
        {
            observer.update();
        }
    }



    public void measurementsChanged()
    {
        notifyObservers();
    }

    public void setMeasurements(float temp, float humidity, float pressure)
    {
        this.temp = temp;
        this.humidity = humidity;
        this.pressure = pressure;

        measurementsChanged();
    }



    public float getTemperature()
    {
        return temp;
    }

    public float getHumidity()
    {
        return humidity;
    }

    public float getPressure()
    {
        return pressure;
    }
}
