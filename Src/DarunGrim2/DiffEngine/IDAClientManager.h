#pragma once
#include "Common.h"

#include "DiffMachine.h"
#include "DataStructure.h"
#include "DBWrapper.h"
#include "LogOperation.h"

class IDAClientManager
{
private:
	DBWrapper *m_OutputDB;
	unsigned short ListeningPort;
	SOCKET ListeningSocket;
	OneIDAClientManager *OneIDAClientManagers[2];

	OneIDAClientManager *TheSource;
	OneIDAClientManager *TheTarget;
	DiffMachine *pDiffMachine;

	char *IDAPath;
	char *EscapedOutputFilename;
	char *EscapedLogFilename;
	DWORD IDACommandProcessorThreadId;
	char IDALogFilename[MAX_PATH+1];

	bool GenerateIDALogFilename();

public:
	IDAClientManager();
	void SetDatabase( DBWrapper *OutputDB );
	bool StartIDAListener( unsigned short port );
	bool StopIDAListener();

	~IDAClientManager();
	BOOL AcceptIDAClient( OneIDAClientManager *pOneIDAClientManager, bool RetrieveData=FALSE );
	OneIDAClientManager *GetOneIDAClientManagerFromFile( char *DataFile );
	DWORD SetMembers( OneIDAClientManager *OneIDAClientManagerTheSource, OneIDAClientManager *OneIDAClientManagerTheTarget, DiffMachine *pArgDiffMachine );
	DWORD IDACommandProcessor();
	BOOL CreateIDACommandProcessorThread();
	void ShowResultsOnIDA();
	void SetIDAPath( const char *ParamIDAPath );
	void SetOutputFilename( char *OutputFilename );
	void SetLogFilename( char *LogFilename );
	void RunIDAToGenerateDB( const char *TheFilename, unsigned long StartAddress, unsigned long EndAddress );
	void ConnectToDarunGrim2( const char *ida_filename );
	void SetIDALogFilename( const char *ida_log_filename );
	const char *GetIDALogFilename();
};
