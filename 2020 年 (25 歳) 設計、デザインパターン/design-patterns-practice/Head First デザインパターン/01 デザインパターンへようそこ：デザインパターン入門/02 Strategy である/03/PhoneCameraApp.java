public abstract class PhoneCameraApp
{
	protected ShareStrategy shareStrategy;
	


	public abstract void edit();

	public void save()
	{
		System.out.println("Saving the photo");
	}
	
	public void share()
	{
		shareStrategy.share();
	}

	public void take()
	{
		System.out.println("Taking the photo");
	}
	


	public void setShareStrategy(ShareStrategy shareStrategy)
	{
		this.shareStrategy = shareStrategy;
	}
}
