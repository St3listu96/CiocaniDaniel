import java.util.Random;
import java.util.Date;
class CoordinateGenerator {
	private Random randomGenerator;
	public CoordinateGenerator() {
		Date now = new Date();
		long sec = now.getTime();
		randomGenerator = new Random(sec);
	}

	public int generateX() {
		int x = randomGenerator.nextInt(101);
			if(x < 5) {
				x = 0;
			} else if(x > 95) {
				x = 100;
			} else {
				x = randomGenerator.nextInt(99) + 1;
			}
			return x;
	}
	public int generateY() {
		int y = randomGenerator.nextInt(101);	
			if(y < 5) {
				y = 0;
			} else if(y > 80 ) {
				y = 50;
			} else {
				y = randomGenerator.nextInt(49) + 1;
			}
			return y;
	}
}

class Minge{

	private int x,y;
	private static CoordinateGenerator cg = new CoordinateGenerator();
	public Minge(int x,int y){
		this.x = x;
		this.y = y;
	}
	
	public int getX(){
		return x;
	}
	
	public int getY(){
		return y;
	}
	
	public void suteaza() throws Out,Corner,Gol{
		x=cg.generateX();
		y=cg.generateY();
		if(y==0 || y==50)
			throw new Out("Este Out. (Y="+y+")");
		if((x==0 || x==100)&&(y>=20 && y<=30))
			throw new Gol("Este Gol. (X,Y)=("+x+","+y+")");
		if((x==0 || x==100) && ((y>0&&y<20)||(y>30&&y<50)))
			throw new Corner("Este Corner. (X,Y)=("+x+","+y+")");
	}
}

class Out extends Exception{
	public Out(String details){
		super(details);
	}
}

class Gol extends Exception{
	public Gol(String details){
		super(details);
	}
}

class Corner extends Exception{
	public Corner(String details){
		super(details);
	}
}

class Main{
	public static void main(String[] args){
		Joc j1 = new Joc("Steaua","Dinamo");
		Joc j2 = new Joc("Barcelona","Real Madrid");
		j1.simuleaza();
		j2.simuleaza();
		System.out.println(j1);
		System.out.println(j2);
	}
}

class Joc{
	private String team1,team2;
	private int gol=0,corner=0,out=0;
	
	public Joc(String team1,String team2){
			this.team1 = team1;
			this.team2 = team2;
	}
	
	public String toString(){
		return team1 + " - " + team2 + " Numar goluri:" + gol + " Numar out-uri:" + out +" Numar cornere:" + corner+".";
	}
	
	public void simuleaza(){
		Minge m1 = new Minge(0,0);
		for(int i=0;i<=1000;i++){
			try{
				m1.suteaza();
				System.out.println(team1+" - "+team2 + " : Mingea se afla la coordonatele ("+m1.getX()+","+m1.getY()+")");
			}catch(Out e){
				System.err.println(e+ " "+team1+" - "+team2 + " : Mingea se afla la coordonatele ("+m1.getX()+","+m1.getY()+")");
				out++;
				int auxx = m1.getX();
				int auxy = m1.getY();
				m1=new Minge(auxx,auxy);
			}catch(Gol e){
				e.getMessage();
				System.err.println(e+ " "+team1+" - "+team2 + " : Mingea se afla la coordonatele ("+m1.getX()+","+m1.getY()+")");
				gol++;
				m1 = new Minge(50,25);

			}catch(Corner e){
				System.err.println(e+ " "+team1+" - "+team2 + " : Mingea se afla la coordonatele ("+m1.getX()+","+m1.getY()+")");
				corner++;
				if(m1.getX()==0){
					if(m1.getY()>0 && m1.getY()<20)
						m1 = new Minge(0,0);
					else if(m1.getY()>30 && m1.getY()<50)
						m1= new Minge(0, 50);
				}
				if(m1.getX()==100){
					if(m1.getY()>0 && m1.getY()<20)
						m1 = new Minge(100,0);
					else if(m1.getY()>30 && m1.getY()<50)
						m1= new Minge(100, 50);
				}
			}
		}
	}

}
