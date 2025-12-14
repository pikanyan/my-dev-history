public class HttpProtocol implements Protocol
{
    @Override
    public void send(String data)
    {
        System.out.println("Sending data via HTTP: " + data);
    }
}
