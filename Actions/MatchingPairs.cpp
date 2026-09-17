#include "MatchingPairs.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
MatchingPairs::MatchingPairs(ApplicationManager* pApp) : Action(pApp) {
	score = 0;
	indx = 0;
    numfigs = pManager->getFigCount();
	SelectedFigs = new CFigure * [numfigs];
}
void MatchingPairs::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Select First Shape");
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("Select Second Shape");
	pIn->GetPointClicked(P2.x, P2.y);
}
void MatchingPairs::Execute() {
    Output* pOut = pManager->GetOutput();
    Input* pIn = pManager->GetInput();
    CFigure* fig1;
    CFigure* fig2;
	pOut->PrintMessage("Choose two items that match in colour or shape");
    Sleep(3000);
    while (indx +1 < numfigs) {
        ReadActionParameters();
		pOut->ClearStatusBar();
        fig1 = pManager->GetFigure(P1.x, P1.y);
        fig2 = pManager->GetFigure(P2.x, P2.y);
        if (fig1==NULL || fig2==NULL) {
            pOut->ClearStatusBar();
            pOut->PrintMessage("Invalid figure(s). Try again.");
            pManager->UpdateInterface();
            Sleep(1500);
            continue;
        }
        bool duplicate = false;
        for (int i = 0; i < indx; i++) {
            if (SelectedFigs[i] == fig1 || SelectedFigs[i] == fig2) {
                pOut->ClearStatusBar();
                pOut->PrintMessage("One of the shapes already selected. Try again.");
                pManager->UpdateInterface();
                Sleep(1500);
                duplicate = true;
                break;
            }
        }
        if (duplicate) continue;
        SelectedFigs[indx] = fig1;
        SelectedFigs[indx + 1] = fig2;
        indx += 2;
  
        if (((fig1->GetFillClr() == fig2->GetFillClr()) && (fig1->getIsFilled()==1)) || fig1->GetType() == fig2->GetType()) {
            score++;
            pOut->ClearStatusBar();
            pOut->PrintMessage("Correct! Score: " + to_string(score));
            pManager->UpdateInterface();
            Sleep(1500);
        }
        else {
            score--;
            pOut->ClearStatusBar();
            pOut->PrintMessage("Not Correct! Score: " + to_string(score));
            pManager->UpdateInterface();
            Sleep(1500);
        }
        pOut->PrintMessage("Click anywhere in playing area to contiue or press the game icon to restart. Select Drawing Mode to exit game :(");
        ActionType act = pManager->GetUserAction();
        if (act == PLAY_MATCHING_SHAPE) {
            pOut->ClearStatusBar();
            pOut->PrintMessage("Game Restarted!");
            Sleep(1500);
            score = 0;
            indx = 0;
            delete[]SelectedFigs;
            SelectedFigs = new CFigure * [numfigs];
            continue;
        }
        else if (act == PLAYING_AREA)
            continue;
        else
            break;

    }
    pOut->ClearStatusBar();
    pOut->PrintMessage("Game over! Final Score: " + to_string(score) + "!. Press on Draw Mode icon to leave");
    pManager->UpdateInterface();
    indx = 0;
    score = 0;
    for (int i = 0; i < numfigs; i++) {
        SelectedFigs[i] = nullptr;
    }
}
MatchingPairs::~MatchingPairs() {
	delete[] SelectedFigs;
	SelectedFigs = nullptr;
}
