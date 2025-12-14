public class EWalletPayment implements PaymentStrategy
{
    private String walletId;



    public EWalletPayment(String walletId)
    {
        this.walletId = walletId;
    }



    @Override
    public void pay(int amount)
    {
        System.out.println(amount + "円を電子マネーで支払います (ウォレットID: " + walletId + ")");
    }
}
