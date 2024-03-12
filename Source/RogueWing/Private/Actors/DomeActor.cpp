// Fill out your copyright notice in the Description page of Project Settings.


#include "DomeActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADomeActor::ADomeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root Component"));
    StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
    RootComponent = StaticMeshComponent;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/StaticMeshes/SkyDome.SkyDome'"));
    if (MeshAsset.Succeeded())
    {
        StaticMeshComponent->SetStaticMesh(MeshAsset.Object);
    }
    StaticMeshComponent->SetWorldScale3D(FVector(20, 20, 20));
}

// Called when the game starts or when spawned
void ADomeActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADomeActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GEngine->GameViewport->GetWorld(), 0);
    FVector PlayerLocation = PlayerPawn->GetActorLocation();
    SetActorLocation(FVector(PlayerLocation.X, PlayerLocation.Y, 0));
    float MapRotation = -1 * PlayerLocation.Y / 5000;
    SetActorRotation(FRotator(0, MapRotation, 0));
}

