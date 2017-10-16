class Pi{
	public static void main(String args[]){
		final double N=100000000;
		//nr. de termeni ce se aduna
		double pi=0; 
		for(int i=0;i<N;i++)
			if(i%2==0)
				pi=pi+4.0/(2*i+1);
			else pi=pi-4.0/(2*i+1);
			System.out.println("PI calculat ca suma de "+N+" termeni: "+pi);
			System.out.println("Constanta PI din clasa Math: "+Math.PI); 
			}
			}