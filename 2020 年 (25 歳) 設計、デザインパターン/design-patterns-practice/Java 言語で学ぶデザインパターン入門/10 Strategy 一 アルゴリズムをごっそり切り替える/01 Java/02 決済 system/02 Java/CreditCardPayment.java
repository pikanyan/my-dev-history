public class CreditCardPayment implements PaymentStrategy
{
    private String cardNumber;
    private String cardHolderName;



    public CreditCardPayment(String cardNumber, String cardHolderName)
    {
        this.cardNumber = cardNumber;
        this.cardHolderName = cardHolderName;
    }



    @Override
    public void pay(int amount)
    {
        System.out.println(amount + "円をクレジットカードで支払います (カード番号: " + cardNumber + ")");
    }
}
