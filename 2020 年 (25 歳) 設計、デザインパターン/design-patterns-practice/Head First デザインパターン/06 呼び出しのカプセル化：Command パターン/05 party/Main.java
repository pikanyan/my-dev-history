public class Main
{
    public static void main(String[] args)
    {
        RemoteControl remoteControl = new RemoteControl();
 


		CeilingFan ceilingFan = new CeilingFan("Living Room");
		Light livingRoomLight = new Light("Living Room");

		CeilingFanHighCommand ceilingFanHigh = new CeilingFanHighCommand(ceilingFan);
		CeilingFanOffCommand ceilingFanOff = new CeilingFanOffCommand(ceilingFan);

		LightOnCommand livingRoomLightOn = new LightOnCommand(livingRoomLight);
		LightOffCommand livingRoomLightOff = new LightOffCommand(livingRoomLight);

		Command[] partyOn = { ceilingFanHigh, livingRoomLightOn };
		Command[] partyOff = { ceilingFanOff, livingRoomLightOff };

		MacroCommand partyOnMacro = new MacroCommand(partyOn);
		MacroCommand partyOffMacro = new MacroCommand(partyOff);

		remoteControl.setCommand(0, partyOnMacro, partyOffMacro);



		remoteControl.onButtonWasPressed(0);
		System.out.println(remoteControl);
        remoteControl.undoButtonWasPushed();
    }
}
