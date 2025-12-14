public class DebitCardPayment implements PaymentStrategy
{
    private String cardNumber;
    private String cardHolderName;



    public DebitCardPayment(String cardNumber, String cardHolderName)
    {
        this.cardNumber = cardNumber;
        this.cardHolderName = cardHolderName;
    }



    @Override
    public void pay(int amount)
    {
        System.out.println(amount + "円をデビットカードで支払います (カード番号: " + cardNumber + ")");
    }
}
