public class Main
{
    public static void main(String[] args)
    {
        PizzaStore store = new PizzaStore();

        Pizza pizza = store.orderPizza("チーズ");
        
        System.out.println("注文したピザが完成しました！");
    }
}
