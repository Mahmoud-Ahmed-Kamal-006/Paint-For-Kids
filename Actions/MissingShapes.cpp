#include "MissingShapes.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
MissingShapes::MissingShapes(ApplicationManager* pApp) : Action(pApp) {
	srand((unsigned)time(nullptr));
}
void MissingShapes::ReadActionParameters() {
	numfigsleft = pManager->getFigCount();
	tempnum = numfigsleft;
	Templist = new CFigure * [tempnum];
	OriginalList = pManager->getFigList();
	for (int i = 0; i < numfigsleft; i++) {
		Templist[i] = OriginalList[i];
	}
	score = 0;
}
void MissingShapes::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Every 5 seconds a shape will disappear... remember the missing shapes!");
	Sleep(2500);
	string userinput;
	while (numfigsleft > 0) {
		userinput = "";
		pOut->ClearStatusBar();
		int randomIndex = rand() % tempnum;
		while (Templist[randomIndex] == nullptr) {
			randomIndex = rand() % tempnum;
		}
		pOut->PrintMessage("You have 5 seconds to Memorise all the shapes!");
		Sleep(5000);
		string hiddenshape = OriginalList[randomIndex]->GetType();
		Templist[randomIndex] = nullptr;
		pOut->ClearDrawArea();
		for (int i = 0; i < tempnum; i++) {
			if (Templist[i] != nullptr) {
				Templist[i]->Draw(pOut);
			}
		}
		pOut->PrintMessage("Which shape dissapeared?");
		userinput=pIn->GetSrting(pOut);
		userinput=setlowercase(userinput);
		if (userinput == hiddenshape) {
			score++;
			pOut->PrintMessage("Correct! Score is currently: " + to_string(score));
			Sleep(1500);
		}
		else {
			score--;
			pOut->PrintMessage("Incorrect! Score is currently: " + to_string(score));
			Sleep(1500);
		}
		numfigsleft--;
		pOut->PrintMessage("Click anywhere in playing area to contiue or press the icon to restart. Select Drawing Mode to exit game :(");
		ActionType act = pManager->GetUserAction();
		if (act == PLAY_MISSING_SHAPE) {
			ReadActionParameters();
			pOut->ClearStatusBar();
			pOut->PrintMessage("Game Restarted!");
			Sleep(1500);
			for (int i = 0; i < tempnum; i++) {
				if (OriginalList[i] != nullptr) {
					OriginalList[i]->Draw(pOut);
				}
			}
			continue;  
		}
		else if (act == PLAYING_AREA) 
			continue;
		else 
			break;


	}

	pOut->PrintMessage("Game Over! Your final score is: " + to_string(score) + "!. Press on Draw Mode icon to leave");

}
string MissingShapes::setlowercase(string text) {
	for (int i = 0; i < text.length(); i++) {
		if (text[i] >= 65 && text[i]<=90) {
			text[i] += 32;
		}
	}
	return text;
}
MissingShapes::~MissingShapes() {
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
	for (int i = 0; i < tempnum; i++) {
		if (OriginalList[i] != nullptr) {
			OriginalList[i]->Draw(pOut);
		}
	}
	delete[] Templist;
	Templist = nullptr;
}