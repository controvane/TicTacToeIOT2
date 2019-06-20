
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

String printer;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

struct PosiblePlay {
	int jugada;
	int ganador;
	int playValue;
};

void setup()
{
	Serial.begin(9600);
	pinMode(registro1, INPUT);
	pinMode(registro2, INPUT);
	pinMode(registro3, INPUT);
	pinMode(registro4, INPUT);
	pinMode(registro5, INPUT);
	pinMode(registro6, INPUT);
	pinMode(registro7, INPUT);
	pinMode(registro8, INPUT);
	pinMode(registro9, INPUT);
	printer = "";
	resetBoard();
	board();
}

void loop()
{
	int n;
	if(Serial.available()){
		n = Serial.read();
		n = n - 48;
	}
	if (n >= 1 && n <= 9) {
		if (square[n] == ' ') {
			square[n] = 'X';
			n = play();
			return;
		}
		else {
			Serial.println(String("Se lo nota nervioso, Dr. Floyd"));
			//Serial.println(printer);
			//board();
			return;
		}
	}
	//Serial.println();
	delay(waitTime);
}

void board()
{
	//system("cls");
	Serial.println(String("\n\n\tTres en Raya\n\n"));
	
	Serial.println(String("Jugador 1 (X)  -  Jugador 2(PC) (O)"));
	Serial.println();
	
	Serial.println(String("     |     |     "));
	
	Serial.print(String("  "));
	Serial.print(String(square[1]));
	Serial.print(String("  |  ")); 
	Serial.print(String(square[2]));
	Serial.print(String("  |  "));
	Serial.println(String(square[3]));
	
	Serial.println(String("_____|_____|_____"));
	Serial.println(String("     |     |     "));
	
	Serial.print(String("  "));
	Serial.print(String(square[4]));
	Serial.print(String("  |  ")); 
	Serial.print(String(square[5]));
	Serial.print(String("  |  "));
	Serial.println(String(square[6]));
	
	Serial.println(String("_____|_____|_____"));
	Serial.println(String("     |     |     "));
	
	Serial.print(String("  "));
	Serial.print(String(square[7]));
	Serial.print(String("  |  ")); 
	Serial.print(String(square[8]));
	Serial.print(String("  |  "));
	Serial.println(String(square[9]));
	
	
	Serial.println(String("     |     |     "));
}

void resetBoard(){
	for(int i = 0; i < 10; i++){
		square[i] = ' ';
	}
}

int checkWin(char squareCheck[])
{
	int testcell;
	if (squareCheck[1] != ' ' && squareCheck[1] == squareCheck[2] && squareCheck[2] == squareCheck[3]) {
		testcell = 1;
	}
	else if (squareCheck[4] != ' ' && squareCheck[4] == squareCheck[5] && squareCheck[5] == squareCheck[6]) {
		testcell = 4;
	}
	else if (squareCheck[7] != ' ' && squareCheck[7] == squareCheck[8] && squareCheck[8] == squareCheck[9]) {
		testcell = 7;
	}
	else if (squareCheck[1] != ' ' && squareCheck[1] == squareCheck[4] && squareCheck[4] == squareCheck[7]) {
		testcell = 1;
	}
	else if (squareCheck[2] != ' ' && squareCheck[2] == squareCheck[5] && squareCheck[5] == squareCheck[8]) {
		testcell = 2;
	}
	else if (squareCheck[3] != ' ' && squareCheck[3] == squareCheck[6] && squareCheck[6] == squareCheck[9]) {
		testcell = 3;
	}
	else if (squareCheck[1] != ' ' && squareCheck[1] == squareCheck[5] && squareCheck[5] == squareCheck[9]) {
		testcell = 1;
	}
	else if (squareCheck[3] != ' ' && squareCheck[3] == squareCheck[5] && squareCheck[5] == squareCheck[7]) {
		testcell = 3;
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (squareCheck[i] == ' ') { 
				return -1;
			}
		}
		return 0;
	}
	return (squareCheck[testcell] == 'X' ? 1 : 2);
}

// checkear esto
PosiblePlay theoreticalPlay(char player) {
	PosiblePlay result;
	int playernum = (player == 'X') ? 1 : 2;
	char adversary = (player == 'X') ? 'O' : 'X';
	int adversarynum = (adversary == 'X') ? 1 : 2;
	result.playValue = -10;
	result.ganador = adversarynum;
	result.jugada = 0;
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
		}
	}
	return result;
}

int play() {
	int check = checkWin(square);
	if (check == -1) {
		if (square[5] == ' ') {
			square[5] = 'O';
		}
		else {
			PosiblePlay result = theoreticalPlay('O');
			square[result.jugada] = 'O';
		}
		check = checkWin(square);
		if (check == 2) {
			Serial.println(String("Gano el Jugador 2(PC), gracias por intentar, Dr. Floyd"));
		}
		else if (check == 0) {
			Serial.println(String("Empate, casi lo logra, Dr. Floyd"));
		}
		else if (check == 1) {
			Serial.println(String("Esto nunca debio haber pasado, Dr. Floyd"));
		}
		board();
		return check;
	}
	else if (check == 1) {
		Serial.println(String("Gano el Jugador 1, o sea usted, Dr. Floyd"));
	}
	else if (check == 0) {
		Serial.println(String("Empate, usted no se deja, Dr. Floyd"));
	}
	else if (check == 2) {
		Serial.println(String("Usted no sirve para este juego, Dr. Floyd"));
	}
	board();
	return check;
}