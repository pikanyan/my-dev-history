public class Client
{
    private Protocol protocol;



    public Client(Protocol protocol)
    {
        this.protocol = protocol;
    }



    public void setProtocol(Protocol protocol)
    {
        this.protocol = protocol;
    }



    public void sendData(String data)
    {
        protocol.send(data);
    }
}
