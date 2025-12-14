public class Main
{
    public static void main(String[] args)
    {
        Duck decoyDuck = new DecoyDuck();
        decoyDuck.display();
        decoyDuck.fly();
        decoyDuck.swim();
        decoyDuck.quack();

        System.out.println();

        Duck mallardDuck = new MallardDuck();
        mallardDuck.display();
        mallardDuck.fly();
        mallardDuck.swim();
        mallardDuck.quack();

        System.out.println();

        Duck redheadDuck = new RedheadDuck();
        redheadDuck.display();
        redheadDuck.fly();
        redheadDuck.swim();
        redheadDuck.quack();

        System.out.println();

        Duck rubberDuck = new RubberDuck();
        rubberDuck.display();
        rubberDuck.fly();
        rubberDuck.swim();
        rubberDuck.quack();
    }
}
