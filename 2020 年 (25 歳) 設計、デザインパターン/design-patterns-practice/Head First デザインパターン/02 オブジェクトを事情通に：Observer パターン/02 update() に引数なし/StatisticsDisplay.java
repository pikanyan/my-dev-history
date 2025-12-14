public class StatisticsDisplay implements Observer, DisplayElement
{
    private float maxTemp = 0.0f;
    private float minTemp = 200;
    private float tempSum = 0.0f;
    private int numReadings;
    private Subject weatherData;



    public StatisticsDisplay(Subject weatherData)
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

            float temp = wd.getTemperature();

            tempSum += temp;
            numReadings++;

            if (maxTemp < temp)
            {
                maxTemp = temp;
            }

            if (temp < minTemp)
            {
                minTemp = temp;
            }

            display();
        }
    }

    @Override
    public void display()
    {
        System.out.println("Avg/Max/Min temperature = " + (tempSum / numReadings) + "/" + maxTemp + "/" + minTemp);
    }
}
