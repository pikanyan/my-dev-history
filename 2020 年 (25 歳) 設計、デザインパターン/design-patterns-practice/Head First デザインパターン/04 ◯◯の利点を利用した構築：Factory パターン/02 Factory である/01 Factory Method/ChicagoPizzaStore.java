public class ChicagoPizzaStore extends PizzaStore
{
    @Override
    protected Pizza createPizza(String type)
    {
        // 不安定
        if (type.equals("チーズ"))
            return new ChicagoStyleCheesePizza();
        else if (type.equals("ペパロニ"))
            return new ChicagoStylePepperoniPizza();
        else if (type.equals("アサリ"))
            return new ChicagoStyleClamPizza();
        else if (type.equals("野菜"))
            return new ChicagoStyleVeggiePizza();
        else
            return null;
    }
}
