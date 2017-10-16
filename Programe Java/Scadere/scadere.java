import javax.swing.*;
class Scadere{
	public static void main(String args[]){
		int u1,z1,s1; 
		int u2,s2;
		boolean are=false;
		for(u1=0;u1<=9;u1++) 
			for(z1=0;z1<=9;z1++) 
				for(s1=1;s1<=9;s1++) 
					for(u2=0;u2<=9;u2++) 
						for(s2=1;s2<=9;s2++){
							int nr1=100*s1+10*z1+u1;
							int nr2=100*s2+20+u2;
							if(nr1-nr2==879){
								are=true;System.out.println(nr1+"-"+nr2+"=879");
								}
							}
							if(are==false)
								System.out.println("nu are solutie"); 
							}
}