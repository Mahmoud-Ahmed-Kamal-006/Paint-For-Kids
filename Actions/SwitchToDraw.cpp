#include "SwitchtoDraw.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
SwitchToDraw::SwitchToDraw(ApplicationManager* pApp) :Action(pApp) {

}
void SwitchToDraw::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pOut->PrintMessage("Change to Draw Mode");
}
void SwitchToDraw::Execute() {
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
}
