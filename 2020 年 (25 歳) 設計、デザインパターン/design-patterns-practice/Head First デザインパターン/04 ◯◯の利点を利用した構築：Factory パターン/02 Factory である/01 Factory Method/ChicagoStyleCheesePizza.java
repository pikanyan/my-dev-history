public class ChicagoStyleCheesePizza extends Pizza
{
    public ChicagoStyleCheesePizza()
    {
        name = "シカゴスタイルのチーズピザ";
        dough = "厚いクラスト生地";
        sauce = "トマトソース";

        toppings.add("モッツァレラチーズ");
    }

    @Override
    public void cut()
    {
        System.out.println("ピザを四角形にカットしています");
    }
}
