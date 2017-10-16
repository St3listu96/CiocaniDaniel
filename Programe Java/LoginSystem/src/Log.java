import javax.swing.JFrame;
import javax.swing.JButton;
import java.awt.Component;
import java.awt.EventQueue;

import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.KeyStroke;

import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.ActionEvent;
import javax.swing.JPasswordField;
import javax.swing.JComponent;
import javax.swing.AbstractAction;
import javax.swing.Action;

import java.awt.Window.Type;
import java.awt.Font;
import java.awt.Color;
import org.eclipse.wb.swing.FocusTraversalOnArray;

import Average.Medie;

public class Log{

	private JFrame frmSystemLogin;
	private JTextField username;
	private JPasswordField parola;
	private final Action action = new SwingAction();
	protected Component frame;
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Log window = new Log();
					window.frmSystemLogin.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Log() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	
	private void runLogin(){
		String id = username.getText();
		@SuppressWarnings("deprecation")
		String pass = parola.getText();
		id = id.toLowerCase();
		
		if(id.equals("st3listu96") && pass.equals("parola")){
			//JOptionPane.showMessageDialog(frame, "Te-ai logat cu succes!");
			//JOptionPane.showMessageDialog(frame, "Te-ai logat cu succes!", "Felicitari!", 1);
			frmSystemLogin.dispose();
			Medie med = new Medie();
			Medie.main(null);
		}
		
		else{
			JOptionPane.showMessageDialog(frame, "ID-ul sau parola sunt incorecte!","Haha!",2);
			username.setText("");
			parola.setText("");
			username.requestFocus();
		}
	}
	
	private void initialize() {
		frmSystemLogin = new JFrame();
		frmSystemLogin.getContentPane().setBackground(Color.LIGHT_GRAY);
		frmSystemLogin.setFont(new Font("Comic Sans MS", Font.PLAIN, 12));
		frmSystemLogin.getContentPane().setFont(new Font("Comic Sans MS", Font.PLAIN, 11));
		frmSystemLogin.setType(Type.UTILITY);
		frmSystemLogin.setTitle("System login");
		frmSystemLogin.setBounds(100, 100, 347, 263);
		frmSystemLogin.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frmSystemLogin.getContentPane().setLayout(null);
		
		JLabel lblUsername = new JLabel("Username:");
		lblUsername.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));
		lblUsername.setBounds(43, 50, 68, 14);
		frmSystemLogin.getContentPane().add(lblUsername);
		
		JLabel lblPassword = new JLabel("Password:");
		lblPassword.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));
		lblPassword.setBounds(43, 95, 68, 14);
		frmSystemLogin.getContentPane().add(lblPassword);
		
		username = new JTextField();
		username.setBounds(109, 48, 157, 20);
		frmSystemLogin.getContentPane().add(username);
		username.setColumns(10);

		
		JButton btnLogare = new JButton("Logare");
		btnLogare.setForeground(Color.RED);
		btnLogare.setBackground(Color.CYAN);
		btnLogare.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));
		btnLogare.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				runLogin();
			}
		});
		btnLogare.setBounds(43, 147, 89, 23);
		frmSystemLogin.getContentPane().add(btnLogare);
		username.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
            	runLogin();
            }});	
		
		JButton btnIesire = new JButton("Iesire");
		btnIesire.setForeground(Color.RED);
		btnIesire.setBackground(Color.CYAN);
		btnIesire.setFont(new Font("Comic Sans MS", Font.PLAIN, 11));
		btnIesire.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
			
		});
	
		KeyStroke escapeKeyStroke = KeyStroke.getKeyStroke(KeyEvent.VK_ESCAPE, 0, false);
		Action escapeAction = new AbstractAction() {
			private static final long serialVersionUID = -5789883408039661293L;

			// close the frame when the user presses escape
		    public void actionPerformed(ActionEvent e) {
		        frmSystemLogin.dispose();
		    }
		}; 
		frmSystemLogin.getRootPane().getInputMap(JComponent.WHEN_IN_FOCUSED_WINDOW).put(escapeKeyStroke, "ESCAPE");
		frmSystemLogin.getRootPane().getActionMap().put("ESCAPE", escapeAction);
		
		btnIesire.setBounds(177, 147, 89, 23);
		frmSystemLogin.getContentPane().add(btnIesire);
		
		parola = new JPasswordField();
		parola = new JPasswordField(10);
	    parola.addKeyListener(new KeyListener(){
	            @Override
	            public void keyTyped(KeyEvent e) {
	                if(e.getKeyChar()==KeyEvent.VK_ENTER){
	                    runLogin();
	                }
	            }

	            @Override
	            public void keyPressed(KeyEvent e) {
	                //Do Nothing
	            }

	            @Override
	            public void keyReleased(KeyEvent e) {
	                //Do Nothing
	            }

	    });
		parola.setBounds(109, 93, 157, 20);
		frmSystemLogin.getContentPane().add(parola);
		frmSystemLogin.setFocusTraversalPolicy(new FocusTraversalOnArray(new Component[]{frmSystemLogin.getContentPane(), lblUsername, lblPassword, username, btnLogare, btnIesire, parola}));
		
	}
	private class SwingAction extends AbstractAction {
		private static final long serialVersionUID = 4349904351138390310L;
		public SwingAction() {
			putValue(NAME, "Exit");
			putValue(SHORT_DESCRIPTION, "Some short description");
		}
		public void actionPerformed(ActionEvent e) {
			frmSystemLogin.dispose();
		}
	}
}
