public class CaliforniaPizzaStore extends PizzaStore
{
    @Override
    protected Pizza createPizza(String type)
    {
        // 不安定
        if (type.equals("チーズ"))
            return new CaliforniaStyleCheesePizza();
        else if (type.equals("ペパロニ"))
            return new CaliforniaStylePepperoniPizza();
        else if (type.equals("アサリ"))
            return new CaliforniaStyleClamPizza();
        else if (type.equals("野菜"))
            return new CaliforniaStyleVeggiePizza();
        else
            return null;
    }
}
