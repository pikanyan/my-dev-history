public class Customer
{
	protected Waitress waitress;
	protected Order order;



	public Customer(Waitress waitress)
	{
		this.waitress = waitress;
	}

	public void createOrder(Order order)
	{
		this.order = order;
	}

	public void hungry()
	{
		waitress.setCommand(order);
	}
}
