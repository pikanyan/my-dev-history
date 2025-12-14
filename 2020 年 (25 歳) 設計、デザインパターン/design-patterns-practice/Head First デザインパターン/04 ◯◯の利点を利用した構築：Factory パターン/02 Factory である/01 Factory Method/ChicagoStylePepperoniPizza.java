public class ChicagoStylePepperoniPizza extends Pizza
{
    public ChicagoStylePepperoniPizza()
    {
        name = "シカゴスタイルのペパロニピザ";
        dough = "厚いクラスト生地";
        sauce = "トマトソース";

        toppings.add("ペパロニ");
        toppings.add("モッツァレラチーズ");
    }

    @Override
    public void cut()
    {
        System.out.println("ピザを四角形にカットしています");
    }
}
