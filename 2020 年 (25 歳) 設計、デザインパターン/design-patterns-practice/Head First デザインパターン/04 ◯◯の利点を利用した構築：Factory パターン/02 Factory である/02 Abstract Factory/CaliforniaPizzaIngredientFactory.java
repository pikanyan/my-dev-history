public class CaliforniaPizzaIngredientFactory implements PizzaIngredientFactory
{
    @Override
    public Cheese createCheese()
    {
        return new MozzarellaCheese();
    }

    @Override
    public Clams createClams()
    {
        return new FrozenClams();
    }

    @Override
    public Dough createDough()
    {
        return new ThickCrustDough();
    }

    @Override
    public Pepperoni createPepperoni()
    {
        return new SlicedPepperoni();
    }

    @Override
    public Sauce createSauce()
    {
        return new PlumTomatoSauce();
    }

    @Override
    public Veggies[] createVeggies()
    {
        Veggies[] veggies =
        {
            new Spinach(),
            new BlackOlives(),
            new Eggplant()
        };
        
        return veggies;
    }
}
