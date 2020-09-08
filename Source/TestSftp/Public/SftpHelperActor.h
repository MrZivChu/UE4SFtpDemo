#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SftpHelperActor.generated.h"

UCLASS()
class TESTSFTP_API ASftpHelperActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASftpHelperActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void ConnectSftp(FString hostName, FString userName, FString passWord, int port);

};
