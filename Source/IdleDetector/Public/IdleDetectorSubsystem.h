// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#pragma once

#include "Subsystems/LocalPlayerSubsystem.h"
#include "IdleDetectorSubsystem.generated.h"

class FIdleDetectorInputPreprocessor;

DECLARE_LOG_CATEGORY_EXTERN(LogIdleDetector, Log, All)

using FIdleStateChangeNative = TMulticastDelegate<void(bool)>;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIdleStateChange, bool, NewState);

UCLASS()
class IDLEDETECTOR_API UIdleDetectorSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

	friend FIdleDetectorInputPreprocessor;

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

protected:
	void IdleCheck();
	void StartIdling();
	void ResetIdling();
	void EndIdling();

public:
	UFUNCTION(BlueprintCallable, Category = "IdleDetector", BlueprintCosmetic)
	void SetIdlingEnabled(bool Enable);

	UFUNCTION(BlueprintPure, Category = "UI NAV|Input", BlueprintCosmetic)
	bool IsIdle() const;

	UFUNCTION(BlueprintCallable, Category = "UI NAV|Input", BlueprintCosmetic)
	void SetTimeUntilIdle(const float NewTime);

	UFUNCTION(BlueprintPure, Category = "UI NAV|Input", BlueprintCosmetic)
	float GetTimeUntilIdle() const;

public:
	FIdleStateChangeNative OnIsIdleChangedCallback;

	UPROPERTY(BlueprintAssignable, Category = "UI NAV|Input")
	FIdleStateChange OnIsIdleChanged;

private:
	bool Enabled = false;
	bool bIsIdle = false;

	// Seconds to wait until idle timer fires.
	float TimeUntilIdle = 20.f;

	/* Handle to the timer that sets idling. */
	FTimerHandle IdleTimer;

	TSharedPtr<FIdleDetectorInputPreprocessor> InputPreprocessor;
};