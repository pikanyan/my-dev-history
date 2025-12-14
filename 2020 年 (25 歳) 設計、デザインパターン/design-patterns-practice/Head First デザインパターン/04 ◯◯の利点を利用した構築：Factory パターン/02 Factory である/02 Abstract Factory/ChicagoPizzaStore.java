public class ChicagoPizzaStore extends PizzaStore
{
    @Override
    protected Pizza createPizza(String type)
    {
        Pizza pizza = null;
        PizzaIngredientFactory ingredientFactory = new ChicagoPizzaIngredientFactory();

        if (type.equals("チーズ"))
        {
            pizza = new CheesePizza(ingredientFactory);
            pizza.setName("シカゴスタイル チーズピザ");
        }
        else if (type.equals("クラム"))
        {
            pizza = new ClamPizza(ingredientFactory);
            pizza.setName("シカゴスタイル クラムピザ");
        }
        else if (type.equals("ペパロニ"))
        {
            pizza = new PepperoniPizza(ingredientFactory);
            pizza.setName("シカゴスタイル ペパロニピザ");
        }
        else if (type.equals("野菜"))
        {
            pizza = new VeggiePizza(ingredientFactory);
            pizza.setName("シカゴスタイル 野菜ピザ");
        }

        return pizza;
    }
}
