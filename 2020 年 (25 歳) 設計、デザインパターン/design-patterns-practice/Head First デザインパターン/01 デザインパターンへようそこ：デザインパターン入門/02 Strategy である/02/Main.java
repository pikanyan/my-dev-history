public class Main
{
    public static void main(String[] args)
    {
        Character queen = new Queen();
        queen.fight();

        System.out.println();

        Character king = new King();
        king.fight();

        System.out.println();

        Character troll = new Troll();
        troll.fight();

        System.out.println();

        Character knight = new Knight();
        knight.fight();
    }
}
