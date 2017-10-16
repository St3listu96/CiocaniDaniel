package Average;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.ActionEvent;
import javax.swing.JSeparator;
import java.awt.Color;

public class Medie {

	private JFrame frame;
	private JTextField txtNota;
	private JLabel txtNoteAdaugate;
	private JLabel lblCopyright;

	private int noteAdaugate = 0;
	private double suma = 0.0;
	private double medie;
	private double teza = -1.0;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Medie window = new Medie();
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
	public Medie() {
		initialize();
	}
	
	public class NotaInvalida extends Exception{
		public NotaInvalida(){
			super();
		}
		
		public NotaInvalida(String msj){
			super(msj);
		}
		
	}
	
	public class UnInput extends Exception {

	}


	
	public static boolean isNumber(String str){
		try{
			double numar = Double.parseDouble(str);
		}
		catch (NumberFormatException nfe){
			return false;
		}
		return true;
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.getContentPane().setBackground(Color.LIGHT_GRAY);
		frame.setBounds(100, 100, 415, 202);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		frame.setTitle("Calculator de medii");
		frame.setResizable(false);

		JLabel lblIntroducetiNota = new JLabel("Nota :");
		lblIntroducetiNota.setFont(new Font("Comic Sans MS", Font.BOLD, 16));
		lblIntroducetiNota.setBounds(32, 21, 55, 14);
		frame.getContentPane().add(lblIntroducetiNota);

		JLabel txtNoteAdaugate = new JLabel("Note adaugate: 0");
		txtNoteAdaugate.setFont(new Font("Comic Sans MS", Font.BOLD, 11));
		txtNoteAdaugate.setBounds(10, 138, 149, 14);
		frame.getContentPane().add(txtNoteAdaugate);

		txtNota = new JTextField();
		txtNota.setBounds(97, 20, 55, 20);
		frame.getContentPane().add(txtNota);
		txtNota.setColumns(10);

		JButton btnNewButton = new JButton("Adauga nota");
		btnNewButton.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
		btnNewButton.setBackground(Color.CYAN);
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try{
					if(txtNota.getText().isEmpty() == true) throw new UnInput();
					double nota;
					nota = Double.parseDouble(txtNota.getText());
					if(nota<1 || nota >10) throw new NotaInvalida("INCORECT");
					nota = Double.parseDouble(txtNota.getText());
					suma = suma + nota;
					noteAdaugate++;
					txtNoteAdaugate.setText("Note adaugate: " + noteAdaugate);
					txtNota.setText("");
					txtNota.requestFocus();	
					
			}catch (NotaInvalida e){
				JOptionPane.showMessageDialog(frame, "Nota trebuia sa fie intre 1 si 10.", "Eroare!", 2);
			}catch (UnInput e){
				JOptionPane.showMessageDialog(frame, "Trebuie sa introduceti o nota.", "Eroare!", 2);
			}catch (NumberFormatException e){
				JOptionPane.showMessageDialog(frame, "'"+txtNota.getText() + "' nu este un caracter valid.", "Eroare!", 2);
				txtNota.setText(null);
			}
				
					
					
				
				
				
			}
		});
		btnNewButton.setBounds(32, 66, 107, 23);
		frame.getContentPane().add(btnNewButton);
		
		txtNota.addActionListener(new ActionListener(){

            public void actionPerformed(ActionEvent e){

            	btnNewButton.doClick();

            }});


		JButton btnNewButton_1 = new JButton("Adauga teza");
		btnNewButton_1.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
		btnNewButton_1.setBackground(Color.CYAN);
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (txtNota.getText().isEmpty())
					JOptionPane.showMessageDialog(frame, "Trebuie sa introduceti o nota.", "Eroare!", 2);
				else {
					teza = Double.parseDouble(txtNota.getText());
					if(teza>=1 && teza <=10){
						txtNota.setText("");
						txtNota.requestFocus();
					}
					else{
						JOptionPane.showMessageDialog(frame, "Teza trebuia sa fie intre 1 si 10.", "Eroare!", 2);
						teza=-1;
					}
					
				}

			}
		});
		btnNewButton_1.setBounds(149, 66, 107, 23);
		frame.getContentPane().add(btnNewButton_1);

		JButton btnNewButton_2 = new JButton("Calculeaza media");
		btnNewButton_2.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
		btnNewButton_2.setBackground(Color.CYAN);
		btnNewButton_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (noteAdaugate == 0)
					JOptionPane.showMessageDialog(frame, "Nu ati introdus nici o nota.", "Eroare!", 2);
				else {
					medie = suma / noteAdaugate;
					if (teza != -1) {
						medie = ((medie * 3) + teza) / 4;
						JOptionPane.showMessageDialog(frame, "Media cu teza este: " + medie, "Felicitari!", 1);
					} else {
						JOptionPane.showMessageDialog(frame, "Media este: " + medie, "Felicitari!", 1);
					}
				}

			}
		});
		btnNewButton_2.setBounds(115, 100, 184, 23);
		frame.getContentPane().add(btnNewButton_2);

		JButton btnExit = new JButton("Exit");
		btnExit.setBackground(Color.RED);
		btnExit.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
		btnExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				frame.dispose();
			}
		});
		btnExit.setBounds(301, 134, 89, 23);
		frame.getContentPane().add(btnExit);

		JButton btnReset = new JButton("Reset");
		btnReset.setFont(new Font("Comic Sans MS", Font.BOLD, 12));
		btnReset.setBackground(Color.CYAN);
		btnReset.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				noteAdaugate = 0;
				suma = 0.0;
				medie = 0.0;
				teza = -1.0;
				txtNoteAdaugate.setText("Note adaugate: 0");
				txtNota.setText(null);
				txtNota.requestFocus(true);
			}
		});
		btnReset.setBounds(282, 66, 89, 23);
		frame.getContentPane().add(btnReset);
		
		JSeparator separator = new JSeparator();
		separator.setBounds(15, 52, 375, 8);
		frame.getContentPane().add(separator);
		
	
	}

}