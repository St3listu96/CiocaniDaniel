import static java.awt.Color.green;
import java.awt.Graphics;    /* awt, swing = biblioteci care creeaza un proces, care se porneste cand
			cream un obiect JFrame; acest proces gestioneaza interfata
			cu utilizatorul (primeste informatii de la tastatura si mouse*/                 
import java.awt.Color;
import java.awt.Graphics2D;						
import java.awt.RenderingHints;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
 
@SuppressWarnings("serial")
public class Game extends JPanel {	//JPanel informeaza toate "ascultatoarele" care sunt inregistrate 
					//sa primeasca notificari pt un eveniment

	Ball ball = new Ball(this);	//instantiaza clasa minge (creeaza obiectul minge)
	Player player = new Player(this);	//instantiaza clasa jucator (creeaza obiectul jucator)

	public Game() {
		addKeyListener(new KeyListener() { 	//"asculta" daca o tasta de la tastatura e apasata
			@Override
			public void keyTyped(KeyEvent e) {
			}
 
			@Override
			public void keyReleased(KeyEvent e) {
				player.keyReleased(e);
			}
 
			@Override
			public void keyPressed(KeyEvent e) {	//se apleleaza cand e o tasta apasata
				player.keyPressed(e);
			}
		});
		setFocusable(true);		//pt a putea controla
	}
	
	private void move() {										
		ball.move();			//apelam mingea
		player.move();			//apelam jucatorul
	}
 
	@Override
	public void paint(Graphics g) {       	//desenez mingea si jucatorul
		super.paint(g);			//curata ecranul		
		Graphics2D g2d = (Graphics2D) g;		//deoarece folosesc Graphics2D, creez variabila  g2d
		g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING,   //face marginile figurii (mingii) mai fina
				RenderingHints.VALUE_ANTIALIAS_ON);
		g.setColor(Color.BLUE);			//mingea este de culoare albastra
		ball.paint(g2d);
		g.setColor(Color.RED);			//jucatorul este de culoare rosie
		player.paint(g2d);
		setBackground(green);
		 
	}
	
	public void gameOver() {		//se apeleaza cand mingea atinge marginea (de jos) ferestrei
		JOptionPane.showMessageDialog(this, "Game Over", "Game Over", JOptionPane.YES_NO_OPTION); //afiseaza 
									//mesaj si buton cu ok, la terminarea jocului
		System.exit(ABORT);
	}
 
	public static void main(String[] args) throws InterruptedException {
		JFrame frame = new JFrame("mini Tenis");  	//desenam fereastra in care are loc jocul
		Game game = new Game();
		frame.add(game);
		frame.setSize(300, 400);
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  //pt inchiderea jocului, o data cu fereastra
		
		while (true) {		//incepe un ciclu infinit, in care apelam in mod repetat 
			game.move();			//"move" pentru a schimba pozitia cercului 
			game.repaint();		//apoi apelam "repaint" sa redesenam mingea in noua pozitie
			Thread.sleep(5);		//firul curent de executie suspenda executia pt 5 milisecunde
		}
	}
}