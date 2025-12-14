public class Player
{
    private Strategy strategy;

    private String name;
    private int gameCount;
    private int winCount;
    private int loseCount;



    public Player(Strategy strategy, String name)
    {
        this.strategy = strategy;
        this.name = name;
    }

    public Hand nextHand()
    {
        return strategy.nextHand();
    }

    public void win()
    {
        strategy.study(true);
        gameCount++;
        winCount++;
    }

    public void lose()
    {
        strategy.study(false);
        gameCount++;
        loseCount++;
    }

    public void even()
    {
        gameCount++;
    }

    @Override
    public String toString()
    {
        return "[" + name + ": " + gameCount + " games, " + winCount + " win, " + loseCount + " lose]";
    }
}
