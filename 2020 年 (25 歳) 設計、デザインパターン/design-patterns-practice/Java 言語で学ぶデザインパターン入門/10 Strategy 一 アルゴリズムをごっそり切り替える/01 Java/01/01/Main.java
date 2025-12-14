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

        int player1Hand = random.nextInt(3);
        int player2Hand = random.nextInt(3);

        System.out.println(player1Hand);                                // 0
        System.out.println(player2Hand);                                // 2

        System.out.println("Player1 の手: " + handNames[player1Hand]);  // Player1 の手: グー
        System.out.println("Player2 の手: " + handNames[player2Hand]);  // Player2 の手: パー



        if (player1Hand == player2Hand)
        {
            System.out.println("引き分け");
        }
        else if ((player1Hand + 1) % 3 == player2Hand)
        {
            System.out.println("Player1 の勝ち");
        }
        else
        {
            System.out.println("Player2 の勝ち");                       // Player2 の勝ち
        }
	}
}
