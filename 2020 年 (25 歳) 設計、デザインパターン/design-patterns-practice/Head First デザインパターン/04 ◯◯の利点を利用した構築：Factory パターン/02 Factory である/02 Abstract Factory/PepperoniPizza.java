public class PepperoniPizza extends Pizza
{
    protected PizzaIngredientFactory ingredientFactory;



    public PepperoniPizza(PizzaIngredientFactory ingredientFactory)
    {
        this.ingredientFactory = ingredientFactory;
    }

    @Override
    public void prepare()
    {
        System.out.println("準備中: " + name);

        cheese = ingredientFactory.createCheese();
        dough = ingredientFactory.createDough();
        pepperoni = ingredientFactory.createPepperoni();
        sauce = ingredientFactory.createSauce();
    }
}
