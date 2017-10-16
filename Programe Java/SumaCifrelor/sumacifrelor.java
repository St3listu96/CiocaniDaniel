import java.io.*;
class SumaCifrelor{
	int numar;
	public SumaCifrelor(int numar){
		this.numar = numar;
	}
	
	public int doSum(){
		int uc;
		int suma=0;
		while(numar>0){
			uc = numar%10;
			suma+=uc;
			numar = numar/10;
		}
		return suma;
	}
}

class Main{
	public static void main(String[] args){
		int numar;
		try{
			BufferedReader in_stream_char = new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Introduceti numarul.");
			numar = Integer.parseInt(in_stream_char.readLine());
			SumaCifrelor sc = new SumaCifrelor(numar);
			System.out.println("Suma cifrelor numarului "+numar+" este: "+sc.doSum());
		}catch(IOException e){
			e.getMessage();
		}
	}
}