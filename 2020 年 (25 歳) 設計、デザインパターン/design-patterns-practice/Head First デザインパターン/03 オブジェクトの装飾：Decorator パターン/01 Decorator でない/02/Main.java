public class Main
{
    public static void main(String[] args)
    {
        Beverage beverage1 = new DarkRoast();
        beverage1.setMocha(true);
        beverage1.setWhip(true);
        System.out.println(beverage1.getDescription() + " $" + String.format("%.2f", beverage1.cost()));

        Beverage beverage2 = new Decaf();
        beverage2.setMilk(true);
        System.out.println(beverage2.getDescription() + " $" + String.format("%.2f", beverage2.cost()));

        Beverage beverage3 = new Espresso();
        beverage3.setMocha(true);
        System.out.println(beverage3.getDescription() + " $" + String.format("%.2f", beverage3.cost()));

        Beverage beverage4 = new HouseBlend();
        beverage4.setMilk(true);
        beverage4.setSoy(true);
        System.out.println(beverage4.getDescription() + " $" + String.format("%.2f", beverage4.cost()));
    }
}
