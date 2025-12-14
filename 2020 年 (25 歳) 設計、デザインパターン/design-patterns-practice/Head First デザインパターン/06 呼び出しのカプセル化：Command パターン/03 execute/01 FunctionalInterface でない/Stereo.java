public class Stereo
{
    private String location;

    public Stereo(String location)
    {
        this.location = location;
    }

    public void on()
    {
        System.out.println("ステレオがオンになりました");
    }

    public void off()
    {
        System.out.println("ステレオがオフになりました");
    }

    public void setCD()
    {
        System.out.println("CDがセットされました");
    }

    public void setVolume(int volume)
    {
        System.out.println("ボリュームを" + volume + "に設定しました");
    }
}
