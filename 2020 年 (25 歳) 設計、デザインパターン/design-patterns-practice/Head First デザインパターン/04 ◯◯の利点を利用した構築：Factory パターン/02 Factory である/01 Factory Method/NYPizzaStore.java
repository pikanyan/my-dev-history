public class NYPizzaStore extends PizzaStore
{
    @Override
    protected Pizza createPizza(String type)
    {
        // 不安定
        if (type.equals("チーズ"))
            return new NYStyleCheesePizza();
        else if (type.equals("ペパロニ"))
            return new NYStylePepperoniPizza();
        else if (type.equals("アサリ"))
            return new NYStyleClamPizza();
        else if (type.equals("野菜"))
            return new NYStyleVeggiePizza();
        else
            return null;
    }
}
