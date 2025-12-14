public class King extends Character
{
    public King()
    {
        weaponBehavior = new SwordBehavior();
    }

    @Override
    public void fight()
    {
        System.out.println("The King fights");
        
        weaponBehavior.useWeapon();
    }
}
