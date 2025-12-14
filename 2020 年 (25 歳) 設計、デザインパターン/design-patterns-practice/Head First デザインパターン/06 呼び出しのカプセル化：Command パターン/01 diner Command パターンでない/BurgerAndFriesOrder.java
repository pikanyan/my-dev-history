public class BurgerAndFriesOrder implements Order
{
	protected Cook cook;



	public BurgerAndFriesOrder(Cook cook)
	{
		this.cook = cook;
	}

	@Override
	public void execute()
	{
		cook.makeBurger();
		cook.makeFries();
	}
}
