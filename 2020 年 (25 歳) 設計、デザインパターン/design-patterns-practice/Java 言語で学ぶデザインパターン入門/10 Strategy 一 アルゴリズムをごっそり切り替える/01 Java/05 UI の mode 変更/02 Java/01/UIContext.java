public class UIContext
{
    private Theme theme;



    public UIContext(Theme theme)
    {
        this.theme = theme;
    }



    public void setTheme(Theme theme)
    {
        this.theme = theme;
    }



    public void applyTheme()
    {
        theme.apply();
    }
}
