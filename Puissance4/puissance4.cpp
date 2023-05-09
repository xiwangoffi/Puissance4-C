#include <stdlib.h>
#include <stdio.h>

typedef struct Cell { //D�finition de la fonction Cell
	int x;
	int y;
	int occupe;
} Cell;

typedef struct Board { //D�finition de la fonction Board
	Cell* cell;
	int width;
	int height;
} Board;

void initBoard(Board* board); //Init de initBoard
void displayBoard(Board* board); //Init de displayBoard
void placeO(Board* board, int x, int y); //Init de la fonction pour mettre une lettre
int getCellPosition(Board* board, int x, int y); //Init de la fonction pour r�cup�rer la position d'une cellule
void play(Board* board); //Init de la fonction pour jouer
void checkPlacement(Board* board, int x, int y); //Init fonction pour v�rifier si le jeton du joueur peut descendre


int getCellPosition(Board* board, int x, int y) { //R�cup�re la position d'une cellule
	return x * board->width + y;
}

Cell* getCell(Board* board, int x, int y) { //R�cup�re une cellule
	int pos = getCellPosition(board, x, y);
	return &board->cell[pos];
}

void initBoard(Board* board) {
	board->cell = (Cell*)malloc(sizeof(Cell) * board->width * board->height); //Attribution d'un espace dans la m�moire au tableau
	for (int x = 0; x < board->width; x++) {
		for (int y = 0; y < board->height; y++) {
			Cell* cell = getCell(board, x, y); //D�finition des valeurs des cellules par d�faut
			cell->x = x;
			cell->y = y;
			cell->occupe = 0;
		}
	}
}

void displayBoard(Board* board) { //Affichage du tableau
	printf("\n");
	for (int x = 0; x < board->width; x++) {
		for (int y = 0; y < board->height; y++) {
			Cell* cell = getCell(board, x, y); //R�cup�ration des cellules
			char display = '.'; //Mettre un . si occupe vaut 0
			if (cell->occupe == 1) {
				display = 'O'; //Mettre un O si occupe vaut 1
			}
			printf("%c", display); //Affichage sur le tableau des valeurs occupe
		}
		printf("\n");
	}
}

void placeO(Board* board, int x, int y) {
	board->cell[getCellPosition(board, x, y)].occupe = 1; //Permet de placer un O dans le tableau
}

void play(Board* board) {
	int y;
	printf("\nIndiquer une colonne entre (0 et 4): "); //Demande au joueur de choisir une colonne o� jouer
	scanf_s("%d", &y);

	while (y > 4 || y < 0) { //V�rification de la valeur saisie
		printf("\nValeurs non valide\n");
		printf("\nIndiquer une colonne entre (0 et 4): ");
		scanf_s("%d", &y);
	}

	checkPlacement(board, 0, y); //V�rification si le jeton du joueur peut aller plus bas
}


void checkPlacement(Board* board, int x ,int y) {
	int j = 1;
	while (board->cell[getCellPosition(board, x-1, y)].occupe = 0 && j < 4) { //V�rifie si la ligne du dessous est libre
		if (board->cell[getCellPosition(board, x + j, y)].occupe = 1)  //Si elle n'est pas libre
			placeO(board, j-1, y); //Placer un O � sur la case pr�c�dente
			displayBoard(board); //Afficher le tableau
		} else {
			j += 1;
			displayBoard(board);
			printf("J = %d / y = %d", j, y);
		}
	}

}

int main() { //Main function
	Board board;
	board.height = 4; //D�finition de la taille du tableau (largeur et hauteur)
	board.width = 4;


	initBoard(&board);	  //
	displayBoard(&board); //Fonction pour d�marrer le jeu
	play(&board);		  //


}