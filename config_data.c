#include "..\\include\cfg_items.h"
#include "config_data.h"

#pragma diag_suppress = Pe177

__root const CFG_HDR cfghdr1 = { CFG_UINT , "Number of Questions" , 0 , 100};
__root const unsigned int NUMBER_OF_QUESTIONS = 5; // Default

__root const CFG_HDR cfghdr2 = { CFG_LEVEL ,"Question Messages" , 1 , 0}; // arg3 = Begin Level >>>LevelName=;
	__root const CFG_HDR cfghdr3 = { CFG_LEVEL ,"Question One" , 1 , 0}; // arg3 = Begin Level >>>LevelName=QuestionOne;
		__root const CFG_HDR cfghdr4 = { CFG_UTF16_STRING , "Message" , 0 , 40};
		__root const wchar_t BCFG_QuestionMessages_QuestionOne[41] = L"Wake up?"; // Default. 

		__root const CFG_HDR cfghdr5 = { CFG_CBOX , "Right Answer" , 0 , 2 }; 
		__root const int BCFG_QuestionOne_RightAnswer = 0; // Default item (Yes).
		__root const CFG_CBOX_ITEM cfgRadioBtn5[2] = {"Yes" , "No"};
	__root const CFG_HDR cfghdr7 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level

	__root const CFG_HDR cfghdr6 = { CFG_LEVEL ,"Question Two" , 1 , 0}; // arg3 = Begin Level >>>LevelName=QuestionTwo;
		__root const CFG_HDR cfghdr8 = { CFG_UTF16_STRING , "Message" , 0 , 40};
		__root const wchar_t BCFG_QuestionMessages_QuestionTwo[41] = L"Really?"; // Default. 

		__root const CFG_HDR cfghdr9 = { CFG_CBOX , "Right Answer" , 0 , 2 }; 
		__root const int BCFG_QuestionTwo_RightAnswer = 0; // Default item (Yes).
		__root const CFG_CBOX_ITEM cfgRadioBtn9[2] = {"Yes" , "No"};
	__root const CFG_HDR cfghdr11 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level

	__root const CFG_HDR cfghdr10 = { CFG_LEVEL ,"Question Three" , 1 , 0}; // arg3 = Begin Level >>>LevelName=QuestionThree;
		__root const CFG_HDR cfghdr12 = { CFG_UTF16_STRING , "Message" , 0 , 40};
		__root const wchar_t BCFG_QuestionMessages_QuestionThree[41] = L"One more try?"; // Default. 

		__root const CFG_HDR cfghdr13 = { CFG_CBOX , "Right Answer" , 0 , 2 }; 
		__root const int BCFG_QuestionThree_RightAnswer = 0; // Default item (Yes).
		__root const CFG_CBOX_ITEM cfgRadioBtn13[2] = {"Yes" , "No"};
		
	__root const CFG_HDR cfghdr15 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level

	__root const CFG_HDR cfghdr14 = { CFG_LEVEL ,"Question Four" , 1 , 0}; // arg3 = Begin Level >>>LevelName=QuestionFour;
		__root const CFG_HDR cfghdr16 = { CFG_UTF16_STRING , "Message" , 0 , 40};
		__root const wchar_t BCFG_QuestionMessages_QuestionFour[41] = L"Its time to wake, now get out of bed!"; // Default. 

		__root const CFG_HDR cfghdr17 = { CFG_CBOX , "Right Answer" , 0 , 2 }; 
		__root const int BCFG_QuestionFour_RightAnswer = 0; // Default item (Yes).
		__root const CFG_CBOX_ITEM cfgRadioBtn17[2] = {"Yes" , "No"};
	__root const CFG_HDR cfghdr19 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level

	__root const CFG_HDR cfghdr18 = { CFG_LEVEL ,"Question Five" , 1 , 0}; // arg3 = Begin Level >>>LevelName=QuestionFive;
		__root const CFG_HDR cfghdr20 = { CFG_UTF16_STRING , "Message" , 0 , 40};
		__root const wchar_t BCFG_QuestionMessages_QuestionFive[41] = L"You asked for this, now GET UP!"; // Default. 

		__root const CFG_HDR cfghdr21 = { CFG_CBOX , "Right Answer" , 0 , 2 }; 
		__root const int BCFG_QuestionFive_RightAnswer = 0; // Default item (Yes).
		__root const CFG_CBOX_ITEM cfgRadioBtn21[2] = {"Yes" , "No"};
	__root const CFG_HDR cfghdr23 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level
        
__root const CFG_HDR cfghdr24 = {CFG_LEVEL , "" , 0 , 0 }; // arg3 = End Level

__root const CFG_HDR cfghdr22 = { CFG_CBOX , "Exit after alarm stops?" , 0 , 2 }; 
__root const int BCFG_ExitAfterAlarmStops = 0; // Default item (Yes).
__root const CFG_CBOX_ITEM cfgRadioBtn22[2] = {"Yes" , "No"};

