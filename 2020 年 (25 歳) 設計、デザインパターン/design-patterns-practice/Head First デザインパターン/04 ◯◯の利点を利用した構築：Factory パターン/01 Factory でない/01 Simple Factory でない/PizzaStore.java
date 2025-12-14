public class PizzaStore
{
    public Pizza orderPizza(String type)
    {
        Pizza pizza = null;

        // 不安定
        if(type.equals("チーズ"))
            pizza = new CheesePizza();
        else if(type.equals("アサリ"))
            pizza = new ClamPizza();
        else if(type.equals("ギリシャ"))
            pizza = new GreekPizza();
        else if(type.equals("ペパロニ"))
            pizza = new PepperoniPizza();
        else if(type.equals("野菜"))
            pizza = new VeggiePizza();
        else
            pizza = null;

        // 安定
        pizza.prepare();
        pizza.bake();
        pizza.cut();
        pizza.box();

        return pizza;
    }
}
