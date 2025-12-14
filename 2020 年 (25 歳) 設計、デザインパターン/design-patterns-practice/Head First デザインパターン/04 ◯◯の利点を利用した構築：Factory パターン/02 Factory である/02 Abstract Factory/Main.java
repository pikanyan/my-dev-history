public class Main
{
    public static void main(String[] args)
    {
        PizzaStore nyStore = new NYPizzaStore();
        Pizza pizza = nyStore.orderPizza("チーズ");
        System.out.println("注文したのは " + pizza.getName() + " です\n");

        PizzaStore chicagoStore = new ChicagoPizzaStore();
        pizza = chicagoStore.orderPizza("ペパロニ");
        System.out.println("注文したのは " + pizza.getName() + " です\n");

        PizzaStore californiaStore = new CaliforniaPizzaStore();
        pizza = californiaStore.orderPizza("野菜");
        System.out.println("注文したのは " + pizza.getName() + " です\n");
    }
}
