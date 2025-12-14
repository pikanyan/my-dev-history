public class Main
{
    public static void main(String[] args)
    {
        Component concreteComponent = new ConcreteComponent();
        Component concreteDecorator = new ConcreteDecorator(concreteComponent);

        concreteComponent.operate();

        System.out.println();

        concreteDecorator.operate();
    }
}
