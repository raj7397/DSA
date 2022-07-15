class Animal{
    private void eat()
    {
        System.out.println("Animals are eating");
    }
}
class Horse extends Animal{
/*    public void eat()
    {
        System.out.println("Horse eating");
    }*/
}
public class TestAnimals {
    public static void main(String [] args)
    {
        Animal a = new Horse();
       // a.eat();
        Horse hr = new Horse();
        //hr.eat();
    }
    
}
