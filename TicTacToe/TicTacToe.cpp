// TicTacToe.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
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
	if (squareCheck[1] == squareCheck[2] && squareCheck[2] == squareCheck[3] && (squareCheck[1] == 'X' || squareCheck[1] == 'O')) {
		if (squareCheck[1] == 'X') {
			return 1;
		}
		else if (squareCheck[1] == 'O') {
			return 2;
		}
	}
	else if (squareCheck[4] == squareCheck[5] && squareCheck[5] == squareCheck[6] && (squareCheck[4] == 'X' || squareCheck[4] == 'O')) {
		if (squareCheck[4] == 'X') {
			return 1;
		}
		else if (squareCheck[4] == 'O') {
			return 2;
		}
	}
	else if (squareCheck[7] == squareCheck[8] && squareCheck[8] == squareCheck[9] && (squareCheck[7] == 'X' || squareCheck[7] == 'O')) {
		if (squareCheck[7] == 'X') {
			return 1;
		}
		else if (squareCheck[7] == 'O') {
			return 2;
		}
	}
	else if (squareCheck[1] == squareCheck[4] && squareCheck[4] == squareCheck[7] && (squareCheck[1] == 'X' || squareCheck[1] == 'O')) {
		if (squareCheck[1] == 'X') {
			return 1;
		}
		else if (squareCheck[1] == 'O') {
			return 2;
		}
	}
	else if (squareCheck[2] == squareCheck[5] && squareCheck[5] == squareCheck[8] && (squareCheck[2] == 'X' || squareCheck[2] == 'O')) {
		if (squareCheck[2] == 'X') {
			return 1;
		}
		else if (squareCheck[2] == 'O') {
			return 2;
		}
	}
	else if (squareCheck[3] == squareCheck[6] && squareCheck[6] == squareCheck[9] && (squareCheck[3] == 'X' || squareCheck[3] == 'O')) {
		if (squareCheck[3] == 'X') {
			return 1;
		}
		else if (squareCheck[3] == 'O') {
			return 2;
		}
	}
	else if (squareCheck[1] == squareCheck[5] && squareCheck[5] == squareCheck[9] && (squareCheck[1] == 'X' || squareCheck[1] == 'O')) {
		if (squareCheck[1] == 'X') {
			return 1;
		}
		else if (squareCheck[1] == 'O') {
			return 2;
		}
	}
	else if (squareCheck[3] == squareCheck[5] && squareCheck[5] == squareCheck[7] && (squareCheck[3] == 'X' || squareCheck[3] == 'O')) {
		if (squareCheck[3] == 'X') {
			return 1;
		}
		else if (squareCheck[3] == 'O') {
			return 2;
		}
	}
	else if ((squareCheck[1] == 'X' || squareCheck[1] == 'O') && (squareCheck[2] == 'X' || squareCheck[2] == 'O') && (squareCheck[3] == 'X' || squareCheck[3] == 'O')) {
		if ((squareCheck[4] == 'X' || squareCheck[4] == 'O') && (squareCheck[5] == 'X' || squareCheck[5] == 'O') && (squareCheck[6] == 'X' || squareCheck[6] == 'O')) {
			if ((squareCheck[7] == 'X' || squareCheck[7] == 'O') && (squareCheck[8] == 'X' || squareCheck[8] == 'O') && (squareCheck[9] == 'X' || squareCheck[9] == 'O')) {
				return 0;
			}
		}
	}
	else {
		return -1;
	}
}

