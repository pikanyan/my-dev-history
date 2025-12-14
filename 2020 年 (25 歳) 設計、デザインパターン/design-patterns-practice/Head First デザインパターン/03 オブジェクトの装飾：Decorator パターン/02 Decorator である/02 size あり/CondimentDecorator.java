public abstract class CondimentDecorator extends Beverage
{
    protected Beverage beverage;



    public abstract String getDescription();

    @Override
    public Size getSize()
    {
		  return beverage.getSize();
	  }
}
