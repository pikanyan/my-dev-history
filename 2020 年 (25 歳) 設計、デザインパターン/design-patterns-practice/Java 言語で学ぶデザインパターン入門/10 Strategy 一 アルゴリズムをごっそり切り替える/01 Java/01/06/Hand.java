public class Hand
{
    public static final int HANDVALUE_GUU = 0;
    public static final int HANDVALUE_CHO = 1;
    public static final int HANDVALUE_PAA = 2;

    public static final Hand[] hands =
	{
        new Hand(HANDVALUE_GUU),
        new Hand(HANDVALUE_CHO),
        new Hand(HANDVALUE_PAA)
    };

    public static final String[] names =
	{
        "グー",
        "チョキ",
        "パー"
    };



    // private
    // public
    private int handValue;



    private Hand(int handValue)
	{
        this.handValue = handValue;
    }

    public static Hand getHand(int handValue)
	{
        return hands[handValue];
    }

    public boolean isStrongerThan(Hand h)
	{
        // this が h より強いとき true
        return fight(h) == 1;
    }

    public boolean isWeakerThan(Hand h)
	{
        // this が h より弱いとき true
        return fight(h) == -1;
    }



    public String toString()
	{
        return names[handValue];
    }



    private int fight(Hand h)
	{
        if (this.handValue == h.handValue)
		{
			// 引き分け
            return 0;
        }
		else if ((this.handValue + 1) % 3 == h.handValue)
		{
			// this の勝ち
            return 1;
        }
		else
		{
			// this の負け
            return -1;
        }
    }
}
