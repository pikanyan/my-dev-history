public class Troll extends Character
{
    public Troll()
    {
        weaponBehavior = new AxeBehavior();
    }

    @Override
    public void fight()
    {
        System.out.println("The Troll fights");
        
        weaponBehavior.useWeapon();
    }
}
