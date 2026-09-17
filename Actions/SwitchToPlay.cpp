#include "SwitchtoPlay.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
SwitchToPlay::SwitchToPlay(ApplicationManager* pApp) :Action(pApp) {

}
void SwitchToPlay::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("Change to Play Mode");
}
void SwitchToPlay::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
}
