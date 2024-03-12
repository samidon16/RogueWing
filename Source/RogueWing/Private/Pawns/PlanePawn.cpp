// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/PlanePawn.h"
#include "Actors/BulletActor.h"
#include "UObject/ConstructorHelpers.h"
#include "PlayerPawnMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlanePawn::APlanePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
    LastShotTime = 0;
    LinearDamping = 0.1;
    AngularDamping = 2;
    SkeletalMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
    SkeletalMeshComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
    RootComponent = SkeletalMeshComponent;
    SkeletalMeshComponent->SetPhysicsMaxAngularVelocityInDegrees(MaxAngularVelocity);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/StaticMeshes/PT-17.PT-17'"));
    if (MeshAsset.Succeeded())
    {
        SkeletalMeshComponent->SetStaticMesh(MeshAsset.Object);
    }

    SkeletalMeshComponent->SetSimulatePhysics(true);
    SkeletalMeshComponent->SetNotifyRigidBodyCollision(true);

    OurMovementComponent = CreateDefaultSubobject<UPlayerPawnMovementComponent>(TEXT("CustomMovementComponent"));
    OurMovementComponent->UpdatedComponent = RootComponent;

}

UPawnMovementComponent* APlanePawn::GetMovementComponent() const
{
    return OurMovementComponent;
}

// Called when the game starts or when spawned
void APlanePawn::BeginPlay()
{
	Super::BeginPlay();
    SkeletalMeshComponent->SetConstraintMode(EDOFMode::YZPlane);
    SkeletalMeshComponent->SetAngularDamping(AngularDamping);
    SkeletalMeshComponent->SetLinearDamping(LinearDamping);
	
}

// Called every frame
void APlanePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlanePawn::Accelerate(float Value)
{
    if (Value == 0 && !SkeletalMeshComponent->IsGravityEnabled())
    {
        SkeletalMeshComponent->SetEnableGravity(true);
    }
    if (Value == 1)
    {
        SkeletalMeshComponent->AddImpulse(SkeletalMeshComponent->GetRightVector() * 60, FName("None"), true);
        SkeletalMeshComponent->SetEnableGravity(false);
    }
}

void APlanePawn::Turn(float Value)
{
    //SkeletalMeshComponent->AddAngularImpulseInDegrees(ForwardVector * Value * 4, FName("None"), true);
    SkeletalMeshComponent->SetAllPhysicsAngularVelocityInDegrees(SkeletalMeshComponent->GetForwardVector() * MaxAngularVelocity * Value, true);
}

void APlanePawn::Shoot(float Value)
{
    float CurrentTime = UGameplayStatics::GetRealTimeSeconds(GEngine->GameViewport->GetWorld());
    if (Value == 1 && (CurrentTime - LastShotTime) > FirePeriod)
    {
        FRotator CurrentRotation = GetActorRotation();
        FVector CurrentLocation = GetActorLocation();
        FVector RightVector = SkeletalMeshComponent->GetRightVector();
        ABulletActor* Bullet = GEngine->GameViewport->GetWorld()->SpawnActor<ABulletActor>(CurrentLocation + RightVector * 300, FRotator(0, 0, 0));
        Bullet->StaticMeshComponent->SetPhysicsLinearVelocity(RightVector * 10000 + GetVelocity());
        LastShotTime = CurrentTime;
    }
}

void APlanePawn::Boost(float Value)
{
    if (Value == 1) {
        SkeletalMeshComponent->AddImpulse(SkeletalMeshComponent->GetRightVector() * 60, FName("None"), true);
    }
}

void APlanePawn::Roll()
{

}

