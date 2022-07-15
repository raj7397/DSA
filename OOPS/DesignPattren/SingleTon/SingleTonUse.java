
import SingleTon.LogggerDemo;

public class SingleTonUse{
    public static void main(String[] args) {
        LoggerDemo logger1 = new LoggerDemo();
        logger1.logged("Entering to system");
        LoggerDemo logger2 = new LoggerDemo();
        logger2.logged("2nd time entering to sys");
        System.out.println("instance: "+ LoggerDemo.instCntr);
    }
}