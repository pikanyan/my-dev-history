public class ClamPizza extends Pizza
{
    protected PizzaIngredientFactory ingredientFactory;



    public ClamPizza(PizzaIngredientFactory ingredientFactory)
    {
        this.ingredientFactory = ingredientFactory;
    }

    @Override
    public void prepare()
    {
        System.out.println("準備中: " + name);

        cheese = ingredientFactory.createCheese();
        clams = ingredientFactory.createClams();
        dough = ingredientFactory.createDough();
        sauce = ingredientFactory.createSauce();
    }
}
