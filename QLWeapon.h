// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "QLWeapon.generated.h"

// forward declaration
class AQLCharacter;

// constant
const float rayTraceEnd = 4000.0f;

UCLASS()
class QL_API AQLWeapon : public AActor
{
    GENERATED_BODY()

protected:
    FString Name;
    bool bIsFireHeldDown;
    bool bIsAltFireHeldDown;
    AQLCharacter* owner;

public:
    // Sets default values for this actor's properties
    AQLWeapon();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;

    virtual void Fire() {};
    virtual void FireReleased() {};
    virtual void FireRepeat() {};

    virtual void AltFire() {};
    virtual void AltFireReleased() {};
    virtual void AltFireRepeat() {};

    void SetOwner(AQLCharacter* owner);
};
