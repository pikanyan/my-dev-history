class ConcreteDecorator extends Decorator
{
    public ConcreteDecorator(Component component)
    {
        super(component);
    }

    @Override
    public void operate()
    {
        System.out.println("ConcreteDecorator pre-operate");
        super.operate();
        System.out.println("ConcreteDecorator post-operate");
    }
}
