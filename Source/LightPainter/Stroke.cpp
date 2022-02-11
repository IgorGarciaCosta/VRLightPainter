// Fill out your copyright notice in the Description page of Project Settings.


#include "Stroke.h"
#include "Components/SplineMeshComponent.h"

// Sets default values
AStroke::AStroke()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	StrokeMeshes = CreateDefaultSubobject<UInstancedStaticMeshComponent>("StrokeMeshes");
	StrokeMeshes->SetupAttachment(Root);
}



void AStroke::Update(FVector CursorLocation)
{
	//create spline mesh
	//update endpoints
	/*USplineMeshComponent* Spline = CreateSplineMesh();
	FVector StartPos  = GetActorTransform().InverseTransformPosition(CursorLocation);
	FVector EndPos = GetActorTransform().InverseTransformPosition(PreviousCursorLoc);*/
	FTransform NewStrokeTransform;
	FVector LocalCursorLoc = GetTransform().InverseTransformPosition(CursorLocation);
	NewStrokeTransform.SetLocation(LocalCursorLoc);
	StrokeMeshes->AddInstance(NewStrokeTransform);

	//Spline->SetStartAndEnd(StartPos, FVector::ZeroVector, EndPos, FVector::ZeroVector);

	PreviousCursorLoc = CursorLocation;
}

//USplineMeshComponent* AStroke::CreateSplineMesh() {
//	USplineMeshComponent* NewSpline = NewObject< USplineMeshComponent>(this);
//	NewSpline->SetMobility(EComponentMobility::Movable);
//	NewSpline->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetIncludingScale);
//	NewSpline->SetStaticMesh(SplineMesh);
//	NewSpline->SetMaterial(0, SplineMaterial);
//	NewSpline->RegisterComponent();
//
//	return NewSpline;
//}


