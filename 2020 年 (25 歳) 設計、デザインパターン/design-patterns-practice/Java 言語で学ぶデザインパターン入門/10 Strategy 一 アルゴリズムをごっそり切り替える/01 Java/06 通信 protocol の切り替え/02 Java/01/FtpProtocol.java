public class FtpProtocol implements Protocol
{
    @Override
    public void send(String data)
    {
        System.out.println("Sending data via FTP: " + data);
    }
}
