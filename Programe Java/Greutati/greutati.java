abstract class Greutate{	
	abstract public int capacitate();
}

class GreutateCollection{
	Greutate[] greutati;
	int elemente=0;
	int max;
	
	public GreutateCollection(int max){
		greutati = new Greutate[max];
		this.max = max;
	}
	
	public void adaugaGreutate(Greutate g1){
		if(max>elemente){
			greutati[elemente]=g1;
			elemente++;
		}
	}

	public double medie(){
		double suma = 0;
		for(int i=0;i<elemente;i++){
			suma += greutati[i].capacitate();
		}
		return (double)(suma)/elemente;
	}
}

class GreutateSimpla extends Greutate {
	
	private int capacitate;
	
	public GreutateSimpla(int capacitate){
		this.capacitate = capacitate;
	}
	
	@Override
	public int capacitate(){
		return this.capacitate;
	}
	
}

class GreutateDubla extends Greutate {
	
	private Greutate g1,g2;
	
	public GreutateDubla(Greutate g1,Greutate g2){
		this.g1 = g1;
		this.g2 = g2;
		
	}
	
	public void setGreutate1(Greutate g1){
		this.g1 = g1;
	}
	
	public void setGreutate2(Greutate g2){
		this.g2 = g2;
	}
	
	@Override
	public int capacitate(){
		return g1.capacitate()+g2.capacitate();
	}
}


class Main{
	
	public static void main(String[] args){
			GreutateSimpla gs1 = new GreutateSimpla(7);
			GreutateSimpla gs2 = new GreutateSimpla(15);
			GreutateDubla gd1 = new GreutateDubla(gs1,gs2);
			GreutateSimpla gs3 = new GreutateSimpla(36);
			GreutateDubla gd2 = new GreutateDubla(gs2,gd1);
			
			GreutateCollection colectie = new GreutateCollection(6);
			colectie.adaugaGreutate(gs1);
			colectie.adaugaGreutate(gs2);
			colectie.adaugaGreutate(gd1);
			colectie.adaugaGreutate(gs3);
			colectie.adaugaGreutate(gd2);
			colectie.adaugaGreutate(gd2);
		
			System.out.println("Media colectiei este: "+colectie.medie()+" kg.");
			
			gd1.setGreutate1(gs2);
			gd1.setGreutate2(gs2);
			
			System.out.println("Media colectiei este: "+colectie.medie()+" kg.");
		
	}
}