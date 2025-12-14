public class Waitress
{
	protected Order order;



	public void setCommand(Order order)
	{
		this.order = order; 

		order.execute();
	}
}
