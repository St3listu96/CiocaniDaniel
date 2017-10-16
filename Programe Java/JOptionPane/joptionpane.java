import javax.swing.*;

class Dialog{
	public static void main(String[] argumente){
		int N = Integer.parseInt(JOptionPane.showInputDialog("N=")); 
		for(int i=0;i<=2*N;i++){
			if(i==4)
				System.out.println(i + " ");
		}
	}
}