import java.util.Random;



public class Main
{
    public static void main(String[] args)
    {
        /*
        Hand guu = Hand.getHand(Hand.HANDVALUE_GUU);
        Hand cho = Hand.getHand(Hand.HANDVALUE_CHO);
        Hand paa = Hand.getHand(Hand.HANDVALUE_PAA);

        System.out.println(guu.handValue);              // 0
        System.out.println(cho.handValue);              // 1
        System.out.println(paa.handValue);              // 2

        System.out.println(guu);                        // グー
        System.out.println(cho);                        // チョキ
        System.out.println(paa);                        // パー

        System.out.println(guu.isStrongerThan(cho));    // true
        System.out.println(guu.isWeakerThan(paa));      // true

        System.out.println(cho.isStrongerThan(paa));    // true
        System.out.println(cho.isWeakerThan(guu));      // true

        System.out.println(paa.isStrongerThan(guu));    // true
        System.out.println(paa.isWeakerThan(cho));      // true
        */



        /*
        Player player1 = new Player(new WinningStrategy(123), "Player1");
        Player player2 = new Player(new WinningStrategy(456), "Player2");

        for (int i = 0; i < 10; i++)
        {
            Hand hand1 = player1.nextHand();
            Hand hand2 = player2.nextHand();

            System.out.println("Round " + (i + 1));
            System.out.println("Player1 の手: " + hand1);
            System.out.println("Player2 の手: " + hand2);

            if (hand1.isStrongerThan(hand2))
            {
                System.out.println("Player1 の勝ち");
                player1.win();
                player2.lose();
            }
            else if (hand1.isWeakerThan(hand2))
            {
                System.out.println("Player2 の勝ち");
                player1.lose();
                player2.win();
            }
            else
            {
                System.out.println("引き分け");
                player1.even();
                player2.even();
            }
            
            System.out.println();
        }

        System.out.println("最終結果:");
        System.out.println(player1);
        System.out.println(player2);
        */



        Player player1 = new Player(new ProbStrategy(123), "Player1");
        Player player2 = new Player(new ProbStrategy(456), "Player2");

        for (int i = 0; i < 3; i++)
        {
            Hand hand1 = player1.nextHand();
            Hand hand2 = player2.nextHand();

            System.out.println("===Round " + (i + 1) + "===");
            System.out.println("Player1 の手: " + hand1);
            System.out.println("Player2 の手: " + hand2);

            if (hand1.isStrongerThan(hand2))
            {
                System.out.println("Player1 の勝ち");
                player1.win();
                player2.lose();
            }
            else if (hand1.isWeakerThan(hand2))
            {
                System.out.println("Player2 の勝ち");
                player1.lose();
                player2.win();
            }
            else
            {
                System.out.println("引き分け");
                player1.even();
                player2.even();
            }
            
            System.out.println();
            System.out.println();
            System.out.println();
        }

        System.out.println("最終結果:");
        System.out.println(player1);
        System.out.println(player2);
	}
}
