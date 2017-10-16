class Ceas{
	
	public int hour,minute,second;
	
	public Ceas(int h,int m,int s){
		hour = ((h>=0 && h<24) ? h : 0);
		minute = ((m>=0 && m<60) ? m : 0);
		second = ((s>=0 && s<60) ? s : 0);		
	}
	
	public void afiseazaCeas(){
		System.out.println("Este ora "+hour+":"+minute+":"+second); 
	}
}

class Main{
	public static void main(String[] args){
		Ceas c1 = new Ceas(23,12,66);
		Ceas c2 = new Ceas(23,13,55);
		c1.afiseazaCeas();
		c2.afiseazaCeas();
	}
	
	
}