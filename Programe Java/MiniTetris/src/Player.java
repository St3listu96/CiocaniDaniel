import java.awt.Graphics2D;
import java.awt.Rectangle;		//clasa care are o metoda de intersectie 
				//(returneaza true cand 2 dreptunghiuri ocupa acelasi spatiu)
import java.awt.event.KeyEvent;
 
public class Player {
	private static final int Y = 330;	//distanta jucatorului fata de marginea de sus
				//aceasta valoare a lui Y este folosita in metoda Paint si getBounds
	private static final int WIDTH = 60;	//latimea paletei
	private static final int HEIGHT = 10;	//inaltimea paletei
	int x = 0;	//jucatorul este in partea stanga a ferestrei (coord)
	int xa = 0;	//jucatorul este static la inceputul jocului
	private Game game;
 
	public Player(Game game) {
		this.game = game;
	}
 
	public void move() {
		if (x + xa > 0 && x + xa < game.getWidth() - WIDTH)
			x = x + xa;
	}
 
	public void paint(Graphics2D g) {
		g.fillRect(x, Y, WIDTH, HEIGHT);
	}
 
	public void keyReleased(KeyEvent e) {	//cand tasta e eliberata
		xa = 0;		//xa=o (se opreste jucatorul)
	}
 
	public void keyPressed(KeyEvent e) {		//e.getKeyCode=obtinem codul tastei apasate
					//cand se apasa o tasta, se apeleaza metoda keyPressed a jucatorului
		if (e.getKeyCode() == KeyEvent.VK_LEFT)			//cand e apasata tasta stanga
			xa = -2;		//jucatorul se deplaseaza la stanga cu cate un pixel la fiecare runda
		if (e.getKeyCode() == KeyEvent.VK_RIGHT)		//cand e apasata tasta dreapta
			xa = 2;		//jucatorul se deplaseaza la dreapta cu cate un pixel la fiecare runda
	
	}
 
	public Rectangle getBounds() {	//returneaza obiect de tip dreptunghi, indicand pozitia jucatorului
		return new Rectangle(x, Y, WIDTH, HEIGHT);	//aceasta metoda va fi utilizata de catre minge, 
					//sa cunoasca pozitia jucatorului si in acest mod sa se detecteze coliziunea
	}
 
	public int getTopY() {		//plasam mingea deasupra jucatorului, pt ca 
					//dreptunghiurile in care se gasesc, sa nu se interclaseze
		return Y;
	}
}