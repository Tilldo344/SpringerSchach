#include <iostream>

using namespace std;

int spielfeld[5][5];

int x;
int y;






void board() {
	cout << "  1  2  3  4  5 --X\n\n";

	  for (int i = 0; i < 5; i++) {
		  cout << i + 1 << " ";

		for (int j = 0; j < 5; j++) {

			cout << spielfeld[i][j] << "  ";

		}
		cout << endl;
	}
	cout << "y\n";
}

bool ValidMove(int x, int y, int newX, int newY) {

	int checkX = abs(newX - x);
	int checkY = abs(newY - y);

	return (checkX == 2 && checkY == 1) || (checkX == 1 && checkY == 2);
}

bool claimed(int x, int y) {

	return spielfeld[y - 1][x - 1] == 1;
}



void kords() {

	if (x >= 1 && x <= 5 && y >= 1 && y <= 5 && !claimed(x, y)) {

		spielfeld[y - 1][x - 1] = 1;

	}

	 else {
		    cout << "\nDas Feld ist schon belegt\n";
	    	cout << "\nversuch es erneut";
		exit(0);
		
	}

}

void springer() {
	while (true) {


		cout << "\nGib deine neue Position an x: ";
		int neuX;

		cin >> neuX;
		cout << "Gib deine neue Position an y: ";
		int neuY;
		cin >> neuY;


		if (ValidMove(x, y, neuX, neuY)) {
			x = neuX;
			y = neuY;
			kords();
			board();
		}
		else {

			cout << "so verhaelt sich kein springer\n";

		}
	}
}

int main() {

	board();

	cout << "\nGib deine Startposition an x: ";
	cin >> x;
	cout << "Gib deine Startposition an y: ";
	cin >> y;

	kords();

	  board();
	   springer();
	return 0;
}
