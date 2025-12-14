import java.util.Scanner;



public class Main
{
    public static void main(String[] args)
    {
        PhoneCameraApp cameraApp = new BasicCameraApp();



		String share = getSharing();

		switch (share)
        {
            case("e"): cameraApp.setShareStrategy(new Email()); break;
            case("s"): cameraApp.setShareStrategy(new Social()); break;
			case("t"): cameraApp.setShareStrategy(new Txt()); break;
			default: cameraApp.setShareStrategy(new Txt());
		}



		cameraApp.take();
		cameraApp.edit();
		cameraApp.save();
		cameraApp.share();
    }

    public static String getSharing()
    {
		Scanner scanner = new Scanner(System.in);

		System.out.println("Share with email (e), social media (s), or txt (t)?");

		String appName = scanner.next();

		scanner.close();

		return appName;
	}
}
