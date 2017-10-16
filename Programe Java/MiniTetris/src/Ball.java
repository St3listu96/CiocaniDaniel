import java.awt.Graphics2D;
import java.awt.Rectangle;
 
public class Ball {
	private static final int DIAMETER = 30;	//diametrul mingii
	int x = 0;		//pozitia initiala a mingii, sus
	int y = 0;		//pozitia initiala a mingii, stanga
	int xa = 1;
	int ya = 1;
	private Game game;
 
	public Ball(Game game) {
		this.game= game;
	}
 
	void move() {
		//fiecare if limiteaza o margine a ferestrei
		if (x + xa < 0)
			xa = 1;		//mingea se deplaseaza la dreapta cu cate un pixel la fiecare runda
		if (x + xa > game.getWidth() - DIAMETER)	//cand mingea depaseste marginea ii schimbam directia
			xa = -1;		//mingea se deplaseaza la stanga cu cate un pixel la fiecare runda
		if (y + ya < 0)
			ya = 1;		//mingea se deplaseaza in jos cu cate un pixel la fiecare runda
		if (y + ya > game.getHeight() - DIAMETER)	//cand mingea depaseste marginea de jos a ferestrei,
			game.gameOver();						//terminam jocul
		if (collision()){		//mingea se deplaseaza in sus, daca se intersecteaza cu jucatorul
			ya = -1;								
			y = game.player.getTopY() - DIAMETER;   //plasam mingea deasupra jucatorului, 
					//pt ca dreptunghiurile in care se gasesc, sa nu se intersecteze
		}
		x = x + xa;		//realizeaza deplasarile de mai sus
		y = y + ya;		//realizeaza deplasarile de mai sus
	}
 
	private boolean collision() {
		return game.player.getBounds().intersects(getBounds()); //returneaza true daca dreptunghiul  
								//jucatorului intersecteaza dreptunghiul mingii
	}
 
	public void paint(Graphics2D g) {
		g.fillOval(x, y, DIAMETER, DIAMETER);
	}
	
	public Rectangle getBounds() {
		return new Rectangle(x, y, DIAMETER, DIAMETER);
	}
}