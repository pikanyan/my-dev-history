import java.util.Random;



public class Main
{
    public static final int HAND_GUU = 0;
    public static final int HAND_CHO = 1;
    public static final int HAND_PAA = 2;

    public static String[] handNames =
    {
        "グー",
        "チョキ",
        "パー"
    };



    public static void main(String[] args)
    {
        Random random = new Random();

        int player1Wins = 0;
        int player2Wins = 0;
        int draws = 0;

        for (int i = 0; i < 10; i++)
        {
            int player1Hand = random.nextInt(3);
            int player2Hand = random.nextInt(3);

            System.out.println("Round " + (i + 1));                         // Round 10
            System.out.println("Player1 の手: " + handNames[player1Hand]);  // Player1 の手: グー
            System.out.println("Player2 の手: " + handNames[player2Hand]);  // Player2 の手: パー

            if (player1Hand == player2Hand)
            {
                System.out.println("引き分け");

                draws++;
            }
            else if ((player1Hand + 1) % 3 == player2Hand)
            {
                System.out.println("Player1 の勝ち");

                player1Wins++;
            }
            else
            {
                System.out.println("Player2 の勝ち");                       // Player2 の勝ち

                player2Wins++;
            }

            System.out.println();
        }

        System.out.println("最終結果:");                                    // 最終結果:
        System.out.println("Player1 の勝ち回数: " + player1Wins);           // Player1 の勝ち回数: 3
        System.out.println("Player2 の勝ち回数: " + player2Wins);           // Player2 の勝ち回数: 4
        System.out.println("引き分け: " + draws);                           // 引き分け: 3
	}
}
