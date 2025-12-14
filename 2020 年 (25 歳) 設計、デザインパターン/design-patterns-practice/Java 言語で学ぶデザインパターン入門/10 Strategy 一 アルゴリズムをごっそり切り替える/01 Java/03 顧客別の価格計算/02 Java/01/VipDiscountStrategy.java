// VIP顧客用の割引戦略
public class VipDiscountStrategy implements DiscountStrategy
{
    @Override
    public double applyDiscount(double price)
    {
        // 20% 割引
        return price * 0.8;
    }
}
