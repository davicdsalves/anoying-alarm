#ifndef FUNCTIONSAA_H
#define FUNCTIONSAA_H
void CreateQuestion ();
int isAlarmBook(BOOK * book);
int TerminateElf(void * ,BOOK* book);
void onTimer(u16 unk,void* data);
int ShowAuthorInfo(void *mess ,BOOK* book);
void onCloseAABook(BOOK * book);
void loopQuestion();
void Onno ( BOOK * BK ,  void  * );
void OnYes ( BOOK * BK ,  void  * );
int myFind (BOOK * book);
const wchar_t* wakeMsg();
static int ReconfigElf(void *mess ,BOOK *book);
int onBcfgConfig(void* mess,BOOK* b);
bool verifyQuestion(int question , int answer);
#endif
