long lastDispTime;
int dispTimeDiffMsec = 1000;
int secFromStart;
long millisAtStart;
void initDisp() {
	lastDispTime = millis();
	secFromStart = 0;
	millisAtStart = millis();
	setup_7seg();
}
void showTime() {
	if (millis() - lastDispTime >= dispTimeDiffMsec) {
		lastDispTime = millis();
		Serial.println("showTime");
		secFromStart = round((millis() - millisAtStart) / 1000);
		//showTimeNoWait(secFromStart / 60, secFromStart % 60);
	}
	showNum(secFromStart, 100);
}

