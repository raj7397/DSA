
class space{
    public void empty()
    {
        System.out.println("space is empty");
    }
}
interface Cookable{
    void cook();
}

public class InnerClassDemo {
    public static void main(String[] args) {
        space sp = new space(){
            public void empty()
            {
                System.out.println("empty inner class");
            }

        };
        Cookable ck = new Cookable(){
            public void cook()
            {
                System.out.println("inteface innner class cookable");
            }
        };
        ck.cook();
        sp.empty();
    }
}
