public class NYPizzaStore extends PizzaStore
{
    @Override
    protected Pizza createPizza(String type)
    {
        Pizza pizza = null;
        PizzaIngredientFactory ingredientFactory = new NYPizzaIngredientFactory();

        if (type.equals("チーズ"))
        {
            pizza = new CheesePizza(ingredientFactory);
            pizza.setName("ニューヨークスタイル チーズピザ");
        }
        else if (type.equals("クラム"))
        {
            pizza = new ClamPizza(ingredientFactory);
            pizza.setName("ニューヨークスタイル クラムピザ");
        }
        else if (type.equals("ペパロニ"))
        {
            pizza = new PepperoniPizza(ingredientFactory);
            pizza.setName("ニューヨークスタイル ペパロニピザ");
        }
        else if (type.equals("野菜"))
        {
            pizza = new VeggiePizza(ingredientFactory);
            pizza.setName("ニューヨークスタイル 野菜ピザ");
        }

        return pizza;
    }
}
