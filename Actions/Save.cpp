#include "Save.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\ApplicationManager.h"


Save::Save(ApplicationManager* pApp) : Action(pApp) {

}

void Save::ReadActionParameters() {  
	Output* pOut = pManager->GetOutput();  
	Input* pIn = pManager->GetInput();  

	pOut->PrintMessage("Enter your FILE NAME.");  

	filename = pIn->GetSrting(pOut); 
}

void Save::Execute() {  
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
    pManager->saveAll(filename);
	pOut->PrintMessage("Saved Successfully");
   
}