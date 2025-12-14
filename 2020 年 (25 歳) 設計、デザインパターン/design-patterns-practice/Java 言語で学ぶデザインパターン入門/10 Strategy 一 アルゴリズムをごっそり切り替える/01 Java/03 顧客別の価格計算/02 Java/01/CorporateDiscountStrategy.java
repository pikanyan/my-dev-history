// 法人顧客用の割引戦略
public class CorporateDiscountStrategy implements DiscountStrategy
{
    @Override
    public double applyDiscount(double price)
    {
        // 10% 割引
        return price * 0.9;
    }
}
