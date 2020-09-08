#include "SftpHelperActor.h"

#if PLATFORM_ANDROID
#include "Launch/Public/Android/AndroidJNI.h"
#include "ApplicationCore/Public/Android/AndroidApplication.h"
#include "..\Public\SftpHelperActor.h"
#endif

ASftpHelperActor::ASftpHelperActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ASftpHelperActor::BeginPlay()
{
	Super::BeginPlay();

	ConnectSftp(FString("192.168.23.105"), FString("zwh"), FString("123"), 22);
}

void ASftpHelperActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASftpHelperActor::ConnectSftp(FString hostName, FString userName, FString passWord, int port)
{
#if PLATFORM_ANDROID
	if (JNIEnv* Env = FAndroidApplication::GetJavaEnv(true))
	{
		jstring hostNameArg = Env->NewStringUTF(TCHAR_TO_UTF8(*hostName));
		jstring userNameArg = Env->NewStringUTF(TCHAR_TO_UTF8(*userName));
		jstring passWordArg = Env->NewStringUTF(TCHAR_TO_UTF8(*passWord));

		jmethodID methodID = FJavaWrapper::FindMethod(Env, FJavaWrapper::GameActivityClassID, "AndroidThunkJava_ConnectSftp", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;I)V", false);
		FJavaWrapper::CallVoidMethod(Env, FJavaWrapper::GameActivityThis, methodID, hostNameArg, userNameArg, passWordArg);

		Env->DeleteLocalRef(hostNameArg);
		Env->DeleteLocalRef(userNameArg);
		Env->DeleteLocalRef(passWordArg);
	}
#endif
}

