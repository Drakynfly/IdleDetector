// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#include "IdleDetectorSubsystem.h"
#include "IdleDetectorInputPreprocessor.h"

DEFINE_LOG_CATEGORY(LogIdleDetector)

void UIdleDetectorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	InputPreprocessor = MakeShared<FIdleDetectorInputPreprocessor>(this);
	FSlateApplication::Get().RegisterInputPreProcessor(InputPreprocessor, 0);
}

void UIdleDetectorSubsystem::Deinitialize()
{
	GetWorld()->GetTimerManager().ClearTimer(IdleTimer);

	FSlateApplication::Get().UnregisterInputPreProcessor(InputPreprocessor);
	InputPreprocessor.Reset();

	Super::Deinitialize();
}

void UIdleDetectorSubsystem::IdleCheck()
{
	if (bIsIdle)
	{
		EndIdling();
	}
	else
	{
		ResetIdling();
	}
}

void UIdleDetectorSubsystem::StartIdling()
{
	if (!bIsIdle)
	{
		bIsIdle = true;
		UE_LOG(LogIdleDetector, Log, TEXT("'%s' started idling... "), *GetLocalPlayer()->GetName());
		OnIsIdleChangedCallback.Broadcast(bIsIdle);
		OnIsIdleChanged.Broadcast(bIsIdle);
	}
}

void UIdleDetectorSubsystem::ResetIdling()
{
	// Reset idle timer.
	GetWorld()->GetTimerManager().SetTimer(IdleTimer, this, &UIdleDetectorSubsystem::StartIdling, TimeUntilIdle);
}

void UIdleDetectorSubsystem::EndIdling()
{
	if (bIsIdle)
	{
		bIsIdle = false;
		UE_LOG(LogIdleDetector, Log, TEXT(" ...'%s' stopped idling!"), *GetLocalPlayer()->GetName());
		OnIsIdleChangedCallback.Broadcast(bIsIdle);
		OnIsIdleChanged.Broadcast(bIsIdle);
		ResetIdling();
	}
}

void UIdleDetectorSubsystem::SetIdlingEnabled(const bool Enable)
{
	if (Enable != Enabled)
	{
		Enabled = Enable;

		if (Enabled)
		{
			ResetIdling();
		}
		else
		{
			GetWorld()->GetTimerManager().ClearTimer(IdleTimer);

			if (IsIdle())
			{
				EndIdling();
			}
		}
	}
}

bool UIdleDetectorSubsystem::IsIdle() const
{
	return bIsIdle;
}

void UIdleDetectorSubsystem::SetTimeUntilIdle(const float NewTime)
{
	TimeUntilIdle = NewTime;

	if (Enabled)
	{
		ResetIdling();
	}
}

float UIdleDetectorSubsystem::GetTimeUntilIdle() const
{
	return TimeUntilIdle;
}