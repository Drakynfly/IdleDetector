// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#include "IdleDetectorInputPreprocessor.h"
#include "IdleDetectorSubsystem.h"

FIdleDetectorInputPreprocessor::FIdleDetectorInputPreprocessor(UIdleDetectorSubsystem* Subsystem)
  : Subsystem(Subsystem)
{
}

void FIdleDetectorInputPreprocessor::Tick(const float DeltaTime, FSlateApplication& SlateApp, TSharedRef<ICursor> Cursor)
{
}

bool FIdleDetectorInputPreprocessor::HandleKeyDownEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
    Subsystem->IdleCheck();
    return false;
}

bool FIdleDetectorInputPreprocessor::HandleKeyUpEvent(FSlateApplication& SlateApp, const FKeyEvent& InKeyEvent)
{
    Subsystem->IdleCheck();
    return false;
}

bool FIdleDetectorInputPreprocessor::HandleAnalogInputEvent(FSlateApplication& SlateApp,
	const FAnalogInputEvent& InAnalogInputEvent)
{
    Subsystem->IdleCheck();
    return false;
}

bool FIdleDetectorInputPreprocessor::HandleMouseMoveEvent(FSlateApplication& SlateApp, const FPointerEvent& MouseEvent)
{
    Subsystem->IdleCheck();
    return false;
}

bool FIdleDetectorInputPreprocessor::HandleMouseButtonDownEvent(FSlateApplication& SlateApp,
	const FPointerEvent& MouseEvent)
{
	Subsystem->IdleCheck();
	return false;
}

bool FIdleDetectorInputPreprocessor::HandleMouseButtonUpEvent(FSlateApplication& SlateApp,
	const FPointerEvent& MouseEvent)
{
	Subsystem->IdleCheck();
	return false;
}

bool FIdleDetectorInputPreprocessor::HandleMouseButtonDoubleClickEvent(FSlateApplication& SlateApp,
	const FPointerEvent& MouseEvent)
{
	Subsystem->IdleCheck();
	return false;
}

bool FIdleDetectorInputPreprocessor::HandleMouseWheelOrGestureEvent(FSlateApplication& SlateApp,
	const FPointerEvent& InWheelEvent, const FPointerEvent* InGestureEvent)
{
	Subsystem->IdleCheck();
	return false;
}

bool FIdleDetectorInputPreprocessor::HandleMotionDetectedEvent(FSlateApplication& SlateApp,
	const FMotionEvent& MotionEvent)
{
	Subsystem->IdleCheck();
	return false;
}

const TCHAR* FIdleDetectorInputPreprocessor::GetDebugName() const
{
  return TEXT("IdleDetectorInputPreprocessor");
}