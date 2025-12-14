public class Main
{
    public static void main(String[] args)
    {
        SimpleRemoteControl remote = new SimpleRemoteControl();

        GarageDoor garageDoor = new GarageDoor();
        Light light = new Light();

        GarageDoorOpenCommand garageOpen = new GarageDoorOpenCommand(garageDoor);
        GarageDoorCloseCommand garageClose = new GarageDoorCloseCommand(garageDoor);

        LightOnCommand lightOn = new LightOnCommand(light);
        LightOffCommand lightOff = new LightOffCommand(light);



		remote.setCommand(garageOpen);
		remote.buttonWasPressed();

        remote.setCommand(garageClose);
		remote.buttonWasPressed();

        remote.setCommand(lightOn);
		remote.buttonWasPressed();

        remote.setCommand(lightOff);
		remote.buttonWasPressed();
    }
}