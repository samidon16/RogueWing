// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABulletActor::ABulletActor() :
    NumbBounces(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = false;

    StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root Component"));
    StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    StaticMeshComponent->SetCollisionResponseToAllChannels(ECR_Block);
    RootComponent = StaticMeshComponent;
    SetActorScale3D(FVector(Scale, Scale, Scale));
    ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile Component"));
    StaticMeshComponent->SetNotifyRigidBodyCollision(true);
    OnActorHit.AddDynamic(this, &ABulletActor::OnHit);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Meshes/StaticMeshes/Bullet.Bullet'"));
    if (SphereMeshAsset.Succeeded())
    {
        StaticMeshComponent->SetStaticMesh(SphereMeshAsset.Object);
    }
    StaticMeshComponent->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();
    SetLifeSpan(LifeSpan);
}

// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABulletActor::OnHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
    if (++NumbBounces <= MaxBounces);
    else Destroy();
}

