public class Main
{
    public static void main(String[] args)
    {
        int[] numbers = {5, 2, 9, 1, 5, 6};

        Sorter sorter = new Sorter();



        // QuickSort を使う
        sorter.setStrategy(new QuickSortStrategy());
        sorter.sortNumbers(numbers);
        printArray(numbers);

        // MergeSort に切り替える
        sorter.setStrategy(new MergeSortStrategy());
        sorter.sortNumbers(numbers);
        printArray(numbers);
	}

    private static void printArray(int[] numbers)
    {
        for (int number : numbers)
        {
            System.out.print(number + " ");
        }
        System.out.println();
    }
}