// checkear esto
PosiblePlay theoreticalPlay(int jugada, char player) {
	square[jugada] = player;
	PosiblePlay result;
	result.jugada = 0;
	result.ganador = -1;
	if (jugada % 2 == 0) {
		result.playValue = 1;
	}
	else {
		if (jugada == 5) {
			result.playValue = 3;
		}
		else {
			result.playValue = 2;
		}
	}
	if (player == 'X') {
		result.playValue *= -1;
	}
	if (checkWin(square) >= 0) {
		result.jugada = jugada;
		result.ganador = checkWin(square);
		square[jugada] = ' ';
		return result;
	}
	PosiblePlay posiblePlay;
	for (int i = 1; i <= 9; i++) {
		if (square[i] == ' ') {
			if (i == 1) {
				if (player == 'O') {
					posiblePlay = theoreticalPlay(i, 'X');
					posiblePlay.playValue = result.playValue + posiblePlay.playValue;
					if ((posiblePlay.ganador == 2 || posiblePlay.ganador == 0) && posiblePlay.playValue >= 0) {
						result = posiblePlay;
					}
				}
				if (player == 'X') {
					posiblePlay = theoreticalPlay(i, 'O');
					posiblePlay.playValue = result.playValue + posiblePlay.playValue;
					if ((posiblePlay.ganador == 1 || posiblePlay.ganador == 0) && posiblePlay.playValue >= 0) {
						result = posiblePlay;
					}
				}
			}
			else {
				if (player == 'O') {
					posiblePlay = theoreticalPlay(i, 'X');
					posiblePlay.playValue = result.playValue + posiblePlay.playValue;
					if ((posiblePlay.ganador == 2 || posiblePlay.ganador == 0) && posiblePlay.playValue >= result.playValue) {
						result = posiblePlay;
					}
				}
				if (player == 'X') {
					posiblePlay = theoreticalPlay(i, 'O');
					posiblePlay.playValue = result.playValue + posiblePlay.playValue;
					if ((posiblePlay.ganador == 1 || posiblePlay.ganador == 0) && posiblePlay.playValue >= result.playValue) {
						result = posiblePlay;
					}
				}
			}
		}
	}
	square[jugada] = ' ';
	return result;
}

void play() {
	if (checkWin(square) == 1) {
		cout << "Gano el Jugador 1" << endl;
		board();
		return;
	}
	if (checkWin(square) == 0) {
		cout << "Empate" << endl;
		board();
		return;
	}
	if (square[5] == ' ') {
		square[5] = 'O';
	}
	else {
		PosiblePlay result;
		result.jugada = 0;
		result.ganador = -1;
		PosiblePlay posiblePlay;
		for (int i = 1; i <= 9; i++) {
			if (square[i] == ' ') {
				if (i % 2 == 0) {
					result.playValue = 1;
				}
				else {
					if (i == 5) {
						result.playValue = 3;
					}
					else {
						result.playValue = 2;
					}
				}
				posiblePlay = theoreticalPlay(i, 'O');
				posiblePlay.playValue = result.playValue + posiblePlay.playValue;
				if ((posiblePlay.ganador == 2 || posiblePlay.ganador == 0) && (posiblePlay.playValue >= result.playValue)) {
					result = posiblePlay;
				}
			}
		}
		square[result.jugada] = 'O';
	}
	if (checkWin(square) == 2) {
		cout << "Gano el Jugador 2(PC)" << endl;
		board();
		return;
	}
	if (checkWin(square) == 1) {
		cout << "Gano el Jugador 1" << endl;
		board();
		return;
	}
	if (checkWin(square) == 0) {
		cout << "Empate" << endl;
		board();
		return;
	}
	board();
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
	if (n == 1) {
		if (square[1] == ' ') {
			square[1] = 'X';
		}
		//Serial.println(printer);
		//board();
		play();
		return;
	}
	else if (n == 2) {
		if (square[2] == ' ') {
			square[2] = 'X';
		}
		//Serial.println(printer);
		//board();
		play();
		return;
	}
	else if (n == 3) {
		if (square[3] == ' ') {
			square[3] = 'X';
		}
		//Serial.println(printer);
		//board();
		play();
		return;
	}
	else if (n == 4) {
		if (square[4] == ' ') {
			square[4] = 'X';
		}
		//Serial.println(printer);
		//board();
		play();
		return;
	}
	else if (n == 5) {
		if (square[5] == ' ') {
			square[5] = 'X';
		}
		//Serial.println(printer);
		//board();
		play();
		return;
	}
	else if (n == 6) {
		if (square[6] == ' ') {
			square[6] = 'X';
		}
		//Serial.println(printer);
		//board();
		play();
		return;
	}
	else if (n == 7) {
		if (square[7] == ' ') {
			square[7] = 'X';
		}
		//Serial.println(printer);
		//board();
		play();
		return;
	}
	else if (n == 8) {
		if (square[8] == ' ') {
			square[8] = 'X';
		}
		//Serial.println(printer);
		//board();
		play();
		return;
	}
	else if (n == 9) {
		if (square[9] == ' ') {
			square[9] = 'X';
		}
		//Serial.println(printer);
		//board();
		play();
		return;
	}
	//Serial.println();
}

int main()
{
	setup();
	while (true) {
		loop();
	}
    return 0;
}

