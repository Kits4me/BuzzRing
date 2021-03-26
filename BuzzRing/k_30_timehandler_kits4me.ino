long lastDispTime;
int dispTimeDiffMsec = 1000;
int secFromStart;
long millisAtStart;
void initGameTimes() {
	lastDispTime = millis();
	secFromStart = 0;
	millisAtStart = millis();
}
void showTime() {
	//if (millis() - lastDispTime >= dispTimeDiffMsec) {
	//	lastDispTime = millis();
	//	Serial.println("showTime");
	//	secFromStart = round((millis() - millisAtStart) / 1000);
	//	//showTimeNoWait(secFromStart / 60, secFromStart % 60);
	//}
	secFromStart = round((millis() - millisAtStart) / 1000);
	showNum(secFromStart, 50);
}

void showFinalResult() {
	showNum(secFromStart, 50);
}

