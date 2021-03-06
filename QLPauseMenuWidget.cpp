//----------------------------------------
// Quarter Life
//
// MIT license
//
//  (\-/)
// (='.'=)
// (")-(")o
//----------------------------------------

#include "QL.h"
#include "QLPlayerController.h"
#include "QLPauseMenuWidget.h"

//------------------------------------------------------------
//------------------------------------------------------------
void UQLPauseMenuWidget::ResumeGame()
{
    if (PlayerController)
    {
        PlayerController->ResumeGame();
    }
}

//------------------------------------------------------------
//------------------------------------------------------------
void UQLPauseMenuWidget::SaveGame()
{
}

//------------------------------------------------------------
//------------------------------------------------------------
void UQLPauseMenuWidget::ReturnToMainMenu()
{
    UGameplayStatics::OpenLevel(GetWorld(), FName(TEXT("QLMainMenu")));
}

//------------------------------------------------------------
//------------------------------------------------------------
void UQLPauseMenuWidget::SetPlayerController(AQLPlayerController* PlayerController)
{
    this->PlayerController = PlayerController;
}