public class Main
{
    public static void main(String[] args)
    {
        RemoteControl remoteControl = new RemoteControl();
 


		CeilingFan ceilingFan = new CeilingFan("Living Room");
		Light livingRoomLight = new Light("Living Room");

		CeilingFanHighCommand ceilingFanHigh = new CeilingFanHighCommand(ceilingFan);
		CeilingFanMediumCommand ceilingFanMedium = new CeilingFanMediumCommand(ceilingFan);
		CeilingFanLowCommand ceilingFanLow = new CeilingFanLowCommand(ceilingFan);
		CeilingFanOffCommand ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

		LightOnCommand livingRoomLightOn = new LightOnCommand(livingRoomLight);
		LightOffCommand livingRoomLightOff = new LightOffCommand(livingRoomLight);



		remoteControl.setCommand(0, livingRoomLightOn, livingRoomLightOff);
		remoteControl.setCommand(1, ceilingFanHigh, ceilingFanOff);



		remoteControl.onButtonWasPressed(0);
		System.out.println(remoteControl);
        remoteControl.undoButtonWasPushed();

		System.out.println();
		
		remoteControl.onButtonWasPressed(1);
		System.out.println(remoteControl);
		remoteControl.undoButtonWasPushed();
    }
}
