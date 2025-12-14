import java.util.Iterator;



public class BookShelf implements Iterable<String>
{
    private String[] elements_;

    

    public BookShelf(String[] elements_)
    {
        this.elements_ = elements_;
    }

    @Override
    public Iterator<String> iterator()
    {
        return new BookShelfIterator(elements_);
    }
}
