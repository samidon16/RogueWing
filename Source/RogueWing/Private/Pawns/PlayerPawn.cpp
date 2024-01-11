// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/PlayerPawn.h"
#include "PlayerPawnMovementComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
APlayerPawn::APlayerPawn()
{
    // Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;
    SkeletalMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
    SkeletalMeshComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
    RootComponent = SkeletalMeshComponent;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/StaticMeshes/PT-17.PT-17'"));
    if (MeshAsset.Succeeded())
    {
        SkeletalMeshComponent->SetStaticMesh(MeshAsset.Object);
    }

    SkeletalMeshComponent->SetSimulatePhysics(true);
    //SkeletalMeshComponent->SetCollisionProfileName(TEXT("Pawn"));


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
    SpringArm->SetRelativeRotation(FRotator(-10.f, 0.f, 0.f));
    SpringArm->bDoCollisionTest = 0;
    SpringArm->TargetArmLength = 3000.0f;
    SpringArm->bEnableCameraLag = true;
    SpringArm->CameraLagSpeed = 3.0f;

    // Create a camera and attach to our spring arm
    UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamera"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

    // Take control of the default player
    AutoPossessPlayer = EAutoReceiveInput::Player0;

    // Create an instance of our movement component, and tell it to update our root component.
    OurMovementComponent = CreateDefaultSubobject<UPlayerPawnMovementComponent>(TEXT("CustomMovementComponent"));
    OurMovementComponent->UpdatedComponent = RootComponent;
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(class UInputComponent* InInputComponent)
{
    Super::SetupPlayerInputComponent(InInputComponent);
    InInputComponent->BindAction("Accelerate", IE_Pressed, this, &APlayerPawn::Accelerate);
}

UPawnMovementComponent* APlayerPawn::GetMovementComponent() const
{
    return OurMovementComponent;
}

void APlayerPawn::Accelerate()
{
    //PhysicsThrusterComponent->Activate();
    GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, "Pressed W");
    //SkeletalMeshComponent->AddForce(FVector(0, 0, 1000), FName("None"), true);
    SkeletalMeshComponent->AddForce(FVector(0, 0, 50000), FName("None"), true);
}

