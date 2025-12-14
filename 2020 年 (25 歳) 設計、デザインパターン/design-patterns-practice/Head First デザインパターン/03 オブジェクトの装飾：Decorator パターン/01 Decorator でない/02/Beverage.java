public class Beverage
{
    protected String description = "Unknown Beverage";
    private boolean milk = false;
    private boolean soy = false;
    private boolean mocha = false;
    private boolean whip = false;



    public String getDescription()
    {
        return description;
    }

    public double cost()
    {
        double totalCost = 0.0;

        if (hasMilk())
            totalCost += 0.10;
        if (hasSoy())
            totalCost += 0.15;
        if (hasMocha())
            totalCost += 0.20;
        if (hasWhip())
            totalCost += 0.10;

        return totalCost;
    }



    public void setMilk(boolean milk)
    {
        this.milk = milk;
    }

    public boolean hasMilk()
    {
        return milk;
    }

    public void setSoy(boolean soy)
    {
        this.soy = soy;
    }

    public boolean hasSoy()
    {
        return soy;
    }

    public void setMocha(boolean mocha)
    {
        this.mocha = mocha;
    }

    public boolean hasMocha()
    {
        return mocha;
    }

    public void setWhip(boolean whip)
    {
        this.whip = whip;
    }

    public boolean hasWhip()
    {
        return whip;
    }
}
