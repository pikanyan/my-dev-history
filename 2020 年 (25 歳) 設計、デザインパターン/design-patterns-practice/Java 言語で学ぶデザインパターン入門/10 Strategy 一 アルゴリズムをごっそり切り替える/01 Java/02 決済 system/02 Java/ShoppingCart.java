public class ShoppingCart
{
    private PaymentStrategy paymentStrategy;



    public void checkout(int amount)
    {
        paymentStrategy.pay(amount);
    }



    public void setPaymentStrategy(PaymentStrategy paymentStrategy)
    {
        this.paymentStrategy = paymentStrategy;
    }
}
