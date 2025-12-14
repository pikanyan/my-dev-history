// 一般顧客用の割引戦略
public class NoDiscountStrategy implements DiscountStrategy
{
    @Override
    public double applyDiscount(double price)
    {
        // 割引なし
        return price;
    }
}
