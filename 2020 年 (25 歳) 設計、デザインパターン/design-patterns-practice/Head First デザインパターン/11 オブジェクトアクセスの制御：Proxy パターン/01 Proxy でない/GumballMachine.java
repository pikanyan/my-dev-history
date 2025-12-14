public class GumballMachine
{
	private State hasQuarterState;
	private State noQuarterState;
	private State soldOutState;
	private State soldState;
	private State winnerState;
 
	private State state;
	private int count = 0;
	private String location;



	public GumballMachine(String location, int numberGumballs)
	{
		hasQuarterState = new HasQuarterState(this);
		noQuarterState = new NoQuarterState(this);
		soldOutState = new SoldOutState(this);
		soldState = new SoldState(this);
		winnerState = new WinnerState(this);

		this.count = numberGumballs;

 		if (0 < numberGumballs)
		{
			state = noQuarterState;
		}
		else
		{
			state = soldOutState;
		}

		this.location = location;
	}
 
	public void insertQuarter()
	{
		state.insertQuarter();
	}
 
	public void ejectQuarter()
	{
		state.ejectQuarter();
	}
 
	public void turnCrank()
	{
		state.turnCrank();
		state.dispense();
	}

	public void releaseBall()
	{
		System.out.println("A gumball comes rolling out the slot...");

		if (0 < count)
		{
			count = count - 1;
		}
	}



	public int getCount()
	{
		return count;
	}

	public String getLocation()
	{
        return location;
    }



	public void refill(int count)
	{
		this.count += count;

		System.out.println("The gumball machine was just refilled; its new count is: " + this.count);

		state.refill();
	}



	public void setState(State state)
	{
		this.state = state;
	}

    public State getState()
	{
        return state;
    }



	public State getHasQuarterState()
	{
        return hasQuarterState;
    }

	public State getNoQuarterState()
	{
        return noQuarterState;
    }

    public State getSoldOutState()
	{
        return soldOutState;
    }

    public State getSoldState()
	{
        return soldState;
    }

	public State getWinnerState()
	{
        return winnerState;
    }



	public String toString()
	{
		StringBuffer result = new StringBuffer();

		result.append("\nMighty Gumball, Inc.");
		result.append("\nJava-enabled Standing Gumball Model #2004");
		result.append("\nInventory: " + count + " gumball");

		if (count != 1)
		{
			result.append("s");
		}

		result.append("\n");
		result.append("Machine is " + state + "\n");

		return result.toString();
	}
}
