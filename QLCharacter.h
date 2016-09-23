//----------------------------------------
// Quarter Life
//
// MIT license
//
//  (\-/)
// (='.'=)
// (")-(")o
//----------------------------------------

#pragma once

#include "QLUtility.h"
#include "QLDebugHelper.h"
#include "QLWeaponGravityGun.h"
#include "QLWeaponPortalGun.h"
#include "GameFramework/Character.h"
#include "QLCharacter.generated.h"

// constant
const int maxNumWeapon = 10;
const float rayTraceRange = 100000.0f;
const float nextToPlayerThreshold = 400.0f;

UCLASS()
class QL_API AQLCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    bool IsEquipped(const FName& Name);
    void ChangeCurrentWeapon(AQLWeapon* Weapon);
    void AddToInventory(AQLActor* QLActor);
    void RemoveFromInventory(AQLActor* QLActor);
    void ShowInventory();
    void Zoom();

    AQLCharacter();
    ~AQLCharacter();

    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;

    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

    virtual void Landed(const FHitResult& Hit) override;
    virtual void Falling() override;

    FHitResult RayTraceFromCharacterPOV();
    bool IsObjectNextToCharacter(AQLGravityGunCompatibleActor* ggcActor);

    // implementation makes sure this function can only be called once
    void UnlockAllWeapon();

    // Handles input for moving forward and backward.
    UFUNCTION()
    void MoveForward(float Value);

    UFUNCTION()
    void MoveRight(float Value);

    // Sets jump flag when key is pressed.
    UFUNCTION()
    void StartJump();

    // Clears jump flag when key is released.
    UFUNCTION()
    void StopJump();

    // Clears jump flag when key is released.
    UFUNCTION()
    void ToggleCrouch();

    UFUNCTION()
    void ToggleSprint();

    UFUNCTION()
    bool CanSprint() const;

    UFUNCTION()
    void Sprint();

    UFUNCTION()
    void UnSprint();

    UFUNCTION()
    void Fire();

    UFUNCTION()
    void AltFire();

    UFUNCTION()
    void AltFireReleased();

    UFUNCTION()
    void SwitchToGravityGun();

    UFUNCTION()
    void SwitchToPortalGun();

    UFUNCTION()
    void SwitchToNeutronAWP();

    UFUNCTION()
    void SwitchToLastWeapon();

    void SwitchToWeapon(const FName& Name);

    void PickUpWeapon(AQLWeapon* Weapon);
    AQLWeapon* GetCurrentWeapon() const;
    UAudioComponent* CreateSoundComponent(USceneComponent*& RootComponent, const TCHAR* soundPath, const TCHAR* soundName);
    USoundWave* CreateFireAndForgetSoundWave(const TCHAR* SoundPath, const TCHAR* SoundName);
    void PlaySoundComponent(const FName& SoundName);
    void PlaySoundFireAndForget(const FName& SoundName, const FVector& Location);

    void Test();
    UPhysicsHandleComponent* PhysicsHandle;

protected:
    bool bIsFalling;
    bool bCanDoubleJump;

    // bool bHaveSprintAbility; // whether player has gained the ability
    bool bIsSprinting; // whether player is sprinting
    bool bWantToSprint; // player wants to spring
    float MaxWalkSpeed;
    float MaxWalkSpeedCrouched;
    int Health;
    bool bAllWeaponUnlockable;
    AQLWeapon* CurrentWeapon;
    AQLWeapon* LastWeapon;
    TMap<FName, AQLWeapon*> WeaponList;
    TMap<FString, AActor*> Inventory;
    USoundAttenuation* SoundNoAttenuation;
    USoundAttenuation* SoundAttenuation;
    TMap<FName, UAudioComponent*> SoundComponentList;
    TMap<FName, USoundWave*> FireAndForgetSoundWaveList;
    UCameraComponent* QLCameraComponent;
};
