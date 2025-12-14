public class Main
{
    public static void main(String[] args)
    {
        Model model = new Model();
        View view = new View(model);
        Controller controller = new Controller(model);

        model.addObserver(view);

        controller.setValue(10);
        controller.setValue(20);
    }
}
