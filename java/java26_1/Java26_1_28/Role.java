public class Role {
    private String name;
    private int heath;
    private int maxHurt;

    public int getMaxHurt() {
        return maxHurt;
    }
    public void setMaxHurt(int maxHurt) {
        this.maxHurt = maxHurt;
    }
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getHeath() {
        return heath;
    }

    public void setHeath(int heath) {
        this.heath = heath;
    }

    public void attack(Role role, int hurt) {
        if (hurt > this.maxHurt) {
            System.out.println("攻击力不足");
        } else {
            int heath = role.getHeath() - hurt;
            if (heath > 0) {
                role.heath = heath;
            } else {
                role.heath = 0;
            }
            System.out.println(this.name + "attack" + role.name);
            System.out.println(role.name + "的血量为" + role.heath);           
        }
    }

    public Role() {}
    public Role(String name, int heath, int maxHurt) {
        this.heath = heath;
        this.name = name;
        this.maxHurt = maxHurt;
    }
}
