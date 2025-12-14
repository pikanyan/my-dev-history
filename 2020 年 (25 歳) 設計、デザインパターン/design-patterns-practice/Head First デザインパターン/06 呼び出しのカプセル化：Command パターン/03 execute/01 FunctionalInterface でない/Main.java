public class Main
{
    public static void main(String[] args)
    {
        RemoteControl remoteControl = new RemoteControl();
 


		CeilingFan ceilingFan = new CeilingFan("Living Room");
		GarageDoor garageDoor = new GarageDoor("Garage");
		Light livingRoomLight = new Light("Living Room");
		Light kitchenLight = new Light("Kitchen");
		Stereo stereo = new Stereo("Living Room");
  

		CeilingFanOnCommand ceilingFanOn = new CeilingFanOnCommand(ceilingFan);
		CeilingFanOffCommand ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

		GarageDoorUpCommand garageDoorUp = new GarageDoorUpCommand(garageDoor);
		GarageDoorDownCommand garageDoorDown = new GarageDoorDownCommand(garageDoor);

		LightOnCommand livingRoomLightOn = new LightOnCommand(livingRoomLight);
		LightOffCommand livingRoomLightOff = new LightOffCommand(livingRoomLight);

		LightOnCommand kitchenLightOn = new LightOnCommand(kitchenLight);
		LightOffCommand kitchenLightOff = new LightOffCommand(kitchenLight);
 
		StereoOnWithCDCommand stereoOnWithCD = new StereoOnWithCDCommand(stereo);
		StereoOffCommand  stereoOff = new StereoOffCommand(stereo);



		remoteControl.setCommand(0, ceilingFanOn, ceilingFanOff);
		remoteControl.setCommand(1, garageDoorUp, garageDoorDown);
		remoteControl.setCommand(2, livingRoomLightOn, livingRoomLightOff);
		remoteControl.setCommand(3, kitchenLightOn, kitchenLightOff);
		remoteControl.setCommand(4, stereoOnWithCD, stereoOff);



		System.out.println(remoteControl);

		remoteControl.onButtonWasPressed(0);
        remoteControl.offButtonWasPressed(0);

		System.out.println();

        remoteControl.onButtonWasPressed(1);
        remoteControl.offButtonWasPressed(1);

		System.out.println();

		remoteControl.onButtonWasPressed(2);
        remoteControl.offButtonWasPressed(2);

		System.out.println();

		remoteControl.onButtonWasPressed(3);
        remoteControl.offButtonWasPressed(3);

		System.out.println();

		remoteControl.onButtonWasPressed(4);
        remoteControl.offButtonWasPressed(4);

		System.out.println();

		remoteControl.onButtonWasPressed(5);
        remoteControl.offButtonWasPressed(5);
    }
}
