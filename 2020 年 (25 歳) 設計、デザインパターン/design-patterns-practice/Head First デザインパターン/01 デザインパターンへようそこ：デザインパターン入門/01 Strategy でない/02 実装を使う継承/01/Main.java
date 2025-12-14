public class Main
{
    public static void main(String[] args)
    {
        Duck mallardDuck = new MallardDuck();
        mallardDuck.display();
        if (mallardDuck instanceof Flyable)
            ((Flyable) mallardDuck).fly();
        mallardDuck.swim();
        if (mallardDuck instanceof Quackable) 
            ((Quackable) mallardDuck).quack();

        System.out.println("");

        Duck redheadDuck = new RedheadDuck();
        redheadDuck.display();
        if (redheadDuck instanceof Flyable)
            ((Flyable) redheadDuck).fly();
        redheadDuck.swim();
        if (redheadDuck instanceof Quackable) 
            ((Quackable) redheadDuck).quack();

        System.out.println("");

        Duck rubberDuck = new RubberDuck();
        rubberDuck.display();
        if (rubberDuck instanceof Flyable)
            ((Flyable) rubberDuck).fly();
        rubberDuck.swim();
        if (rubberDuck instanceof Quackable) 
            ((Quackable) rubberDuck).quack();

        System.out.println("");

        Duck decoyDuck = new DecoyDuck();
        decoyDuck.display();
        if (decoyDuck instanceof Flyable)
            ((Flyable) decoyDuck).fly();
        decoyDuck.swim();
        if (decoyDuck instanceof Quackable) 
            ((Quackable) decoyDuck).quack();
    }
}
