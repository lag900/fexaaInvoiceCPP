﻿#include "loh.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew Fexa::loh());
    return 0;
}

