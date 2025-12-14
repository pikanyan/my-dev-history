public class App
{
    public static void showAll(BookShelf bookShelf)
    {
        for (String element : bookShelf)
        {
            System.out.println(element);
        }
    }



    public static void main(String[] args)
    {
        String[] elements = { "Apple", "Banana", "Cherry" };
        
        BookShelf bookShelf = new BookShelf(elements);

        showAll(bookShelf);
    }
}