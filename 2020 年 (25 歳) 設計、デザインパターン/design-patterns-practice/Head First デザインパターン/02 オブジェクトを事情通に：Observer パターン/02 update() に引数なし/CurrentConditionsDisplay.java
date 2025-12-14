public class CurrentConditionsDisplay implements Observer, DisplayElement
{
    private float temperature;
    private float humidity;
    private Subject weatherData;



    public CurrentConditionsDisplay(Subject weatherData)
    {
        this.weatherData = weatherData;

        weatherData.registerObserver(this);
    }

    @Override
    public void update()
    {
        if (weatherData instanceof WeatherData)
        {
            WeatherData wd = (WeatherData) weatherData;

            this.temperature = wd.getTemperature();
            this.humidity = wd.getHumidity();

            display();
        }
    }

    @Override
    public void display()
    {
        System.out.println("Current conditions: " + temperature + "F degrees and " + humidity + "% humidity");
    }
}
