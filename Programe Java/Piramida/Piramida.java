public class Piramida{
	
	public int n;

	public Piramida(int nr){
		n = nr;
	}
	
	public void afiseazaPiramida(){
		int ct=1;
		int i;
		while(this.n!=0){
			for(i=1;i<=this.n;i++){
				System.out.print(ct);
			}
			System.out.println();
			ct++;
			this.n--;
		}
	}
}

class Main{
	public static void main(String[] args){
		Piramida p1;
		p1=new Piramida(6);
		p1.afiseazaPiramida();
	}
}