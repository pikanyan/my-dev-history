public class Main
{
    public static void main(String[] args)
    {
        PizzaStore nyStore = new NYPizzaStore();
        PizzaStore chicagoStore = new ChicagoPizzaStore();
        PizzaStore californiaStore = new CaliforniaPizzaStore();



        Pizza pizza = nyStore.orderPizza("チーズ");
        System.out.println("注文が完了しました: " + pizza.getName() + "\n");

        Pizza anotherPizza = chicagoStore.orderPizza("ペパロニ");
        System.out.println("注文が完了しました: " + anotherPizza.getName() + "\n");

        Pizza lastPizza = californiaStore.orderPizza("チーズ");
        System.out.println("注文が完了しました: " + lastPizza.getName() + "\n");
    }
}
