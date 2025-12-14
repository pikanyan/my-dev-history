import java.util.Arrays;



public class MergeSortStrategy implements SortStrategy
{
    @Override
    public void sort(int[] numbers)
    {
        System.out.println("Using MergeSort");

        // 仮の実装として、Arrays.sort() を使用
        // 実際には別のアルゴリズムを使う必要があります
        Arrays.sort(numbers);
    }
}
