// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget/Entry/CreateSessionWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Kismet/KismetTextLibrary.h"
#include "AdvancedSessions/Classes/CreateSessionCallbackProxyAdvanced.h"
#include "Kismet/GameplayStatics.h"

void UCreateSessionWidget::NativeConstruct()
{
	MaxPlayerCount = 4;
	PlayerCount = MaxPlayerCount;
	UseLan = true;

	PlayerCountBlock = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextBlock_PlayerCount")));
	ButtonL = Cast<UButton>(GetWidgetFromName(TEXT("Button_SlotL")));
	ButtonR = Cast<UButton>(GetWidgetFromName(TEXT("Button_SlotR")));
	CancelButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_Cancel")));
	CreateButton = Cast<UButton>(GetWidgetFromName(TEXT("Button_Create")));
	SessionNameBox = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBox_SessionName")));

	PlayerCountBlock->SetText(UKismetTextLibrary::Conv_IntToText(PlayerCount));

	if (ButtonL)
	{
		ButtonL->OnClicked.AddDynamic(this, &UCreateSessionWidget::DecreaseLobbyPlayer);
	}
	if (ButtonR)
	{
		ButtonR->OnClicked.AddDynamic(this, &UCreateSessionWidget::IncreaseLobbyPlayer);
	}
	if (CancelButton)
	{
		CancelButton->OnClicked.AddDynamic(this, &UCreateSessionWidget::ProcessClickCancel);
	}
	if (CreateButton)
	{
		CreateButton->OnClicked.AddDynamic(this, &UCreateSessionWidget::CreateLobby);
	}
}

void UCreateSessionWidget::DecreaseLobbyPlayer()
{
	if (PlayerCount > 1)
	{
		PlayerCount--;
		PlayerCountBlock->SetText(UKismetTextLibrary::Conv_IntToText(PlayerCount));
	}
}

void UCreateSessionWidget::IncreaseLobbyPlayer()
{
	if (PlayerCount < MaxPlayerCount)
	{
		PlayerCount++;
		PlayerCountBlock->SetText(UKismetTextLibrary::Conv_IntToText(PlayerCount));
	}
}

void UCreateSessionWidget::CreateLobby()
{
	if (SessionNameBox->GetText().ToString().Len() <= 0)
	{
		return;
	}

	FSessionPropertyKeyPair Setting;
	Setting.Key = TEXT("SessionName");
	Setting.Data = SessionNameBox->GetText().ToString();
	TArray<FSessionPropertyKeyPair> ExtraSettings;
	ExtraSettings.Add(Setting);
	UCreateSessionCallbackProxyAdvanced::CreateAdvancedSession(
		this,
		ExtraSettings,
		UGameplayStatics::GetPlayerController(this, 0),
		PlayerCount,	//PublicConnections
		0,				//PrivateConnections
		UseLan,			//UseLan
		true,			//..default
		false,
		true,
		true,
		true,
		false,
		false,
		false,
		true,
		false,
		true
		);
	
	//TODO:: 게임인스턴스 캐스팅해서 LobbyStage에다가 NextLevelName집어넣고 OpenLevel하기(listen으로)
	GetGameInstance();
}

void UCreateSessionWidget::ProcessClickCancel()
{
}
