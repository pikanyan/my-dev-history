public class ChicagoStyleClamPizza extends Pizza
{
    public ChicagoStyleClamPizza()
    {
        name = "シカゴスタイルのアサリピザ";
        dough = "厚いクラスト生地";
        sauce = "トマトソース";

        toppings.add("アサリ");
        toppings.add("モッツァレラチーズ");
    }

    @Override
    public void cut()
    {
        System.out.println("ピザを四角形にカットしています");
    }
}
