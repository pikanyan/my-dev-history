public class Sorter
{
    private SortStrategy strategy;



    public void setStrategy(SortStrategy strategy)
    {
        this.strategy = strategy;
    }

    public void sortNumbers(int[] numbers)
    {
        if (strategy != null)
        {
            strategy.sort(numbers);
        }
        else
        {
            System.out.println("No sorting strategy set.");
        }
    }
}
