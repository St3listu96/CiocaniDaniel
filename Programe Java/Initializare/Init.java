public class Init{
	private String prenume,nume;
	
	public Init(String first,String last){
		prenume = last;
		nume = first;
	}
	
	public void setFullname(String first,String last){
		prenume = last;
		nume = first;
	}
	
	public String getNume(){
		return nume;
	}
	
	public String getPrenume(){
		return prenume;
	}
	
	public void print(){
		System.out.println("Pe tine te cheama " + nume + " " + prenume);
	}
}

class Main{
	public static void main(String[] args){
			Init pers1 = new Init("Ciocani","Daniel");
			Init pers2 = new Init("Rad","Ana-Maria");
			pers1.setFullname("Ciocani","Daniel");
			System.out.println(pers1.getNume()+" "+pers2.getPrenume());
			//pers1.getPrenume();
			//pers1.print();
	}
}