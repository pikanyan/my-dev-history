public class Customer
{
    private DiscountStrategy discountStrategy;



    public Customer(DiscountStrategy discountStrategy)
    {
        this.discountStrategy = discountStrategy;
    }

    public void setDiscountStrategy(DiscountStrategy discountStrategy)
    {
        this.discountStrategy = discountStrategy;
    }

    public double calculateFinalPrice(double price)
    {
        return discountStrategy.applyDiscount(price);
    }
}
