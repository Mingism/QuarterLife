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
#include "QLPortal.h"
#include "QLPortalGunCompatibleActor.h"
#include "QLWeapon.h"
#include "QLWeaponPortalGun.generated.h"

// constant

UCLASS()
class QL_API AQLWeaponPortalGun : public AQLWeapon
{
    GENERATED_BODY()
public:
    AQLWeaponPortalGun();
    virtual void Fire() override;
    virtual void AltFire() override;
    void CreatePortal(EPortalType PortalType);
    virtual void Tick(float DeltaSeconds) override;
    virtual void ResetWeapon() override;
    void QueryPortal();
    virtual void Zoom() override;
    virtual void PostInitializeComponents() override;

    UPROPERTY()
    UTimelineComponent* ZoomTimeline;

    UPROPERTY()
    UCurveFloat* FCurve;

    FOnTimelineFloat ZoomTimelineInterpFunction{};

    UFUNCTION()
    void ZoomCallback(float Val);
protected:
    bool bBluePortalCreated;
    bool bOrangePortalCreated;
    AQLPortal* BluePortal;
    AQLPortal* OrangePortal;
    bool bCanZoomIn;
};
