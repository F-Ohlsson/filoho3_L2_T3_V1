// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/InputComponent.h"
#include "MyThirdPersonCharacter.h"
#include "GameFramework/Controller.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
AMyThirdPersonCharacter::AMyThirdPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyThirdPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyThirdPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyThirdPersonCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyThirdPersonCharacter::MoveForward);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);


//	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyThirdPersonCharacter::MoveRight(float Value) {
	if (Controller != nullptr && Value != 0.0f) {
		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
		const FVector Direction = UKismetMathLibrary::GetRightVector(YawRotation);
		AddMovementInput(Direction, Value);
	}
}

void AMyThirdPersonCharacter::MoveForward(float Value) {
	if (Controller != nullptr && Value != 0.0f) {
		const FRotator YawRotation(0, Controller->GetControlRotation().Yaw, 0);
		const FVector Direction = UKismetMathLibrary::GetForwardVector(YawRotation);
		AddMovementInput(Direction, Value);
	}
}