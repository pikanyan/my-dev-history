public abstract class Character
{
    protected WeaponBehavior weaponBehavior;



    public abstract void fight();



    public void setWeapon(WeaponBehavior weaponBehavior)
    {
        this.weaponBehavior = weaponBehavior;
    }
}
