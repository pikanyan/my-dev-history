public abstract class PizzaStore
{
    public Pizza orderPizza(String type)
    {
        Pizza pizza = createPizza(type);

        // 安定
        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();

        return pizza;
    }

    protected abstract Pizza createPizza(String type);
}
