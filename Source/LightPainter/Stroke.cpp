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

	if (PreviousCursorLoc.IsNearlyZero()) {
		PreviousCursorLoc = CursorLocation;
		return;
	}

	StrokeMeshes->AddInstance(GetNextSegmentTransform(CursorLocation));

	PreviousCursorLoc = CursorLocation;
}

FTransform AStroke::GetNextSegmentTransform(FVector CurrentLocation) const
{
	FTransform SegmentTransform;

	SegmentTransform.SetScale3D(GetNextSegmentScale(CurrentLocation));
	SegmentTransform.SetRotation(GetNextSegmentRotation(CurrentLocation));
	SegmentTransform.SetLocation(GetNextSegmenttLocation(CurrentLocation));


	return SegmentTransform;
}
FVector AStroke::GetNextSegmentScale(FVector CurrentLocation) const
{
	FVector Segment = CurrentLocation - PreviousCursorLoc;
	return FVector(Segment.Size(), 1, 1);
}

FQuat AStroke::GetNextSegmentRotation(FVector CurrentLocation) const
{
	FVector Segment = CurrentLocation - PreviousCursorLoc;
	FVector SegmentNormal = Segment.GetSafeNormal();
	return FQuat::FindBetweenNormals(FVector::ForwardVector, SegmentNormal);
}

FVector AStroke::GetNextSegmenttLocation(FVector CurrentLocation) const
{

	return GetTransform().InverseTransformPosition(PreviousCursorLoc);
}



