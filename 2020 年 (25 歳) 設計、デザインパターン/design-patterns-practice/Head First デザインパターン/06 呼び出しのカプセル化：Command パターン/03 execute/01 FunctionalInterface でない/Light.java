public class Light
{
    private String location;

    public Light(String location)
    {
        this.location = location;
    }

    public void on()
    {
        System.out.println(location + " ライトが点灯しました");
    }

    public void off()
    {
        System.out.println(location + " のライトが消灯しました");
    }
}
