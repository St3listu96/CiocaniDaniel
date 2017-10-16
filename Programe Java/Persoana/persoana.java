import java.util.Scanner;

class Persoana{
	private String nume,prenume;
	private int varsta;
	
	public Persoana(String nume,String prenume,int varsta){
		this.nume = nume;
		this.prenume = prenume;
		this.varsta = varsta;
	}
	
	public String getName(){
		return nume;
	}
	
	public String getPrenume(){
		return prenume;
	}
	
	public int getVarsta(){
		return varsta;
	}
	
	public void afisare(){
		System.out.printf("Nume: %s, Prenume: %s, Varsta: %d\n",nume,prenume,varsta);
	}
}

class Student extends Persoana{
	private String numeFacultate;
	private int numarMatricol;
	
	public Student(String nume,String prenume,int varsta,String numeFacultate,int numarMatricol){
		super(nume,prenume,varsta);
		this.numeFacultate = numeFacultate;
		this.numarMatricol = numarMatricol;
	}
	
	public String getFacultate(){
		return numeFacultate;
	}
	
	public int getNumarMatricol(){
		return numarMatricol;
	}
	
	@Override
	public void afisare(){
		System.out.printf("Nume: %s, Prenume: %s, Varsta: %d, Facultate: %s, Numar matricol: %d\n",getName(),getPrenume(),getVarsta(),numeFacultate,numarMatricol);
	}
}

class Main{
	public static void main(String[] args){
		Student s1 = new Student("Ciocani","Daniel",20,"UPT AC II CTI",9236);
		s1.afisare();
		System.out.println(s1.getNumarMatricol());
		Persoana p1 = new Persoana("Popescu","Ion",27);
		p1.afisare();
	}
}