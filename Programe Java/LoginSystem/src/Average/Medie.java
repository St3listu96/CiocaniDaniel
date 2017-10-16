package Average;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JSeparator;

public class Medie {

	private JFrame frame;
	private JTextField txtNota;
	private JLabel txtNoteAdaugate;

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

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 410, 204);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(null);
		frame.setTitle("Calculator medie");

		JLabel lblIntroducetiNota = new JLabel("Nota");
		lblIntroducetiNota.setFont(new Font("Tahoma", Font.PLAIN, 16));
		lblIntroducetiNota.setBounds(32, 21, 43, 14);
		frame.getContentPane().add(lblIntroducetiNota);

		JLabel txtNoteAdaugate = new JLabel("Note adaugate:");
		txtNoteAdaugate.setBounds(10, 138, 149, 14);
		frame.getContentPane().add(txtNoteAdaugate);

		txtNota = new JTextField();
		txtNota.setBounds(85, 20, 86, 20);
		frame.getContentPane().add(txtNota);
		txtNota.setColumns(10);

		JButton btnNewButton = new JButton("Adauga nota");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (txtNota.getText().isEmpty())
					JOptionPane.showMessageDialog(frame, "Trebuie sa introduceti o nota.", "Eroare!", 2);
				else {
					double nota;
					nota = Double.parseDouble(txtNota.getText());
					if(nota>=1 && nota<=10){
						suma = suma + nota;
						noteAdaugate++;
						txtNoteAdaugate.setText("Note adaugate: " + noteAdaugate);
						txtNota.setText("");
						txtNota.requestFocus();
					}
					else
						JOptionPane.showMessageDialog(frame, "Nota trebuia sa fie intre 1 si 10.", "Eroare!", 2);
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
		btnNewButton_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if (noteAdaugate == 0)
					JOptionPane.showMessageDialog(frame, "Nu ati introdus nici o nota.", "Eroare!", 2);
				else {
					medie = suma / noteAdaugate;
					if (teza != -1) {
						medie = ((medie * 3) + teza) / 4;
						JOptionPane.showMessageDialog(frame, "Media cu teza este:" + medie, "Felicitari!", 1);
					} else {
						JOptionPane.showMessageDialog(frame, "Media este:" + medie, "Felicitari!", 1);
					}
				}

			}
		});
		btnNewButton_2.setBounds(115, 100, 184, 23);
		frame.getContentPane().add(btnNewButton_2);

		JButton btnExit = new JButton("Exit");
		btnExit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				frame.dispose();
			}
		});
		btnExit.setBounds(301, 134, 89, 23);
		frame.getContentPane().add(btnExit);

		JButton btnReset = new JButton("Reset");
		btnReset.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				noteAdaugate = 0;
				suma = 0.0;
				medie = 0.0;
				teza = -1.0;
				txtNoteAdaugate.setText("Note adaugate: 0");
				txtNota.setText(null);
			}
		});
		btnReset.setBounds(282, 66, 89, 23);
		frame.getContentPane().add(btnReset);
		
		JSeparator separator = new JSeparator();
		separator.setBounds(15, 51, 356, 9);
		frame.getContentPane().add(separator);

	}
}
