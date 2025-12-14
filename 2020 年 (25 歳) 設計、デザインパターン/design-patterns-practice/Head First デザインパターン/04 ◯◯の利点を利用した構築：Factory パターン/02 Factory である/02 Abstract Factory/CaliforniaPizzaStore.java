public class CaliforniaPizzaStore extends PizzaStore
{
    @Override
    protected Pizza createPizza(String type)
    {
        Pizza pizza = null;
        PizzaIngredientFactory ingredientFactory = new CaliforniaPizzaIngredientFactory();

        if (type.equals("チーズ"))
        {
            pizza = new CheesePizza(ingredientFactory);
            pizza.setName("カリフォルニアスタイル チーズピザ");
        }
        else if (type.equals("クラム"))
        {
            pizza = new ClamPizza(ingredientFactory);
            pizza.setName("カリフォルニアスタイル クラムピザ");
        }
        else if (type.equals("ペパロニ"))
        {
            pizza = new PepperoniPizza(ingredientFactory);
            pizza.setName("カリフォルニアスタイル ペパロニピザ");
        }
        else if (type.equals("野菜"))
        {
            pizza = new VeggiePizza(ingredientFactory);
            pizza.setName("カリフォルニアスタイル 野菜ピザ");
        }

        return pizza;
    }
}
