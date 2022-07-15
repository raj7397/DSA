import java.util.ArrayList;

class Student{
    public void print()
    {
        System.out.println("Student");
    }
}
class EnggStudent extends Student{
    public void print()
    {
        System.out.println("Engg Student");
    }
    public void printOther()
    {
        System.out.println("print Other");
    }
}
class MgmtStudent extends Student{
    public void print()
    {
        System.out.println("mgmt student");
    }
    public void printMgmt()
    {
        System.out.println("mgmtPrint");
    }
}

public class WildCardExp {
    
    public void showDetails(ArrayList<?extends Student> arr)
    {
        for(int i = 0; i < arr.size();i++)
        {
            
            Student s = arr.get(i);

            if(s instanceof EnggStudent )
            {
                EnggStudent es = (EnggStudent)s;
                es.printOther();
            }
            if(s instanceof MgmtStudent)
            {
                MgmtStudent ms = (MgmtStudent)s;
                ms.printMgmt();
            }
            //s.print();
            //s.printOther();
            //s.printMgmt();
            //EnggStudent es = (EnggStudent)s;
            //es.print();
            //es.printOther();
        }
    }
    
    public static void main(String[] args) {
        Student s1 = new Student();
        EnggStudent es1 = new EnggStudent();
        if(es1 instanceof Student)
            System.out.println("es1 instanceof s1");
        if(es1 instanceof EnggStudent)
            System.out.println("es1 instance of EnggStudent");;
        ArrayList<EnggStudent> alEng = new ArrayList<>();
        alEng.add(new EnggStudent());
        alEng.add(new EnggStudent());
        alEng.add(new EnggStudent());
        ArrayList<MgmtStudent> alMgmt = new ArrayList<>();
        alMgmt.add(new MgmtStudent());
        alMgmt.add(new MgmtStudent());

        ArrayList<Student> st = new ArrayList<>();
        st.add(new Student());
        st.add(new Student());
        WildCardExp wildCardExp = new WildCardExp();
       // wildCardExp.showDetails(st);
        wildCardExp.showDetails(alEng);
        //wildCardExp.showDetails(alMgmt);
    }
    
}
