// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageComponent.h"

// Sets default values for this component's properties
UDamageComponent::UDamageComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDamageComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

// Called every frame
void UDamageComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UDamageComponent::Damage(float _amount) {
	health -= _amount;
	damagedEvent.Broadcast();

	if (health <= 0.0f) {
		killedEvent.Broadcast();
		return true;
	} else return false;
}

bool UDamageComponent::Heal(float _amount) {
	health += _amount;
	if (health >= maxHealth) {
		health = maxHealth;
		return true;
	} else return false;
}

void UDamageComponent::SetHealth(float _health) {
	maxHealth = _health;
	health = _health;
}
