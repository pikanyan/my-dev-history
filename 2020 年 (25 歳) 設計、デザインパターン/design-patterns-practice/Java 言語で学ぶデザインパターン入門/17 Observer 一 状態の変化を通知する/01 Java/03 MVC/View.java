public class View implements Observer
{
    private Model model;



    public View(Model model)
    {
        this.model = model;
    }

    @Override
    public void update()
    {
        System.out.println("View updated with value: " + model.getValue());
    }
}
