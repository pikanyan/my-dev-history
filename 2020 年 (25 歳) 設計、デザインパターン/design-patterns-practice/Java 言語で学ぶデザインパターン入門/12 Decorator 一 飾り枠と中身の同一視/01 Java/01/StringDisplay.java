public class StringDisplay extends Display
{
    private String string;



    public StringDisplay(String string)
    {
        this.string = string;
    }

    @Override
    public int getColumns()                     // 文字数
    {
        return string.getBytes().length;
    }

    @Override
    public int getRows()                        // 行数は 1
    {
        return 1;
    }

    @Override
    public String getRowText(int row)           // row が 0 のときのみ返す
    {
        if (row == 0)
        {
            return string;
        }
        else
        {
            return null;
        }
    }
}
