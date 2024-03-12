// Fill out your copyright notice in the Description page of Project Settings.


#include "OceanActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AOceanActor::AOceanActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root Component"));
    StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
    RootComponent = StaticMeshComponent;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/StaticMeshes/OceanPlane.OceanPlane'"));
    if (MeshAsset.Succeeded())
    {
        StaticMeshComponent->SetStaticMesh(MeshAsset.Object);
    }
    StaticMeshComponent->SetWorldScale3D(FVector(2000, 2000, 1));
}

// Called when the game starts or when spawned
void AOceanActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOceanActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GEngine->GameViewport->GetWorld(), 0);
	FVector PlayerLocation = PlayerPawn->GetActorLocation();
	SetActorLocation(FVector(PlayerLocation.X, PlayerLocation.Y, 0));
}

