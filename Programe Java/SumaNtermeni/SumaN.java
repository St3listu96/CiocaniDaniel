import java.io.*;
class SumaN{
	int number;
	public SumaN(int number){
		this.number = number;
	}
	
	public int doSumaN(){
		int suma=0;
		for(int i=1;i<=this.number;i++){
			suma+=i;
		}
		return suma;
	}
}

class Main{
	public static void main(String[] args){
		int number;
		try{
			BufferedReader in_stream_char = new BufferedReader(new InputStreamReader(System.in));
			number = Integer.parseInt(in_stream_char.readLine());
			SumaN sn = new SumaN(number);
			System.out.println(sn.doSumaN());
		}catch(IOException e){
			e.getMessage();
		}
		
		
		
	}
}