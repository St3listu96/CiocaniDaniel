import java.util.Random;

abstract class Algoritm
{
    protected Integer[] nr;
    private Random r=new Random();
    public Algoritm(int n)
    {
	nr=new Integer[n];
	for(int i=0; i<nr.length; i++)
	    nr[i]=new Integer(r.nextInt(10)); //Pt. afisarea unui rezultat se modifica nr[i]=new Integer(r.nextInt(10)); adica se folosesc doar aceleasi 10 valori
    }
    public abstract boolean search(Integer n);
    public String toString()
    {
	String s="";
	for(int i=0; i<nr.length; i++)
	    s=s+nr[i]+" ";
	return " - Numar elemente : "+nr.length+" - Elemente : "+s;
    }
}

class CautareLiniaraDupaIdentitate extends Algoritm
{
    public CautareLiniaraDupaIdentitate(int n)
    {
	super(n);
    }
    @Override
    public boolean search(Integer n)
    {
	for(int i=0; i<nr.length; i++){ //super e optional
	    if(nr[i] == n)
			return true;
	}
	return false;
    }
    @Override
    public String toString()
    {
	return "CautareLiniaraDupaIdentitate "+super.toString();
    }
}

class CautareLiniaraDupaEchivalenta extends Algoritm
{
     public CautareLiniaraDupaEchivalenta(int n)
    {
	super(n);
    }
    @Override
    public boolean search(Integer n)
    {
	for(int i=0; i<nr.length; i++) 
	    if(nr[i].equals(n))
			return true;
	return false;
    }
    @Override
    public String toString()
    {
	return "CautareLiniaraDupaEchivalenta "+super.toString();
    }
}

class TestAlgoritm
{
    private Algoritm[] algoritmi=new Algoritm[1000];
    private int nralg=0;
    
    public void addAlgoritm(Algoritm a)
    {
	if(nralg==algoritmi.length)
	    System.out.println("Eroare la adaugare algoritm.");
	else
	    {
		algoritmi[nralg]=a;
		nralg++;
	    }
    }

    public void analyse(Integer n)
    {
	for(int i=0; i<nralg; i++)
	    if(algoritmi[i].search(n))
			System.out.println(algoritmi[i]);
    }
    
}

class ClientAlgoritm
{
    public static void main(String[] args)
    {
	TestAlgoritm test=new TestAlgoritm();
	for(int i=0; i<500; i++) //se modifica si for-ul, sa mearga de ex. pana la 5 
	    test.addAlgoritm(new CautareLiniaraDupaIdentitate(10));
	for(int i=0; i<2; i++) //se modifica si for-ul asta, sa mearga de ex. pana la 2
	    test.addAlgoritm(new CautareLiniaraDupaIdentitate(10));
	test.analyse(0);
    }
}
