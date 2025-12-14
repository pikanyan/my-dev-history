public class Main
{
    public static void main(String[] args)
    {
        SimplePizzaFactory factory = new SimplePizzaFactory();
        PizzaStore store = new PizzaStore(factory);
        
        Pizza pizza = store.orderPizza("チーズ");
        System.out.println("注文したピザが完成しました！");
    }
}
