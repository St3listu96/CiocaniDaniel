import java.util.Scanner;

class Prime{
	private int number;
	
	public Prime(int number){
		this.number = number;
	}
	
	public boolean check(){
		int i;
		int divizori=0;
		if(number == 1)
			return true;
		for(i=2;i<=number;i++){
			if(number % i == 0)
				divizori++;
			if(divizori==2)
				break;
		}
		if(divizori == 1)
			return true;
		else
			return false;
	}	
}

class Main{
	public static void main(String[] args){
			Prime p1;
			Scanner input = new Scanner(System.in);
			int number = input.nextInt();
			p1 = new Prime(number);
			if(p1.check()== true)
				System.out.println(number + " este numar prim.");
			else
				System.out.println(number + " nu este numar prim.");
	
	}
}