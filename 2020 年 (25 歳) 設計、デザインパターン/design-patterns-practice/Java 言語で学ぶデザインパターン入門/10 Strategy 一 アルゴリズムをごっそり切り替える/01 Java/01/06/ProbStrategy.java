import java.util.Random;



public class ProbStrategy implements Strategy
{
    private Random random;
    private int prevHandValue = 0;
    private int currentHandValue = 0;

    private int[][] history =
    {
        {1, 1, 1},  // 前回「グー」を出したときの次の手の重み
        {1, 1, 1},  // 前回「チョキ」を出したときの次の手の重み
        {1, 1, 1}   // 前回「パー」を出したときの次の手の重み
    };



    public ProbStrategy(int seed)
    {
        random = new Random(seed);
    }



    @Override
    public Hand nextHand()
    {
        int sum = getSum(currentHandValue);
        int bet = random.nextInt(sum);
        int handValue = 0;

        System.out.println("===次の手を選ぶ処理===");
        printHistory();
        System.out.println("currentHandValue: " + currentHandValue + ": " + Hand.names[currentHandValue]);
        System.out.println("sum: " + sum);
        System.out.println("bet: " + bet);



        if (bet + 1 <= history[currentHandValue][0])
        {
            handValue = 0;
        }
        else if (bet + 1 <= history[currentHandValue][0] + history[currentHandValue][1])
        {
            handValue = 1;
        }
        else
        {
            handValue = 2;
        }
        
        prevHandValue = currentHandValue;
        currentHandValue = handValue;
        
        System.out.println("currentHandValue: " + currentHandValue + ": " + Hand.names[currentHandValue]);



        return Hand.getHand(handValue);
    }

    @Override
    public void study(boolean win)
    {
        if (win)
        {
            history[prevHandValue][currentHandValue]++;
        }
        else
        {
            history[prevHandValue][(currentHandValue + 1) % 3]++;
            history[prevHandValue][(currentHandValue + 2) % 3]++;
        }

        System.out.println("======");
        printHistory();
    }



    private int getSum(int hv)
    {
        int sum = 0;

        for (int i = 0; i < 3; i++)
        {
            sum += history[hv][i];
        }
        
        return sum;
    }



    private void printHistory()
    {
        for (int i = 0; i < 3; i++)
        {
            System.out.println("前回の手: " + i + " => グー: " + history[i][0] + ", チョキ: " + history[i][1] + ", パー: " + history[i][2]);
        }
    }
}
