public class ChicagoStyleVeggiePizza extends Pizza
{
    public ChicagoStyleVeggiePizza()
    {
        name = "シカゴスタイルの野菜ピザ";
        dough = "厚いクラスト生地";
        sauce = "トマトソース";

        toppings.add("ピーマン");
        toppings.add("玉ねぎ");
        toppings.add("スライスマッシュルーム");
    }

    @Override
    public void cut()
    {
        System.out.println("ピザを四角形にカットしています");
    }
}
