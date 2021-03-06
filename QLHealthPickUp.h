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

#include "QLActor.h"
#include "QLCharacter.h"
#include "QLHealthPickUp.generated.h"

UCLASS()
class QL_API AQLHealthPickUp : public AQLActor
{
    GENERATED_BODY()

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Sets default values for this actor's properties
    AQLHealthPickUp();

    // Called every frame
    virtual void Tick( float DeltaSeconds ) override;

    UFUNCTION()
    void OnOverlapBeginForActor(AActor* OverlappedActor, AActor* OtherActor);

    UFUNCTION(BlueprintCallable, Category = "C++Function")
    float GetHealthIncrement();

    UFUNCTION(BlueprintCallable, Category = "C++Function")
    void SetHealthIncrement(float Increment_ext);

protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "C++Property")
    float Increment;
};
