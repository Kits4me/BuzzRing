int currState;
void stateMachine() {
	int nextState = currState;
	switch (currState) {
		default:
		case WAITING_TO_START:
			ledsOFF();
			displayOFF();
			nextState = (digitalRead(startPositionPin) == LOW) ? ON_START_POINT : WAITING_TO_START;
			break;
		case ON_START_POINT:
			greenON();
			nextState = ON_START_POINT ;
			showNum(0, 100);
			if (digitalRead(startPositionPin) == HIGH) {
				initGameTimes();
				nextState = GOING;
			}
			break;
		case GOING:
			showTime();
			nextState = GOING;
			if (digitalRead(endPositionPin) == LOW) {
				playWin();
				ledsOFF();
				nextState = FINISHED;
			}
			else if (digitalRead(midWirePin) == LOW) {
				playFail();
				ledsOFF();
				redON();
				nextState = ERROR;
			}
			break;
		case ERROR:
			redON();
			showTime();
			nextState = ERROR;
			if (digitalRead(startPositionPin) == LOW) {
				ledsOFF();
				greenON();
				nextState = GOING;
			}
			break;
		case FINISHED:
			showFinalResult();
			nextState = (digitalRead(startPositionPin) == LOW) ? ON_START_POINT : FINISHED;
			break;
	}
	currState = nextState;
}
