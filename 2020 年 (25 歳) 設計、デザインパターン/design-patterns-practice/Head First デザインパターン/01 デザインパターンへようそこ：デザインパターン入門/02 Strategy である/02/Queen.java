public class Queen extends Character
{
    public Queen()
    {
        weaponBehavior = new KnifeBehavior();
    }

    @Override
    public void fight()
    {
        System.out.println("The Queen fights");
        
        weaponBehavior.useWeapon();
    }
}
