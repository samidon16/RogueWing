// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPawn.h"
#include "Actors/BulletActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "MainLevelGameMode.h"
#include "cmath"


// Sets default values
AAIPawn::AAIPawn()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    LinearDamping = 1;
    AngularDamping = 4;
    MaxRange = 5000;
    OnActorHit.AddDynamic(this, &AAIPawn::OnHit);
}

// Called every frame
void AAIPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GEngine->GameViewport->GetWorld(), 0);

    FVector DisplacementVector = PlayerPawn->GetActorLocation() - GetActorLocation();
    FVector RightVector = SkeletalMeshComponent->GetRightVector();
    float ShortAngleToPlayer = asin((DisplacementVector.Y * RightVector.Z - DisplacementVector.Z * RightVector.Y)/(3 * DisplacementVector.Length() * RightVector.Length())) * 180 / 3.1415;

    if (ShortAngleToPlayer > 0)
    {
        Turn(-1);
    }
    if (ShortAngleToPlayer < 0)
    {
        Turn(1);
    }
    if (abs(ShortAngleToPlayer) < 40)
    {
        if (DisplacementVector.Length() < MaxRange)
        {
            Shoot(1);
        }
        else
        {
            Accelerate(1);
        }
    }

    if (GetActorLocation().Z > 80000)
    {
        SkeletalMeshComponent->SetAllPhysicsLinearVelocity(FVector(
            SkeletalMeshComponent->GetPhysicsLinearVelocity().X,
            SkeletalMeshComponent->GetPhysicsLinearVelocity().Y,
            SkeletalMeshComponent->GetPhysicsLinearVelocity().Z * -1));
    }

}

void AAIPawn::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
    Destroy();
    AMainLevelGameMode* MainLevelGameMode = GetWorld()->GetAuthGameMode<AMainLevelGameMode>();
    MainLevelGameMode->SetRemainingEnemies(MainLevelGameMode->GetRemainingEnemies() - 1);
}

