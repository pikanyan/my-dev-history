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

    public static int[] handWeights = { 1, 1, 1 }; 



    public static void main(String[] args)
    {
        Random random = new Random();

        int player1Wins = 0;
        int player2Wins = 0;
        int draws = 0;

        int player1Hand = random.nextInt(3);
        int player2Hand = random.nextInt(3);

        for (int i = 0; i < 10; i++)
        {
            System.out.println("Round " + (i + 1));                         // Round 1
            System.out.println("Player1 の手: " + handNames[player1Hand]);  // Player1 の手: グー
            System.out.println("Player2 の手: " + handNames[player2Hand]);  // Player2 の手: パー



            if (player1Hand == player2Hand)
            {
                System.out.println("引き分け");

                draws++;                                                    // Player1 は次も同じ手を出す
            }
            else if ((player1Hand + 1) % 3 == player2Hand)
            {
                System.out.println("Player1 の勝ち");

                player1Wins++;                                              // Player1 は次も同じ手を出す
                handWeights[player1Hand]++;                                 // 勝った手の重みを増やす
            }
            else
            {
                System.out.println("Player1 の負け");

                player2Wins++;
                player1Hand = chooseNextHand(random);                       // Player1 は次は違う手を出す
                handWeights[player1Hand]++;                                 // その手の重みを強化
            }

            player2Hand = random.nextInt(3);                                // Player2 は次も違う手を出す

            System.out.println();
        }

        System.out.println("最終結果:");                                    // 最終結果:
        System.out.println("Player1 の勝ち回数: " + player1Wins);           // Player1 の勝ち回数: 3
        System.out.println("Player2 の勝ち回数: " + player2Wins);           // Player2 の勝ち回数: 4
        System.out.println("引き分け: " + draws);                           // 引き分け: 3
	}



    public static int chooseNextHand(Random random)
    {
        int sum = handWeights[HAND_GUU] + handWeights[HAND_CHO] + handWeights[HAND_PAA];
        int rand = random.nextInt(sum);



        System.out.println(handWeights[HAND_GUU]);                          // 1
        System.out.println(handWeights[HAND_CHO]);                          // 1
        System.out.println(handWeights[HAND_PAA]);                          // 1

        System.out.println(sum);                                            // 3
        System.out.println(rand);                                           // 2



        if (rand + 1 <= handWeights[HAND_GUU])
        {
            return HAND_GUU;
        }
        else if (rand + 1 <= handWeights[HAND_GUU] + handWeights[HAND_CHO])
        {
            return HAND_CHO;
        }
        else
        {
            return HAND_PAA;
        }
    }
}
