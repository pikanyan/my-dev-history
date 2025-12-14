import java.util.Arrays;



public class QuickSortStrategy implements SortStrategy
{
    @Override
    public void sort(int[] numbers)
    {
        System.out.println("Using QuickSort");

        // primitive 型の配列なので
        // Dual-Pivot QuickSort という
        // QuickSort の改良版を使用
        Arrays.sort(numbers);
    }
}
