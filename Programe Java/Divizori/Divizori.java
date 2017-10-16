class Divizori{
 public static void main(String args[]){
 int nr=Integer.parseInt(args[0]);
 int contor=0;
	for(int i=1; i<=nr; i++)
		if(nr%i ==0){
			System.out.println(i);
			contor++;
		}
		if(contor==0)
			System.out.println("Nu existeste divizori.");
		} 
		}