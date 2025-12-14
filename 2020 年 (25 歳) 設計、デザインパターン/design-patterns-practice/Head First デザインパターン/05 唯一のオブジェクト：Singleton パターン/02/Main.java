public class Main
{
    public static void main(String[] args)
    {
        Thread thread1 = new Thread
        (
            () ->
            {
                ChocolateBoiler boiler1 = ChocolateBoiler.getInstance();
                System.out.println("Thread 1: インスタンスのハッシュコード: " + System.identityHashCode(boiler1));
            }
        );

        Thread thread2 = new Thread
        (
            () ->
            {
                ChocolateBoiler boiler2 = ChocolateBoiler.getInstance();
                System.out.println("Thread 2: インスタンスのハッシュコード: " + System.identityHashCode(boiler2));
            }
        );

        thread1.start();
        thread2.start();
    }
}
