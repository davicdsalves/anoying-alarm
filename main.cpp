#include "..\\include\Lib_Clara.h"
#include "..\\include\Dir.h"
#include "..\\include\var_arg.h"
#include "..\\include\cfg_items.h"
#include "conf_loader.h"
#include "config_data.h"
#include "vars.h"
#include "functions.h"
#define ELF_BCFG_CONFIG_EVENT 994

int TerminateElf(void * ,BOOK* book) {
  FreeBook(book);
  return(1);
}

typedef struct {
  BOOK * book;
}MSG;

void onTimer(u16 unk,void* data) {
  Timer_ReSet(&timer,1000,onTimer,0);
  if (FindBook(isAlarmBook)) {
     Timer_Kill(&timer);
     CreateQuestion();
  }
}

int onBcfgConfig(void* mess,BOOK* b)
{
  FSTAT _fstat;
  wchar_t path[256];
  
  if(fstat(GetDir(DIR_ELFS|MEM_INTERNAL),L"BcfgEdit.elf",&_fstat)==0)
  {
    wstrcpy(path,GetDir(DIR_ELFS|MEM_INTERNAL));
  }
  else if(fstat(GetDir(DIR_ELFS|MEM_EXTERNAL),L"BcfgEdit.elf",&_fstat)==0)
  {
    wstrcpy(path,GetDir(DIR_ELFS|MEM_EXTERNAL));
  }
  else
  {
    MessageBox(0x6FFFFFFF, STR("BcfgEdit.elf not found!"), 0, 1 ,5000, 0);
    return (1);
  }
  wstrcat(path,L"/BcfgEdit.elf");
  elfload(path,(void*)successed_config_path,(void*)successed_config_name,0);
  return (1);
}


int ShowAuthorInfo(void *mess ,BOOK* book){
  MSG * msg = (MSG*)mess;
  MessageBox(EMPTY_SID,STR("Annoying Alarm v0.3b\nby tRaDuZ"), NOIMAGE, 1, 0,msg->book);
  return(1);
}

const PAGE_MSG HW_PageEvents[]@ "DYN_PAGE" ={
  ELF_TERMINATE_EVENT , TerminateElf,
  ELF_SHOW_INFO_EVENT  , ShowAuthorInfo,
  ELF_RECONFIG_EVENT,      ReconfigElf,
  ELF_BCFG_CONFIG_EVENT,   onBcfgConfig,
  NIL_EVENT_TAG,0
};

PAGE_DESC base_page ={"AnnoyingAlarm_BasePage",0,HW_PageEvents};


void elf_exit(void){
  kill_data(&ELF_BEGIN, (void(*)(void*))mfree_adr());
}

void onCloseAABook(BOOK * book){
  if (book){
    Timer_Kill(&timer);
    SUBPROC(elf_exit);
  }
}
void loopQuestion() {
  GUIObject_Destroy(teste);
  if (contador == NUMBER_OF_QUESTIONS) {
    if (BCFG_ExitAfterAlarmStops == 0)
      FreeBook(AABook);
    else {
      contador=0;
      timer=Timer_Set(20000,onTimer,0);
    }
  }
  else
    CreateQuestion ();  
}
bool verifyQuestion(int question , int answer) {
  int answers[0x5] = { BCFG_QuestionFive_RightAnswer, BCFG_QuestionOne_RightAnswer, BCFG_QuestionTwo_RightAnswer ,
  BCFG_QuestionThree_RightAnswer , BCFG_QuestionFour_RightAnswer };
  return (answer == answers[question]) ? true : false;  
}
void Onno ( BOOK * BK ,  void  * ) {
  if (!verifyQuestion(contador%5,1))
    contador--;
  loopQuestion();
} 

void OnYes ( BOOK * BK ,  void  * ) {
  if (!verifyQuestion(contador%5,0))
    contador--;  
  loopQuestion();
}

const wchar_t* wakeMsg() {
  const wchar_t* messages[0x5] = { BCFG_QuestionMessages_QuestionFive , BCFG_QuestionMessages_QuestionOne ,
  BCFG_QuestionMessages_QuestionTwo , BCFG_QuestionMessages_QuestionThree , BCFG_QuestionMessages_QuestionFour };
  
  return messages[contador%5];
}
void CreateQuestion () {
  contador++;
  const wchar_t* on = wakeMsg();
  wchar_t* questionsLeft = new wchar_t[0x15];
  snwprintf(questionsLeft,15,L"Question: %d/%d",contador,NUMBER_OF_QUESTIONS);
  int onID = Str2ID ( on ,  0 ,  41  ) , noID = Str2ID( questionsLeft , 0 , 15 );
  teste = CreateYesNoQuestionVA ( 0 ,
                             VAR_BOOK ( FindBook(isAlarmBook) ) ,
                             VAR_YESNO_PRE_QUESTION ( onID ) ,
                             VAR_YESNO_QUESTION ( noID ) ,
                             VAR_YESNO_YES_ACTION ( OnYes ) ,
                             VAR_YESNO_NO_ACTION ( Onno ) , 
                             0 ) ;
  
  GUIObject_Show(teste);
  on = NULL;
  delete questionsLeft;
}
int isAlarmBook(BOOK * book) {
  if(!strcmp(book->xbook->name,"AlarmBook")) return(1);
  return(0);
}
int myFind (BOOK * book) {
  if (! strcmp (book-> xbook-> name, "Annoying Alarm")) return (1);
  return (0);
}

static int ReconfigElf(void *mess ,BOOK *book)
{
  RECONFIG_EVENT_DATA *reconf=(RECONFIG_EVENT_DATA *)mess;
  int result=0;
  if (wstrcmpi(reconf->path,successed_config_path)==0 && wstrcmpi(reconf->name,successed_config_name)==0)
  {
    InitConfig();
    Timer_ReSet(&timer,1000,onTimer,0);
    result=1;
  }
  return(result);
}

int main (void){
  if (FindBook(myFind)) {
    MessageBox(EMPTY_SID,STR("Annoying Alarm is runing!"), NOIMAGE, 1, 0,0);
    SUBPROC(elf_exit);
  }
  else {
    InitConfig();
    AABook = new BOOK ;
    CreateBook ( AABook,onCloseAABook,&base_page , "Annoying Alarm" , - 1 , 0 ) ;
    timer=Timer_Set(1000,onTimer,0);
  }
  return(0);
}
