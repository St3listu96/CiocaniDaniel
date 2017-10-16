package Convertor;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.JRadioButton;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.ButtonGroup;

public class BinaryConv {

	private JFrame frame;
	private JTextField textNumar;
	private JRadioButton saispeBiti;
	private JRadioButton treizecisidoiBiti;
	private JRadioButton patruBiti;
	private final ButtonGroup buttonGroup = new ButtonGroup();
	

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					BinaryConv window = new BinaryConv();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public BinaryConv() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	
	public static boolean isNumber(String str){
		try{
			double numar = Double.parseDouble(str);
		}
		catch(NumberFormatException nfe){
			return false;
		}
		return true;
		
	}
	
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 325, 367);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		frame.setTitle("Numar -> biti");
		
		textNumar = new JTextField();
		textNumar.setBounds(10, 26, 289, 20);
		frame.getContentPane().add(textNumar);
		textNumar.setColumns(10);
		textNumar.setHorizontalAlignment(SwingConstants.RIGHT);
		
		JRadioButton optBiti = new JRadioButton("8bits");
		buttonGroup.add(optBiti);
		optBiti.setBounds(76, 60, 72, 23);
		frame.getContentPane().add(optBiti);
		
		saispeBiti = new JRadioButton("16bits");
		buttonGroup.add(saispeBiti);
		saispeBiti.setBounds(150, 60, 74, 23);
		frame.getContentPane().add(saispeBiti);
		
		treizecisidoiBiti = new JRadioButton("32bits");
		buttonGroup.add(treizecisidoiBiti);
		treizecisidoiBiti.setBounds(238, 60, 65, 23);
		frame.getContentPane().add(treizecisidoiBiti);
		
		patruBiti = new JRadioButton("4bits");
		buttonGroup.add(patruBiti);
		patruBiti.setBounds(6, 60, 68, 23);
		frame.getContentPane().add(patruBiti);
		
		JButton buton7 = new JButton("7");
		buton7.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				textNumar.setText(textNumar.getText() + 7);
			}
		});
		buton7.setBounds(16, 90, 72, 50);
		frame.getContentPane().add(buton7);
		
		JButton buton4 = new JButton("4");
		buton4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				textNumar.setText(textNumar.getText() + 4);
			}
		});
		buton4.setBounds(16, 151, 72, 50);
		frame.getContentPane().add(buton4);
		
		JButton buton1 = new JButton("1");
		buton1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				textNumar.setText(textNumar.getText() + 1);
			}
		});
		buton1.setBounds(16, 212, 72, 50);
		frame.getContentPane().add(buton1);
		
		JButton buton8 = new JButton("8");
		buton8.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				textNumar.setText(textNumar.getText() + 8);
			}
		});
		buton8.setBounds(110, 90, 72, 50);
		frame.getContentPane().add(buton8);
		
		JButton buton9 = new JButton("9");
		buton9.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				textNumar.setText(textNumar.getText() + 9);
			}
		});
		buton9.setBounds(208, 90, 72, 50);
		frame.getContentPane().add(buton9);
		
		JButton buton5 = new JButton("5");
		buton5.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				textNumar.setText(textNumar.getText() + 5);
			}
		});
		buton5.setBounds(110, 151, 72, 50);
		frame.getContentPane().add(buton5);
		
		JButton buton6 = new JButton("6");
		buton6.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				textNumar.setText(textNumar.getText() + 6);
			}
		});
		buton6.setBounds(208, 151, 72, 50);
		frame.getContentPane().add(buton6);
		
		JButton buton2 = new JButton("2");
		buton2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				textNumar.setText(textNumar.getText() + 2);
			}
		});
		buton2.setBounds(110, 212, 72, 50);
		frame.getContentPane().add(buton2);
		
		JButton buton3 = new JButton("3");
		buton3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				textNumar.setText(textNumar.getText() + 3);
			}
		});
		buton3.setBounds(208, 212, 72, 50);
		frame.getContentPane().add(buton3);
		
		JButton buton0 = new JButton("0");
		buton0.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				textNumar.setText(textNumar.getText() + 0);
			}
		});
		buton0.setBounds(110, 273, 72, 50);
		frame.getContentPane().add(buton0);
		
		textNumar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if(isNumber(textNumar.getText())){
					long number = Integer.parseInt(textNumar.getText());
					long cifra;
					String rezultat="";
					
					if(number <0){
						JOptionPane.showMessageDialog(frame, "Numarul e mai mic ca 0.", "Eroare!", 2);
						textNumar.setText("");
						textNumar.requestFocus();
					}
					else{
						if(number <= 2140000000){
							while(number>0){
								cifra = number%2;
								rezultat = cifra + rezultat;
								number = number / 2;
							}
					
						if(patruBiti.isSelected()){
							int lungime = 4- rezultat.length();
							if(lungime >0){
								int i;
								for(i=0;i<lungime;i++){
									rezultat = 0 + rezultat;
								}
							}
						}
						
						if(optBiti.isSelected()){
							int lungime = 8- rezultat.length();
							if(lungime >0){
								int i;
								for(i=0;i<lungime;i++){
									rezultat = 0 + rezultat;
								}
							}
						}
						
						if(saispeBiti.isSelected()){
							int lungime = 16- rezultat.length();
							if(lungime >0){
								int i;
								for(i=0;i<lungime;i++){
									rezultat = 0 + rezultat;
								}
							}
						}
						
						if(treizecisidoiBiti.isSelected()){
							int lungime = 32- rezultat.length();
							if(lungime >0){
								int i;
								for(i=0;i<lungime;i++){
									rezultat = 0 + rezultat;
								}
							}
						}
						
						textNumar.setText(rezultat);
						}
						else{
							JOptionPane.showMessageDialog(frame, "Prea mare numarul.", "Eroare.", 2);
						}
				}
				}
				else{
					JOptionPane.showMessageDialog(frame, "Caractere invalide.", "Eroare.", 2);
				}
			}
		});
	}
}
