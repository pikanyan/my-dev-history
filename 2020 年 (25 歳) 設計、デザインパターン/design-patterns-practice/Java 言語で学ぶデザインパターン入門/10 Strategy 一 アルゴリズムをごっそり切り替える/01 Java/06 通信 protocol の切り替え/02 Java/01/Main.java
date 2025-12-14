public class Main
{
    public static void main(String[] args)
    {
        Client client = new Client(new HttpProtocol());
        client.sendData("Hello, World!");

        client.setProtocol(new FtpProtocol());
        client.sendData("Hello, FTP!");
    }
}
