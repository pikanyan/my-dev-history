public class Main
{
    public static void main(String[] args)
    {
        ShoppingCart cart = new ShoppingCart();

        cart.setPaymentStrategy(new CreditCardPayment("1234-5678-9101-1121", "Taro Yamada"));
        cart.checkout(5000);

        cart.setPaymentStrategy(new DebitCardPayment("4321-8765-1101-2111", "Taro Yamada"));
        cart.checkout(3000);

        cart.setPaymentStrategy(new EWalletPayment("wallet-56789"));
        cart.checkout(2000);
	}
}
