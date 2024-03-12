// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "Actors/BulletActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APlayerPawn::APlayerPawn()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    FirePeriod = 0.1;
    OnActorHit.AddDynamic(this, &APlayerPawn::OnHit);

    /*
    static ConstructorHelpers::FObjectFinder<USkeletalMesh> PlaneVisualAsset(TEXT("/Script/Engine.SkeletalMesh'/Game/HugeAirplanesPack/Models/PT-17/SK_P-T17.SK_P-T17'"));
    if (PlaneVisualAsset.Succeeded())
    {
        SkeletalMeshComponent->SetSkeletalMeshAsset(PlaneVisualAsset.Object);
        SkeletalMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
        SkeletalMeshComponent->SetWorldScale3D(FVector(0.8f));
    }
    */

    // Use a spring arm to give the camera smooth, natural-feeling motion.
    USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
    SpringArm->SetupAttachment(RootComponent);
    SpringArm->bDoCollisionTest = 0;
    SpringArm->TargetArmLength = 11000.0f;
    SpringArm->bEnableCameraLag = true;
    SpringArm->CameraLagSpeed = 6.0f;

    // Create a camera and attach to our spring arm
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
    Camera->bUsePawnControlRotation = 1;
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    if (GetAltitude() > 80000)
    {
        SkeletalMeshComponent->SetAllPhysicsLinearVelocity(FVector(
            SkeletalMeshComponent->GetPhysicsLinearVelocity().X,
            SkeletalMeshComponent->GetPhysicsLinearVelocity().Y,
            SkeletalMeshComponent->GetPhysicsLinearVelocity().Z * -1));
    }
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(class UInputComponent* InInputComponent)
{
    Super::SetupPlayerInputComponent(InInputComponent);
    InInputComponent->BindAxis("Accelerate", this, &APlayerPawn::Accelerate);
    InInputComponent->BindAxis("Turn", this, &APlayerPawn::Turn);
    InInputComponent->BindAxis("Shoot", this, &APlayerPawn::Shoot);
    InInputComponent->BindAxis("Boost", this, &APlayerPawn::Boost);
    InInputComponent->BindAction("Roll", IE_Pressed, this, &APlayerPawn::Roll);
}

 void APlayerPawn::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
     UGameplayStatics::OpenLevel(GetWorld(), FName("MainMenu"), false, "?Game=/Script/RogueWing.MainMenuGameMode");
}

float APlayerPawn::GetAltitude() const {return GetActorLocation().Z;}
