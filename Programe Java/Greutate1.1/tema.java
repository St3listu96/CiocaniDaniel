
public abstract class Greutate {
	public abstract int capacitate();	
}


public class GreutateSimpla extends Greutate {

	private int capacitate;
	
	public GreutateSimpla(int capacitate) {
		super();
		this.capacitate = capacitate;
	}

	@Override
	public int capacitate() {
		// TODO Auto-generated method stub
		return this.capacitate;
	}

	
}

public class GreutateDubla extends Greutate {
	
	private Greutate greutate1;
	private Greutate greutate2;
	
	
	
	public GreutateDubla(Greutate greutate1, Greutate greutate2) {
		super();
		this.greutate1 = greutate1;
		this.greutate2 = greutate2;
	}



	public void setGreutate1(Greutate greutate1) {
		this.greutate1 = greutate1;
	}



	public void setGreutate2(Greutate greutate2) {
		this.greutate2 = greutate2;
	}



	@Override
	public int capacitate() {
		// TODO Auto-generated method stub
		return greutate1.capacitate()+greutate2.capacitate();
	}

}

import java.util.ArrayList;

public class GreutateMultipla extends Greutate {
	
	private ArrayList <Greutate> greutati;
	private Greutate[] _greutati;
	private int max=10;
	private int el=0;
	
	public GreutateMultipla(ArrayList<Greutate> greutati) {
		super();
		this.greutati = greutati;
	}
	
	public GreutateMultipla(Greutate[] _greutati, int el)
	{
		this._greutati = _greutati;
		this.el = el;
		this.max = _greutati.length;
	}
	
	public GreutateMultipla()
	{
		_greutati = new Greutate[10];
		greutati = new ArrayList<>();
	}

	public void addGreutate(Greutate g) 
	{
		if(max==el)
		{
			Greutate[] new_greutati = new Greutate[max+10];
			max+=10;
			
			for(int i=0; i <el; i++)
				new_greutati[i] = _greutati[i];
			
			_greutati = new_greutati;
		}
		
		_greutati[el++] = g;
		
		greutati.add(g);
	}
	@Override
	public int capacitate() {
		int ret=0;
//		for(int i=0; i<el; i++)
//			ret += _greutati[i].capacitate();
//		
//		for(int i=0; i<greutati.size(); i++)
//			ret += greutati.get(i).capacitate();
		
		for(Greutate g: greutati)
			ret += g.capacitate();
		
//		for(Greutate g: _greutati)
//			ret += g.capacitate();
		
		return ret;
	}

}


public class GreutateCollection {
	int max;
	Greutate[] greutati;
	int el=0;
	
	public GreutateCollection(int max) {
		super();
		this.max = max;
		this.greutati = new Greutate[max];
	}
	
	public boolean adaugareGreutati(Greutate g)
	{
		if(max==el)
			return false;
		
		greutati[el++] = g;
		return true;
	}
	
	public double media()
	{
		int cap_tot = 0;
		for(int i=0; i<el; i++)
		{
			cap_tot += greutati[i].capacitate();
		}
		
		return (double)(cap_tot)/el;
	}
	
	

}


public class Main {

	
	public static void main(String[] args) {
		GreutateSimpla gs1 = new GreutateSimpla(10);
		
		GreutateSimpla gs2 = new GreutateSimpla(15);
		
		GreutateDubla gd1 = new GreutateDubla(gs1, gs2);
		
		GreutateMultipla gm1 = new GreutateMultipla();
		
		gm1.addGreutate(gd1);
		gm1.addGreutate(gs1);
		gm1.addGreutate(gs2);
		gm1.addGreutate(gd1);
		
		GreutateCollection collection = new GreutateCollection(4);
		collection.adaugareGreutati(gs1);
		collection.adaugareGreutati(gs2);
		collection.adaugareGreutati(gd1);
		collection.adaugareGreutati(gm1);
		
		System.out.println(collection.media());
	}
	
	
}
