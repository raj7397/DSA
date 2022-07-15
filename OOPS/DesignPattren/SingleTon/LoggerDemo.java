 class LoggerDemo {
     public static int instCntr = 0;
     public LoggerDemo()
     {
         instCntr++;
         System.out.println("Logger contructor");
     }
     public void logged(String message)
     {
         System.out.println("Writting "+message);
     }
    
}
