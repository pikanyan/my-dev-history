public class Main
{

    public static void main(String[] args)
    {
        // 一般顧客
        Customer regularCustomer = new Customer(new NoDiscountStrategy());
        System.out.println("一般顧客の最終価格: " + regularCustomer.calculateFinalPrice(100.0));

        // 法人顧客
        Customer corporateCustomer = new Customer(new CorporateDiscountStrategy());
        System.out.println("法人顧客の最終価格: " + corporateCustomer.calculateFinalPrice(100.0));

        // VIP顧客
        Customer vipCustomer = new Customer(new VipDiscountStrategy());
        System.out.println("VIP顧客の最終価格: " + vipCustomer.calculateFinalPrice(100.0));
        
        // 一般顧客をVIPにアップグレード
        regularCustomer.setDiscountStrategy(new VipDiscountStrategy());
        System.out.println("アップグレード後の一般顧客の最終価格: " + regularCustomer.calculateFinalPrice(100.0));
	}
}
