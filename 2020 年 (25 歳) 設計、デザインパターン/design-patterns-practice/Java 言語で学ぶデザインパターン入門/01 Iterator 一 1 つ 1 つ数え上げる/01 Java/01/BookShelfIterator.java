import java.util.Iterator;



public class BookShelfIterator implements Iterator<String>
{
    private String[] elements_;
    private int position_;



    public BookShelfIterator(String[] elements_)
    {
        this.elements_ = elements_;
        this.position_ = 0;
    }

    @Override
    public boolean hasNext()
    {
        return position_ < elements_.length;
    }

    @Override
    public String next()
    {
        return elements_[position_++];
    }
}