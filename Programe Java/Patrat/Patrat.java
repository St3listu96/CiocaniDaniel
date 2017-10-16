public class Patrat{
	public int latura;
	
	public Patrat(){
		latura = 10;
	}
	
	public Patrat(int l){
		latura = l;
	}
	
	public void afiseazaArie(){
		System.out.println("Patrat "+ this.latura +" "+ " " +this.latura*this.latura);
	}
	
}

class Main{
	public static void main(String[] args){
		Patrat p1 = new Patrat();
		Patrat p2 = new Patrat(5);
		p1.afiseazaArie();
		p2.afiseazaArie();
		Patrat p3 = new Patrat();
		p3.afiseazaArie();
	}
	
	
	
	
	
}

