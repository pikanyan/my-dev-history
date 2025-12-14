public abstract class Beverage
{
    protected String description = "Unknown Beverage";

    public enum Size
    {
        TALL,   // 350 ml
        GRANDE, // 470 ml
        VENTI   // 590 ml
    };

	protected Size size = Size.TALL;



    public String getDescription()
    {
        return description;
    }

    public void setSize(Size size)
    {
		this.size = size;
	}
	
	public Size getSize()
    {
		return this.size;
	}

    public abstract double cost();
}
