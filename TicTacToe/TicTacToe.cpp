// TicTacToe.cpp: define el punto de entrada de la aplicación de consola.
//

// #include "stdafx.h"
#include "iostream"
#include "string"
using namespace std;
/* Use File->Load Prog to
load a different Program
*/

const int registro1 = 2;
const int registro2 = 3;
const int registro3 = 4;
const int registro4 = 5;
const int registro5 = 6;
const int registro6 = 7;
const int registro7 = 8;
const int registro8 = 9;
const int registro9 = 10;
const int waitTime = 100;

string printer;

char square[10] = { '0','1','2','3','4','5','6','7','8','9' };

struct PosiblePlay {
	int jugada;
	int ganador;
	int playValue;
};

void board()
{
	//system("cls");
	cout << "\n\n\tTres en Raya\n\n" << endl;

	cout << "Jugador 1 (X)  -  Jugador 2(PC) (O)" << endl << endl;

	cout << "     |     |     " << endl;

	cout << "  ";
	cout << square[1];
	cout << "  |  ";
	cout << square[2];
	cout << "  |  ";
	cout << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  ";
	cout << square[4];
	cout << "  |  ";
	cout << square[5];
	cout << "  |  ";
	cout << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  ";
	cout << square[7];
	cout << "  |  ";
	cout << square[8];
	cout << "  |  ";
	cout << square[9] << endl;


	cout << "     |     |     " << endl;
}

void resetBoard() {
	for (int i = 0; i < 10; i++) {
		square[i] = ' ';
	}
}

int checkWin(char squareCheck[])
{
	int testcell;
	if (squareCheck[1] != ' ' && squareCheck[1] == squareCheck[2] && squareCheck[2] == squareCheck[3] ) {
		testcell = 1;
	}
	else if (squareCheck[4] != ' ' && squareCheck[4] == squareCheck[5] && squareCheck[5] == squareCheck[6] ) {
		testcell = 4;
	}
	else if (squareCheck[7] != ' ' && squareCheck[7] == squareCheck[8] && squareCheck[8] == squareCheck[9] ) {
		testcell = 7;
	}
	else if (squareCheck[1] != ' ' && squareCheck[1] == squareCheck[4] && squareCheck[4] == squareCheck[7] ) {
		testcell = 1;
	}
	else if (squareCheck[2] != ' ' && squareCheck[2] == squareCheck[5] && squareCheck[5] == squareCheck[8] ) {
		testcell = 2;
	}
	else if (squareCheck[3] != ' ' && squareCheck[3] == squareCheck[6] && squareCheck[6] == squareCheck[9] ) {
		testcell = 3;
	}
	else if (squareCheck[1] != ' ' && squareCheck[1] == squareCheck[5] && squareCheck[5] == squareCheck[9] ) {
		testcell = 1;
	}
	else if (squareCheck[3] != ' ' && squareCheck[3] == squareCheck[5] && squareCheck[5] == squareCheck[7] ) {
		testcell = 3;
	}
	else {
		for (int i = 1; i <=9; i++) {
			if (squareCheck[i]==' ') return -1;
		}
		return 0;
	}
	return (squareCheck[testcell]=='X' ? 1 : 2);
}

// checkear esto
int level = 0;
PosiblePlay theoreticalPlay(char player) {
	PosiblePlay result;
	int playernum = (player == 'X') ? 1 : 2;
	char adversary = (player == 'X') ? 'O' : 'X';
	int adversarynum = (adversary == 'X') ? 1 : 2;
	result.playValue = -10;
	result.ganador = adversarynum;
	result.jugada = 0;
	level++;
	for (int i = 1; i <= 9; i++) {
		if (square[i] == ' ') {
			PosiblePlay trial;
			square[i] = player;
			int check = checkWin(square);
			if (check == -1) {
				trial = theoreticalPlay(adversary);
				trial.jugada = i;
				trial.playValue = -trial.playValue;
			}
			else {
				trial.jugada = i;
				trial.ganador = check;
				trial.playValue = (check == playernum) ? 1 : (check == 0) ? 0 : -1;
			}
			square[i] = ' ';
			if (trial.playValue > result.playValue) {
				result.jugada = trial.jugada;
				result.ganador = trial.ganador;
				result.playValue = trial.playValue;
			}
			//if (level<=1) 
			//	cout << "trial " << trial.jugada << " - " << trial.playValue << endl;
		}
	}
	level--;
	return result;
}

int play() {
	int check = checkWin(square);
	if (check == -1) {
		level = 0;
		PosiblePlay result = theoreticalPlay('O');
		// cout << "seleccionada " << result.jugada << "-" << result.playValue << endl;
		square[result.jugada] = 'O';
		check = checkWin(square);
		if (check == 2) {
			cout << "Gano el Jugador 2(PC), gracias por intentar, Dr. Floyd" << endl;
		}
		else if (check == 0) {
			cout << "Empate, casi lo logra, Dr. Floyd" << endl;
		}
		else if (check == 1) {
			cout << "Esto nunca debio haber pasado, Dr. Floyd" << endl;
		}
		board();
		return check;
	}
	else if (check == 1) {
		cout << "Gano el Jugador 1, o sea usted, Dr. Floyd" << endl;
	}
	else if (check == 0) {
		cout << "Empate, usted no se deja, Dr. Floyd" << endl;
	}
	else if (check == 2) {
		cout << "Usted no sirve para este juego, Dr. Floyd" << endl;
	}
	board();
	return check;
}

void setup()
{
	/*pinMode(registro1, INPUT);
	pinMode(registro2, INPUT);
	pinMode(registro3, INPUT);
	pinMode(registro4, INPUT);
	pinMode(registro5, INPUT);
	pinMode(registro6, INPUT);
	pinMode(registro7, INPUT);
	pinMode(registro8, INPUT);
	pinMode(registro9, INPUT);*/
	printer = "";
	resetBoard();
	board();
}

void loop()
{
	int n;
	cin >> n;
	if (n >= 1 && n <= 9) {
		if (square[n] == ' ') {
			square[n] = 'X';
			play();
			return;
		}
		else {
			cout << "Se lo nota nervioso, Dr. Floyd" << endl;
			//Serial.println(printer);
			//board();
			return;
		}
	}
	else {
		cout << "Estamos jugando Tic-Tac-Toe, Dr. Floyd" << endl;
		return;
	}
	//Serial.println();
}

int main()
{
	setup();
	while (true) { loop(); }
	return 0;
}

