public class MacroCommand implements Command
{
	private Command[] commands;



	public MacroCommand(Command[] commands)
	{
		this.commands = commands;
	}

	@Override
	public void execute()
	{
		for (int i = 0; i < commands.length; i++)
		{
			commands[i].execute();
		}
	}

    /**
     * NOTE:  these commands have to be done backwards to ensure 
     * proper undo functionality
     */
	@Override
	public void undo()
	{
		for (int i = commands.length - 1; 0 <= i; i--)
		{
			commands[i].undo();
		}
	}
}
