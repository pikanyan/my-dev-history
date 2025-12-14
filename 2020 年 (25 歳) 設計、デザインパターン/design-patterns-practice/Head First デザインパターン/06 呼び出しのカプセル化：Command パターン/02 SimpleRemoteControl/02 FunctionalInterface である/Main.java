public class Main
{
    public static void main(String[] args)
    {
        SimpleRemoteControl remote = new SimpleRemoteControl();

        GarageDoor garageDoor = new GarageDoor();
        Light light = new Light();



		remote.setCommand(garageDoor::up);
		remote.buttonWasPressed();

        remote.setCommand(garageDoor::down);
		remote.buttonWasPressed();

        remote.setCommand(light::on);
		remote.buttonWasPressed();

        remote.setCommand(light::off);
		remote.buttonWasPressed();
    }
}